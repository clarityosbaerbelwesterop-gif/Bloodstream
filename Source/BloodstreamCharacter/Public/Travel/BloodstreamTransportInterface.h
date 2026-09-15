#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BloodstreamTransportInterface.generated.h"
UINTERFACE(BlueprintType) class BLOODSTREAMCHARACTER_API UBloodstreamTransportInterface:public UInterface{GENERATED_BODY()};
class BLOODSTREAMCHARACTER_API IBloodstreamTransportInterface { GENERATED_BODY() public:
 UFUNCTION(BlueprintNativeEvent,BlueprintCallable) bool CanBoard(AActor* Traveler) const;
 UFUNCTION(BlueprintNativeEvent,BlueprintCallable) bool BeginBoard(AActor* Traveler);
 UFUNCTION(BlueprintNativeEvent,BlueprintCallable) bool CompleteBoard(AActor* Traveler);
 UFUNCTION(BlueprintNativeEvent,BlueprintCallable) bool RequestExit(AActor* Traveler);
};
