from __future__ import annotations

from typing import Optional

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from grasp_kitchen_ros2.action import ExecuteTask
from grasp_kitchen_ros2.msg import ScenePerception, TaskTarget
from grasp_kitchen_ros2.planning.entities.scene_state import WorldObject, WorldState
from grasp_kitchen_ros2.planning.policy.orange_heart_policy import OrangeHeartPolicy
from grasp_kitchen_ros2.srv import StartTask


class TaskPlannerNode(Node):
    """ROS2 task planner node for the orange-heart task."""

    def __init__(self) -> None:
        super().__init__("task_planner_node")

        # 内部世界模型 + 策略
        self._world = WorldState()
        self._policy = OrangeHeartPolicy(scene=self._world, num_pattern_points=10)

        # 当前任务状态
        self._active_task_id: Optional[str] = None
        self._active_task_type: str = "orange_heart"
        self._target_class: str = "orange"

        # 订阅最新感知场景（只保留最新）
        self._scene_sub = self.create_subscription(
            ScenePerception,
            "perception/scene",
            self._on_scene,
            10,
        )

        # 启动任务的 service
        self._start_task_srv = self.create_service(
            StartTask,
            "task_planner/start_task",
            self._on_start_task,
        )

        # 与 Motion Executor 的 ExecuteTask action client
        self._execute_client = ActionClient(
            self, ExecuteTask, "motion_executor/execute_task"
        )

        # 简单周期性定时器：当有 active task 且没有正在执行的 goal 时，请求下一个 TaskGoal
        self._tick_timer = self.create_timer(1.0, self._on_tick)
        self._pending_goal: bool = False

        self.get_logger().info(
            "TaskPlannerNode initialized (SceneState + OrangeHeartPolicy wired up)."
        )

    # --- ROS callbacks ------------------------------------------------------------

    def _on_scene(self, msg: ScenePerception) -> None:
        """Update WorldState from the latest perception message."""
        if not msg.scene_valid:
            return

        self._world.objects.clear()
        for obj in msg.objects:
            world_obj = WorldObject(
                id=obj.id,
                class_name=obj.class_name,
                x=obj.pose.position.x,
                y=obj.pose.position.y,
                z=obj.pose.position.z,
            )
            self._world.objects[world_obj.id] = world_obj

    def _on_start_task(
        self, request: StartTask.Request, response: StartTask.Response
    ) -> StartTask.Response:
        """Start a new high-level task (e.g. orange-heart pattern)."""
        if not self._world.objects:
            response.accepted = False
            response.message = "No fruits in current scene."
            self.get_logger().warn("StartTask rejected: no fruits in scene.")
            return response

        task_id = "task_0"  # 后续可扩展为 UUID
        self._active_task_id = task_id
        self._active_task_type = request.task_type or "orange_heart"
        self._target_class = request.target_class or ""

        # 重置 pattern 进度（通过新建 policy 达到重置效果）
        self._policy = OrangeHeartPolicy(scene=self._world, num_pattern_points=10)
        self._pending_goal = False

        self.get_logger().info(
            f"StartTask accepted: task_id={task_id}, "
            f"type={self._active_task_type}, target_class={self._target_class}"
        )

        response.accepted = True
        response.message = f"Task {task_id} started."
        return response

    def _on_tick(self) -> None:
        """Periodic planner tick: send next ExecuteTask goal if needed."""
        if self._active_task_id is None:
            return
        if self._pending_goal:
            return

        # 使用策略选择下一个 PlannedStep（内部会在需要时先 plan 一次）
        goal = self._policy.select_next_goal(
            task_id=self._active_task_id,
            task_type=self._active_task_type,
            target_class=self._target_class,
        )
        if goal is None:
            self.get_logger().info(
                f"Task {self._active_task_id} completed or no more goals available."
            )
            self._active_task_id = None
            return

        # 将 PlannedStep 映射为 ExecuteTask.Action goal
        if not self._execute_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().error(
                "ExecuteTask action server not available, cannot send goal."
            )
            return

        task_target = TaskTarget()
        task_target.task_id = goal.task_id
        task_target.object_id = goal.fruit_id
        task_target.class_name = goal.fruit_class

        # grasp_pose
        task_target.grasp_pose.position.x = goal.grasp_pose.x
        task_target.grasp_pose.position.y = goal.grasp_pose.y
        task_target.grasp_pose.position.z = goal.grasp_pose.z
        # 这里先不映射 roll/pitch/yaw 到四元数，后续可在 MotionExecutor 内部完成

        # place_pose
        task_target.place_pose.position.x = goal.place_pose.x
        task_target.place_pose.position.y = goal.place_pose.y
        task_target.place_pose.position.z = goal.place_pose.z

        goal_msg = ExecuteTask.Goal()
        goal_msg.task_id = goal.task_id
        goal_msg.task_type = self._active_task_type
        goal_msg.target = task_target

        self.get_logger().info(
            f"Sending ExecuteTask goal for task_id={goal_msg.task_id}, "
            f"fruit_id={goal.fruit_id}"
        )

        self._pending_goal = True

        def _on_result(fut) -> None:
            self._pending_goal = False
            result = fut.result().result
            if result.success:
                # 标记该水果已被 pick + placed
                self._world.picked.add(goal.fruit_id)
                self._world.placed.add(goal.fruit_id)
                self.get_logger().info(
                    f"ExecuteTask for fruit_id={goal.fruit_id} succeeded."
                )
            else:
                self.get_logger().warn(
                    f"ExecuteTask for fruit_id={goal.fruit_id} failed: {result.error_msg}"
                )

        send_future = self._execute_client.send_goal_async(goal_msg)
        send_future.add_done_callback(
            lambda goal_future: goal_future.result().get_result_async().add_done_callback(_on_result)
        )


def main(args: Optional[list[str]] = None) -> None:
    rclpy.init(args=args)
    node = TaskPlannerNode()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()


