// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPS_PracticeCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Portal.generated.h"

UCLASS()
class FPS_PRACTICE_API APortal : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Portal")
	class UBoxComponent* Collision;
	
public:	
	// Sets default values for this actor's properties
	APortal();

	UFUNCTION()
		void EnterPortal(class AActor* overlappedActor, class AActor* otherActor);

	UPROPERTY()
	FTimerHandle DelayHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ResetTeleport();

};
