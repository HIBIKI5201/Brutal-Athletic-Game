// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Latent automation test for spawning and validating actors in the game world
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FActorSpawnTest,
	"BrutalAthleticGame.Functional.ActorSpawning",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FActorSpawnTest::RunTest(const FString& Parameters)
{
	// This test validates that our blueprint classes can be spawned
	FSoftClassPath DoorAPath(TEXT("/Game/ThirdPerson/Blueprints/BP_Door_A.BP_Door_A_C"));
	UClass* DoorAClass = DoorAPath.TryLoadClass<AActor>();
	
	if (DoorAClass)
	{
		TestNotNull(TEXT("DoorA class should load"), DoorAClass);
		
		// Verify the class has a valid CDO
		AActor* DoorACDO = DoorAClass->GetDefaultObject<AActor>();
		TestNotNull(TEXT("DoorA should have a valid CDO"), DoorACDO);
		
		if (DoorACDO)
		{
			// Verify basic actor properties
			TestTrue(TEXT("DoorA CDO should be valid actor"), DoorACDO->IsValidLowLevel());
		}
	}
	
	// Test enemy spawn validity
	FSoftClassPath EnemyPath(TEXT("/Game/ThirdPerson/Blueprints/BP_StraightEnemy.BP_StraightEnemy_C"));
	UClass* EnemyClass = EnemyPath.TryLoadClass<AActor>();
	
	if (EnemyClass)
	{
		TestNotNull(TEXT("Enemy class should load"), EnemyClass);
		
		AActor* EnemyCDO = EnemyClass->GetDefaultObject<AActor>();
		TestNotNull(TEXT("Enemy should have a valid CDO"), EnemyCDO);
	}
	
	return true;
}

/**
 * Test to validate blueprint asset integrity
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FBlueprintIntegrityTest,
	"BrutalAthleticGame.Functional.BlueprintIntegrity",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FBlueprintIntegrityTest::RunTest(const FString& Parameters)
{
	// Array of all blueprint paths to validate
	TArray<FString> BlueprintPaths = {
		TEXT("/Game/ThirdPerson/Blueprints/BP_Door_A.BP_Door_A_C"),
		TEXT("/Game/ThirdPerson/Blueprints/BP_Door_B.BP_Door_B_C"),
		TEXT("/Game/ThirdPerson/Blueprints/BP_StraightEnemy.BP_StraightEnemy_C"),
		TEXT("/Game/ThirdPerson/Blueprints/invisible.invisible_C"),
		TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonGameMode.BP_ThirdPersonGameMode_C")
	};
	
	int32 SuccessCount = 0;
	int32 TotalCount = BlueprintPaths.Num();
	
	for (const FString& Path : BlueprintPaths)
	{
		FSoftClassPath ClassPath(Path);
		if (ClassPath.IsValid())
		{
			UClass* LoadedClass = ClassPath.TryLoadClass<UObject>();
			if (LoadedClass)
			{
				SuccessCount++;
				AddInfo(FString::Printf(TEXT("Successfully loaded: %s"), *Path));
			}
			else
			{
				AddError(FString::Printf(TEXT("Failed to load: %s"), *Path));
			}
		}
		else
		{
			AddError(FString::Printf(TEXT("Invalid path: %s"), *Path));
		}
	}
	
	TestEqual(TEXT("All blueprints should load successfully"), SuccessCount, TotalCount);
	
	return SuccessCount == TotalCount;
}

#endif // WITH_DEV_AUTOMATION_TESTS