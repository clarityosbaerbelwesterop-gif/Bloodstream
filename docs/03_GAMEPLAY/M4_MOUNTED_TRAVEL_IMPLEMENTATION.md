# BLOODSTREAM M4 — HORSE / MOUNTED TRAVEL / TRANSPORT SPINE

Status: **AUTHORED / STATIC VALIDATION PENDING / UE 5.8 RUNTIME UNVERIFIED**

## Experience bar
Horseback travel is a primary game experience, not a sprinting car with a horse mesh. The control model exposes Halt→Walk→Trot→Canter→Gallop as intentional gaits, modest horse traits, stamina, terrain/sure-footedness hooks and physical companion states. Final tuning belongs to real animation/terrain playtesting.

## Ownership
`ABloodstreamHorseCharacter` owns horse-local movement/state. `UBloodstreamMountedTravelComponent` is the rider-side bridge and never persists raw horse identity. `FBloodstreamOwnedHorseState` is serialization-ready stable state for familiarity, stamina, tack and saddle-bag item IDs. Stagecoach/train systems consume `IBloodstreamTransportInterface`; M4 does not implement train schedules or M16 gameplay.

## Mount lifecycle
The architecture distinguishes unmounted/approach/mount/mounted/dismount and follow/stay/catch-up/hitched concepts. Runtime animation notifies, safe side selection, obstacle checks and rider attachment cannot truthfully be finished without UE assets; current source therefore transitions directly only as a functional foundation and remains runtime-unverified.

## Mounted camera
M2 camera is reused. Mounted mode lengthens the boom, raises/offsets framing and slightly widens FOV. No second camera authority is introduced. Values are hypotheses until playtested.

## Terrain
The movement model provides slope/water/sure-footedness policy hooks. Actual ground normal sampling, hoof IK, stepping, obstacle avoidance, jump/vault decisions and horse collision require real UE runtime/animation work. M3 route design already reserves horse-compatible grades, crossings and turning space.

## Companion behavior
Follow/Stay/CatchUp/Hitched are explicit states. Visible teleporting is forbidden. Off-screen catch-up may later reposition only under visibility/distance safety rules. Feeding, grooming, fear reactions and camp animation polish are later content/polish work; M4 preserves hooks without grinding systems.

## Tack and inventory
Horse state references a saddle type and stable saddle-bag item IDs. It does not duplicate the player's item authority or invent final capacity/economy. Saddlebags are utility storage hooks; production transfer UI comes later.

## Transport
`IBloodstreamTransportInterface` defines CanBoard/BeginBoard/CompleteBoard/RequestExit for stagecoach/train/boat-compatible transport actors. It intentionally does not implement train movement, timetables or magical fast travel.

## Required UE 5.8 runtime fixture
Create `/Game/Developer/M4/M4_MountedTravel` only in the real editor: horse spawn + mounting sides; flat gait lane; switchbacks; steep rejection slope; shallow creek; narrow/wide bridges; hitch post; obstruction corridor; long road loop; stagecoach/transport interface fixture. Validate mount/dismount cancellation, camera obstruction, gait transitions, stamina, terrain response, streaming loss/recovery and M2 interactions after dismount.

No `.umap` is fabricated while UE 5.8 is unavailable.
