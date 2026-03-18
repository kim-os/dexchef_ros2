from __future__ import annotations

from dataclasses import dataclass
from typing import List, Tuple


@dataclass
class CartesianWaypoint:
    """Single Cartesian waypoint in base frame."""

    position: Tuple[float, float, float]          # x, y, z
    quaternion: Tuple[float, float, float, float] # x, y, z, w


@dataclass
class CartesianTrajectory:
    """Simple Cartesian trajectory description."""

    waypoints: List[CartesianWaypoint]
    max_velocity: float
    max_acceleration: float


