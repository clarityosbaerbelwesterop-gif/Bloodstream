# BLOODSTREAM — WORLD STREAMING & DATA

Status: TECHNICAL AUTHORITY

## World architecture
Use Unreal World Partition as the default basis for the contiguous open world. Final grid/cell sizes, HLOD layers and data layers are established through profiling rather than guessed globally.

## Data Layers
Use Data Layers for controlled world variation such as chapter changes, construction phases, settlement damage/rebuild, seasonal/story conditions and mission-specific sets. Do not create hundreds of overlapping layers with unclear ownership.

## HLOD
HLOD is mandatory for distant settlements, rail structures, forests and terrain-adjacent human spaces. Each region requires budget validation from representative vistas.

## Level Instances / Packed Level Actors
Use for repeated technical structures where appropriate, but hero locations receive unique authored passes. Reuse must never make towns visually interchangeable.

## Persistent simulation
Loaded actors are not the persistence database. Characters, events, bounties and world changes serialize to stable data records so cells can unload safely.

## NPC streaming
Major characters persist through state and schedule even when unloaded. Ambient population can respawn from archetype/state rules. Named people must never duplicate because a cell unloads/reloads.

## Wildlife streaming
Wildlife uses population zones and local simulation. Despawn/respawn rules must protect tracks, active hunts and visible continuity.

## Trains
Rail vehicles require special world-partition testing because they cross cells quickly and carry NPCs/interiors. Their route/state cannot depend on a single loaded level script.

## Roads and navigation
Road graph, trail metadata and regional travel links should be data-driven and queryable by AI, encounters and map systems.

## World origin / large coordinates
Use UE5 large-world coordinate support and validate physics, animation, navigation and audio across far extents before scaling the map.

## Streaming gates
Every milestone that expands world size must pass:
- traversal without visible critical pop-in at target speed;
- stable save/reload across cell boundaries;
- no duplicate named actors;
- AI recovery after unload/reload;
- acceptable frame-time and memory at worst representative vista;
- train/horse traversal stress test.

## Source control
Large binary assets must be managed with an appropriate Git LFS policy once Unreal content is introduced. Repository structure and LFS rules are locked before mass asset generation.