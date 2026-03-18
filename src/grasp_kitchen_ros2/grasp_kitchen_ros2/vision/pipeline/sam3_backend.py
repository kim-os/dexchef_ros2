"""
SAM3 segmentation backend for the vision stack.
"""
from __future__ import annotations

import sys
import time
from typing import List, Tuple

import cv2
import numpy as np
import torch
from PIL import Image

from .segmentation_backend import SegmentationBackend


FIXED_ROIS: List[List[int]] = [
    [100, 120, 220, 240],
    [420, 120, 180, 240],
]


class SAM3Backend(SegmentationBackend):
    """文本提示分割后选取最佳 ROI，对外只暴露 get_best_mask 接口。"""

    def __init__(self, model_path: str) -> None:
        self.model_path = model_path
        self.device = "cuda" if torch.cuda.is_available() else "cpu"
        self.model = None
        self.processor = None
        self._load_model()

    def _load_model(self) -> None:
        from transformers import Sam3Model, Sam3Processor

        print(f"[SAM3] loading from {self.model_path} on {self.device}")
        try:
            torch.backends.cudnn.benchmark = True
            torch.backends.cuda.matmul.allow_tf32 = True

            self.processor = Sam3Processor.from_pretrained(self.model_path)
            self.model = Sam3Model.from_pretrained(self.model_path).to(self.device).half().eval()

            dummy = Image.new("RGB", (640, 480), "red")
            for _ in range(3):
                inputs = self.processor(images=dummy, text="warmup", return_tensors="pt").to(
                    self.device
                )
                with torch.no_grad():
                    _ = self.model(**inputs)
            if self.device.startswith("cuda"):
                torch.cuda.synchronize()
            print("[SAM3] model loaded and warmed up.")
        except Exception as e:
            import traceback

            print(f"[SAM3] failed to load model: {e}")
            print(traceback.format_exc())
            sys.exit(1)

    def _segment_with_text(
        self,
        image: np.ndarray,
        text_prompt: str,
        threshold: float,
    ) -> Tuple[List[np.ndarray], List[List[float]], List[float]]:
        from transformers import Sam3Processor  # type: ignore[name-defined]

        start = time.time()

        rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        img = Image.fromarray(rgb)

        processor_kwargs = {"images": img, "return_tensors": "pt", "text": text_prompt}
        inputs = self.processor(**processor_kwargs).to(self.device, non_blocking=True)

        with torch.no_grad(), torch.amp.autocast("cuda", dtype=torch.float16):
            outputs = self.model(**inputs)
        if self.device.startswith("cuda"):
            torch.cuda.synchronize()

        results = self.processor.post_process_instance_segmentation(
            outputs, target_sizes=[img.size[::-1]], threshold=threshold
        )[0]

        masks: List[np.ndarray] = []
        boxes: List[List[float]] = []
        scores: List[float] = []

        if "masks" in results:
            m = results["masks"].cpu().numpy()
            s = results.get("scores", torch.ones(len(m))).cpu().numpy()
            b = results.get("boxes", None)
            if b is not None:
                b = b.cpu().numpy()
            for i, mask in enumerate(m):
                masks.append(mask)
                scores.append(float(s[i]) if i < len(s) else 1.0)
                if b is not None and i < len(b):
                    boxes.append(list(b[i]))
                else:
                    boxes.append([0.0, 0.0, 10.0, 10.0])

        elapsed = (time.time() - start) * 1000.0
        print(f"[SAM3] {len(masks)} masks for '{text_prompt}' in {elapsed:.0f} ms")
        return masks, boxes, scores

    def get_best_mask(
        self,
        image_bgr: np.ndarray,
        text_prompt: str,
        threshold: float,
    ) -> Tuple[np.ndarray | None, float]:
        """在固定 ROI 中搜索，返回面积最大 mask + 置信度。"""
        h_img, w_img = image_bgr.shape[:2]
        best_mask = None
        best_score = 0.0
        max_area = 0

        for roi in FIXED_ROIS:
            x, y, w, h = roi
            x1, y1, x2, y2 = x, y, x + w, y + h
            roi_img = image_bgr[y1:y2, x1:x2]
            if roi_img.size == 0:
                continue

            masks, boxes, scores = self._segment_with_text(
                roi_img, text_prompt=text_prompt, threshold=threshold
            )

            for mask, score in zip(masks, scores):
                full_mask = np.zeros((h_img, w_img), dtype=np.uint8)
                mask_bin = (mask > 0.5).astype(np.uint8)
                mask_resized = cv2.resize(
                    mask_bin, (x2 - x1, y2 - y1), interpolation=cv2.INTER_NEAREST
                )
                full_mask[y1:y2, x1:x2] = mask_resized

                area = int(np.sum(full_mask > 0))
                if area > max_area:
                    max_area = area
                    best_mask = full_mask
                    best_score = float(score)

        if best_mask is not None:
            print(f"[SAM3] best area={max_area}, score={best_score:.3f}")
        else:
            print("[SAM3] no mask found in ROIs")

        return best_mask, best_score


