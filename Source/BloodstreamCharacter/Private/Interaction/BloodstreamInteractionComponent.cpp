#include "Interaction/BloodstreamInteractionComponent.h"
#include "Interaction/BloodstreamInteractable.h"
#include "Interaction/BloodstreamInteractionResolver.h"
#include "GameFramework/Pawn.h"

UBloodstreamInteractionComponent::UBloodstreamInteractionComponent() { PrimaryComponentTick.bCanEverTick = false; }

void UBloodstreamInteractionComponent::RefreshTarget()
{
    APawn* Pawn = Cast<APawn>(GetOwner()); if (!Pawn || !GetWorld()) return;
    const FVector Start = Pawn->GetPawnViewLocation(); const FVector Forward = Pawn->GetViewRotation().Vector();
    const FVector End = Start + Forward * MaxDistance;
    TArray<FHitResult> Hits; FCollisionQueryParams Params(SCENE_QUERY_STAT(BloodstreamInteraction), false, Pawn);
    GetWorld()->SweepMultiByChannel(Hits, Start, End, FQuat::Identity, InteractionChannel, FCollisionShape::MakeSphere(QueryRadius), Params);
    TArray<FBloodstreamInteractionCandidate> Candidates;
    for (const FHitResult& Hit : Hits)
    {
        AActor* Actor = Hit.GetActor(); if (!IsValid(Actor) || !Actor->GetClass()->ImplementsInterface(UBloodstreamInteractable::StaticClass())) continue;
        if (!IBloodstreamInteractable::Execute_CanInteract(Actor, Pawn)) continue;
        FHitResult Occlusion;
        const bool bBlocked = GetWorld()->LineTraceSingleByChannel(Occlusion, Start, Actor->GetActorLocation(), ECC_Visibility, Params) && Occlusion.GetActor() != Actor;
        if (bBlocked) continue;
        FBloodstreamInteractionCandidate C; C.Actor = Actor; C.Distance = FVector::Distance(Start, Actor->GetActorLocation());
        C.ViewAlignment = FVector::DotProduct(Forward, (Actor->GetActorLocation()-Start).GetSafeNormal());
        const TArray<FBloodstreamInteractionOption> Options = IBloodstreamInteractable::Execute_GetAvailableInteractions(Actor, Pawn);
        for (const auto& Option : Options) C.Priority = FMath::Max(C.Priority, Option.Priority);
        Candidates.Add(C);
    }
    AActor* NewTarget = FBloodstreamInteractionResolver::Resolve(Candidates, MaxDistance);
    if (NewTarget != SelectedTarget.Get()) { SelectedTarget = NewTarget; OnTargetChanged.Broadcast(NewTarget); }
}

bool UBloodstreamInteractionComponent::BeginSelected(EBloodstreamInteractionVerb Verb)
{
    APawn* Pawn = Cast<APawn>(GetOwner()); AActor* Target = SelectedTarget.Get();
    if (!Pawn || !IsValid(Target) || !IBloodstreamInteractable::Execute_CanInteract(Target, Pawn)) return false;
    const auto Options = IBloodstreamInteractable::Execute_GetAvailableInteractions(Target, Pawn);
    if (!Options.ContainsByPredicate([Verb](const auto& O){ return O.Verb == Verb; })) return false;
    if (!IBloodstreamInteractable::Execute_BeginInteraction(Target, Pawn, Verb)) return false;
    ActiveTarget = Target; ActiveVerb = Verb; return true;
}
void UBloodstreamInteractionComponent::CompleteActive(){ if (APawn* P=Cast<APawn>(GetOwner())) if (AActor* T=ActiveTarget.Get()) IBloodstreamInteractable::Execute_CompleteInteraction(T,P,ActiveVerb); ActiveTarget.Reset(); }
void UBloodstreamInteractionComponent::CancelActive(){ if (APawn* P=Cast<APawn>(GetOwner())) if (AActor* T=ActiveTarget.Get()) IBloodstreamInteractable::Execute_CancelInteraction(T,P,ActiveVerb); ActiveTarget.Reset(); }
