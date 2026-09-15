#include "BloodstreamCharacterLog.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(LogBloodstreamCharacter);

class FBloodstreamCharacterModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        UE_LOG(LogBloodstreamCharacter, Log, TEXT("BloodstreamCharacter foundation module initialized; player runtime remains M2 scope."));
    }
};

IMPLEMENT_MODULE(FBloodstreamCharacterModule, BloodstreamCharacter)
