#pragma once
#include "CoreMinimal.h"
#include "Identity/BloodstreamEntityId.h"
#include "BloodstreamWorldTypes.generated.h"

UENUM(BlueprintType) enum class EBloodstreamBiome : uint8 { Basin, Forest, IndustrialVale, Alpine, Wetland, Mesa, Dustland };
UENUM(BlueprintType) enum class EBloodstreamLandmarkType : uint8 { Settlement, Mine, Rail, Ridge, Water, NaturalFormation, Pass, Structure };
UENUM(BlueprintType) enum class EBloodstreamRoadClass : uint8 { Primary, Secondary, Trail, IndustrialAccess };

USTRUCT(BlueprintType)
struct BLOODSTREAMWORLD_API FBloodstreamRegionDefinition {
 GENERATED_BODY()
 UPROPERTY(EditAnywhere) FBloodstreamEntityId RegionId;
 UPROPERTY(EditAnywhere) FName InternalName;
 UPROPERTY(EditAnywhere) FText DisplayName;
 UPROPERTY(EditAnywhere) EBloodstreamBiome Biome=EBloodstreamBiome::Basin;
 UPROPERTY(EditAnywhere) FName JurisdictionProfile;
 UPROPERTY(EditAnywhere) FName EnvironmentProfile;
 UPROPERTY(EditAnywhere) FName EncounterProfile;
 UPROPERTY(EditAnywhere) FVector Center=FVector::ZeroVector;
 UPROPERTY(EditAnywhere) FVector Extent=FVector(100000.0);
 bool Contains(const FVector& P) const { return FBox::BuildAABB(Center,Extent).IsInsideOrOn(P); }
};

USTRUCT(BlueprintType)
struct BLOODSTREAMWORLD_API FBloodstreamLandmarkDefinition {
 GENERATED_BODY()
 UPROPERTY(EditAnywhere) FBloodstreamEntityId LandmarkId;
 UPROPERTY(EditAnywhere) FBloodstreamEntityId RegionId;
 UPROPERTY(EditAnywhere) FName InternalName;
 UPROPERTY(EditAnywhere) EBloodstreamLandmarkType Type=EBloodstreamLandmarkType::NaturalFormation;
 UPROPERTY(EditAnywhere) FVector ApproximateLocation=FVector::ZeroVector;
 UPROPERTY(EditAnywhere) float NavigationImportance=0.5f;
 UPROPERTY(EditAnywhere) float IntendedVisibilityKm=1.f;
 UPROPERTY(EditAnywhere) bool bDiscoveryEligible=true;
};

USTRUCT(BlueprintType)
struct BLOODSTREAMWORLD_API FBloodstreamRoadDefinition {
 GENERATED_BODY()
 UPROPERTY(EditAnywhere) FBloodstreamEntityId RoadId;
 UPROPERTY(EditAnywhere) FBloodstreamEntityId RegionId;
 UPROPERTY(EditAnywhere) FName InternalName;
 UPROPERTY(EditAnywhere) EBloodstreamRoadClass RoadClass=EBloodstreamRoadClass::Secondary;
 UPROPERTY(EditAnywhere) FVector Start=FVector::ZeroVector;
 UPROPERTY(EditAnywhere) FVector End=FVector::ZeroVector;
 UPROPERTY(EditAnywhere) bool bFutureWagonEligible=false;
 UPROPERTY(EditAnywhere) bool bFutureEncounterEligible=true;
};
