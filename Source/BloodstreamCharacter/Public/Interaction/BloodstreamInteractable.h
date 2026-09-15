#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interaction/BloodstreamInteractionTypes.h"
#include "BloodstreamInteractable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UBloodstreamInteractable : public UInterface { GENERATED_BODY() };

class BLOODSTREAMCHARACTER_API IBloodstreamInteractable
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable) bool CanInteract(const APawn* Interactor) const;
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable) TArray<FBloodstreamInteractionOption> GetAvailableInteractions(const APawn* Interactor) const;
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable) bool BeginInteraction(APawn* Interactor, EBloodstreamInteractionVerb Verb);
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable) void CompleteInteraction(APawn* Interactor, EBloodstreamInteractionVerb Verb);
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable) void CancelInteraction(APawn* Interactor, EBloodstreamInteractionVerb Verb);
};
