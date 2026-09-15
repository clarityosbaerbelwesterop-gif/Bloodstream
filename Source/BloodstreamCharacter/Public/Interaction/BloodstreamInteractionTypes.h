#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BloodstreamInteractionTypes.generated.h"

UENUM(BlueprintType)
enum class EBloodstreamInteractionVerb : uint8 { Use, Inspect, Talk, Take };

USTRUCT(BlueprintType)
struct BLOODSTREAMCHARACTER_API FBloodstreamInteractionOption
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly) EBloodstreamInteractionVerb Verb = EBloodstreamInteractionVerb::Use;
    UPROPERTY(EditAnywhere, BlueprintReadOnly) FText ActionLabel;
    UPROPERTY(EditAnywhere, BlueprintReadOnly) FText TargetLabel;
    UPROPERTY(EditAnywhere, BlueprintReadOnly) float Priority = 0.f;
};

USTRUCT()
struct BLOODSTREAMCHARACTER_API FBloodstreamInteractionCandidate
{
    GENERATED_BODY()
    UPROPERTY() TObjectPtr<AActor> Actor = nullptr;
    UPROPERTY() float Distance = 0.f;
    UPROPERTY() float ViewAlignment = 0.f;
    UPROPERTY() float Priority = 0.f;
};
