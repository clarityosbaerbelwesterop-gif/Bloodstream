#!/usr/bin/env python3
"""Run the real Bloodstream M1 UE 5.8 verification on an authorized machine.

Requires an installed Unreal Engine 5.8 tree supplied by --engine-root or UE_ROOT.
The script fails instead of substituting another engine or pretending success.
"""

from __future__ import annotations

import argparse
import json
import os
import platform
import subprocess
from pathlib import Path
from typing import Iterable

ROOT = Path(__file__).resolve().parents[1]
PROJECT = ROOT / "Bloodstream.uproject"
SMOKE_MAP = ROOT / "Content" / "Developer" / "Smoke" / "M1_Smoke.umap"
LFS_POINTER_PREFIX = b"version https://git-lfs.github.com/spec/v1"


def run(command: list[str]) -> None:
    print("+", " ".join(command))
    subprocess.run(command, cwd=ROOT, check=True)


def first_existing(candidates: Iterable[Path], label: str) -> Path:
    checked = []
    for candidate in candidates:
        checked.append(str(candidate))
        if candidate.is_file():
            return candidate
    raise SystemExit(f"{label} not found. Checked: {', '.join(checked)}")


def require_ue58(engine_root: Path) -> None:
    version_file = engine_root / "Engine" / "Build" / "Build.version"
    if not version_file.is_file():
        raise SystemExit(f"Unreal Build.version not found: {version_file}")

    version = json.loads(version_file.read_text(encoding="utf-8"))
    actual = (version.get("MajorVersion"), version.get("MinorVersion"))
    if actual != (5, 8):
        raise SystemExit(
            f"Refusing non-5.8 engine: {version.get('MajorVersion')}.{version.get('MinorVersion')}"
        )


def resolve_tools(engine_root: Path) -> tuple[Path, Path, Path, str]:
    system = platform.system()
    batch = engine_root / "Engine" / "Build" / "BatchFiles"

    if system == "Windows":
        generate = first_existing(
            [engine_root / "GenerateProjectFiles.bat", batch / "GenerateProjectFiles.bat"],
            "GenerateProjectFiles",
        )
        build = first_existing([batch / "Build.bat"], "Build script")
        editor_cmd = first_existing(
            [engine_root / "Engine" / "Binaries" / "Win64" / "UnrealEditor-Cmd.exe"],
            "UnrealEditor-Cmd",
        )
        return generate, build, editor_cmd, "Win64"

    if system == "Linux":
        generate = first_existing(
            [
                engine_root / "GenerateProjectFiles.sh",
                batch / "GenerateProjectFiles.sh",
                batch / "Linux" / "GenerateProjectFiles.sh",
            ],
            "GenerateProjectFiles",
        )
        build = first_existing(
            [batch / "Build.sh", batch / "Linux" / "Build.sh"],
            "Build script",
        )
        editor_cmd = first_existing(
            [engine_root / "Engine" / "Binaries" / "Linux" / "UnrealEditor-Cmd"],
            "UnrealEditor-Cmd",
        )
        return generate, build, editor_cmd, "Linux"

    if system == "Darwin":
        generate = first_existing(
            [
                engine_root / "GenerateProjectFiles.sh",
                batch / "Mac" / "GenerateProjectFiles.sh",
                batch / "GenerateProjectFiles.sh",
            ],
            "GenerateProjectFiles",
        )
        build = first_existing(
            [batch / "Mac" / "Build.sh", batch / "Build.sh"],
            "Build script",
        )
        editor_cmd = first_existing(
            [engine_root / "Engine" / "Binaries" / "Mac" / "UnrealEditor-Cmd"],
            "UnrealEditor-Cmd",
        )
        return generate, build, editor_cmd, "Mac"

    raise SystemExit(f"Unsupported validation host: {system}")


def require_real_smoke_map() -> None:
    if not SMOKE_MAP.is_file():
        raise SystemExit(
            "M1 smoke map is missing. Create /Game/Developer/Smoke/M1_Smoke in real UE 5.8, "
            "save it as Content/Developer/Smoke/M1_Smoke.umap, and commit it through Git LFS."
        )

    with SMOKE_MAP.open("rb") as stream:
        prefix = stream.read(len(LFS_POINTER_PREFIX))
    if prefix == LFS_POINTER_PREFIX:
        raise SystemExit("M1_Smoke.umap is only a Git LFS pointer. Run git lfs pull first.")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--engine-root", default=os.environ.get("UE_ROOT"))
    args = parser.parse_args()
    if not args.engine_root:
        raise SystemExit("UE 5.8 unavailable: provide --engine-root or UE_ROOT")

    engine_root = Path(args.engine_root).expanduser().resolve()
    require_ue58(engine_root)
    generate, build, editor_cmd, platform_name = resolve_tools(engine_root)
    require_real_smoke_map()

    run([str(generate), f"-project={PROJECT}", "-game", "-engine"])
    run([
        str(build),
        "BloodstreamEditor",
        platform_name,
        "Development",
        f"-Project={PROJECT}",
        "-WaitMutex",
        "-NoHotReload",
    ])
    run([
        str(editor_cmd),
        str(PROJECT),
        "/Game/Developer/Smoke/M1_Smoke",
        "-unattended",
        "-nop4",
        "-NullRHI",
        "-ExecCmds=Automation RunTests Bloodstream.M1; Quit",
        "-TestExit=Automation Test Queue Empty",
    ])

    print("PASS: real UE 5.8 M1 compile + smoke map + Bloodstream.M1 automation invocation completed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
