#!/usr/bin/env python3
from pathlib import Path
import sys
ROOT=Path(__file__).resolve().parents[1]
required=[
"Source/BloodstreamCharacter/Public/Player/BloodstreamPlayerController.h",
"Source/BloodstreamCharacter/Public/Player/BloodstreamCharacter.h",
"Source/BloodstreamCharacter/Public/Interaction/BloodstreamInteractable.h",
"Source/BloodstreamCharacter/Public/Interaction/BloodstreamInteractionResolver.h",
"Source/BloodstreamCharacter/Public/Interaction/BloodstreamInteractionComponent.h",
"Source/BloodstreamCharacter/Public/Items/BloodstreamInventoryComponent.h",
"Source/BloodstreamCharacter/Public/Items/BloodstreamEquipmentComponent.h",
"Source/BloodstreamCharacter/Private/Tests/BloodstreamM2Tests.cpp",
"Content/Developer/M2/README.md",
"docs/05_TECH/M2_PLAYER_CAMERA_INTERACTION.md"]
missing=[p for p in required if not (ROOT/p).is_file()]
if missing: sys.exit("ERROR missing M2 files: "+", ".join(missing))
build=(ROOT/"Source/BloodstreamCharacter/BloodstreamCharacter.Build.cs").read_text()
for dep in ("EnhancedInput","InputCore","BloodstreamCore"):
    if f'"{dep}"' not in build: sys.exit(f"ERROR missing dependency {dep}")
controller=(ROOT/required[0]).read_text(); interface=(ROOT/required[2]).read_text(); docs=(ROOT/"docs/05_TECH/M2_PLAYER_CAMERA_INTERACTION.md").read_text()
if "ABloodstreamPlayerController" not in controller or "IBloodstreamInteractable" not in interface: sys.exit("ERROR native M2 authorities missing")
if "UE 5.8 RUNTIME UNVERIFIED" not in docs: sys.exit("ERROR runtime truth boundary missing")
if (ROOT/"Content/Developer/M2/M2_PlayerInteraction.umap").exists(): sys.exit("ERROR fabricated/unverified M2 map present")
print("PASS: Bloodstream M2 static source/config boundary validation")
print("NOTE: movement, camera, interaction and Unreal automation remain runtime-unverified.")
