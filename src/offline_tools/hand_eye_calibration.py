"""
Offline hand-eye calibration script.

This script is intentionally kept OUTSIDE of grasp_kitchen_core and
grasp_kitchen_perception so that calibration logic remains fully
decoupled from the online manipulation service.

Usage (from project root):

    python -m offline_tools.hand_eye_calibration

It will run the existing calibration_get() procedure from
`lbot_catch.utils.calibration_utils`, which writes a
`calibration_result.yaml` file. At runtime, GraspSystemConfig will
prefer the copy under `config/` but will fall back to the legacy
`lbot_catch/config/` location if needed.
"""
from __future__ import annotations

import os
import sys
import argparse
import shutil


def run_calibration(copy_to_config: bool = True) -> None:
    """
    Run the legacy calibration_get() and optionally copy the result into
    the new `config/` directory used by the online system.
    """
    # Ensure project root is on sys.path so we can import lbot_catch.*
    project_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    if project_root not in sys.path:
        sys.path.insert(0, project_root)

    from lbot_catch.utils.calibration_utils import calibration_get

    print("=== Offline hand-eye calibration (legacy calibration_get) ===")
    calibration_get()

    legacy_result = os.path.join(project_root, "lbot_catch", "config", "calibration_result.yaml")
    if not os.path.exists(legacy_result):
        print(f"⚠️ Legacy calibration result not found at: {legacy_result}")
        return

    if not copy_to_config:
        print("Calibration complete. Result stored at:")
        print(f"  {legacy_result}")
        print("You may manually copy it to `config/calibration_result.yaml` if desired.")
        return

    target_dir = os.path.join(project_root, "config")
    os.makedirs(target_dir, exist_ok=True)
    target_path = os.path.join(target_dir, "calibration_result.yaml")
    shutil.copyfile(legacy_result, target_path)
    print("✅ Calibration complete.")
    print(f"Legacy result: {legacy_result}")
    print(f"Copied to   : {target_path}")


def main() -> None:
    parser = argparse.ArgumentParser(description="Offline hand-eye calibration runner.")
    parser.add_argument(
        "--no-copy",
        action="store_true",
        help="Do NOT copy the result into ./config/, only leave it under lbot_catch/config/.",
    )
    args = parser.parse_args()
    run_calibration(copy_to_config=not args.no_copy)


if __name__ == "__main__":
    main()

