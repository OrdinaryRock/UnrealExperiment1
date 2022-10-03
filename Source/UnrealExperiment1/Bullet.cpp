// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UnrealExperiment1GameMode.h"
#include "Target.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup the bullet's mesh
	bulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("BulletMesh");
	SetRootComponent(bulletMesh); // Set the mesh to be the root of the actor

	// Setup the bullet's projectile movement
	bulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>("BulletMovement");
	bulletMovement->InitialSpeed = 2000.f;
	bulletMovement->MaxSpeed = 2000.f;

	
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	// When the bullet hits a wall or object or anything, bind a delagate function "OnBulletHit"
	OnActorHit.AddDynamic(this, &ABullet::OnBulletHit);
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnBulletHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (ATarget* Target = Cast<ATarget>(OtherActor)) {
		if (AUnrealExperiment1GameMode* GM = Cast<AUnrealExperiment1GameMode>(GetWorld()->GetAuthGameMode())) {
			GM->OnTargetHit();
		}

		Target->Destroy();
		Destroy();
	}

}

