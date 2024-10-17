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
	buyWorker = false;
	
}


// Called every frame
void UShopManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	
	CheckBuyWorker();
}

void UShopManager::CheckBuyWorker() {
	//UPlayerProgress
	UPlayerProgressManager* playerProgressManager = this->PlayerProgressManagerActor->GetComponentByClass<UPlayerProgressManager>();
	if (buyWorker) {
		playerProgressManager->deductWood(20);
	}
}

