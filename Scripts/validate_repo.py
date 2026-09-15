#!/usr/bin/env python3
"""Truthful static validation for Bloodstream M1.

This script deliberately does not claim Unreal compilation or runtime success.
It validates only facts available from a normal repository checkout.
"""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

REQUIRED = [
    "Bloodstream.uproject",
    ".gitattributes",
    ".gitignore",
    "Config/DefaultEngine.ini",
    "Config/DefaultGame.ini",
    "Config/DefaultGameplayTags.ini",
    "Source/Bloodstream.Target.cs",
    "Source/BloodstreamEditor.Target.cs",
    "Source/BloodstreamCore/BloodstreamCore.Build.cs",
    "Source/BloodstreamCore/Public/Identity/BloodstreamEntityId.h",
    "Source/BloodstreamCore/Private/Tests/BloodstreamCoreTests.cpp",
    "Source/BloodstreamWorld/BloodstreamWorld.Build.cs",
    "Source/BloodstreamWorld/Public/Framework/BloodstreamGameModeBase.h",
    "Source/BloodstreamCharacter/BloodstreamCharacter.Build.cs",
    "docs/00_AUTHORITY/DESIGN_AUTHORITY.md",
    "docs/06_PRODUCTION/ROADMAP_M1_M28.md",
    "docs/06_PRODUCTION/ALPHA_ACCEPTANCE_CRITERIA.md",
]

FORBIDDEN_DIR_NAMES = {"Binaries", "DerivedDataCache", "Intermediate", "Saved"}
SECRET_PATTERNS = [
    re.compile(r"ghp_[A-Za-z0-9]{20,}"),
    re.compile(r"github_pat_[A-Za-z0-9_]{20,}"),
    re.compile(r"sk-[A-Za-z0-9_-]{20,}"),
    re.compile(r"-----BEGIN (?:RSA |EC |OPENSSH )?PRIVATE KEY-----"),
]
ABSOLUTE_MACHINE_PATHS = [
    re.compile(r"[A-Za-z]:\\(?:Users|Program Files|Epic Games)\\"),
    re.compile(r"/Users/[^/]+/"),
    re.compile(r"/home/[^/]+/"),
]


def fail(message: str) -> None:
    print(f"ERROR: {message}", file=sys.stderr)
    raise SystemExit(1)


def read(path: str) -> str:
    return (ROOT / path).read_text(encoding="utf-8")


def main() -> int:
    missing = [path for path in REQUIRED if not (ROOT / path).is_file()]
    if missing:
        fail("missing required files: " + ", ".join(missing))

    project = json.loads(read("Bloodstream.uproject"))
    if project.get("EngineAssociation") != "5.8":
        fail("Bloodstream.uproject must target EngineAssociation 5.8")

    modules = {module.get("Name") for module in project.get("Modules", [])}
    expected_modules = {"BloodstreamCore", "BloodstreamWorld", "BloodstreamCharacter"}
    if modules != expected_modules:
        fail(f"unexpected M1 module set: {sorted(modules)}")

    attributes = read(".gitattributes")
    for pattern in ("*.uasset filter=lfs", "*.umap filter=lfs"):
        if pattern not in attributes:
            fail(f"Git LFS policy missing: {pattern}")

    ignore = read(".gitignore")
    for generated in ("Binaries/", "DerivedDataCache/", "Intermediate/", "Saved/"):
        if generated not in ignore:
            fail(f"generated Unreal folder not ignored: {generated}")

    tags = read("Config/DefaultGameplayTags.ini")
    for root_tag in ("Character", "World", "State", "Interaction"):
        if f'Tag="{root_tag}"' not in tags:
            fail(f"foundational Gameplay Tag missing: {root_tag}")

    entity_id = read("Source/BloodstreamCore/Public/Identity/BloodstreamEntityId.h")
    for forbidden_identity in ("ActorPath", "SpawnOrder", "ArrayIndex"):
        if forbidden_identity in entity_id:
            fail(f"persistent ID implementation references forbidden identity source: {forbidden_identity}")

    for path in ROOT.rglob("*"):
        if not path.is_dir():
            continue
        if path.name in FORBIDDEN_DIR_NAMES:
            fail(f"generated Unreal directory is present in checkout: {path.relative_to(ROOT)}")

    scan_roots = [ROOT / "Source", ROOT / "Config", ROOT / "Scripts", ROOT / ".github"]
    scan_files = [ROOT / "Bloodstream.uproject"]
    for scan_root in scan_roots:
        if scan_root.exists():
            scan_files.extend(p for p in scan_root.rglob("*") if p.is_file())

    for path in scan_files:
        try:
            text = path.read_text(encoding="utf-8")
        except UnicodeDecodeError:
            continue
        for pattern in SECRET_PATTERNS:
            if pattern.search(text):
                fail(f"possible secret found in {path.relative_to(ROOT)}")
        for pattern in ABSOLUTE_MACHINE_PATHS:
            if pattern.search(text):
                fail(f"machine-specific absolute path found in {path.relative_to(ROOT)}")

    print("PASS: Bloodstream M1 static repository foundation validation")
    print("NOTE: UE 5.8 compile/runtime/smoke-map validation is NOT performed by this script.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
