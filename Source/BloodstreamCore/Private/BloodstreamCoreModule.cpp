#include "BloodstreamLog.h"
#include "BloodstreamVersion.h"
#include "Modules/ModuleManager.h"

class FBloodstreamCoreModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        UE_LOG(LogBloodstreamCore, Log, TEXT("%s"), *BloodstreamVersion::Describe());
    }
};

IMPLEMENT_PRIMARY_GAME_MODULE(FBloodstreamCoreModule, BloodstreamCore, "Bloodstream")
