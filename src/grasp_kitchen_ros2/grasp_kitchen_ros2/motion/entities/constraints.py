from __future__ import annotations

from dataclasses import dataclass


@dataclass
class MotionConstraints:
    """Basic motion constraints used to build primitives."""

    approach_offset: float = 0.08
    retreat_offset: float = 0.08
    min_z: float = -0.33
    max_z: float = 0.20
    max_linear_vel: float = 0.2
    max_linear_acc: float = 0.2


