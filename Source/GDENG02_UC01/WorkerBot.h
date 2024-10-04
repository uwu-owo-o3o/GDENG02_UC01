// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorkerBot.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDENG02_UC01_API UWorkerBot : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWorkerBot();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void initialize();
	
public:
	AActor* Worker;

	bool IsActive;
	bool isWoodBot;
	bool isStoneBot;
	bool bReturning;

	float alpha;

	FVector PointA;
	FVector PointB;

public:
	void moveBot();
	void returnToA(FVector PawnPos);
	void moveTowardsB(FVector PawnPos);
	void updateFlags(FVector PawnPos);


};
