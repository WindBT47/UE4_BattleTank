// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;
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

	TArray<ASprungWheel*> GetWheels() const;
	
	virtual void BeginPlay()override;

	void DriveTrack(float CurrentThrottle);

};
