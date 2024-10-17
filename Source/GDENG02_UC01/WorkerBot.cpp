// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerBot.h"

// Sets default values for this component's properties
UWorkerBot::UWorkerBot()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorkerBot::BeginPlay()
{
	Super::BeginPlay();

	// ...
	this->initialize();
}


// Called every frame
void UWorkerBot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (this->isActivatedWorker) {
		this->moveBot();
	}
}

void UWorkerBot::initialize() {
	this->isActivatedWorker = true;
	this->alpha = 0;
	this->level = 1;
	this->checkForUpgrade(this->level);
}

void UWorkerBot::moveBot() {
	FVector PawnPos = this->Worker->GetActorLocation();
	if (!this->bReturning) {
		this->moveTowardsB(PawnPos);
	}
	else {
		this->returnToA(PawnPos);
	}


	this->updateFlags(PawnPos);	
}

void UWorkerBot::updateFlags(FVector PawnPos) {
	if (PawnPos == PointB) {
		if (!this->bReturning) {
			FString ValueString = FString::Printf(TEXT("Alpha value: %f"), this->alpha);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Flag updated to TRUE."));
			this->storeCollectedResouces();
		}
		this->bReturning = true;
		this->alpha = 0.0f;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Flag updated to TRUE."));
		/*FString ValueString = FString::Printf(TEXT("[TRUE] Pawn Pos X: %f"), this->Bot2Pawn->GetActorLocation().X);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, ValueString);*/
	}
	else if (PawnPos == PointA) {		
		this->bReturning = false;
		this->alpha = 0.0f;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Flag updated to FALSE."));
		/*FString ValueString = FString::Printf(TEXT("[TRUE] Pawn Pos X: %f"), this->Bot2Pawn->GetActorLocation().X);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, ValueString);*/

	}
}

void UWorkerBot::moveTowardsB(FVector PawnPos) {
	if (PawnPos != this->PointB) {
		this->alpha += this->speed * GetWorld()->GetDeltaSeconds();
		this->alpha = FMath::Clamp(this->alpha, 0.0f, 1.0f);
		FVector newPos = FMath::Lerp(this->PointA, this->PointB, this->alpha);
		this->Worker->SetActorLocation(newPos);
	}
	/*FString ValueString = FString::Printf(TEXT("Pawn Pos X: %f"), this->Bot2Pawn->GetActorLocation().X);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, ValueString);

	FString PointAStr = FString::Printf(TEXT("Point A X: %f"), this->PointA.X);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, PointAStr);

	FString PointBStr = FString::Printf(TEXT("Point B X: %f"), PointB.X);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, PointBStr);*/

}

void UWorkerBot::returnToA(FVector PawnPos) {
	if (PawnPos != this->PointA) {
		/*FString alphavalstr = FString::Printf(TEXT("[RETURNING] Alpha Value: %f"), this->alpha);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, alphavalstr);*/

		this->alpha += this->speed * GetWorld()->GetDeltaSeconds();
		this->alpha = FMath::Clamp(this->alpha, 0.0f, 1.0f);
		FVector newPos = FMath::Lerp(this->PointB, this->PointA, this->alpha);
		this->Worker->SetActorLocation(newPos);
	}
	/*FString ValueString = FString::Printf(TEXT("[RETURNING] Pawn Pos X: %f"), this->Bot2Pawn->GetActorLocation().X);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, ValueString);*/
}

void UWorkerBot::storeCollectedResouces() {
	UPlayerProgressManager* playerProgressManager = this->PlayerProgressManagerActor->GetComponentByClass<UPlayerProgressManager>();
	if (playerProgressManager == NULL) return;
	
	if (this->isWoodBot) {
		/*FString ValueString = FString::Printf(TEXT("WOOD COLLECTED: %d"), this->wood_collected);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, ValueString);*/
		playerProgressManager->addWood(this->wood_collected);
	}
	else if (this->isStoneBot) {
		playerProgressManager->addStone(this->stone_collected);
	}
}

void UWorkerBot::levelUp() {
	if (this->level < 5) {
		this->level++;
	}
}

void UWorkerBot::checkForUpgrade(int value) {
	switch (this->level) {
		case 1:
			this->wood_collected = 10;
			this->stone_collected = 4;
			this->speed = 0.1f;
			break;
		case 2:
			this->wood_collected = 15;
			this->stone_collected = 8;
			this->speed = 0.1f;
			break;
		case 3:
			this->wood_collected = 20;
			this->stone_collected = 12;
			this->speed = 0.5f;
			break;
		case 4:
			this->wood_collected = 25;
			this->stone_collected = 16;
			this->speed = 1.0f;
			break;
		case 5:
			this->wood_collected = 30;
			this->stone_collected = 20;
			this->speed = 1.5f;
			break;
	}
}



