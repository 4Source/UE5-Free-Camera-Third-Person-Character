// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AngleRotatorComponent.h"

DEFINE_LOG_CATEGORY(AngleRotator);

// Sets default values for this component's properties
UAngleRotatorComponent::UAngleRotatorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame. 
	PrimaryComponentTick.bCanEverTick = true;

	// Set Default Values
	InputScale = 1.0f;
	RotationInput = FRotator::ZeroRotator;
}


// Called when the game starts
void UAngleRotatorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	// Check Valid Settings
	if (RotationAxis == ERotationAxis::NONE)
	{
		UE_LOG(AngleRotator, Warning, TEXT("Invalid axis (NONE) selected."));
	}
	if (InputScale == 0.0f)
	{
		UE_LOG(AngleRotator, Warning, TEXT("Input Scalte is 0 no Rotation would be applied!"));
	}

}


// Called every frame
void UAngleRotatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Update the Rotation
	UpdateRotation(DeltaTime);

	// Clear axis inputs from previous frame.
	RotationInput = FRotator::ZeroRotator;
}

void UAngleRotatorComponent::AddInput(float Value)
{
	switch (RotationAxis)
	{
	case ERotationAxis::AXIS_ROLL:
		RotationInput.Roll += InputScale * Value;
		break;
	case ERotationAxis::AXIS_PITCH:
		RotationInput.Pitch += InputScale * Value;
		break;
	case ERotationAxis::AXIS_YAW:
		RotationInput.Yaw += InputScale * Value;
		break;
	default:
		UE_LOG(AngleRotator, Warning, TEXT("Could not add rotation input! Invalid axis selected."));
		break;
	}
}

void UAngleRotatorComponent::UpdateRotation(float DeltaTime)
{
	// Calculate Delta to be applied on ViewRotation
	FRotator DeltaRot(RotationInput);

	// Apply Rotation
	this->AddRelativeRotation(DeltaRot);
}

