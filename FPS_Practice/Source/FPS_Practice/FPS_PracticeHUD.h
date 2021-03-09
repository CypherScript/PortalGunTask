// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPS_PracticeHUD.generated.h"

UCLASS()
class AFPS_PracticeHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFPS_PracticeHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

