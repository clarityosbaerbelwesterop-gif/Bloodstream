#include "Items/BloodstreamEquipmentComponent.h"
bool UBloodstreamEquipmentComponent::Equip(FName Slot, FBloodstreamEntityId ItemId){ if(Slot.IsNone()||!ItemId.IsValid()) return false; Equipped.Add(Slot,ItemId); return true; }
bool UBloodstreamEquipmentComponent::Unequip(FName Slot){ return Equipped.Remove(Slot)>0; }
FBloodstreamEntityId UBloodstreamEquipmentComponent::GetEquipped(FName Slot) const { if(const FBloodstreamEntityId* Id=Equipped.Find(Slot)) return *Id; return {}; }
