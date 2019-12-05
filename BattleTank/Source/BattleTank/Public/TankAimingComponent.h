// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/Classes/Kismet/GameplayStaticsTypes.h"
#include "TankAimingComponent.generated.h"
//forward declaration
class UTankBarrel;
class UTankTurrent;
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};
//Holds barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Input")
	void Initialise(UTankBarrel* TankBarrel, UTankTurrent* TankTurrent);

	void AimAt(FVector Hitlocation,float LaughSpeed);

	UTankBarrel* Barrel = nullptr;
protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	UTankTurrent* Turrent = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurrentTowards(FVector AimDirection);
};
