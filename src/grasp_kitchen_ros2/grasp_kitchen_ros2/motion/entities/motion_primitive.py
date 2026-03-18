from __future__ import annotations

from dataclasses import dataclass
from typing import Literal, Optional

from grasp_kitchen_ros2.motion.entities.trajectory import CartesianTrajectory


MotionPrimitiveKind = Literal["MOVE_CARTESIAN", "OPEN_HAND", "CLOSE_HAND"]


@dataclass
class MotionPrimitive:
    """Abstract motion primitive used by the motion layer."""

    kind: MotionPrimitiveKind
    trajectory: Optional[CartesianTrajectory] = None
    speed: float = 0.15
    accel: float = 0.15


