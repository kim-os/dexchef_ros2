#!/usr/bin/env python3

"""
调试脚本：验证感知层数据流
订阅 camera/* 话题和 perception/scene，打印接收到的数据摘要。
运行前确保 ROS2 环境已 source，并启动上游相机驱动 + 感知节点。
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from grasp_kitchen_ros2.msg import ScenePerception


class PerceptionDebugger(Node):
    def __init__(self):
        super().__init__('perception_debugger')

        # 订阅相机话题
        self.create_subscription(Image, 'camera/color/image_raw', self.on_rgb, 10)
        self.create_subscription(Image, 'camera/depth/image_raw', self.on_depth, 10)
        self.create_subscription(CameraInfo, 'camera/camera_info', self.on_info, 10)

        # 订阅感知输出
        self.create_subscription(ScenePerception, 'perception/scene', self.on_scene, 10)

        self.get_logger().info("PerceptionDebugger started. Listening for topics...")

    def on_rgb(self, msg: Image):
        self.get_logger().info(f"RGB Image received: {msg.width}x{msg.height}, encoding={msg.encoding}")

    def on_depth(self, msg: Image):
        self.get_logger().info(f"Depth Image received: {msg.width}x{msg.height}, encoding={msg.encoding}")

    def on_info(self, msg: CameraInfo):
        self.get_logger().info(f"CameraInfo received: K={msg.k[:3]}, distortion={msg.distortion_model}")

    def on_scene(self, msg: ScenePerception):
        self.get_logger().info(f"ScenePerception received: valid={msg.scene_valid}, objects={len(msg.objects)}")
        for obj in msg.objects:
            self.get_logger().info(f"  Object: id={obj.id}, class={obj.class_name}, pose=({obj.pose.position.x:.3f}, {obj.pose.position.y:.3f}, {obj.pose.position.z:.3f})")


def main():
    rclpy.init()
    node = PerceptionDebugger()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()