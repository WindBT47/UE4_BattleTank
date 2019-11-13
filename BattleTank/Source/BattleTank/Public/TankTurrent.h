// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurrent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float DegreesPerSeconds = 5; //Sensible Default

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxYawDegrees = 40; //TODO set

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinYawDegrees = -40; //TODO set
};
