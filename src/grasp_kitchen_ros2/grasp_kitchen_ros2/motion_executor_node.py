from __future__ import annotations

import asyncio
from typing import Optional

import rclpy
from rclpy.action import ActionClient, ActionServer
from rclpy.node import Node

from grasp_kitchen_ros2.action import ExecuteTask, FollowCartesianTrajectory
from grasp_kitchen_ros2.motion.entities.constraints import MotionConstraints
from grasp_kitchen_ros2.motion.entities.motion_primitive import MotionPrimitive
from grasp_kitchen_ros2.motion.skills.pick_and_place import PickAndPlaceSkill
from grasp_kitchen_ros2.planning.entities.pose3d import Pose3D
from grasp_kitchen_ros2.srv import SetIO


class MotionExecutorNode(Node):
    """ROS2 motion executor node.

    - 接收 TaskPlanner 发来的 ExecuteTask action；
    - 使用 PickAndPlaceSkill 将 grasp/place 映射为运动原语列表；
    - 通过 FollowCartesianTrajectory + SetIO 调用 RobotDriver。
    """

    def __init__(self) -> None:
        super().__init__("motion_executor_node")

        # 参数：运动约束
        self.declare_parameter("approach_offset", 0.08)
        self.declare_parameter("retreat_offset", 0.08)
        self.declare_parameter("min_z", -0.33)
        self.declare_parameter("max_z", 0.20)
        self.declare_parameter("max_linear_vel", 0.2)
        self.declare_parameter("max_linear_acc", 0.2)

        c = MotionConstraints(
            approach_offset=self.get_parameter("approach_offset").get_parameter_value().double_value,
            retreat_offset=self.get_parameter("retreat_offset").get_parameter_value().double_value,
            min_z=self.get_parameter("min_z").get_parameter_value().double_value,
            max_z=self.get_parameter("max_z").get_parameter_value().double_value,
            max_linear_vel=self.get_parameter("max_linear_vel").get_parameter_value().double_value,
            max_linear_acc=self.get_parameter("max_linear_acc").get_parameter_value().double_value,
        )
        self._constraints = c
        self._skill = PickAndPlaceSkill(constraints=c)

        self._execute_server = ActionServer(
            self,
            ExecuteTask,
            "motion_executor/execute_task",
            execute_callback=self._execute_task_cb,
        )

        self._traj_client = ActionClient(
            self,
            FollowCartesianTrajectory,
            "robot_driver/follow_cartesian_trajectory",
        )

        self._io_client = self.create_client(SetIO, "robot_driver/set_io")

        self.get_logger().info(
            "MotionExecutorNode initialized with PickAndPlaceSkill "
            "and trajectory/IO clients wired to RobotDriver."
        )

    # --- helpers ------------------------------------------------------------------

    def _ros_pose_to_pose3d(self, ros_pose) -> Pose3D:
        # 当前只使用位置和 yaw=0；将来可从四元数中提取 yaw
        return Pose3D(
            x=ros_pose.position.x,
            y=ros_pose.position.y,
            z=ros_pose.position.z,
            roll=0.0,
            pitch=0.0,
            yaw=0.0,
        )

    async def _execute_motion_primitive(self, prim: MotionPrimitive) -> bool:
        """Execute one MotionPrimitive via RobotDriver interfaces."""
        if prim.kind == "MOVE_CARTESIAN":
            if prim.trajectory is None:
                self.get_logger().error("MOVE_CARTESIAN primitive without trajectory.")
                return False

            if not self._traj_client.wait_for_server(timeout_sec=2.0):
                self.get_logger().error("FollowCartesianTrajectory action server not available.")
                return False

            goal = FollowCartesianTrajectory.Goal()
            for wp in prim.trajectory.waypoints:
                pose = type("P", (), {})()  # placeholder; will be replaced below
            # 正确构造 geometry_msgs/Pose
            from geometry_msgs.msg import Pose

            goal.waypoints = []
            for wp in prim.trajectory.waypoints:
                p = Pose()
                p.position.x, p.position.y, p.position.z = wp.position
                p.orientation.x, p.orientation.y, p.orientation.z, p.orientation.w = wp.quaternion
                goal.waypoints.append(p)

            goal.max_velocity = float(prim.trajectory.max_velocity)
            goal.max_acceleration = float(prim.trajectory.max_acceleration)

            send_future = self._traj_client.send_goal_async(goal)
            goal_handle = await send_future
            if not goal_handle.accepted:
                self.get_logger().error("FollowCartesianTrajectory goal rejected by RobotDriver.")
                return False

            result_future = goal_handle.get_result_async()
            result = await result_future
            if result.result.success:
                return True
            self.get_logger().warn(f"FollowCartesianTrajectory failed: {result.result.error_msg}")
            return False

        if prim.kind in ("OPEN_HAND", "CLOSE_HAND"):
            if not self._io_client.wait_for_service(timeout_sec=2.0):
                self.get_logger().error("SetIO service not available.")
                return False
            request = SetIO.Request()
            request.io_name = "gripper"
            request.state = prim.kind == "CLOSE_HAND"
            future = self._io_client.call_async(request)
            await future
            resp = future.result()
            if resp is None or not resp.success:
                self.get_logger().warn(f"SetIO failed: {getattr(resp, 'message', 'no response')}")
                return False
            return True

        self.get_logger().error(f"Unknown MotionPrimitive kind: {prim.kind}")
        return False

    # --- ExecuteTask action callback ---------------------------------------------

    async def _execute_task_cb(
        self, goal_handle: ExecuteTask.Goal
    ) -> ExecuteTask.Result:
        self.get_logger().info(
            f"ExecuteTask received: task_id={goal_handle.task_id}, "
            f"object_id={goal_handle.target.object_id}"
        )

        grasp_pose = self._ros_pose_to_pose3d(goal_handle.target.grasp_pose)
        place_pose = self._ros_pose_to_pose3d(goal_handle.target.place_pose)

        primitives = self._skill.build_primitives(grasp_pose, place_pose)
        total = len(primitives)
        feedback = ExecuteTask.Feedback()

        for idx, prim in enumerate(primitives):
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                result = ExecuteTask.Result()
                result.success = False
                result.error_msg = "Canceled by client."
                self.get_logger().warn(
                    f"ExecuteTask for task_id={goal_handle.task_id} canceled."
                )
                return result

            ok = await self._execute_motion_primitive(prim)
            if not ok:
                result = ExecuteTask.Result()
                result.success = False
                result.error_msg = f"Failed at primitive {idx} ({prim.kind})"
                self.get_logger().error(result.error_msg)
                return result

            # 简单阶段反馈
            phase = ""
            if prim.kind == "MOVE_CARTESIAN":
                phase = "moving"
            elif prim.kind == "CLOSE_HAND":
                phase = "grasping"
            elif prim.kind == "OPEN_HAND":
                phase = "placing"

            feedback.phase = phase
            feedback.progress = float(idx + 1) / float(total)
            goal_handle.publish_feedback(feedback)

        result = ExecuteTask.Result()
        result.success = True
        result.error_msg = ""
        goal_handle.succeed()

        self.get_logger().info(
            f"ExecuteTask completed successfully for task_id={goal_handle.task_id}."
        )
        return result


def main(args: Optional[list[str]] = None) -> None:
    rclpy.init(args=args)
    node = MotionExecutorNode()

    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()

