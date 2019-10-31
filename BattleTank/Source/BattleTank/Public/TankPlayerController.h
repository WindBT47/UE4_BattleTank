// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Math/Vector.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowordsCrosshair();

	bool GetSightRayLocation(FVector& OutHitLocation) const;
	UPROPERTY(EditAnywhere)
		float CrosshairXlocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrosshairYlocation = 0.3333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LoockDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection,FVector& HitLocation) const;
};
