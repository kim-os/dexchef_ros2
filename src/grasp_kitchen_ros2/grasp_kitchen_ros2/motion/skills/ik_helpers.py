from __future__ import annotations

from typing import Optional, List

from grasp_kitchen_ros2.planning.entities.pose3d import Pose3D


class IKHelpers:
    """
    占位 IK/可达性助手。

    当前实现只返回 True/None，后续可接入真实 IK 求解器（如 MoveIt 或底层 SDK）。
    """

    def check_reachability(self, pose: Pose3D) -> bool:
        return True

    def solve_ik(self, pose: Pose3D) -> Optional[List[float]]:
        return None


