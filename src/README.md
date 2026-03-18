# GraspKitchen: Modular Dexterous Manipulation MVP

GraspKitchen 是一个围绕「机械臂 + 灵巧手抓取水果，并摆放成心形图案」构建的可扩展操作系统雏形。  
它强调 **模块化、可替换、可扩展**，并为后续迁移到 ROS2 做好准备。

当前版本是一个纯 Python MVP，分为 4 层逻辑 + 独立的 offline 标定工具：

- **Perception**：感知水果位置与姿态  
- **Task Planner**：基于对象/图案的任务规划（场景 + 行为）  
- **Skill Executor**：将高层 PICK/PLACE 意图映射为低层技能序列  
- **Controller + Driver**：封装底层 `arm_api`，支持替换不同臂/手实现  

- **Offline Tools**：手眼标定等一次性工具，与在线服务完全解耦

---

## 目录结构

```text
GraspKitchen/
  grasp_kitchen_core/          # 在线控制核心（不含标定）
    __init__.py
    bootstrap.py               # 统一初始化：相机、SAM3、标定矩阵
    common_types.py            # Pose3D, FruitPose, SkillCommand 等领域模型
    geometry.py                # 通用位姿/变换工具 (4x4 <-> 6D)
    config/
      __init__.py
      grasp_system_config.py   # 在线运行配置（robot_ip、路径、抓取参数等）
    robot/
      robot_interfaces.py      # ArmInterface, HandInterface 抽象
      robot_lbot.py            # LBot 实现 (ArmLBot, HandLBot, create_lbot_interfaces)
      robot_driver_node.py     # RobotDriver: SkillCommand -> Arm/Hand 接口调用
    skills/
      motion_executor_node.py  # MotionExecutor: execute_pick/execute_place
    planning/
      task_planner_node.py     # TaskPlanner: 场景+任务逻辑（对象/图案/行为）
      pattern.py               # 心形 pattern 生成与 2D->3D Pose 映射
    run_orange_heart_mvp.py    # MVP 入口（纯 Python，未 ROS2 化）

  grasp_kitchen_perception/    # 感知层（相机 + SAM3 + 几何）
    __init__.py
    calibration.py             # 加载 cam_K, hand-eye 标定矩阵，初始化 RealSense
    vision_utils.py            # 掩码->位姿估计 (mask + depth + K + T_base_cam)
    sam3_detector.py           # SAM3Detector + FIXED_ROIS 等
    perception_system.py       # PerceptionSystem: get_current_fruit_poses()
    perception_node.py         # PerceptionNode 抽象（可接 fake 或 real）

  grasp_kitchen_tests/         # 分层测试脚本
    __init__.py
    test0_config_and_bootstrap_perception.py
    test1_perception_to_planner.py
    test2_planner_to_motion.py
    test3_motion_to_driver.py
    test4_end_to_end_fake_driver.py

  offline_tools/               # 离线工具（不参与在线服务）
    hand_eye_calibration.py    # 调用旧 calibration_get 并复制结果到 ./config

  config/                      # 在线系统使用的配置文件（推荐位置）
    cam_K.txt                  # 相机内参
    calibration_result.yaml    # 手眼标定矩阵 T_base_cam
    L10_positions.yaml         # 手部预姿态等（如需）

  lbot_catch/                  # 旧代码 & 备份配置（逐步淘汰，仅兼容）
    arm_api/                   # 底层 arm_api（将来独立为依赖）
    config/                    # 旧配置，作为 fallback
    ...                        # 旧 grasp_main.py 等，仅供参考
```

> 注意：运行时逻辑已不再依赖 `lbot_catch.utils.*`，只依赖底层 `arm_api` 和配置文件。  
> `lbot_catch` 仅作为过渡期的配置/标定脚本来源。

---

## 安装与依赖

### Python 版本

- 推荐：Python 3.10+

### 主要依赖（需自行安装）

- **数值 & 几何**：
  - `numpy`
  - `scipy`
- **图像与视觉**：
  - `opencv-python`
  - `pyrealsense2`（RealSense 相机）
  - `torch`（GPU 环境优先）
  - `transformers`（Sam3Processor/Sam3Model，用于 SAM3 模型）
  - `Pillow`
  - `PyYAML`
- **机器人底层 API**：
  - 推荐将 `arm_api.Python.lbot.lbot_api` 所在目录加入 `PYTHONPATH` 或安装为独立包；
  - 当前代码会优先尝试：
    - `from arm_api.Python.lbot.lbot_api import ...`
  - 若未找到，会回退到：
    - `from lbot_catch.arm_api.Python.lbot.lbot_api import ...`（兼容旧结构）

### 本地开发环境设置

在项目根目录下：

```bash
cd GraspKitchen
# 可选：创建虚拟环境
# python -m venv .venv && .venv\Scripts\activate  # Windows PowerShell 示例

pip install -r requirements.txt  # 如有
# 或自行安装上述依赖库
```
---

## Offline 标定（一次性）

### 1. 运行手眼标定脚本

```bash
cd GraspKitchen
python -m offline_tools.hand_eye_calibration
```

脚本做的事情：

1. 调用旧逻辑 `lbot_catch.utils.calibration_utils.calibration_get()`，完成一次手眼标定；
2. 在 `lbot_catch/config/calibration_result.yaml` 写入结果；
3. 将结果复制一份到：
   - `config/calibration_result.yaml`

如果你只想跑旧脚本、不复制到新 config，可使用：

```bash
python -m offline_tools.hand_eye_calibration --no-copy
```

### 2. 相机内参与手部配置

- 相机内参 `cam_K.txt` 推荐放在 `config/cam_K.txt`；
- 手眼标定结果 `calibration_result.yaml` 推荐放在 `config/calibration_result.yaml`；
- 手部 YAML（如 `L10_positions.yaml`）推荐放在 `config/` 中。

`GraspSystemConfig` 的路径解析规则：

- 优先读取 `GraspKitchen/config/` 中的对应文件；
- 若不存在，则回退到 `lbot_catch/config/`，以保证兼容旧目录结构。

---

## Online 数据流（逻辑概览）

**整体链路**：

```text
PerceptionSystem → TaskPlanner → MotionExecutor → RobotDriver → Arm/Hand (arm_api)
```

1. **Config & Bootstrap**
   - `load_config(...)` → `GraspSystemConfig`
   - `bootstrap(cfg)` →  
     `BootstrapResult(pipeline, align, K, T_base_cam, sam3_detector, aruco, cam_T_obj1, arm_T_grasp1)`

2. **Perception 层**
   - `PerceptionSystem` 使用：
     - RealSense pipeline + align；
     - 相机内参 `K`；
     - `T_base_cam`；
     - `SAM3Detector` 进行分割；
     - `vision_utils.get_pose_from_mask` 把 mask + depth + K + T_base_cam 转成物体位姿；
   - `get_current_fruit_poses()` 返回 `List[FruitPose]`，每个包含 `Pose3D` 和 `class_name`。

3. **Planning / Task 层**
   - `TaskPlanner` 持有：
     - 轻量 `SceneState`（水果集合 + picked/placed）；
     - 心形 pattern 点对应的放置位姿列表；
   - 每次 `run_task_once()`：
     1. 选择一个尚未抓取/放置的水果；
     2. 选择下一个心形目标位姿；
     3. 计算抓取姿态（当前为 top-down + 固定 yaw）；
     4. 调用 `MotionExecutor.execute_pick` 和 `execute_place`；
     5. 更新场景状态和 pattern 进度。

4. **Skill Executor 层**
   - `MotionExecutor` 负责：
     - 将高层 PICK/PLACE 映射为若干 `SkillCommand`：
       - 抓取：approach → descend → CLOSE_HAND → lift；
       - 放置：approach → descend → OPEN_HAND → retreat。
   - 抽象出来后，TaskPlanner 不关心细节，只调用统一接口。

5. **Controller + Driver 层**
   - `ArmInterface` / `HandInterface` 为抽象接口：
     - `ArmLBot` / `HandLBot` 是基于 `arm_api` 的具体实现；
   - `RobotDriver` 将 `SkillCommand` 转为对 Arm/Hand 接口的调用：
     - `MOVE_POSE` → `arm.move_pose(...)`；
     - `OPEN_HAND` → `hand.open()`；
     - `CLOSE_HAND` → `hand.close()`。

---

## 运行 MVP（真实感知 + 真实机器人）

确保：

- RealSense 相机已连接；
- SAM3 模型路径在 `cfg.sam3_model_dir` 中正确设置；
- `config/` 中有 `cam_K.txt`、`calibration_result.yaml`、`L10_positions.yaml`；
- `arm_api` 可通过 `arm_api.Python.lbot.lbot_api` 或 `lbot_catch/arm_api/...` 导入。

在项目根目录：

```bash
cd GraspKitchen
python -m grasp_kitchen_core.run_orange_heart_mvp
```

这会执行：

1. Config + Bootstrap（相机、SAM3、标定）；
2. 构造 `PerceptionSystem` 和 `PerceptionNode`；
3. 通过 `create_lbot_interfaces(cfg)` 建立 LBot Arm/Hand 接口并回 home；
4. 构造 `RobotDriver`、`MotionExecutor`、`TaskPlanner`；
5. 循环执行「感知 → 选水果+pattern点 → PICK+PLACE」直到心形图案填满或无水果可用。

---

## 分层测试脚本（建议调试顺序）

### Test 0：Config + Bootstrap + Perception

```bash
python -m grasp_kitchen_tests.test0_config_and_bootstrap_perception
```

验证：

- `GraspSystemConfig` 路径；
- `bootstrap` 能否初始化 RealSense + 标定 + SAM3 + ArUco；
- `PerceptionSystem.get_current_fruit_poses()` 能否正常返回结果。

### Test 1：Perception → TaskPlanner（不动机器人）

```bash
python -m grasp_kitchen_tests.test1_perception_to_planner
```

- 使用 fake perception；
- 验证 `TaskPlanner.update_scene_from_perception` 是否正确维护 `SceneState`。

### Test 2：TaskPlanner → MotionExecutor（不动机器人）

```bash
python -m grasp_kitchen_tests.test2_planner_to_motion
```

- 使用 fake perception + `_DummyMotionExecutor`；
- 验证每次 `run_task_once` 输出的 PICK/PLACE 序列是否符合预期。

### Test 3：MotionExecutor → RobotDriver（不动机器人）

```bash
python -m grasp_kitchen_tests.test3_motion_to_driver
```

- 使用 `_DummyRobotDriver`；
- 验证 `execute_pick/execute_place` 生成的 `SkillCommand` 序列（顺序和类型）。

### Test 4：End-to-End（fake perception + fake driver）

```bash
python -m grasp_kitchen_tests.test4_end_to_end_fake_driver
```

- 使用 fake perception + `_DummyRobotDriver`；
- 验证整条逻辑数据流是否可用，而不动真实硬件。

---

## 未来计划与扩展点

- **ROS2 化**：  
  将 `PerceptionSystem`、`TaskPlanner`、`MotionExecutor`、`RobotDriver` 各自封装到独立 ROS2 node 中，通过 topics/services/actions/TF2 通信，并用 launch 文件完成编排。

- **策略扩展**：
  - 将 `TaskPlanner` 中的 object/target 选择逻辑抽象成策略接口，支持规则、模仿学习、RL 等不同实现；
  - 将 ArUco refine 逻辑（目前还只在旧代码中）迁移为独立的「精调技能」，可选地插入在 PICK 之前。

- **多水果与多图案**：
  - 在 `SceneState` 和 `pattern` 中加入 fruit type/pattern type 配置，使系统可扩展到不同水果、不同摆放图案（网格、文字、logo 等）。

- **完全移除 `lbot_catch` 依赖**：
  - 将 `arm_api` 独立安装/部署；
  - 完全迁移（或替换）旧的 `calibration_utils.calibration_get` 标定逻辑。

