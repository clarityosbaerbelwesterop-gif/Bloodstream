#include "Framework/BloodstreamWorldFoundationSubsystem.h"
#include "BloodstreamWorldLog.h"

void UBloodstreamWorldFoundationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogBloodstreamWorld, Verbose, TEXT("World foundation subsystem initialized for %s."), *GetWorld()->GetName());
}

void UBloodstreamWorldFoundationSubsystem::Deinitialize()
{
    UE_LOG(LogBloodstreamWorld, Verbose, TEXT("World foundation subsystem deinitialized."));
    Super::Deinitialize();
}
