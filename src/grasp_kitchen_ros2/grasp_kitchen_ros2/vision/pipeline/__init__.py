"""
Pipeline 层：视觉后端与感知流水线。

- SegmentationBackend 抽象接口
- SAM3Backend / YoloSegBackend 具体实现
- PerceptionPipeline: 组装 backend + 几何 + 相机模型

- 后续复杂的感知理解都在这里实现，包括特殊任务的自定义感知。
    SceneSegmentation 只是目前抓取依赖的一种
    如果只想感知中心点和轴向，可以扩展新.py，在perception_pipeline.py中更改调用。

"""

