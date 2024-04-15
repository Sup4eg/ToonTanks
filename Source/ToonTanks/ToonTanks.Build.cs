// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class ToonTanks : ModuleRules
{
	public ToonTanks(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
