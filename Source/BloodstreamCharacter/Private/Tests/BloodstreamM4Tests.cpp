#if WITH_DEV_AUTOMATION_TESTS
#include "Misc/AutomationTest.h"
#include "Mount/BloodstreamHorseMovementModel.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM4Gait, "Bloodstream.M4.Horse.Gait", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FM4Gait::RunTest(const FString&)
{
    auto Gait = EBloodstreamHorseGait::Halt;
    Gait = FBloodstreamHorseMovementModel::StepGait(Gait, 1);
    TestEqual(TEXT("halt to walk"), Gait, EBloodstreamHorseGait::Walk);
    for (int32 Index = 0; Index < 10; ++Index) Gait = FBloodstreamHorseMovementModel::StepGait(Gait, 1);
    TestEqual(TEXT("upper clamp"), Gait, EBloodstreamHorseGait::Gallop);
    Gait = FBloodstreamHorseMovementModel::StepGait(Gait, -1);
    TestEqual(TEXT("gallop to canter"), Gait, EBloodstreamHorseGait::Canter);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM4Terrain, "Bloodstream.M4.Horse.Terrain", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FM4Terrain::RunTest(const FString&)
{
    TestEqual(TEXT("flat full speed"), FBloodstreamHorseMovementModel::TerrainSpeedScale(0.f, 1.f, false), 1.f);
    TestTrue(TEXT("steep penalized"), FBloodstreamHorseMovementModel::TerrainSpeedScale(35.f, 1.f, false) < 1.f);
    TestTrue(TEXT("water penalized"), FBloodstreamHorseMovementModel::TerrainSpeedScale(0.f, 1.f, true) < 1.f);
    TestTrue(TEXT("sure-footed horse retains more speed"), FBloodstreamHorseMovementModel::TerrainSpeedScale(35.f, 1.4f, false) > FBloodstreamHorseMovementModel::TerrainSpeedScale(35.f, 0.6f, false));
    TestTrue(TEXT("safe dismount"), FBloodstreamHorseMovementModel::IsSafeDismountSlope(15.f));
    TestFalse(TEXT("unsafe dismount"), FBloodstreamHorseMovementModel::IsSafeDismountSlope(40.f));
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM4Stamina, "Bloodstream.M4.Horse.Stamina", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FM4Stamina::RunTest(const FString&)
{
    TestTrue(TEXT("gallop drains"), FBloodstreamHorseMovementModel::StaminaDeltaPerSecond(EBloodstreamHorseGait::Gallop, 1.f) < 0.f);
    TestTrue(TEXT("walk recovers"), FBloodstreamHorseMovementModel::StaminaDeltaPerSecond(EBloodstreamHorseGait::Walk, 1.f) > 0.f);
    TestTrue(TEXT("better endurance reduces gallop drain"), FMath::Abs(FBloodstreamHorseMovementModel::StaminaDeltaPerSecond(EBloodstreamHorseGait::Gallop, 1.4f)) < FMath::Abs(FBloodstreamHorseMovementModel::StaminaDeltaPerSecond(EBloodstreamHorseGait::Gallop, 0.7f)));
    TestTrue(TEXT("gallop turns wider"), FBloodstreamHorseMovementModel::SteeringScale(EBloodstreamHorseGait::Gallop) < FBloodstreamHorseMovementModel::SteeringScale(EBloodstreamHorseGait::Walk));
    return true;
}
#endif
