#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "BloodstreamPlayerController.generated.h"
class UInputMappingContext; class UInputAction; class ABloodstreamCharacter;

UCLASS()
class BLOODSTREAMCHARACTER_API ABloodstreamPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    ABloodstreamPlayerController();
protected:
    virtual void BeginPlay() override; virtual void SetupInputComponent() override; virtual void PlayerTick(float DeltaSeconds) override;
    UPROPERTY(EditDefaultsOnly,Category="Input") TObjectPtr<UInputMappingContext> DefaultMappingContext;
    UPROPERTY(EditDefaultsOnly,Category="Input") TObjectPtr<UInputAction> MoveAction;
    UPROPERTY(EditDefaultsOnly,Category="Input") TObjectPtr<UInputAction> LookAction;
    UPROPERTY(EditDefaultsOnly,Category="Input") TObjectPtr<UInputAction> SprintAction;
    UPROPERTY(EditDefaultsOnly,Category="Input") TObjectPtr<UInputAction> CrouchAction;
    UPROPERTY(EditDefaultsOnly,Category="Input") TObjectPtr<UInputAction> PrimaryInteractionAction;
    UPROPERTY(EditDefaultsOnly,Category="Input") TObjectPtr<UInputAction> InspectAction;
    UPROPERTY(EditDefaultsOnly,Category="Input") TObjectPtr<UInputAction> CancelAction;
private:
    ABloodstreamCharacter* Character() const;
    void InputMove(const FInputActionValue& V); void InputLook(const FInputActionValue& V); void InputSprintStart(); void InputSprintStop(); void InputCrouch(); void InputPrimary(); void InputInspect(); void InputCancel();
};
