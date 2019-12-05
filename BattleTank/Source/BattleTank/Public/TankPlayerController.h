// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Math/Vector.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;
class UTankAimingComponent;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:

		UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;

		UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimingComponent);
private:

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
