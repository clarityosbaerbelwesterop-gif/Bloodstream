# LINDSTRIPE BASIN — M3 GREYBOX SOURCE SPECIFICATION

Status: **AUTHORITATIVE M3 EDITOR CONSTRUCTION SPEC / NOT A PLAYABLE REGION**

## Coordinate policy
UE centimeters and Large World Coordinates are authoritative. Lindstripe Basin is centered near logical world origin for early production, with a 12 km east-west by 10 km north-south planning envelope. Persistent identity never derives from coordinates. Future regions extend beyond this envelope without rebasing IDs.

## Macro geography
A broad green-brown creek basin is enclosed by the North Dark Ridge, western pass uplands and gentler eastern rail country. High ground occludes parts of the basin so travel reveals new silhouettes instead of exposing the whole map at once. Drainage falls from north/west tributaries toward the central creek, then south-east out of the basin. Primary roads follow valley grades; the mine road climbs deliberately toward exposed darker rock in the north-west quadrant.

## Reserved footprints
Lindstripe town occupies the central low terrace beside—but above flood level from—the main creek. Main street runs broadly west/east toward the station/rail district. Industrial/service land lies toward rail and mine logistics; future housing expands onto safer higher terraces. The mine sits north-west at the ridge foot with a switchback-capable access corridor. The rail corridor enters from the east, serves town/station, has a freight relationship to the mine, and exits toward future Iron Vale connectivity; exact splines/gradients require Editor terrain validation.

## Water
Main Creek flows NW/central → SE. North Fork and West Fork feed it. The Creek Confluence is a navigation node south-east of town. Planned authored crossings: primary road bridge near town, industrial bridge/ford on mine route, shallow trail ford south of town, and rail bridge/trestle candidate east of the confluence. No final water system is claimed.

## Roads/trails
`WestPassToLindstripe` is the primary regional road. `LindstripeMineRoad` is industrial/wagon-capable. `EasternRailServiceRoad` parallels the rail relationship without becoming a fake rail runtime. `SouthCreekTrail` is narrower wilderness travel. Future horse requirements: avoid sustained extreme grades, provide bridge/turning width and readable switchbacks; runtime dimensions remain playtest targets.

## Macro landmarks
Six initial navigation anchors: Lindstripe town silhouette, basin mine headframe, eastern rail water tower, North Dark Ridge, Creek Confluence and Western Basin Pass. These are functional names where final canon has not named the object; they do not overwrite working canon.

## Navigation/traversal targets — DESIGN ONLY
Town→western basin pass: roughly 5 km route target. Town→mine: roughly 2.5–3.5 km route target. Town→eastern rail edge: roughly 4–5 km. Town→representative wilderness/bounty space: 2–4 km. Landmark-to-landmark road beats should generally arrive every 1–2 km without filler. These are authored scale hypotheses, not measured travel times.

## Profiling route
`ENTRY_WEST_PASS → RIDGE_VIEW → ROAD_DESCENT → TOWN_BRIDGE → LINDSTRIPE_CORE → RAIL_DISTRICT → MINE_ROAD → MINE_HEADFRAME → SOUTH_WILDERNESS_LOOP → CREEK_CONFLUENCE → RETURN_TOWN`.

Future profiler records timestamp, FVector world position (double-backed under UE LWC), region ID, frame time, hitch markers, memory and streaming diagnostics where supported. No measurement rows exist before runtime.

## World Partition / persistence
Create one partitioned persistent world. Player traversal is the principal streaming-source assumption. Loaded actors are not authoritative persistence. Named/persistent world state uses stable records and IDs; no actor path, cell index or coordinate becomes identity.

## Data Layers / HLOD
Use the controlled layer set documented under `Content/World/LindstripeBasin/README.md`. HLOD categories are specified there but are not built. Grid/cell/HLOD values must come from representative vista and traversal profiling, not guesses.

## Editor build procedure when UE 5.8 exists
Create an Open World/World Partition map at the required path; build broad landscape forms; establish drainage before roads; mass town/mine/rail envelopes; create controlled Data Layers; place simple landmark masses; spawn M2 player; walk the full profiling route; test save/reopen, cell streaming, collision and M1/M2 tests; then prototype HLOD and capture real evidence.
