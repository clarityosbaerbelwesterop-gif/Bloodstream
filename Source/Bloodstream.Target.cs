using UnrealBuildTool;

public class BloodstreamTarget : TargetRules
{
    public BloodstreamTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        ExtraModuleNames.AddRange(new[]
        {
            "BloodstreamCore",
            "BloodstreamWorld",
            "BloodstreamCharacter"
        });
    }
}
