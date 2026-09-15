#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mount/BloodstreamHorseTypes.h"
#include "BloodstreamMountedTravelComponent.generated.h"
class ABloodstreamHorseCharacter;

UCLASS(ClassGroup=(Bloodstream),meta=(BlueprintSpawnableComponent))
class BLOODSTREAMCHARACTER_API UBloodstreamMountedTravelComponent : public UActorComponent {
 GENERATED_BODY()
public:
 UBloodstreamMountedTravelComponent();
 bool Mount(ABloodstreamHorseCharacter* Horse);
 bool Dismount();
 void Move(FVector2D Input);
 void Faster(); void Slower();
 bool IsMounted()const{return MountedHorse.IsValid();}
 ABloodstreamHorseCharacter* GetHorse()const{return MountedHorse.Get();}
private:
 TWeakObjectPtr<ABloodstreamHorseCharacter> MountedHorse;
};
