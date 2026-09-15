#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "BloodstreamWorldFoundationSubsystem.generated.h"

/**
 * Thin world-scoped owner used by M1 to prove subsystem lifetime and logging.
 * It intentionally owns no later-milestone simulation yet.
 */
UCLASS()
class BLOODSTREAMWORLD_API UBloodstreamWorldFoundationSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;
};
