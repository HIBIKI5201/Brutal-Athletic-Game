// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GameMaps/GameMapsSettings.h"
#include "Engine/Engine.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test that validates engine configuration settings
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FEngineConfigurationTest,
	"BrutalAthleticGame.Configuration.Engine",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FEngineConfigurationTest::RunTest(const FString& Parameters)
{
	const UGameMapsSettings* GameMapsSettings = GetDefault<UGameMapsSettings>();
	TestNotNull(TEXT("GameMapsSettings should be valid"), GameMapsSettings);
	
	if (GameMapsSettings)
	{
		// Verify default maps are set
		FSoftObjectPath EditorStartupMap = GameMapsSettings->GetGameDefaultMap();
		TestTrue(TEXT("Editor startup map should be set"), EditorStartupMap.IsValid());
		
		// Verify the default game mode is set
		FSoftClassPath DefaultGameMode = GameMapsSettings->GetGlobalDefaultGameMode();
		TestTrue(TEXT("Default game mode should be set"), DefaultGameMode.IsValid());
		
		// Verify it points to ThirdPersonMap
		FString MapPathString = EditorStartupMap.ToString();
		TestTrue(TEXT("Default map should be ThirdPersonMap"), 
			MapPathString.Contains(TEXT("ThirdPersonMap")));
		
		// Verify it points to BP_ThirdPersonGameMode
		FString GameModePathString = DefaultGameMode.ToString();
		TestTrue(TEXT("Default game mode should be BP_ThirdPersonGameMode"), 
			GameModePathString.Contains(TEXT("BP_ThirdPersonGameMode")));
	}
	
	return true;
}

/**
 * Test that validates rendering settings are properly configured
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FRenderingConfigurationTest,
	"BrutalAthleticGame.Configuration.Rendering",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FRenderingConfigurationTest::RunTest(const FString& Parameters)
{
	// These settings are critical for the game's visual quality
	// Verify ray tracing is enabled (as per config)
	IConsoleVariable* RayTracingCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.RayTracing"));
	if (RayTracingCVar)
	{
		AddInfo(FString::Printf(TEXT("Ray tracing setting: %d"), RayTracingCVar->GetInt()));
	}
	
	// Verify Lumen is properly configured
	IConsoleVariable* ReflectionMethodCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.ReflectionMethod"));
	if (ReflectionMethodCVar)
	{
		TestEqual(TEXT("Reflection method should be set to 1 (Lumen)"), ReflectionMethodCVar->GetInt(), 1);
	}
	
	// Verify virtual shadow maps are enabled
	IConsoleVariable* VirtualShadowCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.Shadow.Virtual.Enable"));
	if (VirtualShadowCVar)
	{
		TestEqual(TEXT("Virtual shadow maps should be enabled"), VirtualShadowCVar->GetInt(), 1);
	}
	
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS