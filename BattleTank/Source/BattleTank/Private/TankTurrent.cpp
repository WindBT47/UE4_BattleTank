// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurrent.h"

void UTankTurrent::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float RotationChange = RelativeSpeed * DegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	float Rotation = RelativeRotation.Yaw + RotationChange;
	Rotation = FMath::Clamp<float>(Rotation, MinYawDegrees, MaxYawDegrees);
	SetRelativeRotation(FRotator(0, Rotation, 0));
	UE_LOG(LogTemp, Warning, TEXT("Barrel Yaw called: %f"), Rotation)
}