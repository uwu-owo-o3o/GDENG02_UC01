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


void UWorkerBotManager::UpdateWorkerBot(int baseNumber, int botNumber)
{
	UWorkerBot* workerBot = NULL;

	switch (baseNumber) {
	case 1:
		workerBot = this->Base1WorkerBots[botNumber]->GetComponentByClass<UWorkerBot>();
		break;

	case 2:	//uncomment later for bases 2 and 3
		workerBot = this->Base2WorkerBots[botNumber]->GetComponentByClass<UWorkerBot>();
		break;

	case 3:
		workerBot = this->Base3WorkerBots[botNumber]->GetComponentByClass<UWorkerBot>();
		break;

	default:
		break;
	}

	if (workerBot != NULL) {
		if (workerBot->level == 0 && workerBot->isActivatedWorker == false) {	//unlock
			workerBot->isActivatedWorker = true;
			workerBot->levelUp();
		}

		else if (workerBot->level != 5) { //upgrade 
			workerBot->levelUp();
		}
	}

}

int UWorkerBotManager::CheckWorkerBotLevel(int baseNumber, int botNumber)
{
	UWorkerBot* workerBot;
	int level = -1;
	switch (baseNumber) {
	case 1:
		workerBot = this->Base1WorkerBots[botNumber]->GetComponentByClass<UWorkerBot>();
		level = workerBot->level;
		break;
	case 2: //BASE 2
		workerBot = this->Base2WorkerBots[botNumber]->GetComponentByClass<UWorkerBot>();
		level = workerBot->level;
		break;
	case 3:	//BASE 3
		workerBot = this->Base3WorkerBots[botNumber]->GetComponentByClass<UWorkerBot>();
		level = workerBot->level;
		break;

	default:
		break;
	}

	return level;
}

