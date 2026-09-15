#pragma once

#include "CoreMinimal.h"
#include "Interaction/BloodstreamInteractionTypes.h"

struct BLOODSTREAMCHARACTER_API FBloodstreamInteractionResolver
{
    static float Score(const FBloodstreamInteractionCandidate& Candidate, float MaxDistance);
    static AActor* Resolve(const TArray<FBloodstreamInteractionCandidate>& Candidates, float MaxDistance);
};
