from __future__ import annotations

from dataclasses import dataclass, field
from typing import List, Literal

from grasp_kitchen_ros2.planning.entities.pose3d import Pose3D


@dataclass
class PlannedStep:
    """One planned pick-and-place step within a task."""

    step_index: int
    fruit_id: str
    pattern_index: int
    grasp_pose: Pose3D
    place_pose: Pose3D
    ik_feasible: bool = True
    ik_failure_reason: str = ""


@dataclass
class TaskPlan:
    """Full plan for a high-level task (sequence of steps)."""

    task_id: str
    task_type: str
    target_class: str
    steps: List[PlannedStep] = field(default_factory=list)
    status: Literal["PLANNED", "RUNNING", "PAUSED", "COMPLETED", "FAILED"] = "PLANNED"


