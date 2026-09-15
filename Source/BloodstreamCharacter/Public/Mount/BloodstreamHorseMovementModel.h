#pragma once
#include "CoreMinimal.h"
#include "Mount/BloodstreamHorseTypes.h"

struct BLOODSTREAMCHARACTER_API FBloodstreamHorseMovementModel
{
    static float TargetSpeed(EBloodstreamHorseGait Gait);
    static EBloodstreamHorseGait StepGait(EBloodstreamHorseGait Current, int32 Direction);
    static float TerrainSpeedScale(float SlopeDegrees, float SureFootedness, bool bShallowWater);
    static float StaminaDeltaPerSecond(EBloodstreamHorseGait Gait, float EnduranceScale);
    static float SteeringScale(EBloodstreamHorseGait Gait);
    static bool IsSafeDismountSlope(float SlopeDegrees);
};
