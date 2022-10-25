// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FreeCamCharacter.generated.h"

UCLASS()
class FREECAMERA_API AFreeCamCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFreeCamCharacter();

	// Rotation Angle in Yaw of the Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UAngleRotatorComponent* CameraAngleYaw;

	// Rotation Angle in Pitch of the Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UAngleRotatorComponent* CameraAnglePitch;

	// Spring Arm Component Hold the Camera 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class USpringArmComponent* SpringArmThirdPerson;

	// Camera Component 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
		class UCameraComponent* CameraThirdPerson;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Movement Turn
	void Turn(float Value);
	// Movement Look Up
	void LookUp(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
