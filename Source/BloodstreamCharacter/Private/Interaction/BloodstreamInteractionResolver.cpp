#include "Interaction/BloodstreamInteractionResolver.h"

float FBloodstreamInteractionResolver::Score(const FBloodstreamInteractionCandidate& C, float MaxDistance)
{
    if (!IsValid(C.Actor) || MaxDistance <= 0.f || C.Distance < 0.f || C.Distance > MaxDistance || C.ViewAlignment <= 0.f) return -1.f;
    const float DistanceScore = 1.f - FMath::Clamp(C.Distance / MaxDistance, 0.f, 1.f);
    return C.Priority + DistanceScore * 0.45f + FMath::Clamp(C.ViewAlignment, 0.f, 1.f) * 0.55f;
}

AActor* FBloodstreamInteractionResolver::Resolve(const TArray<FBloodstreamInteractionCandidate>& Candidates, float MaxDistance)
{
    AActor* Best = nullptr; float BestScore = -1.f;
    for (const FBloodstreamInteractionCandidate& Candidate : Candidates)
    {
        const float CandidateScore = Score(Candidate, MaxDistance);
        if (CandidateScore > BestScore) { BestScore = CandidateScore; Best = Candidate.Actor; }
    }
    return Best;
}
