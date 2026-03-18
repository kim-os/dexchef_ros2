## GraspKitchen ROS2 Package

`grasp_kitchen_ros2` 是 GraspKitchen 项目的 ROS2 化版本，实现了完整的 4 层架构：

- Perception（感知）
- Task Planner（任务规划）
- Motion Executor（运动执行）
- Robot Driver（机器人驱动）

该包 **不依赖** 原仓库中的 `grasp_kitchen_core/` 或 `lbot_catch/` 代码，可以单独打包和部署。

---

### 目录结构概览

```text
grasp_kitchen_ros2/
  grasp_kitchen_ros2/
    perception_node.py        # 感知 ROS2 节点：camera/* → perception/scene
    task_planner_node.py      # Planner 节点：ScenePerception → ExecuteTask.action
    motion_executor_node.py   # Motion 节点：ExecuteTask.action → 轨迹 + IO
    robot_driver_node.py      # Driver 节点：执行轨迹与 IO（当前为 stub）

    vision/                   # 视觉/感知算法（无 ROS 依赖）
      entities/               # CameraModel, DetectedObject 等实体
      pipeline/               # SegmentationBackend, SAM3Backend, PerceptionPipeline, pose_estimator

    planning/                 # 任务规划（无 ROS 依赖）
      entities/               # WorldState, PatternTarget, PlannedStep, TaskPlan, Pose3D ...
      policy/                 # OrangeHeartPolicy（心形摆放策略）

    motion/                   # 运动规划与技能层（无 ROS 依赖）
      entities/               # MotionPrimitive, CartesianTrajectory, MotionConstraints
      skills/                 # PickAndPlaceSkill, IKHelpers

    robot/                    # 驱动核心（未来接入 LBot SDK）
      driver_core.py          # RobotDriverCore：轨迹/IO 执行逻辑（当前为日志 stub）

  launch/
    perception_bringup.launch.py   # 仅启动 camera_driver_node + perception_node
    grasp_kitchen_bringup.launch.py# 启动完整 5 节点链路
```

---

### 运行前提

- ROS2（建议 Humble 或更高），已配置好 `colcon` 工作区。
- Python 3.10+。
- Orbbec（或其他）相机已有 **官方 ROS2 驱动节点**，发布以下话题（或通过参数映射）：
  - `/<namespace>/color/image_raw` (`sensor_msgs/Image`)
  - `/<namespace>/depth/image_raw` (`sensor_msgs/Image`)
  - `/<namespace>/camera_info` (`sensor_msgs/CameraInfo`)
- 若使用 SAM3 分割：
  - 已安装 `torch`、`transformers`、`opencv-python` 等依赖（见 `requirements.txt`）；
  - 已下载好 SAM3 模型，并在参数 `sam3_model_dir` 中配置路径。

**Python 依赖**：本包根目录下的 `requirements.txt` 列出全部 pip 依赖及建议版本；`rclpy`、`cv_bridge`、`sensor_msgs` 等由 ROS2 与 `colcon build` 提供，无需 pip 安装。

**Orbbec 相机驱动（可选）**：本包内 **不包含** Orbbec 硬件驱动。`camera_driver_node` 仅做话题桥接（订阅 `/orbbec/*`，重发布到 `camera/*`）。若使用 Orbbec 真机，需单独安装并启动官方 ROS2 驱动：

1. 克隆 [OrbbecSDK_ROS2](https://github.com/orbbec/OrbbecSDK_ROS2) 到工作区 `src/`。
2. 在工作区根目录执行 `colcon build`（或按该仓库说明只构建相机相关包），并 `source install/setup.bash`。
3. 先启动 Orbbec 的 launch（发布 `/orbbec/color/image_raw` 等），再启动本包的 `perception_bringup` 或 `grasp_kitchen_bringup`。

若该驱动或你的环境需要 Orbbec Python SDK，可额外执行：`pip install pyorbbecsdk2`（参见 `requirements.txt` 内注释）。

---

### 安装与构建

在你的 ROS2 工作区（例如 `ros2_ws`）中：

```bash
cd ros2_ws/src
git clone <this-repo> GraspKitchen
cd GraspKitchen/grasp_kitchen_ros2

# 安装 Python 依赖（见 requirements.txt）
pip install -r requirements.txt

cd ../..
colcon build --packages-select grasp_kitchen_ros2
source install/setup.bash
```

---

### 启动感知链路（仅 camera → perception）

假设 Orbbec 驱动发布：

- `/orbbec/color/image_raw`
- `/orbbec/depth/image_raw`
- `/orbbec/camera_info`

则可以启动：

```bash
ros2 launch grasp_kitchen_ros2 perception_bringup.launch.py \
  orbbec_rgb_topic:=/orbbec/color/image_raw \
  orbbec_depth_topic:=/orbbec/depth/image_raw \
  orbbec_info_topic:=/orbbec/camera_info \
  sam3_model_dir:=/path/to/sam3model \
  backend_type:=sam3 \
  depth_scale:=0.001
```

数据流：

```text
Orbbec driver → /orbbec/* → camera_driver_node → camera/* → perception_node → perception/scene
```

---

### 启动完整 4 层链路

在 Orbbec 驱动已运行的前提下：

```bash
ros2 launch grasp_kitchen_ros2 grasp_kitchen_bringup.launch.py \
  orbbec_rgb_topic:=/orbbec/color/image_raw \
  orbbec_depth_topic:=/orbbec/depth/image_raw \
  orbbec_info_topic:=/orbbec/camera_info \
  sam3_model_dir:=/path/to/sam3model \
  backend_type:=sam3 \
  depth_scale:=0.001
```

此时节点关系：

```text
camera_driver_node   : /orbbec/* → camera/*
perception_node      : camera/* → perception/scene
task_planner_node    : perception/scene + StartTask.srv → ExecuteTask.action
motion_executor_node : ExecuteTask.action → FollowCartesianTrajectory.action + SetIO.srv
robot_driver_node    : 执行轨迹与 IO（当前只打印日志）
```

在另一个终端可以调用 StartTask：

```bash
ros2 service call /task_planner/start_task grasp_kitchen_ros2/srv/StartTask \
"{task_type: 'orange_heart', target_class: 'orange', scene_id: ''}"
```

---

### 测试脚本（纯 Python，无需 ROS）

为了方便在不接硬件、不启动 ROS2 的情况下验证逻辑，本包提供了两个测试脚本：

- **测试 Planner 层**：`test_planner_orange_heart.py`

  ```bash
  python -m grasp_kitchen_ros2.test_planner_orange_heart
  ```

  功能：
  - 构造一个 mock `WorldState`（若干水果）；
  - 使用 `OrangeHeartPolicy` 生成 `TaskPlan`；
  - 打印每个 `PlannedStep` 的抓取/放置位姿；
  - 模拟多次 `select_next_goal` 调用，验证 Planner 行为。

- **测试 Motion 层**：`test_motion_pick_and_place.py`

  ```bash
  python -m grasp_kitchen_ros2.test_motion_pick_and_place
  ```

  功能：
  - 构造 `MotionConstraints` + mock 的 `grasp_pose` / `place_pose`；
  - 调用 `PickAndPlaceSkill.build_primitives` 生成 `MotionPrimitive` 列表；
  - 打印每个 primitive 的类型、轨迹 waypoints 与姿态；
  - 帮助理解从 Planner 的 Pose3D 到 Driver 的 FollowCartesianTrajectory.goal 之间的数据流。

---

### 与硬件的解耦与后续接入

当前版本中：

- `RobotDriverCore` 仅打印日志，不直接调用 LBot SDK；
- 所有硬件相关逻辑集中在 `robot/driver_core.py` 内部，便于后续：
  - 接入 `arm_api.Python.lbot.lbot_api` / `lbot_robot`；
  - 或替换为其他机械臂/手爪实现。

只要保持：

- `FollowCartesianTrajectory.action` 的接口不变；
- `SetIO.srv` 的语义不变（例如 `io_name="gripper"`），

就可以在不修改上层 Perception / Planner / Motion 代码的前提下更换机器人实现。

---

### 设计原则概述

- **高内聚，低耦合**：
  - 视觉逻辑集中在 `vision/`，任务规划集中在 `planning/`，运动规划集中在 `motion/`，驱动逻辑集中在 `robot/`。
- **接口隔离**：
  - 上层只通过 ROS2 消息与服务/Action 交互，内部则通过 Python dataclass 建模领域对象。
- **依赖倒置**：
  - TaskPlanner 只依赖抽象的 Task/World 模型，不依赖 Motion/Driver 的具体实现；
  - Motion 层只依赖抽象的 `MotionPrimitive` 和 `Trajectory`，不直接调用 SDK；
  - Driver 层是唯一实际与硬件 API 对接的地方。

如果你需要将本包进一步拆分成独立仓库或发布到 ROS2 包管理系统，当前结构和接口已经符合工业级开源工程的基本要求。 

