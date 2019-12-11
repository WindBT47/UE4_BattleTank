// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	auto TankAimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(PlayerTank && ControlledTank && TankAimingComponent)) { return; }
	//TODO Move towards the player
	MoveToActor(PlayerTank,AcceptanceRadius);
	//TODO Aim towards the player
	TankAimingComponent->AimAt(PlayerTank->GetActorLocation());
	TankAimingComponent->Fire();
}

