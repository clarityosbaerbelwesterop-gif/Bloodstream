# BLOODSTREAM — PERFORMANCE TARGETS

Status: TECHNICAL QUALITY BAR

## Principle
Performance is an architectural constraint, not a final optimization phase.

## Frame targets
Exact platform matrix is locked later, but all systems must be designed for:
- a stable high-quality 30 FPS class mode on constrained target hardware if console targets require it;
- a 60 FPS performance path where target hardware/content permits;
- scalable PC settings without destroying core readability.

Do not promise a platform/framerate combination until real UE 5.8 profiling exists.

## Frame-time ownership
Budget CPU game thread, render thread/GPU, animation, AI, physics, streaming, audio and Niagara separately. A feature with no measurable budget is not production-ready.

## Worst-case scenes
Performance validation must include:
- busy Lindstripe main street during train arrival;
- major saloon/interior gathering;
- large vista across forest and settlement;
- snowstorm in White Crown;
- wetland fog and vegetation;
- mounted high-speed traversal;
- train traversal across streamed cells;
- combat with multiple active NPCs;
- camp at night with fire/lighting/weather.

## AI scalability
Use simulation tiers and strict update budgets. Off-screen schedules cannot run full navigation/perception.

## Animation scalability
Crowd and distance LOD reduce pose/update cost. Hero characters retain quality close to camera.

## Rendering
Nanite, Lumen, Virtual Shadow Maps, foliage systems and hardware ray tracing are evaluated through real scene costs, not enabled blindly. Each platform/profile may use different feature combinations.

## Memory
Region expansion must pass memory and streaming tests before additional content is approved. High-resolution textures, MetaHuman-class assets, audio and animations require explicit budgets.

## Shader/PSO strategy
Plan shader permutation control, PSO collection/precache and representative packaged-build tests early enough to avoid final-release hitching surprises.

## Traversal hitching
Horse and train speed are streaming stress cases. Measure frame-time spikes, IO and asset residency during sustained traversal.

## Build validation
Performance claims come from packaged builds on real target-class hardware/profiles, not editor viewport impressions.