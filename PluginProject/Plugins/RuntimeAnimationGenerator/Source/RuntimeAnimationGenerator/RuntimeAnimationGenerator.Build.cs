// Some copyright should be here...

using System.IO;
using UnrealBuildTool;

public class RuntimeAnimationGenerator : ModuleRules
{
	public RuntimeAnimationGenerator(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		string ThirdPartyPath = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/"));

        string includePath = Path.Combine(ThirdPartyPath, "include");

        PublicDelayLoadDLLs.Add("zlib1.dll");
        PublicDelayLoadDLLs.Add("pugixml.dll");
        PublicDelayLoadDLLs.Add("assimp-vc143-mt.dll");

        PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "lib", "assimp-vc143-mt.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "lib", "zlib.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "lib", "pugixml.lib"));

        RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries/ThirdParty/assimp-vc143-mt.dll"));
        RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries/ThirdParty/pugixml.dll"));
        RuntimeDependencies.Add(Path.Combine(PluginDirectory, "Binaries/ThirdParty/zlib1.dll"));
        PublicIncludePaths.AddRange(
			new string[] {
				includePath,
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Projects",
				"RawMesh",
				"AssetTools",
				"MeshDescription",
				"StaticMeshDescription",
				"MeshConversion",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
