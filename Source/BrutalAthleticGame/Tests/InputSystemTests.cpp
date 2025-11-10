// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "InputAction.h"
#include "InputMappingContext.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Test that validates Enhanced Input system configuration
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInputActionsExistenceTest,
	"BrutalAthleticGame.Input.Actions.Existence",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FInputActionsExistenceTest::RunTest(const FString& Parameters)
{
	// Test IA_Jump exists
	FSoftObjectPath JumpActionPath(TEXT("/Game/ThirdPerson/Input/Actions/IA_Jump.IA_Jump"));
	TestTrue(TEXT("IA_Jump path should be valid"), JumpActionPath.IsValid());
	
	UObject* JumpAction = JumpActionPath.TryLoad();
	TestNotNull(TEXT("IA_Jump should load successfully"), JumpAction);
	
	// Test IA_Look exists
	FSoftObjectPath LookActionPath(TEXT("/Game/ThirdPerson/Input/Actions/IA_Look.IA_Look"));
	TestTrue(TEXT("IA_Look path should be valid"), LookActionPath.IsValid());
	
	UObject* LookAction = LookActionPath.TryLoad();
	TestNotNull(TEXT("IA_Look should load successfully"), LookAction);
	
	// Test IA_Move exists
	FSoftObjectPath MoveActionPath(TEXT("/Game/ThirdPerson/Input/Actions/IA_Move.IA_Move"));
	TestTrue(TEXT("IA_Move path should be valid"), MoveActionPath.IsValid());
	
	UObject* MoveAction = MoveActionPath.TryLoad();
	TestNotNull(TEXT("IA_Move should load successfully"), MoveAction);
	
	return true;
}

/**
 * Test that validates Input Mapping Context
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FInputMappingContextTest,
	"BrutalAthleticGame.Input.MappingContext.Existence",
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FInputMappingContextTest::RunTest(const FString& Parameters)
{
	// Test IMC_Default exists
	FSoftObjectPath IMCPath(TEXT("/Game/ThirdPerson/Input/IMC_Default.IMC_Default"));
	TestTrue(TEXT("IMC_Default path should be valid"), IMCPath.IsValid());
	
	UObject* IMC = IMCPath.TryLoad();
	TestNotNull(TEXT("IMC_Default should load successfully"), IMC);
	
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS