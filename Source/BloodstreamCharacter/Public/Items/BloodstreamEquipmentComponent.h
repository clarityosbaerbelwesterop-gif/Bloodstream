#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Identity/BloodstreamEntityId.h"
#include "BloodstreamEquipmentComponent.generated.h"

UCLASS(ClassGroup=(Bloodstream), meta=(BlueprintSpawnableComponent))
class BLOODSTREAMCHARACTER_API UBloodstreamEquipmentComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    bool Equip(FName Slot, FBloodstreamEntityId ItemId);
    bool Unequip(FName Slot);
    FBloodstreamEntityId GetEquipped(FName Slot) const;
private:
    UPROPERTY() TMap<FName, FBloodstreamEntityId> Equipped;
};
