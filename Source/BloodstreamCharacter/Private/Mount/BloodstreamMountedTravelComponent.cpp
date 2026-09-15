#include "Mount/BloodstreamMountedTravelComponent.h"
#include "Mount/BloodstreamHorseCharacter.h"
#include "Player/BloodstreamCharacter.h"
UBloodstreamMountedTravelComponent::UBloodstreamMountedTravelComponent(){PrimaryComponentTick.bCanEverTick=false;}
bool UBloodstreamMountedTravelComponent::Mount(ABloodstreamHorseCharacter* H){ABloodstreamCharacter* R=Cast<ABloodstreamCharacter>(GetOwner());if(!IsValid(H)||!IsValid(R)||MountedHorse.IsValid()||!H->RequestMount(R))return false;MountedHorse=H;R->SetPlayerMode(EBloodstreamPlayerMode::Mounted);return true;}
bool UBloodstreamMountedTravelComponent::Dismount(){ABloodstreamCharacter* R=Cast<ABloodstreamCharacter>(GetOwner());if(!MountedHorse.IsValid()||!IsValid(R)||!MountedHorse->RequestDismount())return false;MountedHorse.Reset();R->SetPlayerMode(EBloodstreamPlayerMode::FreeMovement);return true;}
void UBloodstreamMountedTravelComponent::Move(FVector2D I){if(MountedHorse.IsValid())MountedHorse->SetMoveInput(I.Y,I.X);}
void UBloodstreamMountedTravelComponent::Faster(){if(MountedHorse.IsValid())MountedHorse->RequestGaitStep(1);}void UBloodstreamMountedTravelComponent::Slower(){if(MountedHorse.IsValid())MountedHorse->RequestGaitStep(-1);}
