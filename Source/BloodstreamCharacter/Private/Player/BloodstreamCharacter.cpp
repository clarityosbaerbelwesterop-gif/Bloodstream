#include "Player/BloodstreamCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interaction/BloodstreamInteractionComponent.h"
#include "Items/BloodstreamInventoryComponent.h"
#include "Items/BloodstreamEquipmentComponent.h"

ABloodstreamCharacter::ABloodstreamCharacter()
{
    bUseControllerRotationYaw=false; GetCharacterMovement()->bOrientRotationToMovement=true; GetCharacterMovement()->RotationRate=FRotator(0,420,0);
    GetCharacterMovement()->MaxWalkSpeed=RunSpeed; GetCharacterMovement()->MaxAcceleration=900.f; GetCharacterMovement()->BrakingDecelerationWalking=750.f; GetCharacterMovement()->AirControl=.2f; GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch=true;
    CameraBoom=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom")); CameraBoom->SetupAttachment(RootComponent); CameraBoom->TargetArmLength=330.f; CameraBoom->bUsePawnControlRotation=true; CameraBoom->bDoCollisionTest=true; CameraBoom->ProbeSize=14.f; CameraBoom->CameraLagSpeed=14.f; CameraBoom->bEnableCameraLag=true;
    FollowCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera")); FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName); FollowCamera->bUsePawnControlRotation=false; FollowCamera->FieldOfView=75.f;
    InteractionComponent=CreateDefaultSubobject<UBloodstreamInteractionComponent>(TEXT("Interaction")); InventoryComponent=CreateDefaultSubobject<UBloodstreamInventoryComponent>(TEXT("Inventory")); EquipmentComponent=CreateDefaultSubobject<UBloodstreamEquipmentComponent>(TEXT("Equipment"));
}
void ABloodstreamCharacter::Move(const FVector2D& V){ if(PlayerMode!=EBloodstreamPlayerMode::FreeMovement||!Controller)return; const FRotator Yaw(0,Controller->GetControlRotation().Yaw,0); AddMovementInput(FRotationMatrix(Yaw).GetUnitAxis(EAxis::X),V.Y); AddMovementInput(FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y),V.X); }
void ABloodstreamCharacter::Look(const FVector2D& V){ if(PlayerMode==EBloodstreamPlayerMode::Disabled)return; AddControllerYawInput(V.X); AddControllerPitchInput(V.Y); }
void ABloodstreamCharacter::SetSprinting(bool b){ if(PlayerMode!=EBloodstreamPlayerMode::FreeMovement)b=false; GetCharacterMovement()->MaxWalkSpeed=b?SprintSpeed:RunSpeed; }
void ABloodstreamCharacter::ToggleCrouch(){ if(PlayerMode!=EBloodstreamPlayerMode::FreeMovement)return; bIsCrouched?UnCrouch():Crouch(); }
bool ABloodstreamCharacter::SetPlayerMode(EBloodstreamPlayerMode M){ if(PlayerMode==M)return true; if(InteractionComponent&&M==EBloodstreamPlayerMode::FreeMovement) InteractionComponent->CancelActive(); PlayerMode=M; if(M!=EBloodstreamPlayerMode::FreeMovement) SetSprinting(false); return true; }
