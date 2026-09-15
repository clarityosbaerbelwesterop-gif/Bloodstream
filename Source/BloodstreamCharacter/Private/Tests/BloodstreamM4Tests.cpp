#if WITH_DEV_AUTOMATION_TESTS
#include "Misc/AutomationTest.h"
#include "Mount/BloodstreamHorseMovementModel.h"
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM4Gait,"Bloodstream.M4.Horse.Gait",EAutomationTestFlags::EditorContext|EAutomationTestFlags::EngineFilter)
bool FM4Gait::RunTest(const FString&){auto G=EBloodstreamHorseGait::Halt;G=FBloodstreamHorseMovementModel::StepGait(G,1);TestEqual(TEXT("halt to walk"),G,EBloodstreamHorseGait::Walk);for(int i=0;i<10;i++)G=FBloodstreamHorseMovementModel::StepGait(G,1);TestEqual(TEXT("upper clamp"),G,EBloodstreamHorseGait::Gallop);G=FBloodstreamHorseMovementModel::StepGait(G,-1);TestEqual(TEXT("gallop to canter"),G,EBloodstreamHorseGait::Canter);return true;}
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM4Terrain,"Bloodstream.M4.Horse.Terrain",EAutomationTestFlags::EditorContext|EAutomationTestFlags::EngineFilter)
bool FM4Terrain::RunTest(const FString&){TestEqual(TEXT("flat full speed"),FBloodstreamHorseMovementModel::TerrainSpeedScale(0,1,false),1.f);TestTrue(TEXT("steep penalized"),FBloodstreamHorseMovementModel::TerrainSpeedScale(35,1,false)<1.f);TestTrue(TEXT("water penalized"),FBloodstreamHorseMovementModel::TerrainSpeedScale(0,1,true)<1.f);TestTrue(TEXT("safe dismount"),FBloodstreamHorseMovementModel::IsSafeDismountSlope(15));TestFalse(TEXT("unsafe dismount"),FBloodstreamHorseMovementModel::IsSafeDismountSlope(40));return true;}
#endif
