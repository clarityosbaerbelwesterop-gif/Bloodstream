# BLOODSTREAM M4 — HORSE FEEL STANDARD

Status: **AUTHORITATIVE FEEL TARGET / UE 5.8 PLAYTEST REQUIRED**

## Principle
The horse is a living travel partner and locomotion system, not a reskinned vehicle. Input expresses intent; animation, terrain, momentum, temperament and the animal's condition should mediate the result. Responsiveness must remain enjoyable: realism is used where it creates weight, attachment and readable consequence, never to create chores for their own sake.

## Control grammar
Five authored gait states establish a readable rhythm: Halt, Walk, Trot, Canter and Gallop. Gait changes are deliberate rather than an invisible continuous speed slider. Turning authority reduces at high gait so a gallop communicates momentum. Backing, pivots, sidesteps, braking anticipation and animation matching are runtime/animation work and cannot be signed off statically.

## Endurance
Stamina is time-based, never frame-based. Gallop is costly, canter is sustainable only in stretches, while walk and halt recover. Endurance traits alter rate rather than creating enormous RPG stat gaps. Exhaustion progressively caps gait before any later animation/audio distress layer. Exact rates are tuning hypotheses until the long-route fixture is playable.

## Terrain contract
Roads should matter without magnetically snapping the horse to them. Slope, shallow water, surface, clearance and sure-footedness may influence pace and confidence. The horse must not blindly accept unsafe cliffs or squeeze through obviously impossible geometry. M4 source exposes only deterministic policy that can be unit-tested; ground sampling, hoof placement, collision response and obstacle anticipation require UE runtime.

## Camera contract
Mounted framing inherits M2 camera ownership. It should widen the player's awareness at speed while keeping the horse and landscape composition legible. Camera collision may never repeatedly punch into the rider/horse on normal roads. Cinematic travel cameras may later be layered as optional presentation, never as a second gameplay camera authority.

## Relationship without grind
Familiarity is a durable relationship hook, not a daily-maintenance meter. Feeding, grooming, calming and camp care can create authored moments and modest recovery/behavior effects later, but Bloodstream must not punish players with repetitive upkeep. Breed/type differences remain restrained: acceleration, endurance, sure-footedness, size and temperament create character without turning horses into loot tiers.

## Companion presence
Follow, Stay, CatchUp and Hitched are explicit semantic states. Catch-up must first prefer physical navigation. Any emergency off-screen relocation must be invisible, conservative and justified by streaming/recovery—not a visible teleport. Whistling, hitching and camp behavior should make the horse feel present even when not ridden.

## Mounting and dismounting acceptance
Production mounting requires side selection, reachability, clearance, slope safety, cancellation, animation notify authority and correct rider attachment. Dismount requires a safe candidate position rather than dropping the rider into walls, water hazards or steep slopes. The current direct source transition is scaffolding only and must be replaced/validated when animation assets exist.

## Long-route quality gate
The M4 exit test is not "the horse moves." A player must be able to ride the M3 profiling route for an extended session across roads, turns, slopes, water crossings, bridges, settlement approaches and streaming boundaries with no systemic failure. Evaluate: control readability, animation/physics coherence, camera stability, collision, stamina pacing, route width, hitch/follow recovery, mount/dismount safety, persistence and return-to-foot interaction.

The target is premium open-world Western travel quality. It is a quality bar, not a claim of equivalence to any shipped game before runtime evidence exists.
