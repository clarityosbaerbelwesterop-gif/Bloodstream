#if WITH_DEV_AUTOMATION_TESTS
#include "Misc/AutomationTest.h"
#include "World/BloodstreamWorldRegistry.h"
#include "World/BloodstreamWorldTime.h"
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM3Registry,"Bloodstream.M3.World.Registry",EAutomationTestFlags::EditorContext|EAutomationTestFlags::EngineFilter)
bool FM3Registry::RunTest(const FString&){FString E;TestTrue(TEXT("registry valid"),FBloodstreamWorldRegistry::Validate(E));TestNotNull(TEXT("origin resolves Lindstripe"),FBloodstreamWorldRegistry::FindRegion(FVector::ZeroVector));TestNull(TEXT("far point fallback null"),FBloodstreamWorldRegistry::FindRegion(FVector(5000000,5000000,0)));return true;}
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FM3Time,"Bloodstream.M3.World.Time",EAutomationTestFlags::EditorContext|EAutomationTestFlags::EngineFilter)
bool FM3Time::RunTest(const FString&){FBloodstreamWorldTime T;T.DayFraction=.99;T.DayIndex=3;T.AdvanceGameMinutes(30);TestEqual(TEXT("day wraps"),T.DayIndex,4);TestTrue(TEXT("fraction wrapped"),T.DayFraction<.1);const double F=T.DayFraction;T.bPaused=true;T.Advance(100);TestEqual(TEXT("pause"),T.DayFraction,F);return true;}
#endif
