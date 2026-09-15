#include "Mount/BloodstreamHorseMovementModel.h"

float FBloodstreamHorseMovementModel::TargetSpeed(EBloodstreamHorseGait Gait)
{
    switch (Gait)
    {
        case EBloodstreamHorseGait::Walk: return 180.f;
        case EBloodstreamHorseGait::Trot: return 360.f;
        case EBloodstreamHorseGait::Canter: return 560.f;
        case EBloodstreamHorseGait::Gallop: return 760.f;
        default: return 0.f;
    }
}

EBloodstreamHorseGait FBloodstreamHorseMovementModel::StepGait(EBloodstreamHorseGait Current, int32 Direction)
{
    const int32 Step = Direction > 0 ? 1 : Direction < 0 ? -1 : 0;
    return static_cast<EBloodstreamHorseGait>(FMath::Clamp(static_cast<int32>(Current) + Step, 0, static_cast<int32>(EBloodstreamHorseGait::Gallop)));
}

float FBloodstreamHorseMovementModel::TerrainSpeedScale(float SlopeDegrees, float SureFootedness, bool bShallowWater)
{
    const float Trait = FMath::Clamp(SureFootedness, 0.5f, 1.5f);
    const float SlopeSeverity = FMath::Clamp((FMath::Abs(SlopeDegrees) - 8.f) / 30.f, 0.f, 1.f);
    const float SlopePenalty = SlopeSeverity * FMath::Lerp(0.62f, 0.38f, (Trait - 0.5f));
    const float WaterPenalty = bShallowWater ? 0.18f : 0.f;
    return FMath::Clamp(1.f - SlopePenalty - WaterPenalty, 0.35f, 1.f);
}

float FBloodstreamHorseMovementModel::StaminaDeltaPerSecond(EBloodstreamHorseGait Gait, float EnduranceScale)
{
    const float Endurance = FMath::Max(0.5f, EnduranceScale);
    switch (Gait)
    {
        case EBloodstreamHorseGait::Gallop: return -0.042f / Endurance;
        case EBloodstreamHorseGait::Canter: return -0.012f / Endurance;
        case EBloodstreamHorseGait::Trot: return 0.006f * Endurance;
        case EBloodstreamHorseGait::Walk: return 0.014f * Endurance;
        default: return 0.024f * Endurance;
    }
}

float FBloodstreamHorseMovementModel::SteeringScale(EBloodstreamHorseGait Gait)
{
    switch (Gait)
    {
        case EBloodstreamHorseGait::Gallop: return 0.48f;
        case EBloodstreamHorseGait::Canter: return 0.62f;
        case EBloodstreamHorseGait::Trot: return 0.78f;
        default: return 1.f;
    }
}

bool FBloodstreamHorseMovementModel::IsSafeDismountSlope(float SlopeDegrees)
{
    return FMath::Abs(SlopeDegrees) <= 28.f;
}
