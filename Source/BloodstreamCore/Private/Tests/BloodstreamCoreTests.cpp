#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "GameplayTagContainer.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/MemoryWriter.h"
#include "BloodstreamGameplayTags.h"
#include "BloodstreamVersion.h"
#include "Identity/BloodstreamEntityId.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FBloodstreamEntityIdRoundTripTest,
    "Bloodstream.M1.Core.EntityId.RoundTrip",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FBloodstreamEntityIdRoundTripTest::RunTest(const FString& Parameters)
{
    const FBloodstreamEntityId Source = FBloodstreamEntityId::NewId();
    TestTrue(TEXT("new entity ID is valid"), Source.IsValid());

    FBloodstreamEntityId Parsed;
    TestTrue(TEXT("string form parses"), FBloodstreamEntityId::TryParse(Source.ToString(), Parsed));
    TestTrue(TEXT("parsed ID equals source"), Parsed == Source);

    TArray<uint8> Bytes;
    FBloodstreamEntityId Writable = Source;
    FMemoryWriter Writer(Bytes, true);
    Writable.Serialize(Writer);
    Writer.Close();

    FBloodstreamEntityId Loaded;
    FMemoryReader Reader(Bytes, true);
    Loaded.Serialize(Reader);
    Reader.Close();

    TestTrue(TEXT("serialized ID round-trips"), Loaded == Source);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FBloodstreamFoundationConfigTest,
    "Bloodstream.M1.Core.Foundation.Config",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FBloodstreamFoundationConfigTest::RunTest(const FString& Parameters)
{
    TestEqual(TEXT("save schema begins at 1"), BloodstreamVersion::SaveSchemaVersion, 1);
    TestEqual(TEXT("target engine remains 5.8"), FString(BloodstreamVersion::TargetEngineVersion), FString(TEXT("5.8")));

    const FGameplayTag CharacterTag = FGameplayTag::RequestGameplayTag(BloodstreamGameplayTags::CharacterRoot, false);
    const FGameplayTag WorldTag = FGameplayTag::RequestGameplayTag(BloodstreamGameplayTags::WorldRoot, false);
    const FGameplayTag StateTag = FGameplayTag::RequestGameplayTag(BloodstreamGameplayTags::StateRoot, false);
    const FGameplayTag InteractionTag = FGameplayTag::RequestGameplayTag(BloodstreamGameplayTags::InteractionRoot, false);

    TestTrue(TEXT("Character root tag registered"), CharacterTag.IsValid());
    TestTrue(TEXT("World root tag registered"), WorldTag.IsValid());
    TestTrue(TEXT("State root tag registered"), StateTag.IsValid());
    TestTrue(TEXT("Interaction root tag registered"), InteractionTag.IsValid());
    return true;
}

#endif
