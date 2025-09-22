using UnrealBuildTool;

public class LabelManagerEditor : ModuleRules
{
    public LabelManagerEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UnrealEd", "LabelManager" });
        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
