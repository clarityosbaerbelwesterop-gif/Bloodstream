#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interaction/BloodstreamInteractionTypes.h"
#include "BloodstreamInteractionComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FBloodstreamInteractionTargetChanged, AActor*);

UCLASS(ClassGroup=(Bloodstream), meta=(BlueprintSpawnableComponent))
class BLOODSTREAMCHARACTER_API UBloodstreamInteractionComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UBloodstreamInteractionComponent();
    void RefreshTarget();
    bool BeginSelected(EBloodstreamInteractionVerb Verb);
    void CompleteActive();
    void CancelActive();
    AActor* GetSelectedTarget() const { return SelectedTarget.Get(); }
    FBloodstreamInteractionTargetChanged OnTargetChanged;
protected:
    UPROPERTY(EditAnywhere, Category="Interaction") float MaxDistance = 300.f;
    UPROPERTY(EditAnywhere, Category="Interaction") float QueryRadius = 70.f;
    UPROPERTY(EditAnywhere, Category="Interaction") TEnumAsByte<ECollisionChannel> InteractionChannel = ECC_Visibility;
private:
    TWeakObjectPtr<AActor> SelectedTarget;
    TWeakObjectPtr<AActor> ActiveTarget;
    EBloodstreamInteractionVerb ActiveVerb = EBloodstreamInteractionVerb::Use;
};
