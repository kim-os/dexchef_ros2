from __future__ import annotations

from typing import Optional

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import CameraInfo, Image


class CameraDriverNode(Node):
    """Generic camera bridge node.

    设计目标：
    - 不直接依赖具体厂商 SDK（Orbbec、RealSense 等）；
    - 从已有相机节点订阅图像与 CameraInfo；
    - 统一重发布为:
        - camera/color/image_raw
        - camera/depth/image_raw
        - camera/camera_info

    这样做可以：
    - 利用厂商官方 ROS2 驱动（包括 Orbbec）；
    - 通过 rosbag 直接录制/回放这些标准 topic；
    - 感知算法只依赖这些通用话题，而不关心硬件细节。
    """

    def __init__(self) -> None:
        super().__init__("camera_driver_node")

        # 可配置：上游相机节点输出的 topic 名
        self.declare_parameter("rgb_topic_in", "/orbbec/color/image_raw")
        self.declare_parameter("depth_topic_in", "/orbbec/depth/image_raw")
        self.declare_parameter("camera_info_topic_in", "/orbbec/camera_info")

        rgb_in = self.get_parameter("rgb_topic_in").get_parameter_value().string_value
        depth_in = self.get_parameter("depth_topic_in").get_parameter_value().string_value
        info_in = (
            self.get_parameter("camera_info_topic_in").get_parameter_value().string_value
        )

        # 统一对外发布的 topic
        self._rgb_pub = self.create_publisher(Image, "camera/color/image_raw", 10)
        self._depth_pub = self.create_publisher(Image, "camera/depth/image_raw", 10)
        self._info_pub = self.create_publisher(CameraInfo, "camera/camera_info", 10)

        self._rgb_sub = self.create_subscription(
            Image,
            rgb_in,
            self._on_rgb,
            10,
        )
        self._depth_sub = self.create_subscription(
            Image,
            depth_in,
            self._on_depth,
            10,
        )
        self._info_sub = self.create_subscription(
            CameraInfo,
            info_in,
            self._on_info,
            10,
        )

        self.get_logger().info(
            "CameraDriverNode initialized.\n"
            f"  Subscribing RGB:   {rgb_in}\n"
            f"  Subscribing Depth: {depth_in}\n"
            f"  Subscribing Info:  {info_in}\n"
            "  Publishing as   :  camera/color|depth/image_raw, camera/camera_info"
        )

    def _on_rgb(self, msg: Image) -> None:
        self._rgb_pub.publish(msg)

    def _on_depth(self, msg: Image) -> None:
        self._depth_pub.publish(msg)

    def _on_info(self, msg: CameraInfo) -> None:
        self._info_pub.publish(msg)


def main(args: Optional[list[str]] = None) -> None:
    rclpy.init(args=args)
    node = CameraDriverNode()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()

