// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerProgressManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDENG02_UC01_API UPlayerProgressManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerProgressManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void initialize();
	void addWood(int value);
	void addStone(int value);
	void deductWood(int value);
	void deductStone(int value);
	void updateMaxResources();
	FString updateCurrWoodString();

public:
	UPROPERTY(EditAnywhere)
	int CurrWood;

	UPROPERTY(EditAnywhere)
	int CurrStone;

	UPROPERTY(EditAnywhere)
	int ActiveSilo;

	UPROPERTY(EditAnywhere)
	int ActiveWorkers;

	UPROPERTY(EditAnywhere)
	int maxWood;

	UPROPERTY(EditAnywhere)
	int maxStone;
};
