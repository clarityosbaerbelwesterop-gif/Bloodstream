#!/usr/bin/env python3
from pathlib import Path
import sys
R=Path(__file__).resolve().parents[1]
req=["Source/BloodstreamCharacter/Public/Mount/BloodstreamHorseTypes.h","Source/BloodstreamCharacter/Public/Mount/BloodstreamHorseMovementModel.h","Source/BloodstreamCharacter/Public/Mount/BloodstreamHorseCharacter.h","Source/BloodstreamCharacter/Public/Mount/BloodstreamMountedTravelComponent.h","Source/BloodstreamCharacter/Public/Travel/BloodstreamTransportInterface.h","Source/BloodstreamCharacter/Private/Tests/BloodstreamM4Tests.cpp","docs/03_GAMEPLAY/M4_MOUNTED_TRAVEL_IMPLEMENTATION.md","Content/Developer/M4/README.md"]
miss=[p for p in req if not(R/p).is_file()]
if miss:sys.exit("ERROR missing M4 files: "+", ".join(miss))
for p in R.joinpath("Content/Developer/M4").glob("*.umap"):sys.exit("ERROR fabricated/unverified M4 map: "+str(p))
text="\n".join((R/p).read_text() for p in req)
for token in ("EBloodstreamHorseGait","FBloodstreamOwnedHorseState","UBloodstreamMountedTravelComponent","IBloodstreamTransportInterface","M4_MountedTravel","RUNTIME UNVERIFIED"):
 if token not in text:sys.exit("ERROR missing M4 authority: "+token)
if "GetAllActorsOfClass" in text:sys.exit("ERROR M4 introduces global actor scan")
print("PASS: Bloodstream M4 static mounted-travel boundary validation")
print("NOTE: no UE 5.8 horse animation, physics, terrain, camera or transport runtime claim is made.")
