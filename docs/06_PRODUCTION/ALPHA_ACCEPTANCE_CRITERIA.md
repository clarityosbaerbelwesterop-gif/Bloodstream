# BLOODSTREAM — ALPHA ACCEPTANCE CRITERIA

Status: AUTHORITATIVE QUALITY GATE

## Definition of alpha
Bloodstream Alpha is not a document set, prototype video or collection of disconnected systems. It is a real packaged build in which a player can start a new game, play the complete main story, traverse the intended alpha world, use the core systems and reach epilogue/credits.

## Required end-to-end path
New Game → childhood prologue → adulthood transition → Lindstripe → bounty/investigation progression → regional chapters → survivor arc → Vance confrontation → post-Vance institutional campaign → epilogue → credits.

## Core systems required
- third-person player locomotion and interaction;
- horse travel;
- stable open-world streaming;
- gunplay and weapon state;
- duel/standoff gameplay;
- bounty dossier/investigation/tracking;
- wildlife/hunting baseline;
- camp/rest/food/weather baseline;
- NPC schedules/social reactions;
- law/reputation/economy;
- narrative consequence state;
- save/load and checkpointing;
- map/journal/UI/accessibility baseline;
- original audio/music implementation sufficient for complete playthrough.

## World requirements
- Lindstripe at strong vertical-slice quality;
- all campaign-required regions traversable;
- all campaign-required settlements usable;
- no main-story reliance on unbuilt empty maps;
- region transitions and major travel routes validated;
- major world changes persist correctly.

## Narrative requirements
- family/community are established before the opening catastrophe;
- Vance network and wider institutional responsibility are understandable;
- survivors remain active human characters;
- major named character outcomes persist;
- no required dialogue references cut or nonexistent scenes;
- epilogue reflects key authored consequences.

## Bounty requirements
At least the complete set required by the campaign plus enough optional authored cases to prove systemic breadth. Any advertised content count must match the real build. No duplicate template bounties disguised through renamed targets.

## Technical requirements
- clean build from documented repository state;
- packaged build launches without editor;
- no blocker crash in start-to-credits regression;
- no save corruption in supported alpha path;
- no duplicate persistent named characters after streaming/load;
- representative performance budgets met or explicitly documented as alpha-known issues;
- critical controls and settings persist;
- logs do not show uncontrolled recurring errors.

## QA severity gate
Alpha candidate may contain known polish defects and selected non-blocking bugs. It must not contain:
- reliable progression blockers;
- missing main-story assets that prevent play;
- corrupting save defects;
- systematic input loss;
- repeatable critical streaming failure;
- legal/provenance unknowns in required shipped content;
- fake UI that claims unavailable systems work.

## Truthful handoff
Final handoff lists exact commit, build artifact/version, tested platform/profile, completion matrix, known issues and cut/deferred scope. Anything unverified is labeled unverified.