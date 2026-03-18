from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, Set


@dataclass
class WorldObject:
    """Simple perceived object in base coordinates (currently fruit only)."""

    id: str
    class_name: str
    x: float
    y: float
    z: float


@dataclass
class WorldState:
    """World model snapshot used by the task planner."""

    objects: Dict[str, WorldObject] = field(default_factory=dict)
    picked: Set[str] = field(default_factory=set)
    placed: Set[str] = field(default_factory=set)


