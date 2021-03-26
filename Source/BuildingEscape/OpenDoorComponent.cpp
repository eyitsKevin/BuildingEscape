// Copyright Kevin Luu 2021


#include "OpenDoorComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoorComponent::UOpenDoorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UOpenDoorComponent::HandleOpenDoor() const
{
	const FRotator CurrentRotation = GetOwner()->GetActorRotation();
	const FRotator OpenDoorRotation	 = FRotator(0.0f, CurrentRotation.Yaw + 90.0f, 0.0f);
	GetOwner()->SetActorRotation(OpenDoorRotation);
}

void UOpenDoorComponent::HandleCloseDoor() const
{
	GetOwner()->SetActorRotation(InitialRotation);
}


// Called when the game starts
void UOpenDoorComponent::BeginPlay()
{
	Super::BeginPlay();
	InitialRotation = GetOwner()->GetActorRotation();
	this->HandleOpenDoor();
}




// Called every frame
void UOpenDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

