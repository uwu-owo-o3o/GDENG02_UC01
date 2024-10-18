// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerProgressManager.h"
#include "WorkerBotManager.h"
#include "KeyState.h"
#include "Components/InputComponent.h"
#include "ShopManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDENG02_UC01_API UShopManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShopManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void BuyWorker();
	void SelectWorker(float axisValue);

public:
	//UPROPERTY(EDitAnywhere)
	//bool buyWorker;

	UPROPERTY(EDitAnywhere)
	AActor* PlayerProgressManagerActor;

	UPROPERTY(EDitAnywhere)
	AActor* WorkerBotManagerActor;

	UPROPERTY(EDitAnywhere)
	APawn* PlayerInput;

	bool canSelectWorker;
	int botNumber;

	const FName BUY_WORKER_NAME = FName("BUY_WORKER");
	const FName BUY_SILOS_NAME = FName("BUY_SILOS");
	const FName SELECT_WORKER_NAME = FName("SELECT_WORKER");


};
