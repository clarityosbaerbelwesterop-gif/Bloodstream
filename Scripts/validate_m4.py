#!/usr/bin/env python3
from pathlib import Path
import sys

R = Path(__file__).resolve().parents[1]
required = [
    "Source/BloodstreamCharacter/Public/Mount/BloodstreamHorseTypes.h",
    "Source/BloodstreamCharacter/Public/Mount/BloodstreamHorseMovementModel.h",
    "Source/BloodstreamCharacter/Public/Mount/BloodstreamHorseCharacter.h",
    "Source/BloodstreamCharacter/Public/Mount/BloodstreamMountedTravelComponent.h",
    "Source/BloodstreamCharacter/Public/Travel/BloodstreamTransportInterface.h",
    "Source/BloodstreamCharacter/Private/Tests/BloodstreamM4Tests.cpp",
    "docs/03_GAMEPLAY/M4_MOUNTED_TRAVEL_IMPLEMENTATION.md",
    "docs/03_GAMEPLAY/M4_HORSE_FEEL_STANDARD.md",
    "Content/Developer/M4/README.md",
]
missing = [path for path in required if not (R / path).is_file()]
if missing:
    sys.exit("ERROR missing M4 files: " + ", ".join(missing))

for path in R.joinpath("Content/Developer/M4").glob("*.umap"):
    sys.exit("ERROR fabricated/unverified M4 map: " + str(path))

text = "\n".join((R / path).read_text() for path in required)
for token in (
    "EBloodstreamHorseGait", "FBloodstreamOwnedHorseState", "UBloodstreamMountedTravelComponent",
    "IBloodstreamTransportInterface", "M4_MountedTravel", "RUNTIME UNVERIFIED",
    "StaminaDeltaPerSecond", "Long-route quality gate", "Follow, Stay, CatchUp and Hitched",
):
    if token not in text:
        sys.exit("ERROR missing M4 authority: " + token)
if "GetAllActorsOfClass" in text:
    sys.exit("ERROR M4 introduces global actor scan")
if "AddControllerYawInput" in (R / "Source/BloodstreamCharacter/Private/Mount/BloodstreamHorseCharacter.cpp").read_text():
    sys.exit("ERROR horse steering incorrectly assumes horse controller ownership")
print("PASS: Bloodstream M4 static mounted-travel boundary validation")
print("NOTE: no UE 5.8 horse animation, physics, terrain, camera or transport runtime claim is made.")
