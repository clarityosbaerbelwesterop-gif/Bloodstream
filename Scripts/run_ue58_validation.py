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

ROOT = Path(__file__).resolve().parents[1]
PROJECT = ROOT / "Bloodstream.uproject"
SMOKE_MAP = ROOT / "Content" / "Developer" / "Smoke" / "M1_Smoke.umap"


def run(command: list[str]) -> None:
    print("+", " ".join(command))
    subprocess.run(command, cwd=ROOT, check=True)


def require_ue58(engine_root: Path) -> None:
    version_file = engine_root / "Engine" / "Build" / "Build.version"
    if not version_file.is_file():
        raise SystemExit(f"Unreal Build.version not found: {version_file}")
    version = json.loads(version_file.read_text(encoding="utf-8"))
    if (version.get("MajorVersion"), version.get("MinorVersion")) != (5, 8):
        raise SystemExit(
            f"Refusing non-5.8 engine: {version.get('MajorVersion')}.{version.get('MinorVersion')}"
        )


def paths(engine_root: Path) -> tuple[Path, Path, Path, str]:
    system = platform.system()
    batch = engine_root / "Engine" / "Build" / "BatchFiles"
    if system == "Windows":
        return (
            batch / "GenerateProjectFiles.bat",
            batch / "Build.bat",
            engine_root / "Engine" / "Binaries" / "Win64" / "UnrealEditor-Cmd.exe",
            "Win64",
        )
    if system == "Linux":
        return (
            batch / "GenerateProjectFiles.sh",
            batch / "Build.sh",
            engine_root / "Engine" / "Binaries" / "Linux" / "UnrealEditor-Cmd",
            "Linux",
        )
    if system == "Darwin":
        return (
            batch / "Mac" / "GenerateProjectFiles.sh",
            batch / "Mac" / "Build.sh",
            engine_root / "Engine" / "Binaries" / "Mac" / "UnrealEditor-Cmd",
            "Mac",
        )
    raise SystemExit(f"Unsupported validation host: {system}")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--engine-root", default=os.environ.get("UE_ROOT"))
    args = parser.parse_args()
    if not args.engine_root:
        raise SystemExit("UE 5.8 unavailable: provide --engine-root or UE_ROOT")

    engine_root = Path(args.engine_root).expanduser().resolve()
    require_ue58(engine_root)
    generate, build, editor_cmd, platform_name = paths(engine_root)
    for required in (generate, build, editor_cmd):
        if not required.exists():
            raise SystemExit(f"required UE tool missing: {required}")

    if not SMOKE_MAP.is_file():
        raise SystemExit(
            "M1 smoke map is missing. Create /Game/Developer/Smoke/M1_Smoke in real UE 5.8, "
            "save it as Content/Developer/Smoke/M1_Smoke.umap, and commit it through Git LFS."
        )

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
