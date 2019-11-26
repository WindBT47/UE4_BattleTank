// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float ElevationChange = RelativeSpeed * DegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	float Elevation = RelativeRotation.Pitch+ElevationChange;
	Elevation=FMath::Clamp<float>(Elevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate called: %f"),Elevation)
}
