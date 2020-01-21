// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	void SetThrottle(float Throttle);

	UPROPERTY(EditAnywhere, Category = "Drive")
	float TrackMaxDrivingFroce=30000000;//TODO assume 40 tonne tank and 1g acceleration

private:
	UTankTrack();

	float CurrentThrottle = 0;
	
	virtual void BeginPlay()override;

	void ApplySidewayForce();

	void DriveTrack();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
