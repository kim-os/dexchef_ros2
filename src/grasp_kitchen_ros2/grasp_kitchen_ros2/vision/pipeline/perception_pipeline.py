from __future__ import annotations

from typing import List

import numpy as np

from grasp_kitchen_ros2.vision.entities.camera_model import CameraModel
from grasp_kitchen_ros2.vision.entities.detections import DetectedObject
from grasp_kitchen_ros2.vision.pipeline.segmentation_backend import SegmentationBackend
from grasp_kitchen_ros2.vision.pipeline.pose_estimator import estimate_pose_from_mask


class PerceptionPipeline:
    """
    高内聚的感知管线：

    输入：
      - RGB 图 (BGR, HxWx3)
      - 深度图 raw_depth (uint16 / float32)
      - CameraModel（K, T_base_cam, depth_scale）
    输出：
      - List[DetectedObject] （基座坐标系下的目标列表）

    不依赖 ROS2，不依赖具体相机，只依赖 numpy 和 SegmentationBackend 抽象接口。
    """

    def __init__(
        self,
        backend: SegmentationBackend,
        text_prompt: str = "orange",
        conf_threshold: float = 0.5,
    ) -> None:
        self._backend = backend
        self._text_prompt = text_prompt
        self._threshold = conf_threshold

    def run(
        self,
        color_bgr: np.ndarray,
        raw_depth: np.ndarray,
        cam: CameraModel,
    ) -> List[DetectedObject]:
        # 1) 深度单位转换：raw_depth -> 米
        depth_m = raw_depth.astype(np.float32) * float(cam.depth_scale)

        # 2) 调用后端分割算法（SAM3 / YOLO 等）获取最优 mask
        best_mask, score = self._backend.get_best_mask(
            color_bgr, text_prompt=self._text_prompt, threshold=self._threshold
        )
        if best_mask is None:
            return []

        # 3) 通过几何模块，把 mask + depth + 内参/标定 转成位姿与尺寸
        pose_cam, dynamic_bbox_3d, max_length, min_length, angle_base_xy_rad = (
            estimate_pose_from_mask(best_mask, depth_m, cam.K, cam.T_base_cam)
        )
        if pose_cam is None:
            return []

        # 4) 转到 base 坐标系，并从旋转矩阵提取四元数
        pose_base = cam.T_base_cam @ pose_cam
        position = tuple(float(x) for x in pose_base[:3, 3])

        rot = pose_base[:3, :3]
        qw = float(
            np.sqrt(max(0.0, 1.0 + rot[0, 0] + rot[1, 1] + rot[2, 2])) / 2.0
        )
        qx = float(
            np.sign(rot[2, 1] - rot[1, 2])
            * np.sqrt(max(0.0, 1.0 + rot[0, 0] - rot[1, 1] - rot[2, 2])) / 2.0
        )
        qy = float(
            np.sign(rot[0, 2] - rot[2, 0])
            * np.sqrt(max(0.0, 1.0 - rot[0, 0] + rot[1, 1] - rot[2, 2])) / 2.0
        )
        qz = float(
            np.sign(rot[1, 0] - rot[0, 1])
            * np.sqrt(max(0.0, 1.0 - rot[0, 0] - rot[1, 1] + rot[2, 2])) / 2.0
        )

        # 5) 把物理尺寸和姿态打包为领域模型 DetectedObject
        size_xyz = (
            float(max_length) if max_length is not None else 0.0,
            float(min_length) if min_length is not None else 0.0,
            0.05,
        )

        return [
            DetectedObject(
                class_name=self._text_prompt,
                position=position,
                quaternion=(qx, qy, qz, qw),
                confidence=float(score),
                size_xyz=size_xyz,
            )
        ]

