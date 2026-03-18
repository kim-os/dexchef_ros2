from __future__ import annotations

from dataclasses import dataclass
from typing import Tuple


@dataclass
class DetectedObject:
    """High-level description of a detected object in base coordinates."""

    class_name: str
    position: Tuple[float, float, float]
    quaternion: Tuple[float, float, float, float]
    confidence: float
    size_xyz: Tuple[float, float, float]


