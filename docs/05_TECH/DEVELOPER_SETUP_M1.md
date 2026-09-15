# BLOODSTREAM — M1 DEVELOPER SETUP

Status: M1 TECHNICAL HANDOFF

## Engine truth

- Target engine: **Unreal Engine 5.8**.
- Engine version actually validated during this implementation: **NOT AVAILABLE**.
- No other Unreal version was substituted or presented as 5.8 evidence.

The source/config foundation is authored for UE 5.8 but remains uncompiled until an authorized UE 5.8 installation executes the real validation path.

## Repository bootstrap

1. Install Git and Git LFS.
2. Run `git lfs install` once for the workstation.
3. Clone `clarityosbaerbelwesterop-gif/Bloodstream`.
4. Run `git lfs pull` before opening Unreal content once binary assets are present.
5. Install/obtain an authorized Unreal Engine 5.8 source or launcher build.
6. Set `UE_ROOT` to the Unreal installation root or pass `--engine-root` to the validation script.

No machine-specific Unreal path is stored in the repository.

## Project/module spine

M1 contains only the minimum planned runtime modules:

- `BloodstreamCore` — stable entity identity, tag names/config contract, version/save-schema metadata, core logging and non-rendering tests.
- `BloodstreamWorld` — minimal GameMode and world-scoped foundation subsystem/logging.
- `BloodstreamCharacter` — character-domain module boundary and logging only; real player controller/camera/interaction remains M2.

Future architecture modules in `UE58_TECHNICAL_ARCHITECTURE.md` are intentionally not created as empty shells.

## Generate / compile / test

Static repository validation (does not require Unreal):

```text
python Scripts/validate_repo.py
```

Real UE 5.8 validation:

```text
python Scripts/run_ue58_validation.py --engine-root <authorized-UE-5.8-root>
```

The real validation script refuses a non-5.8 `Build.version`, requires the actual `M1_Smoke.umap`, invokes project generation, builds `BloodstreamEditor Development`, opens the smoke map with `UnrealEditor-Cmd`, and invokes the `Bloodstream.M1` automation namespace.

## Automation tests authored

- `Bloodstream.M1.Core.EntityId.RoundTrip`
  - validates generated ID validity;
  - string parse/equality;
  - archive serialization round-trip.
- `Bloodstream.M1.Core.Foundation.Config`
  - validates save-schema metadata;
  - validates target-engine metadata;
  - validates the foundational Gameplay Tag roots are registered.

These tests are **AUTHORED / NOT RUN** until real UE 5.8 is available.

## Gameplay Tags

Only foundational roots are registered in M1:

- `Character`
- `World`
- `State`
- `Interaction`

No speculative tag tree is generated.

## Stable authored IDs

`FBloodstreamEntityId` wraps a persisted `FGuid`. It does not use actor paths, runtime pointers, array position or spawn order. Authoring tools/content should generate an ID once and preserve it across renames, World Partition unload/reload and save versions.

## World Partition readiness

M1 deliberately does not create the open world. The persistent-identity design is streaming-safe, and no project framework decision requires actor paths as save identity. World Partition grid/HLOD/Data Layer settings remain M3 profiling decisions.

## Smoke map blocker

A `.umap` is an Unreal binary asset and was not fabricated without the editor. Create `/Game/Developer/Smoke/M1_Smoke` using real UE 5.8, keep it minimal, save it, run the validation script, and commit it through Git LFS.

## CI truth

`.github/workflows/m1-foundation.yml` is a **static repository validation** job only. Its success must never be reported as Unreal compile, launch, test, smoke-map, cook or package success.

## Deferred to M2+

M2 owns the player controller, production camera, Enhanced Input mappings/assets, interaction interface/resolver, inspect/talk/use runtime, debug interaction map and basic inventory/equipment shell. M1 intentionally does not implement those systems.
