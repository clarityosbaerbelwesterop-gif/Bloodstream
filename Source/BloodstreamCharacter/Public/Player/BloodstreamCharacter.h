#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Player/BloodstreamPlayerMode.h"
#include "BloodstreamCharacter.generated.h"
class USpringArmComponent; class UCameraComponent; class UBloodstreamInteractionComponent; class UBloodstreamInventoryComponent; class UBloodstreamEquipmentComponent;

UCLASS()
class BLOODSTREAMCHARACTER_API ABloodstreamCharacter : public ACharacter
{
    GENERATED_BODY()
public:
    ABloodstreamCharacter();
    void Move(const FVector2D& Value); void Look(const FVector2D& Value);
    void SetSprinting(bool bSprint); void ToggleCrouch();
    bool SetPlayerMode(EBloodstreamPlayerMode NewMode); EBloodstreamPlayerMode GetPlayerMode() const { return PlayerMode; }
    UBloodstreamInteractionComponent* GetInteractionComponent() const { return InteractionComponent; }
    UBloodstreamInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }
    UBloodstreamEquipmentComponent* GetEquipmentComponent() const { return EquipmentComponent; }
protected:
    UPROPERTY(VisibleAnywhere) TObjectPtr<USpringArmComponent> CameraBoom;
    UPROPERTY(VisibleAnywhere) TObjectPtr<UCameraComponent> FollowCamera;
    UPROPERTY(VisibleAnywhere) TObjectPtr<UBloodstreamInteractionComponent> InteractionComponent;
    UPROPERTY(VisibleAnywhere) TObjectPtr<UBloodstreamInventoryComponent> InventoryComponent;
    UPROPERTY(VisibleAnywhere) TObjectPtr<UBloodstreamEquipmentComponent> EquipmentComponent;
    UPROPERTY(VisibleInstanceOnly) EBloodstreamPlayerMode PlayerMode = EBloodstreamPlayerMode::FreeMovement;
    UPROPERTY(EditDefaultsOnly, Category="Movement") float WalkSpeed=240.f;
    UPROPERTY(EditDefaultsOnly, Category="Movement") float RunSpeed=390.f;
    UPROPERTY(EditDefaultsOnly, Category="Movement") float SprintSpeed=560.f;
};
