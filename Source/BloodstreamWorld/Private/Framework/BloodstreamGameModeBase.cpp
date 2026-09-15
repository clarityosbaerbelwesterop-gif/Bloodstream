#include "Framework/BloodstreamGameModeBase.h"
#include "BloodstreamWorldLog.h"
#include "Player/BloodstreamCharacter.h"
#include "Player/BloodstreamPlayerController.h"

ABloodstreamGameModeBase::ABloodstreamGameModeBase()
{
    DefaultPawnClass = ABloodstreamCharacter::StaticClass();
    PlayerControllerClass = ABloodstreamPlayerController::StaticClass();
}

void ABloodstreamGameModeBase::StartPlay()
{
    Super::StartPlay();
    UE_LOG(LogBloodstreamWorld, Log, TEXT("Bloodstream game framework StartPlay."));
}
