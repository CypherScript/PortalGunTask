// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS_PracticeGameMode.h"
#include "FPS_PracticeHUD.h"
#include "FPS_PracticeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPS_PracticeGameMode::AFPS_PracticeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPS_PracticeHUD::StaticClass();
}
