from __future__ import annotations

from typing import List, Tuple

import numpy as np

from grasp_kitchen_ros2.motion.entities.constraints import MotionConstraints
from grasp_kitchen_ros2.motion.entities.motion_primitive import MotionPrimitive
from grasp_kitchen_ros2.motion.entities.trajectory import (
    CartesianTrajectory,
    CartesianWaypoint,
)
from grasp_kitchen_ros2.planning.entities.pose3d import Pose3D


def _rpy_to_quaternion(roll: float, pitch: float, yaw: float) -> Tuple[float, float, float, float]:
    """
    Minimal RPY->quaternion 转换（与 scipy Rotation 一致的约定）。
    为了避免在 motion 层引入 scipy 依赖，这里直接写解析表达式。
    """
    cr = np.cos(roll * 0.5)
    sr = np.sin(roll * 0.5)
    cp = np.cos(pitch * 0.5)
    sp = np.sin(pitch * 0.5)
    cy = np.cos(yaw * 0.5)
    sy = np.sin(yaw * 0.5)

    qw = cr * cp * cy + sr * sp * sy
    qx = sr * cp * cy - cr * sp * sy
    qy = cr * sp * cy + sr * cp * sy
    qz = cr * cp * sy - sr * sp * cy
    return float(qx), float(qy), float(qz), float(qw)


class PickAndPlaceSkill:
    """
    将单次 PICK+PLACE 任务目标映射为一组 MotionPrimitive。

    流程等价于旧版 MotionExecutor：
    - PICK:
        1) approach above grasp (z + approach_offset)
        2) descend to grasp
        3) CLOSE_HAND
        4) lift (z + retreat_offset)
    - PLACE:
        5) approach above place
        6) descend to place
        7) OPEN_HAND
        8) retreat (z + retreat_offset)
    """

    def __init__(self, constraints: MotionConstraints) -> None:
        self._c = constraints

    def _pose3d_to_waypoint(self, pose: Pose3D) -> CartesianWaypoint:
        qx, qy, qz, qw = _rpy_to_quaternion(pose.roll, pose.pitch, pose.yaw)
        return CartesianWaypoint(
            position=(pose.x, pose.y, pose.z),
            quaternion=(qx, qy, qz, qw),
        )

    def _clamp_z(self, z: float) -> float:
        return float(max(self._c.min_z, min(self._c.max_z, z)))

    def build_primitives(
        self,
        grasp_pose: Pose3D,
        place_pose: Pose3D,
    ) -> List[MotionPrimitive]:
        primitives: List[MotionPrimitive] = []
        c = self._c

        # --- PICK phase -----------------------------------------------------

        # 1) approach above grasp
        grasp_above = Pose3D(
            x=grasp_pose.x,
            y=grasp_pose.y,
            z=self._clamp_z(grasp_pose.z + c.approach_offset),
            roll=grasp_pose.roll,
            pitch=grasp_pose.pitch,
            yaw=grasp_pose.yaw,
        )
        traj_approach_grasp = CartesianTrajectory(
            waypoints=[
                self._pose3d_to_waypoint(grasp_above),
                self._pose3d_to_waypoint(grasp_pose),
            ],
            max_velocity=c.max_linear_vel,
            max_acceleration=c.max_linear_acc,
        )
        primitives.append(
            MotionPrimitive(
                kind="MOVE_CARTESIAN",
                trajectory=traj_approach_grasp,
                speed=c.max_linear_vel,
                accel=c.max_linear_acc,
            )
        )

        # 2) descend to grasp (already covered in same trajectory above; keep for clarity)
        # 如果希望拆成两段，可以再添加一个 primitive，这里暂时不重复。

        # 3) close hand
        primitives.append(MotionPrimitive(kind="CLOSE_HAND"))

        # 4) lift after grasp
        lift_pose = Pose3D(
            x=grasp_pose.x,
            y=grasp_pose.y,
            z=self._clamp_z(grasp_pose.z + c.retreat_offset),
            roll=grasp_pose.roll,
            pitch=grasp_pose.pitch,
            yaw=grasp_pose.yaw,
        )
        traj_lift = CartesianTrajectory(
            waypoints=[
                self._pose3d_to_waypoint(grasp_pose),
                self._pose3d_to_waypoint(lift_pose),
            ],
            max_velocity=c.max_linear_vel,
            max_acceleration=c.max_linear_acc,
        )
        primitives.append(
            MotionPrimitive(
                kind="MOVE_CARTESIAN",
                trajectory=traj_lift,
                speed=c.max_linear_vel,
                accel=c.max_linear_acc,
            )
        )

        # --- PLACE phase ----------------------------------------------------

        # 5) approach above place
        place_above = Pose3D(
            x=place_pose.x,
            y=place_pose.y,
            z=self._clamp_z(place_pose.z + c.approach_offset),
            roll=place_pose.roll,
            pitch=place_pose.pitch,
            yaw=place_pose.yaw,
        )
        traj_to_place_above = CartesianTrajectory(
            waypoints=[
                self._pose3d_to_waypoint(lift_pose),
                self._pose3d_to_waypoint(place_above),
            ],
            max_velocity=c.max_linear_vel,
            max_acceleration=c.max_linear_acc,
        )
        primitives.append(
            MotionPrimitive(
                kind="MOVE_CARTESIAN",
                trajectory=traj_to_place_above,
                speed=c.max_linear_vel,
                accel=c.max_linear_acc,
            )
        )

        # 6) descend to place
        traj_descend_place = CartesianTrajectory(
            waypoints=[
                self._pose3d_to_waypoint(place_above),
                self._pose3d_to_waypoint(place_pose),
            ],
            max_velocity=c.max_linear_vel,
            max_acceleration=c.max_linear_acc,
        )
        primitives.append(
            MotionPrimitive(
                kind="MOVE_CARTESIAN",
                trajectory=traj_descend_place,
                speed=c.max_linear_vel,
                accel=c.max_linear_acc,
            )
        )

        # 7) open hand
        primitives.append(MotionPrimitive(kind="OPEN_HAND"))

        # 8) retreat after place
        retreat_pose = Pose3D(
            x=place_pose.x,
            y=place_pose.y,
            z=self._clamp_z(place_pose.z + c.retreat_offset),
            roll=place_pose.roll,
            pitch=place_pose.pitch,
            yaw=place_pose.yaw,
        )
        traj_retreat = CartesianTrajectory(
            waypoints=[
                self._pose3d_to_waypoint(place_pose),
                self._pose3d_to_waypoint(retreat_pose),
            ],
            max_velocity=c.max_linear_vel,
            max_acceleration=c.max_linear_acc,
        )
        primitives.append(
            MotionPrimitive(
                kind="MOVE_CARTESIAN",
                trajectory=traj_retreat,
                speed=c.max_linear_vel,
                accel=c.max_linear_acc,
            )
        )

        return primitives


