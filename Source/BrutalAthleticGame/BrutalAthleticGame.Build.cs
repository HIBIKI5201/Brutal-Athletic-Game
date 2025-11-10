// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BrutalAthleticGame : ModuleRules
{
	public BrutalAthleticGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"EnhancedInput"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		// Enable automation testing support
		if (Target.Configuration != UnrealTargetConfiguration.Shipping)
		{
			PrivateDependencyModuleNames.AddRange(new string[] { 
				"FunctionalTesting",
				"AutomationController"
			});
		}
	}
}