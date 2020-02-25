// Copyright WindBT LTD


#include "SprungWheel.h"

// Sets default values
ASprungWheel::ASprungWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprung = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Sprung"));
	SetRootComponent(Sprung);

	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));
	Mass->AttachToComponent(Sprung, FAttachmentTransformRules::KeepRelativeTransform);

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));
	Wheel->AttachToComponent(Sprung, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ASprungWheel::BeginPlay()
{
	Super::BeginPlay();

	if (GetParentActor())
	{
		UE_LOG(LogTemp,Warning,TEXT("not null"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("null"))
	}
	
}

// Called every frame
void ASprungWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

