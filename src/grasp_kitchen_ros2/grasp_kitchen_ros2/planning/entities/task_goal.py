from __future__ import annotations

from dataclasses import dataclass

from grasp_kitchen_ros2.planning.entities.pose3d import Pose3D


@dataclass
class TaskGoal:
    """High-level goal for one pick-and-place step."""

    task_id: str
    fruit_id: str
    fruit_class: str
    grasp_pose: Pose3D
    place_pose: Pose3D


