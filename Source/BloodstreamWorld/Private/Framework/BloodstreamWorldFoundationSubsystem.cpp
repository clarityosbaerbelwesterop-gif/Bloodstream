#include "Framework/BloodstreamWorldFoundationSubsystem.h"
#include "BloodstreamWorldLog.h"
#include "World/BloodstreamWorldRegistry.h"
#include "Stats/Stats.h"
void UBloodstreamWorldFoundationSubsystem::Initialize(FSubsystemCollectionBase& Collection){Super::Initialize(Collection);FString Error;UE_LOG(LogBloodstreamWorld,Log,TEXT("World foundation initialized. Registry=%s"),FBloodstreamWorldRegistry::Validate(Error)?TEXT("valid"):*Error);}
void UBloodstreamWorldFoundationSubsystem::Deinitialize(){UE_LOG(LogBloodstreamWorld,Log,TEXT("World foundation deinitialized."));Super::Deinitialize();}
void UBloodstreamWorldFoundationSubsystem::Tick(float DeltaSeconds){WorldTime.Advance(DeltaSeconds);}
TStatId UBloodstreamWorldFoundationSubsystem::GetStatId() const { RETURN_QUICK_DECLARE_CYCLE_STAT(UBloodstreamWorldFoundationSubsystem,STATGROUP_Tickables); }
const FBloodstreamRegionDefinition* UBloodstreamWorldFoundationSubsystem::FindRegion(const FVector&P) const{return FBloodstreamWorldRegistry::FindRegion(P);}
