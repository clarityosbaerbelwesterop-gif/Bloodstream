#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/BloodstreamItemTypes.h"
#include "BloodstreamInventoryComponent.generated.h"

UCLASS(ClassGroup=(Bloodstream), meta=(BlueprintSpawnableComponent))
class BLOODSTREAMCHARACTER_API UBloodstreamInventoryComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    bool AddItem(const FBloodstreamOwnedItem& Item);
    bool RemoveItem(FBloodstreamEntityId InstanceId, int32 Quantity=1);
    const TArray<FBloodstreamOwnedItem>& GetItems() const { return Items; }
    const FBloodstreamOwnedItem* FindItem(FBloodstreamEntityId InstanceId) const;
private:
    UPROPERTY() TArray<FBloodstreamOwnedItem> Items;
};
