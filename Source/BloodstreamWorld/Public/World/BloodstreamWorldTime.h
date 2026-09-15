#pragma once
#include "CoreMinimal.h"
#include "BloodstreamWorldTime.generated.h"

USTRUCT(BlueprintType)
struct BLOODSTREAMWORLD_API FBloodstreamWorldTime {
 GENERATED_BODY()
 UPROPERTY(EditAnywhere, SaveGame) double DayFraction=0.35;
 UPROPERTY(EditAnywhere, SaveGame) int32 DayIndex=0;
 UPROPERTY(EditAnywhere) double GameMinutesPerRealSecond=1.0;
 UPROPERTY(EditAnywhere) bool bPaused=false;
 void Advance(double RealSeconds);
 void AdvanceGameMinutes(double Minutes);
};
