#include "Mount/BloodstreamHorseCharacter.h"
#include "Mount/BloodstreamHorseMovementModel.h"
#include "Player/BloodstreamCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
ABloodstreamHorseCharacter::ABloodstreamHorseCharacter(){PrimaryActorTick.bCanEverTick=true;GetCharacterMovement()->bOrientRotationToMovement=false;GetCharacterMovement()->MaxAcceleration=650.f;GetCharacterMovement()->BrakingDecelerationWalking=500.f;}
void ABloodstreamHorseCharacter::Tick(float D){Super::Tick(D);if(MountState==EBloodstreamMountState::Mounted)UpdateMountedMovement(D);else if(Rider.IsValid()==false&&MountState!=EBloodstreamMountState::Unmounted)MountState=EBloodstreamMountState::Unmounted;}
bool ABloodstreamHorseCharacter::RequestMount(ABloodstreamCharacter* R){if(!IsValid(R)||MountState!=EBloodstreamMountState::Unmounted||FollowState==EBloodstreamHorseFollowState::Hitched)return false;Rider=R;MountState=EBloodstreamMountState::Mounted;Gait=EBloodstreamHorseGait::Walk;return true;}
bool ABloodstreamHorseCharacter::RequestDismount(){if(MountState!=EBloodstreamMountState::Mounted)return false;Rider.Reset();MountState=EBloodstreamMountState::Unmounted;Gait=EBloodstreamHorseGait::Halt;ForwardInput=TurnInput=0;return true;}
void ABloodstreamHorseCharacter::SetMoveInput(float F,float T){ForwardInput=FMath::Clamp(F,-1.f,1.f);TurnInput=FMath::Clamp(T,-1.f,1.f);}
void ABloodstreamHorseCharacter::RequestGaitStep(int32 D){Gait=FBloodstreamHorseMovementModel::StepGait(Gait,D);}
void ABloodstreamHorseCharacter::SetFollowState(EBloodstreamHorseFollowState S){if(MountState==EBloodstreamMountState::Mounted&&S==EBloodstreamHorseFollowState::Hitched)return;FollowState=S;}
void ABloodstreamHorseCharacter::UpdateMountedMovement(float){const float Speed=FBloodstreamHorseMovementModel::TargetSpeed(Gait)*Definition.AccelerationScale;GetCharacterMovement()->MaxWalkSpeed=Speed;AddMovementInput(GetActorForwardVector(),ForwardInput);AddControllerYawInput(TurnInput*.55f);const float Drain=Gait==EBloodstreamHorseGait::Gallop?.0007f:Gait==EBloodstreamHorseGait::Canter?.00025f:-.00018f;OwnedState.StaminaNormalized=FMath::Clamp(OwnedState.StaminaNormalized-Drain,0.f,1.f);if(OwnedState.StaminaNormalized<=.03f&&Gait==EBloodstreamHorseGait::Gallop)Gait=EBloodstreamHorseGait::Canter;}
