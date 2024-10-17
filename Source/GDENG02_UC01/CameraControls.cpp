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

