// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPS_PracticeGameMode.generated.h"

UCLASS(minimalapi)
class AFPS_PracticeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFPS_PracticeGameMode();

	//initialize the portals array
	TArray<class APortal*, TInlineAllocator<2>> Portals = { nullptr, nullptr };
};



