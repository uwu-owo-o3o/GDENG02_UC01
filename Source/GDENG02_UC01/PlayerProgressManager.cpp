// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerProgressManager.h"

// Sets default values for this component's properties
UPlayerProgressManager::UPlayerProgressManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerProgressManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	this->initialize();
}


// Called every frame
void UPlayerProgressManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	this->updateMaxResources();
}

void UPlayerProgressManager::initialize() {
	this->CurrWood = 10;
	this->CurrStone = 0;
	this->ActiveSilo = 1;
	this->ActiveWorkers = 0;
	this->updateMaxResources();
}

void UPlayerProgressManager::addWood(int value) {
	if (this->CurrWood + value < this->maxWood) {
		this->CurrWood += value;
	}
	else {
		this->CurrWood = maxWood;
	}
}

void UPlayerProgressManager::addStone(int value) {
	if (this->CurrStone + value < this->maxStone) {
		this->CurrStone += value;
	}
	else {
		this->CurrStone = maxStone;
	}
}

void UPlayerProgressManager::deductWood(int value) {
	if (this->CurrWood - value > 0) {
		this->CurrWood -= value;
	}
	else {
		this->CurrWood = 0;
	}
}

void UPlayerProgressManager::deductStone(int value) {
	if (this->CurrStone - value > 0) {
		this->CurrStone -= value;
	}
	else {
		this->CurrStone = 0;
	}
}

void UPlayerProgressManager::updateMaxResources() {
	int total_max_wood = 100 * this->ActiveSilo;
	this->maxWood = total_max_wood;
	int total_max_stone = 25 * this->ActiveSilo;
	this->maxStone = total_max_stone;
}
