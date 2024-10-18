// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopManager.h"

// Sets default values for this component's properties
UShopManager::UShopManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UShopManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//buyWorker = false;
	this->PlayerInput->InputComponent->BindAction(BUY_WORKER_NAME, EInputEvent::IE_Pressed, this, &UShopManager::CheckBuyWorker);
	
}


// Called every frame
void UShopManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	// ...
	//this->PlayerInputComponent->BindAction(BUY_WORKER_NAME, EInputEvent::IE_Pressed, this, &UShopManager::CheckBuyWorker);
	//this->PlayerInput->InputComponent->BindAction(BUY)
	//	CheckBuyWorker();
}

void UShopManager::CheckBuyWorker() {
	//UPlayerProgress
	UPlayerProgressManager* playerProgressManager = this->PlayerProgressManagerActor->GetComponentByClass<UPlayerProgressManager>();
	if (playerProgressManager != NULL) {
		playerProgressManager->deductWood(20);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Bought Wood"));
	}

}

