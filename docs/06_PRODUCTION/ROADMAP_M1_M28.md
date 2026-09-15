# BLOODSTREAM — PRODUCT ROADMAP M1–M28

Status: AUTHORITATIVE PRODUCTION SEQUENCE

## Roadmap objective
Build Bloodstream from an empty repository into a real start-to-credits Unreal Engine 5.8 alpha through 28 gated milestones. Milestones are dependency-ordered; later work may begin in parallel only when it does not create a second authority or hide unfinished blockers.

Each milestone must end with: real repository state, verified tests/build evidence, known issues, updated docs, and a clean handoff.

---

## M1 — Unreal Foundation / Repository / Build Spine
Create the real UE 5.8 project, C++ module foundation, folder conventions, Git LFS policy, build configuration, CI smoke compile, developer test map, logging, Gameplay Tags/ID conventions and initial automation test harness.

**Exit:** clean clone builds; project launches; CI compiles; no placeholder second architecture.

## M2 — Player Controller / Camera / Interaction Foundation
Third-person locomotion, camera, input, interaction interface/resolver, inspect/talk/use framework, basic inventory/equipment shell and debug interaction map.

**Exit:** responsive playable character with consistent core verbs.

## M3 — World Partition / Lindstripe Basin Greybox
Create the first contiguous world-partition landscape, roads, river/creek logic, landmark navigation, data layers, HLOD prototype, time-of-day and traversal profiling route.

**Exit:** stable on-foot traversal through a meaningful Lindstripe Basin greybox.

## M4 — Horse / Mounted Travel / Transport Spine
Production-ready horse control foundation, mounting, following, hitching, tack/inventory hooks, mounted camera, terrain handling, stage/train travel interfaces.

**Exit:** long mounted traversal feels reliable enough to build the open world around it.

## M5 — Historical & Cultural Research Lock
Lock historical year/window, geography logic, protagonist nation/language/naming decision, material culture, weapons shortlist, law/bounty framework, rail/mining facts and family/community cultural brief with sourced notes/review plan.

**Exit:** research-gated design facts required for final character/environment production become documented canon.

## M6 — Prologue Vertical Slice: Home
Build the childhood home/community slice: family interactions, ordinary work, tracking lesson, meal/music/memory anchors, warning signs, catastrophe, escape and immediate aftermath.

**Exit:** complete playable prologue proving warmth → loss emotionally and mechanically.

## M7 — Gunplay / Weapons / Damage Foundation
Native firearm state, weapon instances, ammo, aim/recoil/reload, cover interactions, hit reactions, basic injury state, enemy survival behavior and weapon audio hooks.

**Exit:** dangerous, readable Western gunplay in a representative combat test space.

## M8 — Duel & Standoff System
Implement authored duel state machine, intent-reading tells, draw timing, witness/aggressor state, cinematic camera hooks and three-person standoff prototype.

**Exit:** one polished duel and one functioning multi-threat standoff playable end to end.

## M9 — Tracking / Hunting / Fauna Foundation
Footprints/spoor, clue aging/weather hooks, animal population prototype, core wildlife behaviors, hunting loop, field processing and journal clue integration.

**Exit:** player can discover, track and complete a full hunt without waypoint dependency.

## M10 — Camp / Food / Survival / Weather
Portable camp placement, fire, rest, cooking, equipment maintenance, clothing/exposure hooks, fatigue/hunger pacing and production weather families.

**Exit:** multi-day wilderness trip works as a coherent loop without becoming meter maintenance.

## M11 — NPC Life / Social Simulation
NPC tiers, schedules, jobs, homes, local memory, group reactions, conversations, off-screen schedule state and settlement population budget.

**Exit:** a greybox Lindstripe street feels inhabited across a complete day/night cycle.

## M12 — Law / Crime / Reputation / Economy
Witness identification, jurisdiction, warrants/local wanted state, contextual reputation, shops, prices, rewards, money sinks, arrest/surrender shell and faction ownership.

**Exit:** player actions in Lindstripe produce coherent social/economic/legal consequences.

## M13 — Bounty Investigation Runtime
Bounty definitions, dossier, clue confidence/source data, target state/routines, social investigation, live-capture state, delivery/reward and rival-hunter hooks.

**Exit:** one complex bounty supports investigate → locate → multiple outcomes → persistent aftermath.

## M14 — Lindstripe Production Pass / Chapter 2
Turn Lindstripe from greybox into first production-quality town/region: districts, interiors, mine, rail yard, services, named locals, chapter missions and first major bounty-board reveal.

**Exit:** Lindstripe is a shippable-quality vertical-slice hub within alpha constraints.

## M15 — First Bounty Anthology
Build roughly 8–10 handcrafted major bounties around Lindstripe/Alder Country showing different forms: pursuit, live capture, false accusation, rival competition, social hiding, wilderness chase and evidence-bearing target.

**Exit:** bounty system proves variety without template repetition.

## M16 — Iron Vale / Rail / Chapter 4
Expand world through industrial mountain foothills. Implement train schedules/streaming, stations, freight/passenger contexts, trestles/tunnels and rail-company narrative.

**Exit:** Chapter 4 and representative moving-train gameplay are playable.

## M17 — White Crown / Snow / Chapter 5
Build high-country region, snow traversal/visibility/track effects, mountain settlement and signature snowbound ensemble sequence centered on suspicion and information.

**Exit:** the game's high-tension confined Western pillar is proven at campaign scale.

## M18 — Blackwater Reach / River Systems
Build wetland/river region, fog, waterways, local boats where useful, wildlife/ecology and distinctive settlement/encounter content.

**Exit:** region is traversal-complete and demonstrates a new systemic identity rather than reskinned terrain.

## M19 — Red Mesa + Southern Dust / Chapter 7
Build dry frontier regions, heat/dust conditions, border trade, smuggling/law complexity, desert settlements and campaign-signature three-way standoff.

**Exit:** southern arc playable with unique traversal, law and bounty situations.

## M20 — Survivor Arc / Chapter 8
Finalize returning community survivors, relationship systems, culturally reviewed scenes and missions that confront the protagonist's interpretation of the past.

**Exit:** Chapter 8 provides emotional counterweight to the revenge loop and has consequence branches wired forward.

## M21 — Vance Network / Chapter 9
Complete Vance inner circle, evidence chains, negotiation/leverage systems and the personal hunt. Build the Vance confrontation as a narrative/gameplay climax rather than a health-bar boss.

**Exit:** personal revenge arc resolves in a fully playable Chapter 9.

## M22 — After Vance / Chapters 10–11 / Epilogue
Build consequences, institutional antagonist campaign, witness/evidence protection, final alliances, ending logic and playable epilogue.

**Exit:** entire main story is playable start to credits with temporary assets allowed only where documented.

## M23 — World Content Completion
Complete remaining major settlements, 30–50 total major bounty target goal as capacity permits, authored encounters, side stories, discoverable spaces and regional world evolution. Cut quantity before lowering quality.

**Exit:** open world no longer feels like disconnected story corridors.

## M24 — Higgsfield-Assisted Art / Cinematic / Audio Production
Use approved pipeline for final concept convergence, environment/character briefs, cinematic previs, original score implementation, ambient audio, signage/prop passes and regional visual identity.

**Exit:** major regions and story scenes meet a unified presentation bar and all AI-assisted output has provenance/curation.

## M25 — Animation / AI / Physicality Polish
Motion quality, horse polish, weapon handling, interaction animation, crowd LOD, NPC transitions, physics, hit reactions, cinematic performance and traversal edge cases.

**Exit:** constant player-facing motion no longer reads as prototype quality.

## M26 — Performance / Streaming / Platform Hardening
Profile worst-case scenes, tune World Partition/HLOD, memory, AI budgets, shaders/PSO, asset residency, cook/package pipeline and target hardware profiles.

**Exit:** packaged builds meet agreed performance/memory budgets for alpha targets with no critical traversal hitches.

## M27 — Full Campaign QA / Save / Balance / Accessibility
Start-to-credits regression, golden saves, migration tests, law/economy balance, bounty outcome matrix, accessibility pass, subtitle/audio review, stuck-state repair and high-priority bug burn-down.

**Exit:** no known blocker prevents a clean complete campaign playthrough.

## M28 — ALPHA CANDIDATE / CONTENT LOCK / HANDOFF
Freeze alpha scope, remove invalid placeholders, verify all authority docs against implementation, package target builds, run final smoke/performance/save checks and produce a truthful release/handoff report.

**Exit:** a real, packaged, playable Bloodstream alpha from New Game through epilogue/credits with documented known issues and no fake completion claims.

---

## Scope rule
If production capacity cannot support both breadth and quality, preserve in this order:
1. complete main story;
2. core travel/gunplay/bounty systems;
3. Lindstripe + signature regions;
4. authored bounty quality;
5. additional world breadth.

Never preserve raw map size at the expense of a finished game.