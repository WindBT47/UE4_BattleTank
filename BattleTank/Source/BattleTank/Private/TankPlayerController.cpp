// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "BattleTank.h"


void  ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(TankAimingComponent))
	{
		FoundAimingComponent(TankAimingComponent);
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowordsCrosshair();
}
void ATankPlayerController::AimTowordsCrosshair()
{
	auto TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(TankAimingComponent))
	{
		return;
	}
	FVector Hitlocation;
	if (GetSightRayLocation(Hitlocation))
	{
		TankAimingComponent->AimAt(Hitlocation);
	}
}

bool ATankPlayerController::GetSightRayLocation(FVector& HitLocation) const
{
	//Find Crosshair Position
	//Line-trace along that lookdirection
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	FVector2D ScreenLocation = FVector2D(ViewPortSizeX * CrosshairXlocation, ViewPortSizeY * CrosshairYlocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + LookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}