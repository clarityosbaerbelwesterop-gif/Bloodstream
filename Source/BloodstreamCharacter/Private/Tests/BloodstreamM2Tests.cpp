#if WITH_DEV_AUTOMATION_TESTS
#include "Misc/AutomationTest.h"
#include "Interaction/BloodstreamInteractionResolver.h"
#include "Items/BloodstreamInventoryComponent.h"
#include "Items/BloodstreamEquipmentComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM2ResolverTest,"Bloodstream.M2.Interaction.Resolver",EAutomationTestFlags::EditorContext|EAutomationTestFlags::EngineFilter)
bool FM2ResolverTest::RunTest(const FString&){ FBloodstreamInteractionCandidate Invalid; TestTrue(TEXT("invalid candidate rejected"),FBloodstreamInteractionResolver::Score(Invalid,300.f)<0.f); return true; }

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM2InventoryTest,"Bloodstream.M2.Inventory.Transitions",EAutomationTestFlags::EditorContext|EAutomationTestFlags::EngineFilter)
bool FM2InventoryTest::RunTest(const FString&){ UBloodstreamInventoryComponent* I=NewObject<UBloodstreamInventoryComponent>(); FBloodstreamOwnedItem Item; Item.InstanceId=FBloodstreamEntityId::New(); Item.ItemType=TEXT("M2.TestItem"); Item.Quantity=2; TestTrue(TEXT("add"),I->AddItem(Item)); TestFalse(TEXT("duplicate stable instance rejected"),I->AddItem(Item)); TestTrue(TEXT("remove quantity"),I->RemoveItem(Item.InstanceId,1)); TestEqual(TEXT("remaining"),I->FindItem(Item.InstanceId)->Quantity,1); return true; }

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM2EquipmentTest,"Bloodstream.M2.Equipment.Transitions",EAutomationTestFlags::EditorContext|EAutomationTestFlags::EngineFilter)
bool FM2EquipmentTest::RunTest(const FString&){ UBloodstreamEquipmentComponent* E=NewObject<UBloodstreamEquipmentComponent>(); const auto Id=FBloodstreamEntityId::New(); TestTrue(TEXT("equip"),E->Equip(TEXT("Debug.Hand"),Id)); TestTrue(TEXT("query"),E->GetEquipped(TEXT("Debug.Hand"))==Id); TestTrue(TEXT("unequip"),E->Unequip(TEXT("Debug.Hand"))); return true; }
#endif
