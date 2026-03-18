"""
Vision stack for grasp_kitchen_ros2.

结构（DDD 风格粗分层）：
- entities/: 领域模型与相机模型（CameraModel, DetectedObject 等）
- pipeline/: 视觉后端与感知流水线（SegmentationBackend, SAM3Backend, YoloSegBackend, PerceptionPipeline）

该子包不依赖 ROS2、不持有相机，只处理 numpy 数据。

"""

