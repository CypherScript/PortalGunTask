// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPS_PracticeCharacter.h"
#include "FPS_PracticeProjectile.h"
#include "Portal.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "FPS_PracticeGameMode.h"
#include <Runtime\Experimental\Chaos\Public\Chaos\DebugDrawQueue.h>

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AFPS_PracticeCharacter

AFPS_PracticeCharacter::AFPS_PracticeCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(0, 0, 0)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

}

void AFPS_PracticeCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
}

//////////////////////////////////////////////////////////////////////////
// Input

void AFPS_PracticeCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire event
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPS_PracticeCharacter::OnFire);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPS_PracticeCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPS_PracticeCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFPS_PracticeCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFPS_PracticeCharacter::LookUpAtRate);
}

void AFPS_PracticeCharacter::OnFire()
{
	//parameters for the ray cast (start, end and hit result)
	FVector start = FP_MuzzleLocation->GetComponentLocation();
	FVector forward = FirstPersonCameraComponent->GetForwardVector();

	//so that the ray cast is always in front of the player
	start = FVector((start.X + (forward.X * 100)/2), (start.Y + (forward.Y * 100)/2), (start.Z + (forward.Z * 100)/2));
	FVector end = start + (forward * 1500);
	FHitResult hit;

	//check to avoid crash
	if (GetWorld())
	{
		//actual ray cast
		bool ActorHit = GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Pawn, FCollisionQueryParams(), FCollisionResponseParams());

		//DrawDebugLine(GetWorld(), start, end, FColor::Red, false, 2, 0, 10);

		//check if the ray cast was succesful and if an actor was hit
		if (ActorHit && hit.GetActor())
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Red, hit.GetActor()->GetFName().ToString());

			//check portal class
			if (PortalClass != NULL)
			{
				//if actor hit has the correct tag
				if (hit.GetActor()->ActorHasTag(FName("PortalWall")))
				{
					//set the rotation and location of the portal to spawn
					const FRotator SpawnRotation = hit.Normal.ToOrientationRotator();
					const FVector SpawnLocation = hit.Location;

					//get the world
					UWorld* const World = GetWorld();

					//get the game mode for the portals array
					AFPS_PracticeGameMode* GM = Cast<AFPS_PracticeGameMode>(UGameplayStatics::GetGameMode(World));

					//find the element in the array that it is null
					int32 IndexOfN = GM->Portals.Find(nullptr);

					//if index is null (there are already two prtals spawned)
					if (IndexOfN == INDEX_NONE)
					{
						//destroy the first portal
						GM->Portals[0]->Destroy();

						//move the second portal to become the first one
						GM->Portals[0] = GM->Portals[1];

						//spawn the portal
						GM->Portals[1] = World->SpawnActor<APortal>(PortalClass, SpawnLocation, SpawnRotation);
					}
					else
					{
						//spawn the portal
						GM->Portals[IndexOfN] = World->SpawnActor<APortal>(PortalClass, SpawnLocation, SpawnRotation);
					}
						
						//World->SpawnActor<APortal>(PortalClass, SpawnLocation, SpawnRotation);
				}
			}
		}
	}

	// try and fire a projectile
	/*if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL)
		{
				const FRotator SpawnRotation = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile at the muzzle
				World->SpawnActor<AFPS_PracticeProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}*/

	// try and play the sound if specified
	/*if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}*/

	// try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}

void AFPS_PracticeCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFPS_PracticeCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFPS_PracticeCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFPS_PracticeCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}
