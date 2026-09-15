# BLOODSTREAM M2 — PLAYER / CAMERA / INTERACTION FOUNDATION

Status: **AUTHORED / STATIC VALIDATION PENDING / UE 5.8 RUNTIME UNVERIFIED**

M2 is stacked on M1 because PR #2 remains runtime-blocked. Runtime authority remains native C++ in `BloodstreamCharacter`.

## Ownership
`ABloodstreamPlayerController` routes Enhanced Input intent and refreshes contextual selection. `ABloodstreamCharacter` owns physical movement and camera components. `UBloodstreamInteractionComponent` owns bounded local discovery and active-interaction cancellation. Inventory and equipment are small actor components with serialization-ready stable item instance IDs.

## Movement/camera
CharacterMovement supplies collision, slope/step/fall behavior. Tuned acceleration/braking/rotation/speeds establish a deliberate baseline without final animation claims. A spring arm provides third-person framing and collision testing; FOV and lag are tunable properties. Aim, horse and cinematic modes remain future hooks rather than M2 implementations.

## Interaction
`IBloodstreamInteractable` is the single capability contract. Semantic verbs are USE, INSPECT, TALK and TAKE. The resolver scores bounded sweep candidates using distance, gaze alignment and explicit priority after an occlusion check. Prompts expose action/target semantics, never keyboard-specific strings. Active interactions are cancellable and weak-reference targets so destruction cannot create a persistence authority.

## Player modes
One `EBloodstreamPlayerMode` represents FreeMovement, Interacting, Inspecting, Conversation and Disabled rather than unrelated boolean flags. Later Aim/Duel/Mounted/Cinematic modes extend this authority deliberately.

## Inventory/equipment
Definitions and owned item state are separate structures. Owned instances use `FBloodstreamEntityId`; mutable state lives on the player components. Equipment maps semantic slots to stable owned item IDs. M2 intentionally has no firearm behavior or final inventory UI.

## Enhanced Input assets
C++ ownership and soft authoring points are present, but real `UInputAction`/`UInputMappingContext` assets cannot be fabricated without UE 5.8. Create them in `/Game/Developer/M2/Input` during runtime integration and assign them to the controller defaults. No keyboard key is hardcoded in gameplay code.

## Runtime fixture
`/Game/Developer/M2/M2_PlayerInteraction` is specified in `Content/Developer/M2/README.md`; its `.umap` remains blocked until UE 5.8 can save it.

## Verification
Static validation must check module dependencies, native authorities, absence of generated files/secrets/machine paths and test source presence. Real UE 5.8 must then compile, load the fixture and run `Bloodstream.M1` plus `Bloodstream.M2` automation tests. Until that happens, no movement/camera/interaction behavior is described as working.

## M3 handoff
M3 owns World Partition / Lindstripe Basin greybox. It must consume this player spine without adding a parallel controller, interaction system or inventory authority.
