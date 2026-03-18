"""
YOLO segmentation backend (占位实现).

当前仅实现接口，不做任何实际分割，用于后续扩展。
"""
from __future__ import annotations

from typing import Tuple

import numpy as np

from .segmentation_backend import SegmentationBackend


class YoloSegBackend(SegmentationBackend):
    """占位实现：返回 None, 0.0，方便未来扩展 YOLOv8-Seg 等模型。"""

    def __init__(self) -> None:
        # 预留：加载 YOLO 模型、类别映射等
        pass

    def get_best_mask(
        self,
        image_bgr: np.ndarray,
        text_prompt: str,
        threshold: float,
    ) -> Tuple[np.ndarray | None, float]:
        # 预留实现：使用 text_prompt 或配置映射到 YOLO 类别，然后做分割
        return None, 0.0


