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
	
}


// Called every frame
void UWorkerBot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWorkerBot::initialize() {
	this->IsActive = false;
}

//void UBot2Behavior::moveBot() {
//	FVector PawnPos = this->Bot2Pawn->GetActorLocation();
//	if (!this->bReturning) {
//		this->moveTowardsB(PawnPos);
//	}
//	else {
//		this->returnToA(PawnPos);
//	}
//
//
//	this->updateFlags(PawnPos);
//
//}
//
//void UBot2Behavior::updateFlags(FVector PawnPos) {
//	if (PawnPos == PointB) {
//		this->bReturning = true;
//		this->alpha = 0.0f;
//		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Flag updated to TRUE."));
//		/*FString ValueString = FString::Printf(TEXT("[TRUE] Pawn Pos X: %f"), this->Bot2Pawn->GetActorLocation().X);
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, ValueString);*/
//
//	}
//	else if (PawnPos == PointA) {
//
//		//FString ValueString = FString::Printf(TEXT("Pawn Pos X: %f"), this->Bot2Pawn->GetActorLocation().X);
//		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, ValueString);
//
//		this->bReturning = false;
//		this->alpha = 0.0f;
//		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Flag updated to FALSE."));
//		/*FString ValueString = FString::Printf(TEXT("[TRUE] Pawn Pos X: %f"), this->Bot2Pawn->GetActorLocation().X);
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, ValueString);*/
//
//	}
//}
//
//void UBot2Behavior::moveTowardsB(FVector PawnPos) {
//	if (PawnPos != this->PointB) {
//		this->alpha += 0.1f * GetWorld()->GetDeltaSeconds();
//		this->alpha = FMath::Clamp(this->alpha, 0.0f, 1.0f);
//		FVector newPos = FMath::Lerp(this->PointA, this->PointB, this->alpha);
//		this->Bot2Pawn->SetActorLocation(newPos);
//	}
//	/*FString ValueString = FString::Printf(TEXT("Pawn Pos X: %f"), this->Bot2Pawn->GetActorLocation().X);
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, ValueString);
//
//	FString PointAStr = FString::Printf(TEXT("Point A X: %f"), this->PointA.X);
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, PointAStr);
//
//	FString PointBStr = FString::Printf(TEXT("Point B X: %f"), PointB.X);
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, PointBStr);*/
//
//}
//
//void UBot2Behavior::returnToA(FVector PawnPos) {
//	if (PawnPos != this->PointA) {
//		/*FString alphavalstr = FString::Printf(TEXT("[RETURNING] Alpha Value: %f"), this->alpha);
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, alphavalstr);*/
//
//		this->alpha += 0.1f * GetWorld()->GetDeltaSeconds();
//		this->alpha = FMath::Clamp(this->alpha, 0.0f, 1.0f);
//		FVector newPos = FMath::Lerp(this->PointB, this->PointA, this->alpha);
//		this->Bot2Pawn->SetActorLocation(newPos);
//	}
//	/*FString ValueString = FString::Printf(TEXT("[RETURNING] Pawn Pos X: %f"), this->Bot2Pawn->GetActorLocation().X);
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, ValueString);*/
//}


