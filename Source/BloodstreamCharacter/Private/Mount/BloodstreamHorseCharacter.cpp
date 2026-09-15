#include "Mount/BloodstreamHorseCharacter.h"
#include "Mount/BloodstreamHorseMovementModel.h"
#include "Player/BloodstreamCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

ABloodstreamHorseCharacter::ABloodstreamHorseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    GetCharacterMovement()->bOrientRotationToMovement = false;
    GetCharacterMovement()->MaxAcceleration = 650.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 500.f;
}

void ABloodstreamHorseCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if (MountState == EBloodstreamMountState::Mounted)
    {
        if (!Rider.IsValid())
        {
            MountState = EBloodstreamMountState::Unmounted;
            Gait = EBloodstreamHorseGait::Halt;
            return;
        }
        UpdateMountedMovement(DeltaSeconds);
    }
}

bool ABloodstreamHorseCharacter::RequestMount(ABloodstreamCharacter* NewRider)
{
    if (!IsValid(NewRider) || MountState != EBloodstreamMountState::Unmounted || FollowState == EBloodstreamHorseFollowState::Hitched)
    {
        return false;
    }
    Rider = NewRider;
    MountState = EBloodstreamMountState::Mounted;
    Gait = EBloodstreamHorseGait::Walk;
    return true;
}

bool ABloodstreamHorseCharacter::RequestDismount()
{
    if (MountState != EBloodstreamMountState::Mounted)
    {
        return false;
    }
    Rider.Reset();
    MountState = EBloodstreamMountState::Unmounted;
    Gait = EBloodstreamHorseGait::Halt;
    ForwardInput = 0.f;
    TurnInput = 0.f;
    return true;
}

void ABloodstreamHorseCharacter::SetMoveInput(float Forward, float Turn)
{
    ForwardInput = FMath::Clamp(Forward, -1.f, 1.f);
    TurnInput = FMath::Clamp(Turn, -1.f, 1.f);
}

void ABloodstreamHorseCharacter::RequestGaitStep(int32 Direction)
{
    if (MountState != EBloodstreamMountState::Mounted)
    {
        return;
    }
    Gait = FBloodstreamHorseMovementModel::StepGait(Gait, Direction);
}

void ABloodstreamHorseCharacter::SetFollowState(EBloodstreamHorseFollowState NewState)
{
    if (MountState == EBloodstreamMountState::Mounted && NewState == EBloodstreamHorseFollowState::Hitched)
    {
        return;
    }
    FollowState = NewState;
}

void ABloodstreamHorseCharacter::UpdateMountedMovement(float DeltaSeconds)
{
    UCharacterMovementComponent* Movement = GetCharacterMovement();
    Movement->MaxWalkSpeed = FBloodstreamHorseMovementModel::TargetSpeed(Gait) * FMath::Clamp(Definition.AccelerationScale, 0.7f, 1.3f);
    AddMovementInput(GetActorForwardVector(), ForwardInput);

    const float SteeringDegreesPerSecond = 105.f * FBloodstreamHorseMovementModel::SteeringScale(Gait);
    AddActorWorldRotation(FRotator(0.f, TurnInput * SteeringDegreesPerSecond * DeltaSeconds, 0.f));

    OwnedState.StaminaNormalized = FMath::Clamp(
        OwnedState.StaminaNormalized + FBloodstreamHorseMovementModel::StaminaDeltaPerSecond(Gait, Definition.EnduranceScale) * DeltaSeconds,
        0.f,
        1.f);

    if (OwnedState.StaminaNormalized <= 0.03f && Gait == EBloodstreamHorseGait::Gallop)
    {
        Gait = EBloodstreamHorseGait::Canter;
    }
    if (OwnedState.StaminaNormalized <= 0.01f && Gait == EBloodstreamHorseGait::Canter)
    {
        Gait = EBloodstreamHorseGait::Trot;
    }
}
