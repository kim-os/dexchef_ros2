from __future__ import annotations

"""
Standalone test script for the planner layer (no ROS2 required).

用法（在项目根目录 GraspKitchen 下）：

    python -m grasp_kitchen_ros2.test_planner_orange_heart

它会：
1. 构造一个包含若干 mock 水果的 WorldState；
2. 使用 OrangeHeartPolicy 生成一个 TaskPlan；
3. 按顺序打印每个 PlannedStep 的抓取/放置位姿；
4. 模拟多次 select_next_goal 调用，展示 Planner 的逐步输出。
"""

from typing import List

from grasp_kitchen_ros2.planning.entities.scene_state import WorldObject, WorldState
from grasp_kitchen_ros2.planning.policy.orange_heart_policy import OrangeHeartPolicy


def _make_mock_world() -> WorldState:
    """Construct a simple WorldState with a few mock fruits."""
    world = WorldState()

    # 三个假水果，沿 X 轴排布
    mock_objects: List[WorldObject] = [
        WorldObject(id="fruit_0", class_name="orange", x=0.35, y=-0.05, z=0.10),
        WorldObject(id="fruit_1", class_name="orange", x=0.40, y=0.00, z=0.10),
        WorldObject(id="fruit_2", class_name="orange", x=0.45, y=0.05, z=0.10),
    ]
    for obj in mock_objects:
        world.objects[obj.id] = obj

    return world


def main() -> None:
    world = _make_mock_world()

    print("=== Mock WorldState ===")
    for obj_id, obj in world.objects.items():
        print(
            f"  {obj_id}: class={obj.class_name}, "
            f"pos=({obj.x:.3f}, {obj.y:.3f}, {obj.z:.3f})"
        )

    policy = OrangeHeartPolicy(scene=world, num_pattern_points=5)

    task_id = "debug_task"
    task_type = "orange_heart"
    target_class = "orange"

    print("\n=== Planning phase ===")
    plan = policy.plan(task_id=task_id, task_type=task_type, target_class=target_class)
    print(f"TaskPlan status={plan.status}, steps={len(plan.steps)}")

    for step in plan.steps:
        print(
            f"  Step {step.step_index}: fruit_id={step.fruit_id}, pattern_index={step.pattern_index}, "
            f"ik_feasible={step.ik_feasible}"
        )
        gp = step.grasp_pose
        pp = step.place_pose
        print(
            f"    grasp  @ base: ({gp.x:.3f}, {gp.y:.3f}, {gp.z:.3f}, "
            f"rpy=({gp.roll:.2f}, {gp.pitch:.2f}, {gp.yaw:.2f}))"
        )
        print(
            f"    place  @ base: ({pp.x:.3f}, {pp.y:.3f}, {pp.z:.3f}, "
            f"rpy=({pp.roll:.2f}, {pp.pitch:.2f}, {pp.yaw:.2f}))"
        )

    print("\n=== select_next_goal simulation ===")
    for i in range(5):
        step = policy.select_next_goal(
            task_id=task_id, task_type=task_type, target_class=target_class
        )
        if step is None:
            print(f"  [Tick {i}] no more planned steps (planner returned None).")
            break
        print(
            f"  [Tick {i}] next step: index={step.step_index}, "
            f"fruit_id={step.fruit_id}, pattern_index={step.pattern_index}"
        )


if __name__ == "__main__":
    main()

