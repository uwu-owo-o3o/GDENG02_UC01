// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraControls.h"

// Sets default values for this component's properties
UCameraControls::UCameraControls()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCameraControls::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CamPositionNumber = 1;
	this->Player->InputComponent->BindAction(SWITCH_CAMERA_RIGHT_NAME, EInputEvent::IE_Pressed, this, &UCameraControls::SwitchCameraToRight);
	this->Player->InputComponent->BindAction(SWITCH_CAMERA_LEFT_NAME, EInputEvent::IE_Pressed, this, &UCameraControls::SwitchCameraToLeft);
}


// Called every frame
void UCameraControls::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	switch (CamPositionNumber) {
		case 1:
			Camera->SetActorLocation(CamPositionA->GetActorLocation());
			break;
		case 2:
			Camera->SetActorLocation(CamPositionB->GetActorLocation());
			break;
		case 3:
			Camera->SetActorLocation(CamPositionC->GetActorLocation());
			break;
		default:
			Camera->SetActorLocation(CamPositionA->GetActorLocation());
			break;
	}

}

void UCameraControls::SwitchCameraToRight()
{
	CamPositionNumber += 1;
	if (CamPositionNumber == 4)
		CamPositionNumber = 1;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("%d"), CamPositionNumber));
}

void UCameraControls::SwitchCameraToLeft()
{
	CamPositionNumber -= 1;
	if (CamPositionNumber == 0)
		CamPositionNumber = 3;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, FString::Printf(TEXT("%d"), CamPositionNumber));
}
