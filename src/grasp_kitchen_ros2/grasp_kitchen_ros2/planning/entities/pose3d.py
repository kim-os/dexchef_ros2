from __future__ import annotations

from dataclasses import dataclass


@dataclass
class Pose3D:
    """Minimal 6D pose representation in base frame."""

    x: float
    y: float
    z: float
    roll: float
    pitch: float
    yaw: float


