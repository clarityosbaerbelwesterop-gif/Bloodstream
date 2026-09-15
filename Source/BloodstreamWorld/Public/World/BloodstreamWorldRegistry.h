#pragma once
#include "CoreMinimal.h"
#include "World/BloodstreamWorldTypes.h"

struct BLOODSTREAMWORLD_API FBloodstreamWorldRegistry {
 static const TArray<FBloodstreamRegionDefinition>& Regions();
 static const TArray<FBloodstreamLandmarkDefinition>& Landmarks();
 static const TArray<FBloodstreamRoadDefinition>& Roads();
 static const FBloodstreamRegionDefinition* FindRegion(const FVector& WorldPosition);
 static bool Validate(FString& Error);
};
