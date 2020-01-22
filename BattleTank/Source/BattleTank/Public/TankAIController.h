// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
class ATank;
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:
	//The Radius That AI Tank can find
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 8000;
private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
