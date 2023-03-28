// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NeuralDance : ModuleRules
{
	public NeuralDance(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
