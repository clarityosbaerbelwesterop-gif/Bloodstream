using UnrealBuildTool;

public class BloodstreamCore : ModuleRules
{
    public BloodstreamCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "GameplayTags"
        });
    }
}
