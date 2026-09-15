# BLOODSTREAM — SAVE & PERSISTENCE

Status: TECHNICAL AUTHORITY

## Goal
Saving must preserve the player's actual world, not just mission checkpoints.

## Persistent domains
At minimum save:
- story chapter and mission states;
- bounty states and outcomes;
- clue/evidence ownership and knowledge;
- named NPC state and relationships;
- local reputation and law state;
- settlement/world changes;
- inventory, money and weapon instances;
- horse state and equipment;
- camp state where relevant;
- player position, time and environmental context;
- discovered locations/routes;
- accessibility/gameplay settings separately from world save where appropriate.

## Stable IDs
All persistent authored entities use stable IDs that do not depend on actor path or level instance names.

## Save schema
Use versioned save structures with explicit migration. Never deserialize arbitrary old binary state directly into current actors without version handling.

## Autosave
Autosave at safe transactional points: completed mission steps, bounty resolution, major purchases, rest, arrival/transport transitions and configurable intervals when not in unstable action.

## Manual save
Permit manual save in broad free-roam conditions. Where an encounter cannot be safely serialized mid-state, communicate the restriction clearly and keep the blocked window short.

## Transaction safety
Money, reward, item acquisition and mission/bounty resolution must commit atomically enough to prevent duplication through interruption.

## Death/retry
Reloading after player failure should return to a coherent recent state without silently undoing long exploration sessions. Mission checkpoints must restore mission-local actors and relevant world state.

## Testing
Automated tests should create representative saves from multiple schema versions, load them, verify state invariants and resave. Maintain a small suite of golden saves for regression.

## Corruption recovery
Use safe-write patterns and maintain at least one fallback/autosave generation. A failed write must not destroy the previous valid save.

## Debug tooling
Development builds need save inspection, state diff, forced migration and named-state commands so narrative/system bugs are diagnosable.