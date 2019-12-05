// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned

// Called to bind functionality to input
void ATank::AimAt(FVector Hitlocation)
{
	TankAimingComponent->AimAt(Hitlocation,LaughSpeed);
}
void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel&&isReloaded)
	{
		//spaw a projectile in the socket of barrel
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaughProjectile(LaughSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}