// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal.h"
#include "FPS_PracticeGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "FPS_PracticeCharacter.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "FPS_PracticeCharacter.h"
#include "Components/BoxComponent.h"

// Sets default values
APortal::APortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	Collision->InitBoxExtent(FVector(100.f));
	//Collision->bGenerateOverlapEvents = true; 
	RootComponent = Collision;

	//bind the collision action
	OnActorBeginOverlap.AddDynamic(this, &APortal::EnterPortal);
}

// Called when the game starts or when spawned
void APortal::BeginPlay()
{
	Super::BeginPlay();
	
}

void APortal::EnterPortal(AActor* overlappedActor, AActor* otherActor)
{
	//get the world
	UWorld* const World = GetWorld();

	//get the game mode
	AFPS_PracticeGameMode* GM = Cast<AFPS_PracticeGameMode>(UGameplayStatics::GetGameMode(World));

	//get the index of the portals array
	int32 IndexOfThis = GM->Portals.Find(this);

	//get the character
	AFPS_PracticeCharacter* character = Cast<AFPS_PracticeCharacter>(UGameplayStatics::GetPlayerCharacter(World, 0));

	//initialize vectors for velocity
	FVector SavedVelocity, Dots, NewVelocity;

	//get the current velocity of the character
	SavedVelocity = character->GetCharacterMovement()->Velocity;

	//dot product to get the direction of the character
	Dots.X = FVector::DotProduct(SavedVelocity, character->GetActorForwardVector());
	Dots.Y = FVector::DotProduct(SavedVelocity, character->GetActorRightVector());
	Dots.Z = FVector::DotProduct(SavedVelocity, character->GetActorUpVector());

	//check if cast of character was succesful, check that the index for the array is not null, and check if the character can teleport
	if ((otherActor == character) && (IndexOfThis != INDEX_NONE) && (character->bCanTeleport))
	{
		//check if the index is 0 (the player collides with the first portal), check if the second element in the array (the other portal) is not null
		if ((IndexOfThis == 0) && (GM->Portals[1] != nullptr))
		{
			//set the bool to false (so as not to create an infinite loop)
			character->bCanTeleport = false;

			//calculate the new velocity and direction for the player by using its direction with the new portal's direction
			NewVelocity = (Dots.X * GM->Portals[1]->GetActorForwardVector() + Dots.Y * GM->Portals[1]->GetActorRightVector() + Dots.Z * GM->Portals[1]->GetActorUpVector());

			//set the timer for the bool
			GetWorldTimerManager().SetTimer(DelayHandle, this, &APortal::ResetTeleport, 0.05f, false);

			//teleport the character
			character->SetActorLocation(GM->Portals[1]->GetActorLocation());

			//adjust the character's rotation
			character->SetActorRotation(GM->Portals[1]->GetActorRotation());

			character->GetController()->SetControlRotation(character->GetActorRotation());

			//apply the velocity to the player
			character->GetCharacterMovement()->Velocity = NewVelocity;

		}

		//check if the index is 1 (the player is colliding with the second portal) and check if the first portal is not null
		else if ((IndexOfThis == 1) && (GM->Portals[0] != nullptr))
		{
			//set the bool to false
			character->bCanTeleport = false; 

			//calculate new velocity
			NewVelocity = (Dots.X * GM->Portals[0]->GetActorForwardVector()) + (Dots.Y * GM->Portals[0]->GetActorRightVector()) + (Dots.Z * GM->Portals[0]->GetActorUpVector());

			//set timer for bool
			GetWorldTimerManager().SetTimer(DelayHandle, this, &APortal::ResetTeleport, 0.05f, false);

			//teleport the character
			character->SetActorLocation(GM->Portals[0]->GetActorLocation());

			//set the new rotation to the character
			character->SetActorRotation(GM->Portals[0]->GetActorRotation());

			character->GetController()->SetControlRotation(character->GetActorRotation());

			//apply new velocity
			character->GetCharacterMovement()->Velocity = NewVelocity;
		}
	}
}

//reset the timer and the teleport bool to true
void APortal::ResetTeleport()
{
	AFPS_PracticeCharacter* character = Cast<AFPS_PracticeCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	GetWorldTimerManager().ClearTimer(DelayHandle);

	if (character)
	{
		character->bCanTeleport = true;
	}
}

