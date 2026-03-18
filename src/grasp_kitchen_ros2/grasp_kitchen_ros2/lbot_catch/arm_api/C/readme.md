# LBot API 版本更新日志
========================================================================================================================
版本：v1.0.1 (2025.12.12) → v1.0.2 (2025.1.8)
本次版本更新主要为API功能扩展和数据结构优化，存在不兼容的API变更。v1.0.1的部分接口需要在v1.0.2中做相应修改。

## API接口变更
1. 运动控制函数参数完善
    关节跟随控制
``` bash c
    // v1.0.1 - 基础关节跟随接口
    bool lbot_left_joint_follow(const double joints[7]);
    bool lbot_right_joint_follow(const double joints[7]);

    // v1.0.2 - 合并关节跟随接口；增加跟随模式参数，支持高低跟随模式选择
    bool lbot_joint_follow(lbot_arm_t arm, const double joints[7], bool follow);
```
2. 灵巧手控制接口
    更新L6灵巧手控制接口；
    新增L10灵巧手控制接口。
``` bash c
    // l6 手控制接口
    bool lbot_l6_set_position(lbot_arm_t arm, const uint8_t position[6]);
    bool lbot_l6_set_velocity(lbot_arm_t arm, const uint8_t velocity[6]);
    bool lbot_l6_set_effort(lbot_arm_t arm, const uint8_t torque[6]);

    // l10 手控制接口（10个自由度）
    bool lbot_l10_set_position(lbot_arm_t arm, const uint8_t position[10]);
    bool lbot_l10_set_velocity(lbot_arm_t arm, const uint8_t velocity[10]);
    bool lbot_l10_set_effort(lbot_arm_t arm, const uint8_t torque[10]);
```

## 向后兼容性
✅ 完全兼容的功能
    所有基本的运动控制函数（关节运动、笛卡尔运动）
    运动学计算函数（正逆运动学）
    坐标系管理函数（工具/工件坐标系）
    状态监控回调机制
    错误处理和系统功能
⚠️ 需要注意的变更
    关节跟随控制: 接口参数变更，需更新调用方式
    灵巧手控制接口: 更新L6灵巧手控制接口，新增L10手控制接口，需根据使用的手型选择对应接口
## 迁移指南
``` bash c
    // v1.0.1代码示例
    // 关节跟随
    double joints[7] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    lbot_left_joint_follow(joints);
    // 灵巧手
    uint8_t left_position[6] = {200, 200, 200, 200, 200, 200};
    lbot_left_l6_set_position(left_position);

    // v1.0.2代码示例
    // 关节跟随
    lbot_joint_follow(LBOT_LEFT_ARM, joints, true);
    // 灵巧手
    lbot_l6_set_position(LBOT_LEFT_ARM,left_position);
    
    // 仍然兼容旧调用方式（加速度使用默认值）
```
## 🚀 新功能使用示例

1. L10手部控制示例
``` bash c
    // 控制左L10手到指定位置
    uint8_t hand_position[10] = {128, 128, 128, 128, 128, 128, 128, 128, 128, 128};
    lbot_l10_set_position(LBOT_LEFT_ARM, hand_position);
```
更新日期：2025年1月8日
更新作者：李亚慧
版权所有 © 灵心巧手科技有限公司
============================================================================