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
	this->PlayerInput->InputComponent->BindAction(BUY_WORKER_NAME, EInputEvent::IE_Pressed, this, &UShopManager::BuyWorker);
	this->PlayerInput->InputComponent->BindAxis(SELECT_WORKER_NAME, this, &UShopManager::SelectWorker);
	//this->PlayerInput->InputComponent->BindAction(SELECT_1_NAME, EInputEvent::IE_Pressed, this, &UShopManager::SelectWorker(1));
	//this->PlayerInput->InputComponent->BindAction()
	this->canSelectWorker = false;
}


// Called every frame
void UShopManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	// ...
	//this->PlayerInputComponent->BindAction(BUY_WORKER_NAME, EInputEvent::IE_Pressed, this, &UShopManager::CheckBuyWorker);
	//this->PlayerInput->InputComponent->BindAction(BUY)
	//	CheckBuyWorker();

	//GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow, TEXT("IMONG MAMA " + FString::SanitizeFloat(botNumber)));
	
}

void UShopManager::BuyWorker() {

	//if (playerProgressManager != NULL) {

		//select worker
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow, TEXT("Selecting Worker..."));
		//switch HUD
		canSelectWorker = true;


	//	playerProgressManager->deductWood(20);
		//canSelectWorker = true;
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Bought Wood Bot"));


	//}

}

void UShopManager::SelectWorker(float axisValue) {
	UPlayerProgressManager* playerProgressManager = this->PlayerProgressManagerActor->GetComponentByClass<UPlayerProgressManager>();
	UWorkerBotManager* workerBotManager = this->WorkerBotManagerActor->GetComponentByClass<UWorkerBotManager>();

	if (canSelectWorker) {
	
		switch ((int)axisValue) {
			case 1:
				GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow, TEXT("IMONG MAMA " + FString::SanitizeFloat(axisValue)));
				break;
			case 2:
				GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Yellow, TEXT("GAGO KA " + FString::SanitizeFloat(axisValue)));
				break;
		}
		canSelectWorker = false;
	}
		
		//canSelectWorker = false;
	//}
}

