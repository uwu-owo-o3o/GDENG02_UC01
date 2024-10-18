// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerBotManager.h"

// Sets default values for this component's properties
UWorkerBotManager::UWorkerBotManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorkerBotManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWorkerBotManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWorkerBotManager::registerBot(int baseNumber, int botNumber) 
{
	//UWorkerBot* newBot;
	//this->workerBotsArray.Add(newBot);
	//newBot->isActivatedWorker = false;
	//newBot->baseNumber = baseNumber;
	//newBot->botNumber = botNumber;
	
}

AActor* UWorkerBotManager::getWorkerBot(int baseNumber, int botNumber)
{
	TArray<AActor*> workerBots;
	switch (baseNumber) {
		case 1:
			workerBots = this->Base1WorkerBots;
			break;
		case 2:
			//workerBots = this->Base2WorkerBots;
			break;
		case 3:
		//	workerBots = this->Base3WorkerBots;
			break;
	}

	return workerBots[botNumber];
}

