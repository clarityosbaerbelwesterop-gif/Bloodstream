# BLOODSTREAM — CANON AND SOURCE REGISTER

Status: AUTHORITATIVE INDEX

This register defines which document owns each major decision. Later documents may elaborate but may not silently contradict the owning source.

## Authority order

1. `docs/00_AUTHORITY/DESIGN_AUTHORITY.md`
2. Domain authority named below
3. Supporting design documents
4. Production prompts and milestone notes
5. Temporary prototypes and experiments

## Domain ownership

| Domain | Authority |
|---|---|
| Product identity, tone, non-negotiables | `DESIGN_AUTHORITY.md` |
| Creative mood and reference grammar | `CREATIVE_DIRECTION.md` |
| Historical/cultural constraints | `HISTORICAL_CULTURAL_AUTHENTICITY.md` |
| Core story, protagonist arc, antagonist structure | `../01_NARRATIVE/NARRATIVE_AUTHORITY.md` |
| Family/community opening | `../01_NARRATIVE/PROLOGUE_FAMILY_COMMUNITY.md` |
| Named major characters | `../01_NARRATIVE/CHARACTER_BIBLE.md` |
| Factions and institutional power | `../01_NARRATIVE/FACTIONS_ANTAGONISTS.md` |
| Chapter order | `../01_NARRATIVE/STORY_CHAPTERS.md` |
| World geography | `../02_WORLD/WORLD_BIBLE.md` |
| Regions/biomes | `../02_WORLD/REGIONS_BIOMES.md` |
| Settlements | `../02_WORLD/TOWNS_SETTLEMENTS.md` |
| Nature/weather | `../02_WORLD/NATURE_WEATHER.md` |
| Wildlife | `../02_WORLD/FAUNA_ECOLOGY.md` |
| Gameplay pillars | `../03_GAMEPLAY/GAMEPLAY_PILLARS.md` |
| Bounties/investigation | `../03_GAMEPLAY/BOUNTY_INVESTIGATION.md` |
| Guns/duels | `../03_GAMEPLAY/GUNPLAY_WEAPONS_DUELS.md` |
| Hunting/tracking | `../03_GAMEPLAY/HUNTING_TRACKING.md` |
| Camp/food/survival | `../03_GAMEPLAY/CAMP_SURVIVAL_FOOD.md` |
| Horses/travel | `../03_GAMEPLAY/HORSES_TRAVEL.md` |
| Law/reputation | `../03_GAMEPLAY/LAW_CRIME_REPUTATION.md` |
| NPC simulation | `../03_GAMEPLAY/NPC_AI_SOCIAL.md` |
| Economy/progression | `../03_GAMEPLAY/ECONOMY_PROGRESSION.md` |
| Interaction/immersion | `../03_GAMEPLAY/INTERACTION_IMMERSION.md` |
| Visual art | `../04_PRESENTATION/ART_DIRECTION.md` |
| Cinematics | `../04_PRESENTATION/CINEMATIC_DIRECTION.md` |
| Audio/music | `../04_PRESENTATION/AUDIO_MUSIC.md` |
| UI/accessibility | `../04_PRESENTATION/UI_UX_ACCESSIBILITY.md` |
| Animation/physicality | `../04_PRESENTATION/ANIMATION_PHYSICS_DAMAGE.md` |
| UE architecture | `../05_TECH/UE58_TECHNICAL_ARCHITECTURE.md` |
| World streaming | `../05_TECH/WORLD_STREAMING_DATA.md` |
| Save/state | `../05_TECH/SAVE_PERSISTENCE.md` |
| Performance | `../05_TECH/PERFORMANCE_TARGETS.md` |
| Higgsfield/asset pipeline | `../05_TECH/HIGGSFIELD_CONTENT_PIPELINE.md` |
| Milestone sequence | `../06_PRODUCTION/ROADMAP_M1_M28.md` |
| Acceptance rules | `../06_PRODUCTION/ALPHA_ACCEPTANCE_CRITERIA.md` |

## Canon states

Every major fact should be treated as one of:
- **LOCKED** — may not change casually.
- **WORKING CANON** — current official direction, revisable through explicit change.
- **RESEARCH-GATED** — intentionally unresolved until historical/cultural/technical validation.
- **EXPERIMENTAL** — prototype only; never assume shipping canon.

## Current locked facts

- Project title: **Bloodstream**.
- Genre: large single-player third-person open-world Western action-adventure.
- Emotional contrast is mandatory: warmth and wonder are as important as brutality.
- The opening establishes a loved family/community before catastrophic violence.
- The protagonist survives childhood loss and later becomes a frontier hunter/bounty hunter.
- Frank "The Judge" Vance is a central antagonist and direct human link to the opening catastrophe.
- Vance is part of a wider system of commercial, legal and political violence.
- Bounty hunting, tracking, duels, travel, camp life and authored encounters are core systems.
- Development target: Unreal Engine 5.8 unless later engine reality requires a version adjustment.

## Research-gated facts

- Exact historical year.
- Exact U.S./Mexican-inspired geography and border configuration.
- Protagonist's real-world nation, language and personal naming conventions.
- Exact historical weapon roster.
- Specific ceremonies, dress, architecture and cultural practices.

These must be validated before final asset lock.