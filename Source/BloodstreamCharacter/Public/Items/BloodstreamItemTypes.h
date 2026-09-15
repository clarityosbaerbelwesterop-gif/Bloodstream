#pragma once

#include "CoreMinimal.h"
#include "Identity/BloodstreamEntityId.h"
#include "BloodstreamItemTypes.generated.h"

USTRUCT(BlueprintType)
struct BLOODSTREAMCHARACTER_API FBloodstreamItemDefinition
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly) FName ItemType;
    UPROPERTY(EditAnywhere, BlueprintReadOnly) FText DisplayName;
    UPROPERTY(EditAnywhere, BlueprintReadOnly) bool bStackable = false;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(ClampMin="1")) int32 MaxStack = 1;
};

USTRUCT(BlueprintType)
struct BLOODSTREAMCHARACTER_API FBloodstreamOwnedItem
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly) FBloodstreamEntityId InstanceId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly) FName ItemType;
    UPROPERTY(EditAnywhere, BlueprintReadOnly) int32 Quantity = 1;
    bool IsValid() const { return InstanceId.IsValid() && !ItemType.IsNone() && Quantity > 0; }
};
