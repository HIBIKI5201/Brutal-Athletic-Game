# BrutalAthleticGame Test Suite

This directory contains automated tests for the BrutalAthleticGame project using Unreal Engine's Automation Testing Framework.

## Test Categories

### 1. Configuration Tests (`ConfigurationTests.cpp`)
- **Engine Configuration Test**: Validates default map and game mode settings
- **Rendering Configuration Test**: Verifies ray tracing, Lumen, and virtual shadow map settings

### 2. Game Mode Tests (`GameModeTests.cpp`)
- **GameMode Configuration Test**: Validates BP_ThirdPersonGameMode exists and is properly configured
- **Default Map Configuration Test**: Verifies ThirdPersonMap loads correctly
- **Door Blueprints Existence Test**: Validates BP_Door_A and BP_Door_B exist and are valid Actor subclasses
- **Enemy Blueprints Existence Test**: Validates BP_StraightEnemy exists and is properly configured
- **Invisible Actor Existence Test**: Validates the invisible actor blueprint

### 3. Input System Tests (`InputSystemTests.cpp`)
- **Input Actions Existence Test**: Validates IA_Jump, IA_Look, and IA_Move input actions
- **Input Mapping Context Test**: Verifies IMC_Default mapping context exists

### 4. Functional Tests (`Functional/FunctionalGameplayTests.cpp`)
- **Actor Spawn Test**: Validates blueprint classes can be properly instantiated
- **Blueprint Integrity Test**: Comprehensive check of all blueprint assets

## Running Tests

### From Unreal Editor
1. Open the Session Frontend (Window -> Developer Tools -> Session Frontend)
2. Navigate to the Automation tab
3. Select tests under "BrutalAthleticGame" category
4. Click "Start Tests"

### From Command Line
```bash
# Run all tests
UE5Editor.exe "YourProject.uproject" -ExecCmds="Automation RunTests BrutalAthleticGame" -unattended -nopause -NullRHI -log

# Run specific test category
UE5Editor.exe "YourProject.uproject" -ExecCmds="Automation RunTests BrutalAthleticGame.GameMode" -unattended -nopause -NullRHI -log
```

### From Continuous Integration
```bash
# Generate test report
UE5Editor.exe "YourProject.uproject" -ExecCmds="Automation RunTests BrutalAthleticGame; Quit" -unattended -nopause -NullRHI -ReportOutputPath="TestReports" -log
```

## Test Coverage

### Changed Assets Tested
- ✅ BP_Door_A - Existence and validity
- ✅ BP_Door_B - Existence and validity
- ✅ BP_StraightEnemy - Existence and validity
- ✅ invisible - Existence and validity
- ✅ BP_ThirdPersonGameMode - Configuration and validity
- ✅ ThirdPersonMap - Load validation
- ✅ Input Actions (IA_Jump, IA_Look, IA_Move)
- ✅ Input Mapping Context (IMC_Default)

### Configuration Tested
- ✅ Default map settings
- ✅ Default game mode
- ✅ Rendering settings (Lumen, Ray Tracing, Virtual Shadows)
- ✅ Enhanced Input system

## Adding New Tests

To add new tests:

1. Create a new `.cpp` file in the appropriate directory
2. Include necessary headers:
```cpp
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
```

3. Wrap tests in automation test guards:
```cpp
#if WITH_DEV_AUTOMATION_TESTS
// Your test code here
#endif
```

4. Use the automation test macros:
```cpp
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FYourTestName,
    "BrutalAthleticGame.Category.TestName",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FYourTestName::RunTest(const FString& Parameters)
{
    // Test implementation
    TestTrue(TEXT("Description"), Condition);
    return true;
}
```

## Best Practices

1. **Naming**: Use descriptive test names that clearly indicate what is being tested
2. **Categories**: Organize tests in logical categories (GameMode, Input, Configuration, etc.)
3. **Assertions**: Use appropriate TestTrue, TestFalse, TestEqual, TestNotNull macros
4. **Messages**: Provide clear failure messages for easier debugging
5. **Independence**: Each test should be independent and not rely on other tests
6. **Clean Up**: Ensure tests clean up after themselves (spawn actors, create objects, etc.)

## Troubleshooting

- **Tests not appearing**: Ensure the module is properly compiled and loaded
- **Asset load failures**: Check asset paths are correct (use `/Game/` prefix)
- **CDO access issues**: Some properties may not be accessible from CDO, spawn actual instances instead
- **Threading issues**: Use latent commands for tests that need to wait for game state changes

## Future Enhancements

Potential areas for additional test coverage:
- Collision detection tests for door interactions
- Enemy AI behavior validation
- Character movement and jumping mechanics
- Input binding validation
- Performance benchmarks
- Memory leak detection