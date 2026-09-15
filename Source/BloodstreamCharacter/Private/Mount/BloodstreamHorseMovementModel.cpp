#include "Mount/BloodstreamHorseMovementModel.h"
float FBloodstreamHorseMovementModel::TargetSpeed(EBloodstreamHorseGait G){switch(G){case EBloodstreamHorseGait::Walk:return 180.f;case EBloodstreamHorseGait::Trot:return 360.f;case EBloodstreamHorseGait::Canter:return 560.f;case EBloodstreamHorseGait::Gallop:return 760.f;default:return 0.f;}}
EBloodstreamHorseGait FBloodstreamHorseMovementModel::StepGait(EBloodstreamHorseGait G,int32 D){int32 V=FMath::Clamp((int32)G+(D>0?1:D<0?-1:0),0,(int32)EBloodstreamHorseGait::Gallop);return (EBloodstreamHorseGait)V;}
float FBloodstreamHorseMovementModel::TerrainSpeedScale(float S,float Sure,bool Water){const float Penalty=FMath::Clamp((FMath::Abs(S)-8.f)/30.f,0.f,.55f)*(1.f-FMath::Clamp(Sure*.25f,0.f,.25f));return FMath::Clamp(1.f-Penalty-(Water?.18f:0.f),.4f,1.f);}
bool FBloodstreamHorseMovementModel::IsSafeDismountSlope(float S){return FMath::Abs(S)<=28.f;}
