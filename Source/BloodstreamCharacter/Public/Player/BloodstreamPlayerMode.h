#pragma once

#include "CoreMinimal.h"
#include "BloodstreamPlayerMode.generated.h"

UENUM(BlueprintType)
enum class EBloodstreamPlayerMode : uint8
{
    FreeMovement,
    Interacting,
    Inspecting,
    Conversation,
    Disabled
};
