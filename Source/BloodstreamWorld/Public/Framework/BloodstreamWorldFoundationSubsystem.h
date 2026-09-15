#pragma once
#include "CoreMinimal.h"
#include "Subsystems/TickableWorldSubsystem.h"
#include "World/BloodstreamWorldTime.h"
#include "BloodstreamWorldFoundationSubsystem.generated.h"
struct FBloodstreamRegionDefinition;

UCLASS()
class BLOODSTREAMWORLD_API UBloodstreamWorldFoundationSubsystem : public UTickableWorldSubsystem {
 GENERATED_BODY()
public:
 virtual void Initialize(FSubsystemCollectionBase& Collection) override;
 virtual void Deinitialize() override;
 virtual void Tick(float DeltaSeconds) override;
 virtual TStatId GetStatId() const override;
 const FBloodstreamRegionDefinition* FindRegion(const FVector& WorldPosition) const;
 const FBloodstreamWorldTime& GetWorldTime() const { return WorldTime; }
 void SetTimePaused(bool bPaused){WorldTime.bPaused=bPaused;}
private:
 UPROPERTY() FBloodstreamWorldTime WorldTime;
};
