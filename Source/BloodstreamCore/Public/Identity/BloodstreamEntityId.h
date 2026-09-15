#pragma once

#include "CoreMinimal.h"
#include "BloodstreamEntityId.generated.h"

/**
 * Stable authored identity for persistent Bloodstream entities.
 *
 * The value is independent of actor path, spawn order, array index and runtime
 * pointer identity so World Partition cells can unload without losing identity.
 */
USTRUCT(BlueprintType)
struct BLOODSTREAMCORE_API FBloodstreamEntityId
{
    GENERATED_BODY()

public:
    FBloodstreamEntityId() = default;
    explicit FBloodstreamEntityId(const FGuid& InValue) : Value(InValue) {}

    /** Tooling/helper factory. Authored assets should generate once and then persist the value. */
    static FBloodstreamEntityId NewId();

    static bool TryParse(const FString& Text, FBloodstreamEntityId& OutId);

    bool IsValid() const { return Value.IsValid(); }
    void Invalidate() { Value.Invalidate(); }
    const FGuid& GetGuid() const { return Value; }
    FString ToString() const;

    bool Serialize(FArchive& Archive);

    friend bool operator==(const FBloodstreamEntityId& A, const FBloodstreamEntityId& B)
    {
        return A.Value == B.Value;
    }

    friend bool operator!=(const FBloodstreamEntityId& A, const FBloodstreamEntityId& B)
    {
        return !(A == B);
    }

private:
    UPROPERTY(EditAnywhere, SaveGame, Category="Bloodstream|Identity")
    FGuid Value;
};

template<>
struct TStructOpsTypeTraits<FBloodstreamEntityId> : TStructOpsTypeTraitsBase2<FBloodstreamEntityId>
{
    enum
    {
        WithSerializer = true
    };
};

FORCEINLINE uint32 GetTypeHash(const FBloodstreamEntityId& Id)
{
    return GetTypeHash(Id.GetGuid());
}
