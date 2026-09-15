#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "World/BloodstreamWorldTime.h"
#include "BloodstreamWorldFoundationSubsystem.generated.h"
struct FBloodstreamRegionDefinition;

UCLASS()
class BLOODSTREAMWORLD_API UBloodstreamWorldFoundationSubsystem : public UWorldSubsystem {
 GENERATED_BODY()
public:
 virtual void Initialize(FSubsystemCollectionBase& Collection) override;
 virtual void Deinitialize() override;
 virtual void Tick(float DeltaSeconds);
 bool IsTickable() const { return true; }
 TStatId GetStatId() const;
 const FBloodstreamRegionDefinition* FindRegion(const FVector& WorldPosition) const;
 const FBloodstreamWorldTime& GetWorldTime() const { return WorldTime; }
 void SetTimePaused(bool bPaused){WorldTime.bPaused=bPaused;}
private:
 UPROPERTY() FBloodstreamWorldTime WorldTime;
};
