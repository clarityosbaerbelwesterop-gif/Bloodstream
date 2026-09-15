#include "Framework/BloodstreamGameModeBase.h"
#include "BloodstreamWorldLog.h"

void ABloodstreamGameModeBase::StartPlay()
{
    Super::StartPlay();
    UE_LOG(LogBloodstreamWorld, Log, TEXT("Bloodstream M1 game framework StartPlay."));
}
