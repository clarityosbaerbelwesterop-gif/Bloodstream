using UnrealBuildTool;

public class BloodstreamCharacter : ModuleRules
{
    public BloodstreamCharacter(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayTags", "BloodstreamCore"
        });
    }
}
