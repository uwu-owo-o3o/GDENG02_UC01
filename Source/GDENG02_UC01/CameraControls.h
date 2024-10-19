// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraActor.h"
#include "Components/InputComponent.h"
#include "CameraControls.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDENG02_UC01_API UCameraControls : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCameraControls();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SwitchCameraToRight();
	void SwitchCameraToLeft();

public:
	UPROPERTY(EDitAnywhere)
	AActor* CamPositionA;

	UPROPERTY(EDitAnywhere)
	AActor* CamPositionB;

	UPROPERTY(EDitAnywhere)
	AActor* CamPositionC;

	UPROPERTY(EDitAnywhere)
	ACameraActor* Camera;

	UPROPERTY(EDitAnywhere)
	APawn* Player;

	UPROPERTY(EDitAnywhere)
	int CamPositionNumber;

	const FName SWITCH_CAMERA_RIGHT_NAME = FName("SWITCH_CAMERA_RIGHT");
	const FName SWITCH_CAMERA_LEFT_NAME = FName("SWITCH_CAMERA_LEFT");
};
