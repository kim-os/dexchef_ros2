from __future__ import annotations

from dataclasses import dataclass
from typing import List, Optional

from grasp_kitchen_ros2.planning.entities.pattern import (
    PatternTarget,
    generate_heart_pattern_points,
    pattern_points_to_pattern_targets,
)
from grasp_kitchen_ros2.planning.entities.pose3d import Pose3D
from grasp_kitchen_ros2.planning.entities.scene_state import WorldObject, WorldState
from grasp_kitchen_ros2.planning.entities.plan import PlannedStep, TaskPlan


@dataclass
class OrangeHeartParams:
    """Static parameters needed by the orange-heart policy."""

    grasp_yaw_fix_rad: float = -0.8


class OrangeHeartPolicy:
    """
    Planner core for the MVP "orange heart" task.

    责任：
    - 维护内部 SceneState 引用（或使用外部注入的 SceneState）；
    - 根据当前世界状态和心形 pattern 选择下一个 TaskGoal；
    - 不关心 ROS2，不直接调用 MotionExecutor。
    """

    def __init__(
        self,
        scene: Optional[SceneState] = None,
        num_pattern_points: int = 10,
        params: Optional[OrangeHeartParams] = None,
    ) -> None:
        self._world = scene or WorldState()
        self._params = params or OrangeHeartParams()

        pattern_points = generate_heart_pattern_points(num_pattern_points)
        self._pattern_targets: List[PatternTarget] = pattern_points_to_pattern_targets(
            pattern_points
        )
        self._next_pattern_index: int = 0
        self._current_plan: Optional[TaskPlan] = None

    @property
    def world(self) -> WorldState:
        return self._world

    # ------------------------------------------------------------------ helpers

    def _select_next_fruit(self) -> Optional[WorldObject]:
        """Select the next unpicked/unplaced object (simplest: first one)."""
        for obj_id, fruit in self._world.objects.items():
            if obj_id not in self._world.picked and obj_id not in self._world.placed:
                return fruit
        return None

    def _select_next_pattern_target(self) -> Optional[PatternTarget]:
        if self._next_pattern_index >= len(self._pattern_targets):
            return None
        target = self._pattern_targets[self._next_pattern_index]
        self._next_pattern_index += 1
        return target

    def _compute_grasp_pose(self, fruit: WorldObject) -> Pose3D:
        """
        Compute a grasp pose for the given fruit (top-down + fixed yaw).
        """
        yaw = self._params.grasp_yaw_fix_rad
        return Pose3D(
            x=fruit.x,
            y=fruit.y,
            z=fruit.z,
            roll=0.0,
            pitch=0.0,
            yaw=yaw,
        )

    # ----------------------------------------------------------------- public

    def plan(self, task_id: str, task_type: str, target_class: str) -> TaskPlan:
        """
        规划阶段：基于当前 WorldState + 心形 pattern 生成完整的 TaskPlan。

        目前 IK 检查尚未接入，暂时将所有步骤标记为 ik_feasible=True。
        预留：在创建 PlannedStep 时调用 IK service 进行过滤。
        """
        steps: List[PlannedStep] = []

        # 简单策略：按 pattern 顺序与未被 picked/placed 的对象一一配对
        pattern_iter = iter(self._pattern_targets)
        step_index = 0

        for obj_id, obj in self._world.objects.items():
            if obj_id in self._world.picked or obj_id in self._world.placed:
                continue
            target = next(pattern_iter, None)
            if target is None:
                break

            grasp_pose = self._compute_grasp_pose(obj)
            place_pose = target.pose

            # TODO: 在此处调用 IK service 检查可达性，并设置 ik_feasible/ik_failure_reason
            step = PlannedStep(
                step_index=step_index,
                fruit_id=obj.id,
                pattern_index=target.index,
                grasp_pose=grasp_pose,
                place_pose=place_pose,
                ik_feasible=True,
            )
            steps.append(step)
            step_index += 1

        plan = TaskPlan(
            task_id=task_id,
            task_type=task_type,
            target_class=target_class,
            steps=steps,
            status="PLANNED",
        )
        self._current_plan = plan
        return plan

    def select_next_goal(
        self, task_id: str, task_type: str, target_class: str
    ) -> Optional[PlannedStep]:
        """
        Select the next TaskGoal for a pick-and-place step.

        返回:
            PlannedStep: 若还有工作要做；
            None: 若 pattern 填满或没有可用水果。
        """
        # 若当前还没有 plan，则先规划一次
        if self._current_plan is None or self._current_plan.task_id != task_id:
            self.plan(task_id, task_type, target_class)

        if self._current_plan is None or not self._current_plan.steps:
            return None

        # 选择下一个尚未执行的、且 ik_feasible 的步骤
        for step in self._current_plan.steps:
            if not step.ik_feasible:
                continue
            # 简单实现：返回第一个可行步骤（后续可扩展为按状态跟踪已执行步骤）
            return step

        return None

