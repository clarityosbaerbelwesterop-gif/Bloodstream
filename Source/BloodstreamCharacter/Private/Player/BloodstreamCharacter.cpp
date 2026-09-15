#include "Player/BloodstreamCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interaction/BloodstreamInteractionComponent.h"
#include "Items/BloodstreamInventoryComponent.h"
#include "Items/BloodstreamEquipmentComponent.h"

ABloodstreamCharacter::ABloodstreamCharacter()
{
    bUseControllerRotationYaw = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 420.f, 0.f);
    GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
    GetCharacterMovement()->MaxAcceleration = 900.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 750.f;
    GetCharacterMovement()->AirControl = .2f;
    GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;

    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 330.f;
    CameraBoom->bUsePawnControlRotation = true;
    CameraBoom->bDoCollisionTest = true;
    CameraBoom->ProbeSize = 14.f;
    CameraBoom->bEnableCameraLag = true;
    CameraBoom->CameraLagSpeed = 14.f;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;
    FollowCamera->FieldOfView = 75.f;

    InteractionComponent = CreateDefaultSubobject<UBloodstreamInteractionComponent>(TEXT("Interaction"));
    InventoryComponent = CreateDefaultSubobject<UBloodstreamInventoryComponent>(TEXT("Inventory"));
    EquipmentComponent = CreateDefaultSubobject<UBloodstreamEquipmentComponent>(TEXT("Equipment"));
}

void ABloodstreamCharacter::Move(const FVector2D& Value)
{
    if (PlayerMode != EBloodstreamPlayerMode::FreeMovement || !Controller) return;
    const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
    AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Value.Y);
    AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y), Value.X);
}

void ABloodstreamCharacter::Look(const FVector2D& Value)
{
    if (PlayerMode == EBloodstreamPlayerMode::Disabled) return;
    AddControllerYawInput(Value.X);
    AddControllerPitchInput(Value.Y);
}

void ABloodstreamCharacter::SetSprinting(bool bSprint)
{
    if (PlayerMode != EBloodstreamPlayerMode::FreeMovement) bSprint = false;
    GetCharacterMovement()->MaxWalkSpeed = bSprint ? SprintSpeed : RunSpeed;
}

void ABloodstreamCharacter::ToggleCrouch()
{
    if (PlayerMode != EBloodstreamPlayerMode::FreeMovement) return;
    bIsCrouched ? UnCrouch() : Crouch();
}

bool ABloodstreamCharacter::SetPlayerMode(EBloodstreamPlayerMode NewMode)
{
    if (PlayerMode == NewMode) return true;
    if (InteractionComponent && NewMode == EBloodstreamPlayerMode::FreeMovement) InteractionComponent->CancelActive();
    PlayerMode = NewMode;
    if (NewMode != EBloodstreamPlayerMode::FreeMovement) SetSprinting(false);
    return true;
}
