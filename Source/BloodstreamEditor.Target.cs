using UnrealBuildTool;

public class BloodstreamEditorTarget : TargetRules
{
    public BloodstreamEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        ExtraModuleNames.AddRange(new[]
        {
            "BloodstreamCore",
            "BloodstreamWorld",
            "BloodstreamCharacter"
        });
    }
}
