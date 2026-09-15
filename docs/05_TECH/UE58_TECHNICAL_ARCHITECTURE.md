# BLOODSTREAM — UNREAL ENGINE 5.8 TECHNICAL ARCHITECTURE

Status: TECHNICAL AUTHORITY

## Target
Bloodstream targets Unreal Engine 5.8 for production unless the real engine/toolchain at implementation time requires a documented version change.

## Architecture principle
Core game rules live in C++ with data-driven authoring through Unreal assets. Blueprint is allowed for presentation, level scripting, animation glue and designer-authored composition where it does not create a second authority for core systems.

## Proposed game modules
- `BloodstreamCore` — shared types, tags, IDs, save interfaces, utilities.
- `BloodstreamWorld` — world state, regions, weather hooks, time, travel, encounter director.
- `BloodstreamCharacter` — player/NPC base characters, attributes, equipment, interaction.
- `BloodstreamAI` — perception, behaviors, schedules, social/combat states.
- `BloodstreamCombat` — weapons, ammunition, damage, duels, restraint/surrender.
- `BloodstreamTracking` — clues, spoor, evidence, target dossiers.
- `BloodstreamBounty` — contracts, target state, outcomes, delivery and rewards.
- `BloodstreamHorse` — mounted movement, horse state, tack and inventory.
- `BloodstreamCamp` — camp placement, rest, cooking, maintenance.
- `BloodstreamNarrative` — quests, chapter gates, dialogue state, consequences.
- `BloodstreamUI` — HUD, journal, map, dossier and accessibility presentation.
- `BloodstreamAudio` — gameplay audio hooks and adaptive music state.
- `BloodstreamDev` — debug tools, validators, cheats and automation; excluded/limited in shipping.

Exact module boundaries may be consolidated after the first playable slice; avoid premature plugin sprawl.

## Data model
Use stable Gameplay Tags plus GUID/stable string IDs for authored entities. Data Assets/Data Tables may hold definitions, but mutable world state must live in runtime/save structures rather than changing definition assets.

Key persistent IDs:
- character;
- bounty;
- clue/evidence;
- settlement;
- faction;
- world event;
- mission/step;
- item/weapon instance where individuality matters;
- horse;
- camp/world change.

## Gameplay framework
Prefer composition with Actor Components for reusable behavior. Avoid a single enormous player class or global manager.

Subsystems are appropriate for world-scale authorities such as time, save orchestration, encounter scheduling and content registries.

## Ability architecture
Evaluate Gameplay Ability System only where its complexity pays for itself. Bloodstream is not a cooldown-heavy RPG. Do not adopt GAS merely by habit; prototype damage/status/action requirements first.

## AI
Use StateTree/Behavior Tree/Mass where each fits, not one technology everywhere:
- authored major NPCs: richer behavior/schedule logic;
- combat groups: tactical coordination layer;
- ambient crowds: scalable lightweight representation;
- distant schedules: data-only/off-screen simulation.

## Interaction
One native interaction interface and target-resolution system should serve free roam and missions. Level scripts call the same verbs rather than implementing bespoke alternatives.

## Events
Use explicit gameplay events/delegates/message channels with owned schemas. Avoid uncontrolled global dispatch that makes save/debugging impossible.

## Determinism and testability
Bounty state, mission state, evidence, money, inventory and major world consequences must be testable without rendering. Random systems use seeded sources where repeatability matters.

## Editor tooling
Plan custom editor utilities/validators for:
- duplicate stable IDs;
- broken mission references;
- missing bounty outcomes;
- inaccessible settlement services;
- region/tag mismatch;
- save-version compatibility;
- content budget warnings.

## Build philosophy
A feature only counts when it compiles in the real UE project, runs in a playable map and has automated or reproducible verification. Design documents must never claim an Unreal feature exists before integration proves it.