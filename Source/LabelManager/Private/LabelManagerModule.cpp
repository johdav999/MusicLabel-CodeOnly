#include "Modules/ModuleManager.h"
#include "Style/LabelUIStyle.h"

class FLabelManagerModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        FLabelUIStyle::Initialize();
    }
    virtual void ShutdownModule() override
    {
        FLabelUIStyle::Shutdown();
    }
};

IMPLEMENT_MODULE(FLabelManagerModule, LabelManager);
