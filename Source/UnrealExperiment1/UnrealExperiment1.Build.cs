// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealExperiment1 : ModuleRules
{
	public UnrealExperiment1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
