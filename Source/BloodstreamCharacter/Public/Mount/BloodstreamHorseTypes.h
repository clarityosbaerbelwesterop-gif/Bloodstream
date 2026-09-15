#pragma once
#include "CoreMinimal.h"
#include "Identity/BloodstreamEntityId.h"
#include "BloodstreamHorseTypes.generated.h"

UENUM(BlueprintType) enum class EBloodstreamHorseGait : uint8 { Halt, Walk, Trot, Canter, Gallop };
UENUM(BlueprintType) enum class EBloodstreamHorseTemperament : uint8 { Steady, Alert, Spirited };
UENUM(BlueprintType) enum class EBloodstreamMountState : uint8 { Unmounted, Approaching, Mounting, Mounted, Dismounting };
UENUM(BlueprintType) enum class EBloodstreamHorseFollowState : uint8 { Stay, Follow, CatchUp, Hitched };

USTRUCT(BlueprintType)
struct BLOODSTREAMCHARACTER_API FBloodstreamHorseDefinition {
 GENERATED_BODY()
 UPROPERTY(EditAnywhere) FName HorseType;
 UPROPERTY(EditAnywhere) EBloodstreamHorseTemperament Temperament=EBloodstreamHorseTemperament::Steady;
 UPROPERTY(EditAnywhere) float AccelerationScale=1.f;
 UPROPERTY(EditAnywhere) float EnduranceScale=1.f;
 UPROPERTY(EditAnywhere) float SureFootedness=1.f;
 UPROPERTY(EditAnywhere) float SizeScale=1.f;
};

USTRUCT(BlueprintType)
struct BLOODSTREAMCHARACTER_API FBloodstreamOwnedHorseState {
 GENERATED_BODY()
 UPROPERTY(EditAnywhere,SaveGame) FBloodstreamEntityId HorseId;
 UPROPERTY(EditAnywhere,SaveGame) FName HorseType;
 UPROPERTY(EditAnywhere,SaveGame) float Familiarity=0.f;
 UPROPERTY(EditAnywhere,SaveGame) float StaminaNormalized=1.f;
 UPROPERTY(EditAnywhere,SaveGame) FName SaddleType;
 UPROPERTY(EditAnywhere,SaveGame) TArray<FBloodstreamEntityId> SaddleBagItems;
};
