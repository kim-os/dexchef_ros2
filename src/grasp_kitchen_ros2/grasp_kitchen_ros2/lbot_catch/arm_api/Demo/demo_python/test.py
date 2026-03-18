#!/usr/bin/env python3
"""
    @brief : 双臂柔和顺滑测试：外展 + 前举
    @details : 
        1. 速度 0.2, 加速度 0.05 -> 极度顺滑。
        2. 步骤一：双臂向外展开 (J2关节, 左负右正)。
        3. 步骤二：双臂向前平举 (J1关节, 左负右正)。
"""
import time
from lbot.lbot_robot import LbotRobot, LbotArm

# === 柔和参数配置 ===
# 速度 (0.2 rad/s ≈ 11度/秒)
SMOOTH_SPEED = 0.2
# 加速度 (0.05 rad/s² -> 起停无顿挫)
SMOOTH_ACCEL = 0.05

# 动作幅度
DELTA = 0.5  # 0.5 弧度 ≈ 28.6 度

def test_dual_arm_sequence(robot):
    print("\n=== 开始双臂顺滑运动测试 ===")

    # 1. 获取双臂当前初始状态
    # ------------------------------------------------
    state = robot.get_state()
    if not state:
        print("❌ 无法获取机器人状态")
        return

    # 复制当前的关节角度作为计算基准
    # 注意：get_joints_list 返回的是 list，我们可以直接修改
    left_target = list(state.left_arm.get_joints_list())
    right_target = list(state.right_arm.get_joints_list())

    print(f"初始状态获取成功。")
    print(f"左臂 J2: {left_target[1]:.3f}, 右臂 J2: {right_target[1]:.3f}")
    time.sleep(1)

    # 2. 阶段一：向外展 (修改第2个关节 J2 / Index 1)
    # ------------------------------------------------
    print("\n🚀 [阶段一] 准备执行：双臂外展 (J2 关节)")
    print(f"   幅度: {DELTA} rad (左臂 -, 右臂 +)")
    
    # 左臂 J2 减去 0.5 (添加负号)
    left_target[1] -= DELTA
    # 右臂 J2 加上 0.5
    right_target[1] += DELTA

    # 执行运动
    # 我们先让左臂动，再让右臂动（或者几乎同时）
    print("   -> 左臂外展...")
    robot.move_to_joint_target(LbotArm.LEFT_ARM, left_target, SMOOTH_SPEED, SMOOTH_ACCEL, False) # False=不阻塞(让他先动起来)
    
    print("   -> 右臂外展...")
    robot.move_to_joint_target(LbotArm.RIGHT_ARM, right_target, SMOOTH_SPEED, SMOOTH_ACCEL, True)  # True=阻塞(等右臂到位再进行下一步)
    
    print("✅ 阶段一完成")
    time.sleep(1)

    # 3. 阶段二：向前举 (修改第1个关节 J1 / Index 0)
    # ------------------------------------------------
    # 在刚才外展的基础上，继续叠加前举动作
    print("\n🚀 [阶段二] 准备执行：双臂前举 (J1 关节)")
    print(f"   幅度: {DELTA} rad (左臂 -, 右臂 +)")

    # 左臂 J1 减去 0.5 (依旧添加负号)
    left_target[0] -= DELTA
    # 右臂 J1 加上 0.5
    right_target[0] += DELTA

    print("   -> 左臂前举...")
    robot.move_to_joint_target(LbotArm.LEFT_ARM, left_target, SMOOTH_SPEED, SMOOTH_ACCEL, False)
    
    print("   -> 右臂前举...")
    robot.move_to_joint_target(LbotArm.RIGHT_ARM, right_target, SMOOTH_SPEED, SMOOTH_ACCEL, True)
    
    print("✅ 阶段二完成")
    time.sleep(2)

    # 4. (可选) 柔和回零
    # ------------------------------------------------
    print("\n🔙 测试结束，正在柔和回正到初始位置...")
    
    # 获取最初始的状态（重新读取一遍最稳妥，或者用之前的变量）
    # 这里我们直接让它回到“全0”或者“刚开始读到的位置”
    # 为了安全，我们让它回到刚开始读到的那个位置(Current - Delta)不太准，
    # 最好是直接发最开始存的 raw data。但为了演示简单，我们这里手动反向操作回去。
    
    # 简单的回正逻辑：把刚才加的减回去
    left_target[0] += DELTA  # 恢复 J1
    left_target[1] += DELTA  # 恢复 J2
    
    right_target[0] -= DELTA # 恢复 J1
    right_target[1] -= DELTA # 恢复 J2

    robot.move_to_joint_target(LbotArm.LEFT_ARM, left_target, SMOOTH_SPEED, SMOOTH_ACCEL, False)
    robot.move_to_joint_target(LbotArm.RIGHT_ARM, right_target, SMOOTH_SPEED, SMOOTH_ACCEL, True)
    print("✅ 已回到起点")


def main():
    robot = LbotRobot('192.168.10.21')
    
    if robot.connect():
        print("✅ 机器人连接成功")
        
        # 使能
        try:
            robot.enable_arm(LbotArm.LEFT_ARM, True)
            robot.enable_arm(LbotArm.RIGHT_ARM, True)
            time.sleep(1)
        except:
            pass

        try:
            test_dual_arm_sequence(robot)
        except KeyboardInterrupt:
            print("\n🛑 强制停止")
            robot.emergency_stop(LbotArm.LEFT_ARM, True)
            robot.emergency_stop(LbotArm.RIGHT_ARM, True)
        finally:
            robot.disconnect()
    else:
        print("❌ 连接失败")

if __name__ == "__main__":
    main()