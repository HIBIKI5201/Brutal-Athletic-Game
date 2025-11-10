// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test that validates BP_ThirdPersonGameMode is properly configured
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameModeConfigurationTest,
	"BrutalAthleticGame.GameMode.Configuration",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameModeConfigurationTest::RunTest(const FString& Parameters)
{
	// Test that the game mode class path is valid
	FSoftClassPath GameModeClassPath(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonGameMode.BP_ThirdPersonGameMode_C"));
	TestTrue(TEXT("GameMode class path should be valid"), GameModeClassPath.IsValid());
	
	// Verify the asset exists
	UClass* GameModeClass = GameModeClassPath.TryLoadClass<AGameModeBase>();
	TestNotNull(TEXT("GameMode class should load successfully"), GameModeClass);
	
	if (GameModeClass)
	{
		// Verify it's a valid GameMode subclass
		TestTrue(TEXT("Loaded class should be a GameModeBase"), GameModeClass->IsChildOf(AGameModeBase::StaticClass()));
		
		// Create a CDO to verify default properties
		AGameModeBase* GameModeCDO = GameModeClass->GetDefaultObject<AGameModeBase>();
		TestNotNull(TEXT("GameMode CDO should be valid"), GameModeCDO);
	}
	
	return true;
}

/**
 * Test that validates the default map configuration
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FDefaultMapConfigurationTest,
	"BrutalAthleticGame.Maps.DefaultConfiguration",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FDefaultMapConfigurationTest::RunTest(const FString& Parameters)
{
	// Verify ThirdPersonMap exists and is valid
	FSoftObjectPath MapPath(TEXT("/Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap"));
	TestTrue(TEXT("ThirdPersonMap path should be valid"), MapPath.IsValid());
	
	// Check if the map asset exists
	UObject* MapAsset = MapPath.TryLoad();
	TestNotNull(TEXT("ThirdPersonMap should load successfully"), MapAsset);
	
	return true;
}

/**
 * Test suite for door blueprints functionality
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FDoorBlueprintsExistenceTest,
	"BrutalAthleticGame.Actors.Doors.Existence",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FDoorBlueprintsExistenceTest::RunTest(const FString& Parameters)
{
	// Test BP_Door_A exists
	FSoftClassPath DoorAClassPath(TEXT("/Game/ThirdPerson/Blueprints/BP_Door_A.BP_Door_A_C"));
	TestTrue(TEXT("BP_Door_A path should be valid"), DoorAClassPath.IsValid());
	
	UClass* DoorAClass = DoorAClassPath.TryLoadClass<AActor>();
	TestNotNull(TEXT("BP_Door_A should load successfully"), DoorAClass);
	
	if (DoorAClass)
	{
		TestTrue(TEXT("BP_Door_A should be an Actor subclass"), DoorAClass->IsChildOf(AActor::StaticClass()));
	}
	
	// Test BP_Door_B exists
	FSoftClassPath DoorBClassPath(TEXT("/Game/ThirdPerson/Blueprints/BP_Door_B.BP_Door_B_C"));
	TestTrue(TEXT("BP_Door_B path should be valid"), DoorBClassPath.IsValid());
	
	UClass* DoorBClass = DoorBClassPath.TryLoadClass<AActor>();
	TestNotNull(TEXT("BP_Door_B should load successfully"), DoorBClass);
	
	if (DoorBClass)
	{
		TestTrue(TEXT("BP_Door_B should be an Actor subclass"), DoorBClass->IsChildOf(AActor::StaticClass()));
	}
	
	return true;
}

/**
 * Test suite for enemy blueprints
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FEnemyBlueprintsExistenceTest,
	"BrutalAthleticGame.Actors.Enemies.Existence",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FEnemyBlueprintsExistenceTest::RunTest(const FString& Parameters)
{
	// Test BP_StraightEnemy exists
	FSoftClassPath EnemyClassPath(TEXT("/Game/ThirdPerson/Blueprints/BP_StraightEnemy.BP_StraightEnemy_C"));
	TestTrue(TEXT("BP_StraightEnemy path should be valid"), EnemyClassPath.IsValid());
	
	UClass* EnemyClass = EnemyClassPath.TryLoadClass<AActor>();
	TestNotNull(TEXT("BP_StraightEnemy should load successfully"), EnemyClass);
	
	if (EnemyClass)
	{
		TestTrue(TEXT("BP_StraightEnemy should be an Actor subclass"), EnemyClass->IsChildOf(AActor::StaticClass()));
	}
	
	return true;
}

/**
 * Test suite for invisible actor blueprint
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInvisibleActorExistenceTest,
	"BrutalAthleticGame.Actors.Invisible.Existence",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FInvisibleActorExistenceTest::RunTest(const FString& Parameters)
{
	// Test invisible actor exists
	FSoftClassPath InvisibleClassPath(TEXT("/Game/ThirdPerson/Blueprints/invisible.invisible_C"));
	TestTrue(TEXT("invisible actor path should be valid"), InvisibleClassPath.IsValid());
	
	UClass* InvisibleClass = InvisibleClassPath.TryLoadClass<AActor>();
	TestNotNull(TEXT("invisible actor should load successfully"), InvisibleClass);
	
	if (InvisibleClass)
	{
		TestTrue(TEXT("invisible should be an Actor subclass"), InvisibleClass->IsChildOf(AActor::StaticClass()));
	}
	
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS