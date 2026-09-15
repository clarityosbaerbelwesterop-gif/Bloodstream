#include "Framework/BloodstreamWorldFoundationSubsystem.h"
#include "BloodstreamWorldLog.h"

void UBloodstreamWorldFoundationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    const UWorld* World = GetWorld();
    UE_LOG(
        LogBloodstreamWorld,
        Verbose,
        TEXT("World foundation subsystem initialized for %s."),
        World != nullptr ? *World->GetName() : TEXT("<null-world>"));
}

void UBloodstreamWorldFoundationSubsystem::Deinitialize()
{
    UE_LOG(LogBloodstreamWorld, Verbose, TEXT("World foundation subsystem deinitialized."));
    Super::Deinitialize();
}
