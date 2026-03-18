#!/usr/bin/env python3

"""Fake camera publisher for testing ROS2 topics.

此脚本会不断向 `/orbbec/color/image_raw` 和 `/orbbec/depth/image_raw` 发布伪造图像，
可用于验证感知层（camera_driver_node + perception_node）是否能够订阅并处理图像流。

用法示例：
  ros2 run grasp_kitchen_ros2 camera_driver_node --ros-args -p orbbec_rgb_topic:=/orbbec/color/image_raw ...
  python3 text/fake_camera_publisher.py

然后运行 debug_perception.py 来验证 topic 是否被消费。
"""

import time

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from geometry_msgs.msg import TransformStamped
from rclpy.node import Node
from sensor_msgs.msg import CameraInfo, Image


class FakeCameraPublisher(Node):
    def __init__(self):
        super().__init__('fake_camera_publisher')
        self._bridge = CvBridge()
        self._rgb_pub = self.create_publisher(Image, '/orbbec/color/image_raw', 10)
        self._depth_pub = self.create_publisher(Image, '/orbbec/depth/image_raw', 10)
        self._info_pub = self.create_publisher(CameraInfo, '/orbbec/camera_info', 10)

        self._timer = self.create_timer(1.0 / 10.0, self._on_timer)
        self._frame_id = 'orbbec_camera'
        self._seq = 0

        self.get_logger().info('FakeCameraPublisher started, publishing dummy frames to /orbbec/...')

    def _make_rgb(self) -> Image:
        h, w = 480, 640
        img = np.zeros((h, w, 3), dtype=np.uint8)
        t = time.time()
        # 动态彩条
        img[:, :, 0] = np.linspace(0, 255, w, dtype=np.uint8)[None, :]
        img[:, :, 1] = (np.sin(t) * 127 + 128).astype(np.uint8)
        img[:, :, 2] = (np.cos(t) * 127 + 128).astype(np.uint8)
        msg = self._bridge.cv2_to_imgmsg(img, encoding='bgr8')
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self._frame_id
        msg.header.frame_id = self._frame_id
        msg.header.seq = self._seq
        return msg

    def _make_depth(self) -> Image:
        h, w = 480, 640
        img = np.full((h, w), 1000, dtype=np.uint16)  # 1m depth
        msg = self._bridge.cv2_to_imgmsg(img, encoding='16UC1')
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self._frame_id
        msg.header.seq = self._seq
        return msg

    def _make_info(self) -> CameraInfo:
        info = CameraInfo()
        info.header.stamp = self.get_clock().now().to_msg()
        info.header.frame_id = self._frame_id
        info.width = 640
        info.height = 480
        info.k = [600.0, 0.0, 320.0, 0.0, 600.0, 240.0, 0.0, 0.0, 1.0]
        info.p = [600.0, 0.0, 320.0, 0.0, 0.0, 600.0, 240.0, 0.0, 0.0, 0.0, 1.0, 0.0]
        return info

    def _on_timer(self):
        self._seq += 1
        self._rgb_pub.publish(self._make_rgb())
        self._depth_pub.publish(self._make_depth())
        self._info_pub.publish(self._make_info())


def main():
    rclpy.init()
    node = FakeCameraPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
