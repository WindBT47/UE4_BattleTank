// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::AimAt(FVector Hitlocation, float LaughSpeed)
{
	if (!Barrel)
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
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)//Calculate The OutLaughVelocity
	{
		FVector AimDirection = OutLaughVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f Aiming solution found at %s"), Time,*Hitlocation.ToString())
	}
	else
	{
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f No Aiming solution found"), Time)
	}
}
void UTankAimingComponent::SetBarrelRefrence(UTankBarrel* BarrelToSet)
{
	this->Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//TODO Work-out Difference Between the current Barrel & AimDirection
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;
	
	//TODO Move the Barrel right amount in this frame
	Barrel->Elevate(5);
	//TODO Given a max elevation speed & the frame time
}
