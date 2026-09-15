# BLOODSTREAM — ANIMATION, PHYSICS & DAMAGE PRESENTATION

Status: DOMAIN AUTHORITY

## Animation thesis
The protagonist, horses, NPCs and objects should feel grounded in weight and intention without sacrificing responsiveness.

## Player locomotion
Support readable starts, stops, turns, slopes, crouch, cover transitions, vaulting, climbing and contextual hand contacts. Input responsiveness has priority over decorative inertia.

## Weapon handling
Draw, holster, aim, reload, inspect and maintenance animations reflect the specific weapon class and current state. Reload state persists when interrupted where technically practical.

## Interaction animation
High-frequency interactions need efficient variants. Do not force a five-second animation every time the player opens a drawer, gathers food or mounts a horse.

## NPC physicality
NPCs should transition believably between routine, alert, conversation and conflict states. Motion matching or equivalent UE 5.8 systems may be evaluated, but architecture must permit handcrafted overrides for signature scenes.

## Physics
Use physics for secondary motion, loose props, cloth, doors, hanging objects, wagons and selected world reactions. Gameplay-critical objects need deterministic enough behavior to remain testable.

## Damage presentation
Impacts are readable through animation, sound, posture, clothing/material effects and restrained visual feedback rather than floating numbers. Graphic intensity is user-adjustable.

## Injury states
Selected temporary states can influence gait, aim stability or stamina. They must communicate clearly and never trap the player in long unfun impairment loops.

## Ragdoll / physical reaction
Blend authored hit reactions and physical simulation carefully. Avoid exaggerated launches. Named cinematic moments may use bespoke animation.

## Environmental contact
Feet, hands, coats, saddles and carried items should respond to terrain and movement where budget permits. Prioritize the interactions the player sees constantly.

## Technical rule
Animation systems must degrade gracefully across NPC LOD and crowd tiers. Visual ambition cannot make major settlements CPU-bound.