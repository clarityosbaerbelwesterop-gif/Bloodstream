# M1 Smoke Map Gate

The required runtime asset is:

`Content/Developer/Smoke/M1_Smoke.umap`

It is intentionally **not fabricated as a text/binary placeholder**. A real `.umap` must be created and saved by an authorized Unreal Engine 5.8 editor, then committed through the repository Git LFS policy.

Minimum map content for M1:

- empty/simple floor and lighting sufficient to load safely;
- `ABloodstreamGameModeBase` active through project defaults or world override;
- no Lindstripe, combat, horse, bounty, final locomotion, or M2 interaction scope;
- map loads without recurring errors;
- BloodstreamCore/World/Character startup logs appear;
- `Bloodstream.M1` automation suite can be executed from the real editor/commandlet environment.

Until this real asset is created and loaded under UE 5.8, the smoke-map acceptance item remains **UNVERIFIED / BLOCKED**.
