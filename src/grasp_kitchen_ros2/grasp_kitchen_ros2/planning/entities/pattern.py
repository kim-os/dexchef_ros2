from __future__ import annotations

from dataclasses import dataclass
from typing import List, Tuple

from grasp_kitchen_ros2.planning.entities.pose3d import Pose3D


@dataclass
class PatternPoint:
    """2D point on tray plane, used to build patterns."""

    u: float
    v: float
    index: int


@dataclass
class PatternTarget:
    """One concrete 3D place target in base frame."""

    index: int
    pose: Pose3D


def generate_heart_pattern_points(
    num_points: int,
    center: Tuple[float, float] = (0.4, 0.0),
    scale: float = 0.15,
) -> List[PatternPoint]:
    """Very simple heart pattern generator in 2D."""
    if num_points <= 0:
        return []

    points: List[PatternPoint] = []
    for i in range(num_points):
        t = (i / max(1, num_points - 1)) * 3.14159  # 0..pi
        x = scale * 16 * (0.5 * (1 - (t / 3.14159)))  # crude placeholder
        y = scale * (1 - (2 * abs(t - 3.14159 / 2) / 3.14159))  # crude placeholder
        u = center[0] + x
        v = center[1] + y
        points.append(PatternPoint(u=u, v=v, index=i))
    return points


def pattern_points_to_pattern_targets(
    pattern_points: List[PatternPoint],
    tray_height: float = 0.1,
) -> List[PatternTarget]:
    """Map 2D pattern points into simple 3D place targets."""
    targets: List[PatternTarget] = []
    for p in pattern_points:
        pose = Pose3D(
            x=p.u,
            y=p.v,
            z=tray_height,
            roll=0.0,
            pitch=0.0,
            yaw=0.0,
        )
        targets.append(PatternTarget(index=p.index, pose=pose))
    return targets

