from __future__ import annotations

from abc import ABC, abstractmethod
from typing import Tuple

import numpy as np


class SegmentationBackend(ABC):
    """抽象分割后端接口。

    无论 SAM3 / YOLOv8-Seg / GroundingDINO，都通过同一个接口暴露：
    - 输入：BGR 图像 + 文本提示（可选）+ 阈值
    - 输出：最佳 mask + 置信度
    """

    @abstractmethod
    def get_best_mask(
        self,
        image_bgr: np.ndarray,
        text_prompt: str,
        threshold: float,
    ) -> Tuple[np.ndarray | None, float]:
        ...


