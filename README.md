# Bloodstream

Bloodstream is a large-scale single-player third-person open-world Western action-adventure focused on authored bounty hunting, investigation, tracking, dangerous gunplay, duels, horse travel, camp life, wildlife, living settlements and a complete character-driven story.

## Current implementation phase

**PRODUCT M1 — Unreal Foundation / Repository / Build Spine**

M1 source/config/repository foundations are now authored on `build/m1-unreal-foundation` against the design authorities. The project targets **Unreal Engine 5.8**.

Current truth: the connected implementation environment does **not** provide a real UE 5.8 editor/toolchain, so compile, editor launch, automation execution and the required binary developer smoke map remain runtime-verification blockers. They are not represented as passed.

See:

- `docs/05_TECH/DEVELOPER_SETUP_M1.md`
- `docs/06_PRODUCTION/M1_IMPLEMENTATION_STATUS.md`
- `Scripts/validate_repo.py`
- `Scripts/run_ue58_validation.py`

## M1 module spine

- `BloodstreamCore` — stable IDs, foundational tags, version/save-schema metadata, logging and automation tests.
- `BloodstreamWorld` — minimal world framework owner and M1 GameMode.
- `BloodstreamCharacter` — character-domain module boundary only; real player runtime belongs to M2.

No future gameplay modules have been generated as empty architecture.

## Git LFS

Unreal binary assets are governed by `.gitattributes`. Install Git LFS before pulling/committing `.uasset` or `.umap` files:

```text
git lfs install
git lfs pull
```

## Authority

The highest design authority is `docs/00_AUTHORITY/DESIGN_AUTHORITY.md`. Domain ownership is defined by `docs/00_AUTHORITY/CANON_AND_SOURCE_REGISTER.md`.

The complete design bible remains under:

- `docs/00_AUTHORITY`
- `docs/01_NARRATIVE`
- `docs/02_WORLD`
- `docs/03_GAMEPLAY`
- `docs/04_PRESENTATION`
- `docs/05_TECH`
- `docs/06_PRODUCTION`

## Production sequence

Bloodstream uses 28 gated milestones. M1 establishes the real Unreal foundation; M2 owns Player Controller / Camera / Interaction Foundation. Do not start M2 inside an incomplete M1 verification pass.

## Truth rule

A source file, `.uproject`, workflow, generated image or video is not evidence that gameplay works. Unreal functionality is reported as verified only after real build/runtime evidence exists.
