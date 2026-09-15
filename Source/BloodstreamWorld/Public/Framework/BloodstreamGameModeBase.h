#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BloodstreamGameModeBase.generated.h"

/** Minimal M1 framework owner. M2 owns real player controller/camera/interaction behavior. */
UCLASS()
class BLOODSTREAMWORLD_API ABloodstreamGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    virtual void StartPlay() override;
};
