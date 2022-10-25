// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AngleRotatorComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(AngleRotator, Log, All);

UENUM()
enum class ERotationAxis
{
	NONE UMETA(DisplayName = "None"),
	AXIS_ROLL UMETA(DisplayName = "X (Roll)"),
	AXIS_PITCH UMETA(DisplayName = "Y (Pitch)"),
	AXIS_YAW UMETA(DisplayName = "Z (Yaw)")
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FREECAMERA_API UAngleRotatorComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAngleRotatorComponent();

	// The axis at which the component should rotate 
	UPROPERTY(EditAnywhere, Category = "Rotation")
		ERotationAxis RotationAxis;

	// The Scalte the Rotation would be multiplied
	UPROPERTY(EditAnywhere, Category = "Rotation")
		float InputScale;

	// Input axes values, accumulated each tick.
	FRotator RotationInput;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * Add input in given axes. This value is multiplied by InputScale.
	 * @param Value Amount to add to axes. This value is multiplied by InputScale.
	 */
	void AddInput(float Value);

	/**
	 * Updates the rotation of Component, after RotationInput has been applied.
	 * @param DeltaTime Time Since Last Tick.
	 */
	void UpdateRotation(float DeltaTime);
};
