# 感知层调试脚本

## 文件说明
- `start_perception.sh`: Bash 脚本，用于启动感知层的 camera_driver_node 和 perception_node。
- `debug_perception.py`: Python 脚本，用于订阅并打印相机和感知话题的数据，验证数据流。

## 使用步骤
1. 确保 ROS2 环境已配置：`source /opt/ros/humble/setup.bash`
2. 构建包：`colcon build --packages-select grasp_kitchen_ros2`
3. 启动上游相机驱动（e.g., Orbbec 节点，确保发布 /orbbec/* 话题）。
4. 运行启动脚本：`bash text/start_perception.sh`
5. 在另一个终端运行调试脚本：`python3 text/debug_perception.py`
6. 检查日志和输出：确认 RGB/Depth/CameraInfo 被接收，ScenePerception 被发布。
7. 如果有问题，检查模型路径、参数，或使用 `ros2 topic list` 验证话题存在。

## 注意
- 脚本假设默认参数；可修改脚本中的参数。
- 如果 SAM3 模型路径不存在，请更新 `sam3_model_dir` 参数。


# 感知层调试说明

## 文件说明
- `start_perception.sh`: 启动感知层的 `camera_driver_node` 与 `perception_node`。
- `debug_perception.py`: 订阅相机与感知话题，并打印接收到的数据摘要。
- `fake_camera_publisher.py`: 在没有真实相机的情况下，发布伪造的 RGB/Depth/CameraInfo 数据到 `/orbbec/...` 话题，供感知层输入测试。

## 目标
验证以下几点：
1. 相机驱动节点（或伪造节点）能够持续发布帧到 `/orbbec/color/image_raw`、`/orbbec/depth/image_raw`。
2. `camera_driver_node` 能够桥接话题到 `/camera/...`，`perception_node` 能够从 `/camera/...` 接收并发布 `perception/scene`。
3. 使用 `debug_perception.py` 可以看到数据流通过并解析出检测到的物体。

## 快速验证流程
1. **安装/恢复 ROS2（如果尚未安装）**
   - 示例：`sudo apt install ros-humble-desktop`（取决于你的 ROS 发行版）。
   - source 环境：`source /opt/ros/humble/setup.bash`

2. **构建 ROS2 包**
   ```bash
   cd /home/dex-rob/felixczhang/DexChef
   colcon build --packages-select grasp_kitchen_ros2
   source install/setup.bash
   ```

3. **如果没有真实相机**，启动伪造相机发布器（推荐）
   ```bash
   python3 text/fake_camera_publisher.py
   ```

4. **启动感知层（camera_driver_node + perception_node）**
   ```bash
   bash text/start_perception.sh
   ```

5. **运行调试脚本验证数据流**
   ```bash
   python3 text/debug_perception.py
   ```

6. **检查 topic 是否发布帧**
   - `ros2 topic list | grep -E "camera|perception"`
   - `ros2 topic hz /orbbec/color/image_raw`（或 `/camera/color/image_raw`）
   - `ros2 topic echo /perception/scene --no-arr`（验证 ScenePerception 发布）

## 常见问题排查
- 如果 `ros2 topic hz` 没有输出帧：确认上游相机节点正在运行，或 `fake_camera_publisher.py` 是否在运行。
- 如果 `perception_node` 没有输出：检查 `sam3_model_dir` 是否存在模型，或调低 `conf_threshold`。
- 如果 `camera_driver_node` 没有桥接：确认命名空间 `/orbbec/...` 与实际话题一致。
