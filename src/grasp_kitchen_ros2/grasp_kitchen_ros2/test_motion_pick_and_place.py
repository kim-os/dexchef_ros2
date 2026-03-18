from __future__ import annotations

"""
Standalone test script for the motion layer (no ROS2 required).

用法（在项目根目录 GraspKitchen 下）：

    python -m grasp_kitchen_ros2.test_motion_pick_and_place

它会：
1. 构造一个简单的抓取/放置位姿 (Pose3D)；
2. 使用 PickAndPlaceSkill 生成 MotionPrimitive 列表；
3. 按顺序打印每个 primitive 的类型和对应轨迹；
4. 帮助你理解 motion 层在「Planner → Motion → Driver」之间的数据流。
"""

from typing import List

from grasp_kitchen_ros2.motion.entities.constraints import MotionConstraints
from grasp_kitchen_ros2.motion.entities.motion_primitive import MotionPrimitive
from grasp_kitchen_ros2.motion.skills.pick_and_place import PickAndPlaceSkill
from grasp_kitchen_ros2.planning.entities.pose3d import Pose3D


def _print_primitive(idx: int, prim: MotionPrimitive) -> None:
    """Pretty-print 单个 MotionPrimitive 的内容。"""
    header = f"Primitive #{idx}: kind={prim.kind}"
    if prim.kind == "MOVE_CARTESIAN" and prim.trajectory is not None:
        print(header)
        print(
            f"  speed={prim.speed:.3f}, accel={prim.accel:.3f}, "
            f"max_vel={prim.trajectory.max_velocity:.3f}, "
            f"max_acc={prim.trajectory.max_acceleration:.3f}"
        )
        for wi, wp in enumerate(prim.trajectory.waypoints):
            x, y, z = wp.position
            qx, qy, qz, qw = wp.quaternion
            print(
                f"    waypoint[{wi}]: pos=({x:.3f}, {y:.3f}, {z:.3f}), "
                f"quat=({qx:.3f}, {qy:.3f}, {qz:.3f}, {qw:.3f})"
            )
    else:
        print(header)


def main() -> None:
    # 1) 构造约束（对应旧 MotionExecutor 的 PickPlaceParams + 安全高度）
    constraints = MotionConstraints(
        approach_offset=0.08,
        retreat_offset=0.08,
        min_z=-0.33,
        max_z=0.20,
        max_linear_vel=0.2,
        max_linear_acc=0.2,
    )

    skill = PickAndPlaceSkill(constraints=constraints)

    # 2) 构造一个 mock 的抓取/放置 Pose3D（基座系）
    grasp_pose = Pose3D(
        x=0.40,
        y=0.00,
        z=0.10,
        roll=0.0,
        pitch=0.0,
        yaw=-0.8,
    )
    place_pose = Pose3D(
        x=0.50,
        y=0.10,
        z=0.10,
        roll=0.0,
        pitch=0.0,
        yaw=0.0,
    )

    print("=== Input Poses (base frame) ===")
    print(
        f"  Grasp: ({grasp_pose.x:.3f}, {grasp_pose.y:.3f}, {grasp_pose.z:.3f}, "
        f"rpy=({grasp_pose.roll:.2f}, {grasp_pose.pitch:.2f}, {grasp_pose.yaw:.2f}))"
    )
    print(
        f"  Place: ({place_pose.x:.3f}, {place_pose.y:.3f}, {place_pose.z:.3f}, "
        f"rpy=({place_pose.roll:.2f}, {place_pose.pitch:.2f}, {place_pose.yaw:.2f}))"
    )

    # 3) 通过 PickAndPlaceSkill 生成 MotionPrimitive 列表
    primitives: List[MotionPrimitive] = skill.build_primitives(grasp_pose, place_pose)

    print("\n=== Generated MotionPrimitives ===")
    for idx, prim in enumerate(primitives):
        _print_primitive(idx, prim)

    print(
        "\n说明：\n"
        "  - MotionExecutorNode 在收到 ExecuteTask.action 后，会从 TaskTarget 中\n"
        "    构造类似的 grasp_pose/place_pose，并调用 PickAndPlaceSkill.build_primitives。\n"
        "  - 然后它会依次把 MOVE_CARTESIAN primitive 映射为 FollowCartesianTrajectory.action\n"
        "    的 goal，把 OPEN_HAND/CLOSE_HAND primitive 映射为 SetIO.srv 调用。\n"
        "  - 你可以用这个脚本先验证规划出的轨迹是否合理，再接上真实 RobotDriver。"
    )


if __name__ == "__main__":
    main()

