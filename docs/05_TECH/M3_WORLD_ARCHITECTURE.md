# BLOODSTREAM M3 — WORLD ARCHITECTURE

Status: **AUTHORED / UE 5.8 WORLD ASSET & RUNTIME UNVERIFIED**

`BloodstreamWorld` owns lightweight region, landmark, road and world-time metadata. `FBloodstreamWorldRegistry` is a bounded authored registry for M3—not a giant actor manager. `UBloodstreamWorldFoundationSubsystem` exposes region lookup and time coordination without scanning world actors.

World Partition remains Unreal's streaming authority. Gameplay persistence remains stable-data authority. Region/landmark/road identity uses `FBloodstreamEntityId`, never map names or coordinates. World positions use `FVector`, preserving UE5 Large World Coordinate compatibility; coordinates are descriptive, not identity.

World time stores day index + normalized day fraction and configurable game-minutes-per-real-second. It supports pause and explicit advancement without coupling to a sky asset. Lighting/weather/NPC schedule systems subscribe later.

M2 streaming audit: active interaction targets are weak references and cancellation handles invalid targets; inventory/equipment store stable IDs rather than world actor pointers. No M3 change introduces persistent actor-pointer ownership.

World Partition grid sizes, HLOD distances and performance budgets are intentionally not hardcoded without UE profiling. Data Layer naming and HLOD categories are specified, but no runtime asset/build claim is made.

M4 handoff: mounted travel should consume road classes, crossing/route intent and region queries without introducing a parallel world registry. M4 must runtime-validate horse-scale widths/slopes once the real greybox exists.
