// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/FreeCamCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/AngleRotatorComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFreeCamCharacter::AFreeCamCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Angle Rotator Component, Attach to RootComponent and Set Rotation Axis to Yaw 
	CameraAngleYaw = CreateDefaultSubobject<UAngleRotatorComponent>(TEXT("Yaw Camera Angle"));
	CameraAngleYaw->SetupAttachment(RootComponent);
	CameraAngleYaw->RotationAxis = ERotationAxis::AXIS_YAW;

	// Create Angle Rotator Component, Attach to CameraAngleYaw and Set Rotation Axis to Pitch 
	CameraAnglePitch = CreateDefaultSubobject<UAngleRotatorComponent>(TEXT("Pitch Camera Angle"));
	CameraAnglePitch->SetupAttachment(CameraAngleYaw);
	CameraAnglePitch->RotationAxis = ERotationAxis::AXIS_PITCH;

	// Create SpringArm Component, Attach to CameraAnglePitch and Set TargerArmLength
	SpringArmThirdPerson = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmThirdPerson->SetupAttachment(CameraAnglePitch);
	SpringArmThirdPerson->TargetArmLength = 450.0f;

	// Create Camera Component and Attach to SpringArmThirdPerson
	CameraThirdPerson = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraThirdPerson->SetupAttachment(SpringArmThirdPerson);

	// Change Defaults for Character Movement
	this->GetCharacterMovement()->bOrientRotationToMovement = true;
	this->GetCharacterMovement()->RotationRate = FRotator(0.0, 50000.0, 0.0);

}

// Called when the game starts or when spawned
void AFreeCamCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFreeCamCharacter::Turn(float Value)
{
	// Add Rotaion in the Value Direction
	CameraAngleYaw->AddInput(Value);
}

void AFreeCamCharacter::LookUp(float Value)
{
	// Add Rotaion in the Value Direction 
	CameraAnglePitch->AddInput(Value);
}

// Called every frame
void AFreeCamCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFreeCamCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Axis Turn
	// Bind Axis Mapping when Input to Function
	PlayerInputComponent->BindAxis("Turn Right / Left Gamepad", this, &AFreeCamCharacter::Turn);
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &AFreeCamCharacter::Turn);

	// Axis LookUp
	// Bind Axis Mapping when Input to Function
	PlayerInputComponent->BindAxis("Look Up / Down Gamepad", this, &AFreeCamCharacter::LookUp);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &AFreeCamCharacter::LookUp);
}

