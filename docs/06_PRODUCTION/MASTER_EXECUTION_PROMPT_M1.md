======================================================================
BLOODSTREAM — PRODUCT BUILD
MILESTONE M1 OF M1–M28
UNREAL FOUNDATION / REPOSITORY / BUILD SPINE
======================================================================

TARGET REPOSITORY
======================================================================

GitHub repository:

clarityosbaerbelwesterop-gif/Bloodstream

Canonical branch:

main

This repository already exists.

DO NOT:
- create another repository;
- rename or restart Bloodstream;
- create a parallel game architecture;
- ignore the design authorities;
- claim Unreal functionality that has not been built and verified;
- substitute generated images/video for a real Unreal build;
- fill the project with marketplace/demo/template content and call it production;
- build later milestone systems merely to inflate progress;
- use Blueprint as a second authority for core runtime rules when the architecture assigns them to C++;
- commit secrets, local machine paths, DerivedDataCache, Intermediate, Saved, generated build output or unapproved giant binaries.

======================================================================
0. CONTEXT
======================================================================

Bloodstream is a large single-player third-person open-world Western action-adventure built around:

- authored bounty hunting;
- investigation and tracking;
- lethal Western gunplay;
- signature duels and standoffs;
- horse travel;
- camp / food / survival texture;
- wildlife and hunting;
- living settlements and NPC continuity;
- law, economy and reputation;
- a complete authored story from childhood home through revenge, institutional discovery and epilogue.

Creative target:

A world that can be brutal, tense and melancholy, but is equally capable of warmth, humor and breathtaking beauty.

The opening family/community must matter because the player genuinely spends time with them before the catastrophe.

======================================================================
1. FIRST ACTION — VERIFY REAL REPOSITORY STATE
======================================================================

Before changing anything:

1. Fetch the real current repository.
2. Verify the default/canonical branch and newest remote `main`.
3. Inspect the complete repository tree.
4. Read ALL files under `docs/00_AUTHORITY` through `docs/06_PRODUCTION`.
5. Treat `docs/00_AUTHORITY/DESIGN_AUTHORITY.md` as highest design authority.
6. Treat `docs/00_AUTHORITY/CANON_AND_SOURCE_REGISTER.md` as the domain ownership map.
7. Read `ROADMAP_M1_M28.md` and `ALPHA_ACCEPTANCE_CRITERIA.md` before implementation.
8. Record the exact starting SHA.
9. Do not assume any state described in this prompt is newer than the repository.

If the design-foundation PR has not yet been merged when this prompt is executed, stop implementation until the authoritative docs are available on the intended base branch, or deliberately target the approved branch without inventing replacements.

======================================================================
2. M1 PRIMARY OBJECTIVE
======================================================================

Create the real Unreal Engine 5.8 technical foundation for Bloodstream.

M1 is NOT a content milestone.

M1 must leave the repository with a clean, buildable, testable Unreal C++ project that later milestones can safely extend for years.

TARGET RESULT:

A developer can clone the repository on a supported environment with Unreal Engine 5.8 available, obtain required dependencies/LFS assets, generate project files, compile the development editor target, open the project, load a developer smoke-test map and run the initial automated validation suite.

======================================================================
3. ENGINE / PROJECT FOUNDATION
======================================================================

Create the actual Unreal project using Unreal Engine 5.8.

Project requirements:

- C++ project, not Blueprint-only;
- project name: Bloodstream;
- clean module/API naming;
- Enhanced Input enabled if it is the appropriate real UE 5.8 input path;
- World Partition support planned from the first real world map;
- gameplay tags/config foundation;
- deterministic stable-ID conventions for persistent authored entities;
- logging categories;
- developer/debug configuration;
- automation test support;
- source-control-friendly config.

Do not enable every Unreal plugin by default.

Only enable plugins required by M1 or clearly foundational to near-term milestones.

======================================================================
4. CODE ARCHITECTURE
======================================================================

Follow `docs/05_TECH/UE58_TECHNICAL_ARCHITECTURE.md`.

At M1, establish the minimum viable module spine without creating empty complexity.

Expected baseline modules may include:

- BloodstreamCore
- BloodstreamWorld
- BloodstreamCharacter

Additional modules from the architecture document may be created now only when they contain real foundational code/config required for M1.

Do NOT create dozens of empty modules just because the design document names future boundaries.

Required foundational types:

- stable authored entity ID type/convention;
- shared gameplay tag registry/config pattern;
- base project GameInstance/GameMode or equivalent real framework owners where appropriate;
- project logging categories;
- core developer/test helpers;
- version/build metadata exposure;
- save-version constant/schema placeholder only as required for forward compatibility.

Avoid:

- god singletons;
- giant `GameInstance` authority;
- uncontrolled global event buses;
- circular module dependencies;
- hardcoded map-specific logic in core modules.

======================================================================
5. REPOSITORY STRUCTURE
======================================================================

Establish a production-oriented Unreal layout.

At minimum:

/Source
/Config
/Content
/Plugins                  only if real project plugins exist
/Tests or appropriate UE automation-test location
/docs                     preserve existing authorities
/Build or Scripts         only for real reproducible build helpers

Create/repair `.gitignore` for Unreal.

Create Git LFS policy before mass binary content enters the repository.

LFS should cover appropriate Unreal binary assets such as `.uasset` and `.umap` if this is the chosen repository strategy.

Do NOT commit:

- Binaries
- DerivedDataCache
- Intermediate
- Saved
- local IDE data
- packaged output
- machine-specific Unreal paths

Document dependency/bootstrap expectations in README or a dedicated developer setup document.

======================================================================
6. DEVELOPER SMOKE MAP
======================================================================

Create one minimal real developer map for M1 verification.

Purpose:

- project opens into a known map or can load it directly;
- base game framework initializes;
- logging confirms project/module startup;
- a simple controllable/test pawn may exist only if required to prove the input/runtime foundation;
- no fake Western vertical slice is required.

Do not spend M1 building Lindstripe, horses, gunplay, bounties or the prologue.

Those belong to later milestones.

======================================================================
7. INPUT / TEST SHELL
======================================================================

M1 may establish only the minimum input shell necessary to prove the project is interactive and ready for M2.

Do not overbuild player locomotion.

M2 owns the real player controller/camera/interaction foundation.

Create automation tests for foundational non-rendering logic where practical, including:

- stable ID validity/equality/serialization convention;
- core configuration availability;
- gameplay tag presence/registration pattern;
- any build/version metadata helper;
- any deterministic utility added in M1.

======================================================================
8. CI / BUILD SPINE
======================================================================

Inspect the real environment and choose a truthful CI strategy.

CI must not pretend Unreal is installed if the runner cannot build it.

Preferred evidence hierarchy:

1. real compile on an available UE 5.8-capable runner/environment;
2. repository/static validation plus documented local/authorized Unreal build path if CI cannot legally/technically install the engine;
3. never a fake green job that only echoes "build succeeded."

Where an Unreal-capable environment exists, validate:

- project generation/config;
- development editor compile;
- automation test invocation;
- smoke launch or commandlet where practical.

Add scripts only if they improve reproducibility.

======================================================================
9. WORLD / DATA PREPARATION
======================================================================

Do not build the open world in M1.

But verify the project can support the documented future plan:

- World Partition-compatible project configuration;
- Large World Coordinates assumptions do not conflict with chosen framework;
- future Data Layers/HLOD path is not blocked;
- persistent entities will not rely on raw actor paths as identity.

No premature world scale claims.

======================================================================
10. EDITOR / VALIDATION TOOLS
======================================================================

Create only small validators that are genuinely useful now.

Examples:

- build/project version printout;
- stable ID format validation;
- config sanity test;
- developer smoke commandlet/test.

The large content validators described in technical docs belong in later milestones when those content types exist.

======================================================================
11. DOCUMENTATION REQUIRED IN M1
======================================================================

Add/update technical documentation covering:

- exact Unreal version used;
- supported setup path;
- how to generate/build/open the project;
- Git LFS expectations;
- module dependency overview;
- how to run tests;
- known limitations;
- what is intentionally deferred to M2+.

Do not rewrite creative authorities unless a real technical conflict is discovered.

If a conflict exists, document it explicitly instead of silently overriding canon.

======================================================================
12. VERIFICATION LOOP
======================================================================

Work in this loop:

PLAN
→ IMPLEMENT
→ COMPILE / VALIDATE
→ TEST
→ INSPECT LOGS
→ REPAIR
→ RE-RUN
→ REVIEW DIFF
→ PACKAGE/HANDOFF EVIDENCE

If a defect is discovered inside M1 scope, fix it before moving on.

If the first implementation path fails, choose a technically sound alternative that preserves the authority documents and M1 objective.

======================================================================
13. M1 ACCEPTANCE GATE
======================================================================

M1 is complete only if all applicable items are true:

[ ] Real UE 5.8 Bloodstream project exists.
[ ] C++ foundation compiles in an authorized real UE environment, or any unavailable build capability is explicitly proven/documented rather than faked.
[ ] Repository ignores generated Unreal artifacts correctly.
[ ] Git LFS policy is established before large binary asset production.
[ ] Core module structure is clean and minimal.
[ ] Stable persistent-ID convention exists.
[ ] Gameplay tag/config foundation exists.
[ ] Developer smoke map exists and loads in real Unreal validation.
[ ] Initial automation/validation tests exist and pass where runnable.
[ ] No secret or machine-specific path is committed.
[ ] No giant placeholder architecture was generated.
[ ] Existing design authorities remain intact.
[ ] Technical setup/testing documentation is accurate.
[ ] Git diff has been reviewed for accidental generated files.
[ ] All M1 blockers found during work are repaired or explicitly documented with hard evidence that they cannot be resolved in the available environment.

======================================================================
14. GIT / PR / MERGE
======================================================================

Use a focused M1 branch.

Commit logically.

Open a pull request to the real canonical branch.

PR body must include:

- starting SHA;
- final head SHA;
- files/systems added;
- exact Unreal version;
- compile evidence;
- tests run and results;
- CI status;
- LFS status;
- known issues;
- explicitly deferred M2 work.

If checks are green and no blocker remains, merge M1.

Do not claim a merge succeeded until GitHub confirms it.

After merge, verify the real `main` SHA and record it for M2.

======================================================================
15. FINAL HANDOFF
======================================================================

Return a concise engineering handoff containing:

- M1 status: COMPLETE / PARTIAL / BLOCKED;
- merged PR number and merge SHA if complete;
- exact UE version;
- compile/test evidence;
- repository structure summary;
- known issues;
- M2 readiness;
- the exact next milestone: M2 Player Controller / Camera / Interaction Foundation.

Do not start M2 inside the M1 PR unless explicitly instructed.

======================================================================
END OF M1 DIRECTIVE
======================================================================