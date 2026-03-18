from __future__ import annotations

from dataclasses import dataclass

import numpy as np


@dataclass
class CameraModel:
    """Minimal camera model used by the perception pipeline."""

    K: np.ndarray          # 3x3 intrinsics
    T_base_cam: np.ndarray # 4x4 base->cam
    depth_scale: float     # raw_depth * depth_scale -> meters


