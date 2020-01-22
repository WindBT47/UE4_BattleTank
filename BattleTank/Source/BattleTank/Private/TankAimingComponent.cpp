// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurrent.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UTankAimingComponent::BeginPlay()
{
	LastFireTime = FPlatformTime::Seconds();
}

void UTankAimingComponent::Initialise(UTankBarrel* TankBarrel, UTankTurrent* TankTurrent)
{
	Barrel = TankBarrel;
	Turrent = TankTurrent;
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FiringState = EFiringState::Reloading;
	}
	else
		if (IsBarrelMoving())
		{
			FiringState = EFiringState::Aiming;
		}
		else
		{
			FiringState = EFiringState::Locked;
	    }
}

void UTankAimingComponent::AimAt(FVector Hitlocation)
{
	if (!ensure(Barrel))
	{
		return;
	}
	FVector OutLaughVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaughVelocity,
		StartLocation,
		Hitlocation,
		LaughSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)//Calculate The OutLaughVelocity
	{
		AimDirection = OutLaughVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Barrel||Turrent)) { return; }
	//TODO Work-out Difference Between the current Barrel & AimDirection
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator TurrentRotator = Turrent->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator BarrelDeltaRotator = AimAsRotator - BarrelRotator;
	FRotator TurrentDeltaRotator = AimAsRotator - TurrentRotator;
	//TODO Move the Barrel right amount in this frame
	if (TurrentDeltaRotator.Yaw < 180)
	{
		Turrent->Rotate(TurrentDeltaRotator.Yaw);
	}
	else
	{
		Turrent->Rotate(-TurrentDeltaRotator.Yaw);
	}
	Barrel->Elevate(BarrelDeltaRotator.Pitch);
	
}

void UTankAimingComponent::Fire()
{
	if (FiringState != EFiringState::Reloading)
	{
		if (!ensure(Barrel)) { return; }
		if (!ensure(ProjectileBluePrint)) { return; }
		//spaw a projectile in the socket of barrel
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaughProjectile(LaughSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel))
		return false;
	return !Barrel->GetForwardVector().Equals(AimDirection, 0.01);
}