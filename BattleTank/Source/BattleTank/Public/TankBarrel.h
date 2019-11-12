// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere,Category=Setup)
	float MaxDegreesPerSeconds = 20; //Sensible Default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevateDegrees = 0; //TODO set

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinDegreesPerSeconds = 0; //TODO set
};
