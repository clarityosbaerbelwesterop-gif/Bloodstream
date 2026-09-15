#include "Items/BloodstreamInventoryComponent.h"

bool UBloodstreamInventoryComponent::AddItem(const FBloodstreamOwnedItem& Item)
{
    if (!Item.IsValid() || FindItem(Item.InstanceId)) return false;
    Items.Add(Item); return true;
}
const FBloodstreamOwnedItem* UBloodstreamInventoryComponent::FindItem(FBloodstreamEntityId Id) const { return Items.FindByPredicate([&](const auto& I){ return I.InstanceId == Id; }); }
bool UBloodstreamInventoryComponent::RemoveItem(FBloodstreamEntityId Id, int32 Quantity)
{
    if (Quantity <= 0) return false;
    const int32 Index=Items.IndexOfByPredicate([&](const auto& I){ return I.InstanceId==Id; }); if(Index==INDEX_NONE) return false;
    if (Quantity >= Items[Index].Quantity) Items.RemoveAt(Index); else Items[Index].Quantity -= Quantity; return true;
}
