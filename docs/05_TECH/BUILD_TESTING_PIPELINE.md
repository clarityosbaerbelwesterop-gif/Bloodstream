# BLOODSTREAM — BUILD & TESTING PIPELINE

Status: TECHNICAL PRODUCTION STANDARD

## Principle
No milestone is complete because source files exist. It completes when the real project builds, runs and satisfies reproducible acceptance checks.

## Source-control workflow
- `main` is canonical.
- Work lands through focused branches and pull requests unless an explicitly approved emergency path is used.
- Design authorities and implementation changes that alter canon are reviewed together.
- Unreal binary assets require Git LFS policy before large content production.

## CI stages once Unreal project exists
1. repository/config validation;
2. C++ compile for supported development target;
3. editor automation/unit tests;
4. content validation commandlets;
5. cook/package smoke build on scheduled or milestone pipelines;
6. optional deterministic gameplay test maps;
7. artifact/report publication.

## Test layers
- pure C++/automation tests for data/state logic;
- functional test maps for interaction, bounty, save and AI systems;
- scripted traversal tests for streaming;
- golden save load/migration tests;
- performance captures in representative scenes;
- manual cinematic/narrative QA where automation cannot judge quality.

## Required debug tools
Development builds need commands/widgets to:
- jump to chapter/mission state;
- spawn or locate test NPCs;
- inspect bounty and evidence state;
- change time/weather;
- show AI schedule/state;
- show World Partition cells and streaming status;
- grant controlled inventory/economy state;
- dump save data;
- run encounter simulations;
- record performance markers.

## Bug policy
A known blocker discovered inside the current milestone is fixed before expanding scope unless the fix is demonstrably independent and tracked with explicit severity/owner.

## Packaging truth
Only a packaged executable/build artifact counts as a packaged build. Editor play sessions, mockups or generated videos do not.

## Milestone evidence
Each milestone handoff records commit SHA, tests run, packaged-build status where applicable, known defects, performance notes and exact unfinished items.

## Reproducibility
If a failure cannot be reproduced, capture logs, save file/state, map, time/weather, target platform and steps. Build test maps intentionally instead of depending on enormous story saves for every regression.