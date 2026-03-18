from __future__ import annotations

from typing import Optional

import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from sensor_msgs.msg import CameraInfo, Image

from grasp_kitchen_ros2.msg import ObjectDetection, ScenePerception
from grasp_kitchen_ros2.vision.entities.camera_model import CameraModel
from grasp_kitchen_ros2.vision.entities.detections import DetectedObject
from grasp_kitchen_ros2.vision.pipeline.perception_pipeline import PerceptionPipeline
from grasp_kitchen_ros2.vision.pipeline.sam3_backend import SAM3Backend
from grasp_kitchen_ros2.vision.pipeline.yolo_backend import YoloSegBackend


class PerceptionNode(Node):
    """ROS2 perception node.

    封装 RealSense + SAM3 + 标定，周期性发布 `ScenePerception` 到 `perception/scene`。
    """

    def __init__(self) -> None:
        super().__init__("perception_node")

        # Declare parameters (can be overridden via launch/CLI)
        self.declare_parameter("backend_type", "sam3")  # "sam3" or "yolo"
        self.declare_parameter("sam3_model_dir", "/home/dex-rob/DexCatch/sam3model")
        self.declare_parameter("text_prompt", "orange")
        self.declare_parameter("conf_threshold", 0.5)
        self.declare_parameter("publish_rate_hz", 1.0)
        self.declare_parameter("depth_scale", 0.001)  # e.g. 16UC1 in mm -> meters
        self.declare_parameter("T_base_cam", [1.0, 0.0, 0.0, 0.0,
                                              0.0, 1.0, 0.0, 0.0,
                                              0.0, 0.0, 1.0, 0.0,
                                              0.0, 0.0, 0.0, 1.0])

        backend_type = self.get_parameter("backend_type").get_parameter_value().string_value
        sam3_model_dir = self.get_parameter("sam3_model_dir").get_parameter_value().string_value
        text_prompt = self.get_parameter("text_prompt").get_parameter_value().string_value
        conf_threshold = self.get_parameter("conf_threshold").get_parameter_value().double_value
        publish_rate_hz = self.get_parameter("publish_rate_hz").get_parameter_value().double_value
        depth_scale = self.get_parameter("depth_scale").get_parameter_value().double_value
        T_base_cam_list = (
            self.get_parameter("T_base_cam").get_parameter_value().double_array_value
        )

        self._T_base_cam = np.array(T_base_cam_list, dtype=float).reshape(4, 4)
        self._bridge = CvBridge()
        self._latest_rgb: Optional[Image] = None
        self._latest_depth: Optional[Image] = None
        self._latest_info: Optional[CameraInfo] = None
        self._K: Optional[np.ndarray] = None

        self._scene_pub = self.create_publisher(
            ScenePerception,
            "perception/scene",
            10,
        )

        if backend_type == "yolo":
            backend = YoloSegBackend()
        else:
            backend = SAM3Backend(model_path=sam3_model_dir)

        self._pipeline = PerceptionPipeline(
            backend=backend,
            text_prompt=text_prompt,
            conf_threshold=float(conf_threshold),
        )
        self._camera_model: Optional[CameraModel] = None

        self._rgb_sub = self.create_subscription(
            Image,
            "camera/color/image_raw",
            self._on_rgb,
            10,
        )
        self._depth_sub = self.create_subscription(
            Image,
            "camera/depth/image_raw",
            self._on_depth,
            10,
        )
        self._info_sub = self.create_subscription(
            CameraInfo,
            "camera/camera_info",
            self._on_info,
            10,
        )

        timer_period = 1.0 / max(publish_rate_hz, 0.1)
        self._scene_timer = self.create_timer(timer_period, self._publish_scene)
        self._scene_counter: int = 0

        self.get_logger().info(
            "PerceptionNode initialized as pure ROS2 consumer of camera topics.\n"
            f"  sam3_model_dir: {sam3_model_dir}\n"
            f"  text_prompt: {text_prompt}, conf_threshold: {conf_threshold}"
        )

    # ----------------------------------------------------------------- subscribers

    def _on_rgb(self, msg: Image) -> None:
        self._latest_rgb = msg

    def _on_depth(self, msg: Image) -> None:
        self._latest_depth = msg

    def _on_info(self, msg: CameraInfo) -> None:
        self._latest_info = msg
        if self._K is None and len(msg.k) == 9:
            self._K = np.array(msg.k, dtype=float).reshape(3, 3)
            self._camera_model = CameraModel(
                K=self._K,
                T_base_cam=self._T_base_cam,
                depth_scale=float(self.get_parameter("depth_scale").get_parameter_value().double_value),
            )

    def _publish_scene(self) -> None:
        if (
            self._latest_rgb is None
            or self._latest_depth is None
            or self._camera_model is None
        ):
            # 尚未收到完整的 RGB/Depth/CameraInfo，发布无效场景
            msg = ScenePerception()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = "base"
            msg.scene_id = f"scene_{self._scene_counter}"
            msg.scene_valid = False
            msg.objects = []
            self._scene_pub.publish(msg)
            self._scene_counter += 1
            return

        # Convert ROS images to numpy
        color_bgr = self._bridge.imgmsg_to_cv2(self._latest_rgb, desired_encoding="bgr8")
        depth_raw = self._bridge.imgmsg_to_cv2(
            self._latest_depth, desired_encoding="passthrough"
        )

        detections = self._pipeline.run(color_bgr, depth_raw, self._camera_model)

        msg = ScenePerception()
        now = self.get_clock().now().to_msg()
        msg.header.stamp = now
        msg.header.frame_id = "base"  # using base frame after hand-eye calibration
        msg.scene_id = f"scene_{self._scene_counter}"

        if not detections:
            msg.scene_valid = False
            msg.objects = []
            self._scene_pub.publish(msg)
            self._scene_counter += 1
            return

        msg.scene_valid = True

        objects: list[ObjectDetection] = []
        for idx, det in enumerate(detections):
            obj = ObjectDetection()
            obj.id = f"obj_{self._scene_counter}_{idx}"
            obj.class_name = det.class_name
            obj.pose.position.x = det.position[0]
            obj.pose.position.y = det.position[1]
            obj.pose.position.z = det.position[2]
            obj.pose.orientation.x = det.quaternion[0]
            obj.pose.orientation.y = det.quaternion[1]
            obj.pose.orientation.z = det.quaternion[2]
            obj.pose.orientation.w = det.quaternion[3]
            obj.confidence = det.confidence
            obj.size.x = det.size_xyz[0]
            obj.size.y = det.size_xyz[1]
            obj.size.z = det.size_xyz[2]
            objects.append(obj)

        msg.objects = objects
        self._scene_pub.publish(msg)
        self.get_logger().info(
            f"Published ScenePerception id={msg.scene_id}, objects={len(objects)}"
        )

        self._scene_counter += 1


def main(args: Optional[list[str]] = None) -> None:
    rclpy.init(args=args)
    node = PerceptionNode()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()



