#pragma once

#include "CoreMinimal.h"

namespace BloodstreamVersion
{
    inline constexpr int32 SaveSchemaVersion = 1;
    inline constexpr const TCHAR* TargetEngineVersion = TEXT("5.8");
    inline constexpr const TCHAR* ProjectVersion = TEXT("0.1.0-m1");

    BLOODSTREAMCORE_API FString Describe();
}
