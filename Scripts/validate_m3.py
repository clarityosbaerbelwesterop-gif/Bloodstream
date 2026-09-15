#!/usr/bin/env python3
from pathlib import Path
import re,sys
R=Path(__file__).resolve().parents[1]
req=["Source/BloodstreamWorld/Public/World/BloodstreamWorldTypes.h","Source/BloodstreamWorld/Public/World/BloodstreamWorldRegistry.h","Source/BloodstreamWorld/Public/World/BloodstreamWorldTime.h","Source/BloodstreamWorld/Private/Tests/BloodstreamM3Tests.cpp","Content/World/LindstripeBasin/README.md","docs/02_WORLD/LINDSTRIPE_BASIN_M3_GREYBOX.md","docs/05_TECH/M3_WORLD_ARCHITECTURE.md"]
miss=[p for p in req if not(R/p).is_file()]
if miss:sys.exit("ERROR missing M3 files: "+", ".join(miss))
if list((R/"Content/World/LindstripeBasin").glob("*.umap")):sys.exit("ERROR unverified/fabricated M3 umap present")
cpp=(R/"Source/BloodstreamWorld/Private/World/BloodstreamWorldRegistry.cpp").read_text()
ids=re.findall(r'TEXT\("([123]0000000-0000-0000-0000-00000000000[1-9])"\)',cpp)
if len(ids)!=len(set(ids)):sys.exit("ERROR duplicate authored M3 stable ID literal")
for token in ("LindstripeBasin","LindstripeTownSilhouette","BasinMineHeadframe","WesternBasinPass","WestPassToLindstripe"):
 if token not in cpp:sys.exit("ERROR missing world metadata: "+token)
spec=(R/"docs/02_WORLD/LINDSTRIPE_BASIN_M3_GREYBOX.md").read_text()
for token in ("World Partition","Data Layers","HLOD","Profiling route","NOT A PLAYABLE REGION"):
 if token not in spec:sys.exit("ERROR incomplete greybox truth/spec: "+token)
print("PASS: Bloodstream M3 static world architecture validation")
print("NOTE: no UE 5.8 World Partition, landscape, HLOD, traversal or runtime claim is made.")
