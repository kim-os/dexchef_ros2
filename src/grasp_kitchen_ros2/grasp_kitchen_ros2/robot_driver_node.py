from __future__ import annotations

import asyncio
from typing import Optional, List

import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from grasp_kitchen_ros2.action import FollowCartesianTrajectory
from grasp_kitchen_ros2.robot.driver_core import CartesianStep, RobotDriverCore
from grasp_kitchen_ros2.srv import SetIO


class RobotDriverNode(Node):
    """ROS2 robot driver node.

    责任：
    - 对上：提供 FollowCartesianTrajectory.action + SetIO.srv 接口；
    - 内部：调用 RobotDriverCore 执行轨迹与 IO 操作；
    - 对下：未来在 RobotDriverCore 内接入真实 LBot SDK。
    """

    def __init__(self) -> None:
        super().__init__("robot_driver_node")

        # 核心 driver（当前为 stub，只打印日志）
        self._core = RobotDriverCore(logger=self.get_logger())

        self._traj_server = ActionServer(
            self,
            FollowCartesianTrajectory,
            "robot_driver/follow_cartesian_trajectory",
            execute_callback=self._follow_traj_cb,
        )

        self._set_io_srv = self.create_service(
            SetIO,
            "robot_driver/set_io",
            self._on_set_io,
        )

        self.get_logger().info(
            "RobotDriverNode initialized (trajectory action + IO service bound to RobotDriverCore)."
        )

    # --- FollowCartesianTrajectory action ----------------------------------------

    async def _follow_traj_cb(
        self, goal_handle: FollowCartesianTrajectory.Goal
    ) -> FollowCartesianTrajectory.Result:
        waypoints = goal_handle.waypoints

        # 1. 将 ROS Pose[] 转为 CartesianStep 列表，供核心层使用
        steps: List[CartesianStep] = []
        for p in waypoints:
            steps.append(
                CartesianStep(
                    position=(p.position.x, p.position.y, p.position.z),
                    quaternion=(
                        p.orientation.x,
                        p.orientation.y,
                        p.orientation.z,
                        p.orientation.w,
                    ),
                )
            )

        self.get_logger().info(
            f"FollowCartesianTrajectory received: {len(steps)} steps, "
            f"v={goal_handle.max_velocity}, a={goal_handle.max_acceleration}"
        )

        feedback = FollowCartesianTrajectory.Feedback()

        # 2. 逐步执行 steps，同时发布 feedback
        for idx, step in enumerate(steps):
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                result = FollowCartesianTrajectory.Result()
                result.success = False
                result.error_msg = "Canceled by client."
                self.get_logger().warn("Trajectory execution canceled by client.")
                return result

            ok = self._core.execute_cartesian_trajectory(
                [step],
                max_velocity=goal_handle.max_velocity,
                max_acceleration=goal_handle.max_acceleration,
            )
            if not ok:
                result = FollowCartesianTrajectory.Result()
                result.success = False
                result.error_msg = f"Failed at step {idx}"
                self.get_logger().error(result.error_msg)
                return result

            # 填充并发布反馈
            feedback.current_index = idx
            # 将 CartesianStep 映射回 Pose（用于 feedback）
            from geometry_msgs.msg import Pose

            pose_fb = Pose()
            pose_fb.position.x, pose_fb.position.y, pose_fb.position.z = step.position
            (
                pose_fb.orientation.x,
                pose_fb.orientation.y,
                pose_fb.orientation.z,
                pose_fb.orientation.w,
            ) = step.quaternion
            feedback.current_pose = pose_fb
            goal_handle.publish_feedback(feedback)

            # 模拟执行时间；真实实现中应等待底层 SDK 完成
            await asyncio.sleep(0.3)

        result = FollowCartesianTrajectory.Result()
        result.success = True
        result.error_msg = ""
        goal_handle.succeed()

        self.get_logger().info("FollowCartesianTrajectory completed successfully.")
        return result

    # --- SetIO service -----------------------------------------------------------

    def _on_set_io(self, request: SetIO.Request, response: SetIO.Response) -> SetIO.Response:
        ok = self._core.set_io(request.io_name, request.state)
        response.success = ok
        response.message = "IO updated." if ok else "Failed to update IO."
        return response


def main(args: Optional[list[str]] = None) -> None:
    rclpy.init(args=args)
    node = RobotDriverNode()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()

