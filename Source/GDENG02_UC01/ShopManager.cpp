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
	this->Player->InputComponent->BindAction(BUY_WORKER_NAME, EInputEvent::IE_Pressed, this, &UShopManager::BuyWorker);
	this->Player->InputComponent->BindAction(BUY_SILOS_NAME, EInputEvent::IE_Pressed, this, &UShopManager::BuySilos);
	this->Player->InputComponent->BindAxis(SELECT_WORKER_NAME, this, &UShopManager::SelectWorker);
	this->canSelectWorker = false;
	this->botNumber = -1;
	this->baseNumber = 1;
}


// Called every frame
void UShopManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);	
}

void UShopManager::BuyWorker() 
{

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Selecting Worker..."));	
	canSelectWorker = true;

	//switch to Shop HUD (shows all worker bots info)

}

void UShopManager::BuySilos()
{
	UPlayerProgressManager* playerProgressManager = this->PlayerProgressManagerActor->GetComponentByClass<UPlayerProgressManager>();
	this->baseNumber = this->PlayerCamera->GetComponentByClass<UCameraControls>()->CamPositionNumber;

	if (playerProgressManager->ActiveSilo < 6) {
		if (playerProgressManager->CurrWood >= 50) {
			playerProgressManager->ActiveSilo += 1;
			playerProgressManager->deductWood(50);
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, TEXT("UNLOCKED SILOS"));
		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, TEXT("SILOS MAX UPGRADE"));
	}
	
}

void UShopManager::SelectWorker(float axisValue) 
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("INPUT AXIS: " + FString::SanitizeFloat(axisValue)));
	if (canSelectWorker) {
	
		switch ((int)axisValue) {
			case 1:
				this->botNumber = 0;
				canSelectWorker = false;
				TransactWorker();
				break;
			case 2:
				this->botNumber = 1;
				canSelectWorker = false;
				TransactWorker();
				break;
			case 3: 
				this->botNumber = 2;
				canSelectWorker = false;
				TransactWorker();
				break;
			case 4:
				this->botNumber = 3;
				canSelectWorker = false;
				TransactWorker();
				break;
			case 5:
				this->botNumber = 4;
				canSelectWorker = false;
				TransactWorker();
				break;
			case 6:
				this->botNumber = 5;
				canSelectWorker = false;
				TransactWorker();
				break;
			case 7:
				this->botNumber = 6;
				canSelectWorker = false;
				TransactWorker();
				break;
		}
	}

	//NOTE: after selecting, it should exit shop HUD
	
}

void UShopManager::TransactWorker()
{
	UPlayerProgressManager* playerProgressManager = this->PlayerProgressManagerActor->GetComponentByClass<UPlayerProgressManager>();
	UWorkerBotManager* workerBotManager = this->WorkerBotManagerActor->GetComponentByClass<UWorkerBotManager>();
	
	this->baseNumber = this->PlayerCamera->GetComponentByClass<UCameraControls>()->CamPositionNumber;
	int level = workerBotManager->CheckWorkerBotLevel(this->baseNumber, this->botNumber);

	switch (level) {

	case 0: //UNLOCK BOT
		if (playerProgressManager->CurrWood >= 20) {
			workerBotManager->UpdateWorkerBot(this->baseNumber, this->botNumber);
			playerProgressManager->deductWood(20);
			ResetTransact();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("UNLOCKED BOT"));
		}
		else
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Insufficient funds for unlock"));
		break;

	case 1:	//UPGRADE BOT TO LVL 2
		if (playerProgressManager->CurrWood >= 10 && playerProgressManager->CurrStone >= 10) {
			workerBotManager->UpdateWorkerBot(this->baseNumber, this->botNumber);
			playerProgressManager->deductWood(10);
			playerProgressManager->deductStone(10);
			ResetTransact();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Upgraded to LvL 2"));
		}
		else
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Insufficient funds for upgrade 2"));
		break;


	case 2:	//UPGRADE BOT TO LVL 3
		if (playerProgressManager->CurrWood >= 15 && playerProgressManager->CurrStone >= 10) {
			workerBotManager->UpdateWorkerBot(this->baseNumber, this->botNumber);
			playerProgressManager->deductWood(15);
			playerProgressManager->deductStone(10);
			ResetTransact();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Upgraded to LvL 3"));
		}
		else
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Insufficient funds for upgrade 3"));
		break;

	case 3:	//UPGRADE BOT TO LVL 4
		if (playerProgressManager->CurrWood >= 20 && playerProgressManager->CurrStone >= 15) {
			workerBotManager->UpdateWorkerBot(this->baseNumber, this->botNumber);
			playerProgressManager->deductWood(20);
			playerProgressManager->deductStone(15);
			ResetTransact();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Upgraded to LvL 4"));
		}
		else
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Insufficient funds for upgrade 4"));
		break;

	case 4: //UPGRADE BOT TO LVL 5
		if (playerProgressManager->CurrWood >= 30 && playerProgressManager->CurrStone >= 20) {
			workerBotManager->UpdateWorkerBot(this->baseNumber, this->botNumber);
			playerProgressManager->deductWood(30);
			playerProgressManager->deductStone(20);
			ResetTransact();
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Upgraded to LvL 5"));
		}
		else
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Insufficient funds for upgrade 5"));
		break;

	case 5:	//ALREADY AT MAX UPGRADE
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("BOT MAX UPGRADE"));
		break;
	

	default:
		break;

	}
}

void UShopManager::ResetTransact() {
	this->baseNumber = -1;
	this->botNumber = -1;
}

