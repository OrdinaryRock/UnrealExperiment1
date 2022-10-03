// Fill out your copyright notice in the Description page of Project Settings.


#include "SpherePawn.h"
#include "Bullet.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASpherePawn::ASpherePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create all of our components
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	
	CameraArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	CameraArm->SetupAttachment(StaticMesh); // Attach the spring arm to the mesh
	CameraArm->TargetArmLength = 500.f; // The maximum length of the boom arm
	
	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetRelativeLocation(FVector(0.f, 0.f, 0.f)); // Initialize the camera's relative position
	Camera->SetupAttachment(CameraArm); // Attach the camera to the spring arm
	
	// Set the mesh as the root of this actor
	SetRootComponent(StaticMesh);

	// The rotation of this actor will mimic the rotation of the pawn movement controller
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;
}

// Called when the game starts or when spawned
void ASpherePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpherePawn::moveForward(float amount)
{
	FloatingPawnMovement->AddInputVector(GetActorForwardVector() * amount);
}

void ASpherePawn::moveRight(float amount)
{
	FloatingPawnMovement->AddInputVector(GetActorRightVector() * amount);
}

void ASpherePawn::turn(float amount)
{
	AddControllerYawInput(amount);
}

void ASpherePawn::lookUp(float amount)
{
	AddControllerPitchInput(amount);
}

void ASpherePawn::shoot()
{
	if (BulletClass) {
		// Create spawn parameters for the bullet
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;
		SpawnParams.bNoFail = true;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = this;

		// Spawn position for the bullet
		FTransform BulletSpawnTransform;
		BulletSpawnTransform.SetLocation(GetActorForwardVector() * 500.f + GetActorLocation());
		BulletSpawnTransform.SetRotation(GetActorRotation().Quaternion());
		BulletSpawnTransform.SetScale3D(FVector(1.f)); // Probably unnecessary

		// Spawn the bullet into the world
		GetWorld()->SpawnActor<ABullet>(BulletClass, BulletSpawnTransform, SpawnParams);
	}
}

// Called every frame
void ASpherePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpherePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Movement Input
	PlayerInputComponent->BindAxis("MoveForward", this, &ASpherePawn::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASpherePawn::moveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ASpherePawn::turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASpherePawn::lookUp);

	// Action Input
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASpherePawn::shoot);

}

