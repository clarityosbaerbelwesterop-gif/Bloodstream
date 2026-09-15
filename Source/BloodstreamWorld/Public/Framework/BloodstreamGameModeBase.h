#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BloodstreamGameModeBase.generated.h"

/** Minimal framework owner. M2 supplies the native player controller/character spine. */
UCLASS()
class BLOODSTREAMWORLD_API ABloodstreamGameModeBase : public AGameModeBase
{
    GENERATED_BODY()
public:
    ABloodstreamGameModeBase();
    virtual void StartPlay() override;
};
