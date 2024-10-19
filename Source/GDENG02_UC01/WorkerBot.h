// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerProgressManager.h"
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

	UPROPERTY(EditAnywhere)
	AActor* PlayerProgressManagerActor;

	UPROPERTY(EditAnywhere)
	AActor* Worker;

	UPROPERTY(EditAnywhere)
	bool isActivatedWorker;

	UPROPERTY(EditAnywhere)
	bool isWoodBot;

	UPROPERTY(EditAnywhere)
	bool isStoneBot;

	UPROPERTY(EditAnywhere)
	bool bReturning;

	UPROPERTY(EditAnywhere)
	float alpha;

	UPROPERTY(EditAnywhere)
	FVector PointA;

	UPROPERTY(EditAnywhere)
	AActor* PointBFlag;

	UPROPERTY(EditAnywhere)
	int level;

	UPROPERTY(EditAnywhere)
	float speed;
	
	UPROPERTY(EditAnywhere)
	int wood_collected;

	UPROPERTY(EditAnywhere)
	int stone_collected;

	UPROPERTY(EditAnywhere)
	int baseNumber;

	UPROPERTY(EditAnywhere)
	int botNumber;

	FVector PointB;


public:
	void moveBot();
	void returnToA(FVector PawnPos);
	void moveTowardsB(FVector PawnPos);
	void updateFlags(FVector PawnPos);
	void storeCollectedResources();
	void levelUp();
	void checkForUpgrade(int level);

};
