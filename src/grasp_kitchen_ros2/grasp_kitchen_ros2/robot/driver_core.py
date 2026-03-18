from __future__ import annotations

from dataclasses import dataclass
from typing import Tuple, List


@dataclass
class CartesianStep:
    """One Cartesian step in base frame."""

    position: Tuple[float, float, float]
    quaternion: Tuple[float, float, float, float]


class RobotDriverCore:
    """
    Core driver logic (ROS-agnostic).

    当前实现为 stub：只记录日志，不直接调用真实 SDK。
    未来可以在这里接入 LBot 的 arm_api/lbot_robot，使 RobotDriverNode 逻辑保持不变。
    """

    def __init__(self, logger) -> None:
        self._logger = logger

    def execute_cartesian_trajectory(
        self,
        steps: List[CartesianStep],
        max_velocity: float,
        max_acceleration: float,
    ) -> bool:
        """
        执行一条笛卡尔轨迹。

        真正的硬件实现应当：
        - 将 steps 转换为机器人 SDK 所需的指令（moveL/moveJ 等）；
        - 按 max_velocity/max_acceleration 做插值；
        - 阻塞直到执行完成或失败。

        当前 stub 实现只打印信息并返回 True。
        """
        self._logger.info(
            f"[RobotDriverCore] execute_cartesian_trajectory: "
            f"{len(steps)} steps, v={max_velocity}, a={max_acceleration}"
        )
        for idx, s in enumerate(steps):
            x, y, z = s.position
            self._logger.info(
                f"[RobotDriverCore]  step {idx}: "
                f"pos=({x:.3f}, {y:.3f}, {z:.3f}), quat={s.quaternion}"
            )
        return True

    def set_io(self, io_name: str, state: bool) -> bool:
        """
        设置 IO/夹爪状态。

        真正实现中：
        - 应将 io_name 映射到具体的数字 IO 或手爪动作；
        - 这里的 state 表示开/关。
        """
        self._logger.info(f"[RobotDriverCore] set_io: {io_name} -> {state}")
        return True


