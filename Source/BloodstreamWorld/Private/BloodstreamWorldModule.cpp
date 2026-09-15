#include "BloodstreamWorldLog.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(LogBloodstreamWorld);

class FBloodstreamWorldModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        UE_LOG(LogBloodstreamWorld, Log, TEXT("BloodstreamWorld foundation module initialized."));
    }
};

IMPLEMENT_GAME_MODULE(FBloodstreamWorldModule, BloodstreamWorld);
