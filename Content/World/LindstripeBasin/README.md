# Lindstripe Basin — M3 Runtime Asset Plan

Status: **RUNTIME ASSET CREATION BLOCKED**. No `.umap` or `.uasset` is fabricated without an authorized UE 5.8 editor.

Required real asset: `/Game/World/LindstripeBasin/LindstripeBasin_WP` as a World Partition world. Planned folders: `Landscape/`, `Infrastructure/`, `Landmarks/`, `Water/`, `Debug/`.

Required Data Layer convention: `WORLD_BASE`, `WORLD_INFRASTRUCTURE`, `WORLD_SETTLEMENT`, `WORLD_DEBUG`, `WORLD_PROFILE`. Later `STORY_*`, `STATE_*`, `EVENT_*` require explicit owners; Data Layers are presentation/streaming organization, not persistence state.

HLOD prototype categories: settlement silhouette, industrial/rail structures, vegetation clusters and distant infrastructure. Cell/grid and HLOD distances are deliberately unset until profiling in UE 5.8.
