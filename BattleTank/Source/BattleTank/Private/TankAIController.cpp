// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerControlledTank = GetPlayerControlledTank();
	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp,Warning,TEXT("can not get PlayercontrolledTank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AITankcontroller Find PlayerControlledTank : %s"),*(PlayerControlledTank->GetName()))
	}

}
ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerControlledTank() const 
{
	auto PlayerControlledTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerControlledTank)
		return nullptr;
	else
		return Cast<ATank>(PlayerControlledTank);

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Hitlocation = FVector(0);
	if (GetAIControlledTank())
	{
		//TODO Move towards the player

		//TODO Aim towards the player
		GetAIControlledTank()->AimAt(GetPlayerControlledTank()->GetActorLocation());
	}
}