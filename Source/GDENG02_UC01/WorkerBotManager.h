// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorkerBot.h"
#include "WorkerBotManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDENG02_UC01_API UWorkerBotManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWorkerBotManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void InteractWorkerBot(int baseNumber, int botNumber);
	int CheckWorkerBotLevel(int baseNumber, int botNumber);

public:
	UPROPERTY(EDitAnywhere)
	TArray<AActor*> Base1WorkerBots;

	//uncomment later for bases 2 and 3
	//UPROPERTY(EDitAnywhere)
	//TArray<UWorkerBot*> Base2WorkerBots;

	//UPROPERTY(EDitAnywhere)
	//TArray<UWorkerBot*> Base3WorkerBots;



};
