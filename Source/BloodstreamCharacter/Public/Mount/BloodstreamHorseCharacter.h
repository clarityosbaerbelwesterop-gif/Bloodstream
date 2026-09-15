#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mount/BloodstreamHorseTypes.h"
#include "BloodstreamHorseCharacter.generated.h"
class ABloodstreamCharacter;

UCLASS()
class BLOODSTREAMCHARACTER_API ABloodstreamHorseCharacter : public ACharacter {
 GENERATED_BODY()
public:
 ABloodstreamHorseCharacter();
 virtual void Tick(float DeltaSeconds) override;
 bool RequestMount(ABloodstreamCharacter* Rider);
 bool RequestDismount();
 void SetMoveInput(float Forward,float Turn);
 void RequestGaitStep(int32 Direction);
 void SetFollowState(EBloodstreamHorseFollowState NewState);
 EBloodstreamMountState GetMountState()const{return MountState;}
 EBloodstreamHorseGait GetGait()const{return Gait;}
 ABloodstreamCharacter* GetRider()const{return Rider.Get();}
 const FBloodstreamOwnedHorseState& GetOwnedState()const{return OwnedState;}
private:
 void UpdateMountedMovement(float DeltaSeconds);
 UPROPERTY(EditAnywhere) FBloodstreamHorseDefinition Definition;
 UPROPERTY(EditAnywhere,SaveGame) FBloodstreamOwnedHorseState OwnedState;
 UPROPERTY(VisibleAnywhere) EBloodstreamMountState MountState=EBloodstreamMountState::Unmounted;
 UPROPERTY(VisibleAnywhere) EBloodstreamHorseGait Gait=EBloodstreamHorseGait::Halt;
 UPROPERTY(VisibleAnywhere) EBloodstreamHorseFollowState FollowState=EBloodstreamHorseFollowState::Stay;
 TWeakObjectPtr<ABloodstreamCharacter> Rider;
 float ForwardInput=0.f; float TurnInput=0.f;
};
