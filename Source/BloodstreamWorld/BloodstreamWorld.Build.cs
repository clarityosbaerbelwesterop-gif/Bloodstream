using UnrealBuildTool;

public class BloodstreamWorld : ModuleRules
{
    public BloodstreamWorld(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "BloodstreamCore", "BloodstreamCharacter" });
    }
}
