using UnrealBuildTool;

public class LabelManager : ModuleRules
{
    public LabelManager(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UMG", "Slate", "SlateCore", "MusicLabel" });
        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
