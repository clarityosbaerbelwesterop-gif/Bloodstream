#include "BloodstreamVersion.h"

FString BloodstreamVersion::Describe()
{
    return FString::Printf(
        TEXT("Bloodstream %s | Target UE %s | Save schema %d"),
        ProjectVersion,
        TargetEngineVersion,
        SaveSchemaVersion);
}
