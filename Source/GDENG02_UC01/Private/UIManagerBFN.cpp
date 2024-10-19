// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManagerBFN.h"

void UUIManagerBFN::test(AActor* manager) {


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,TEXT("test func called!"));

	UPlayerProgressManager* reference = manager->GetComponentByClass<UPlayerProgressManager>();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Manager curr wood: %d"), reference->CurrWood));
}

FText UUIManagerBFN::GetPlayerCurrentWood(AActor* manager) {

	UPlayerProgressManager* reference = manager->GetComponentByClass<UPlayerProgressManager>();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Manager curr wood: %d"), reference->CurrWood));
	FText text = FText::AsNumber(static_cast<int32>(reference->CurrWood));	
	return text;
}

FText UUIManagerBFN::GetPlayerCurrentStone(AActor* manager) {

	UPlayerProgressManager* reference = manager->GetComponentByClass<UPlayerProgressManager>();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Manager curr wood: %d"), reference->CurrWood));
	FText text = FText::AsNumber(static_cast<int32>(reference->CurrStone));
	return text;
}

FText UUIManagerBFN::GetPlayerMaxWood(AActor* manager) {

	UPlayerProgressManager* reference = manager->GetComponentByClass<UPlayerProgressManager>();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Manager curr wood: %d"), reference->CurrWood));
	FText text = FText::AsNumber(static_cast<int32>(reference->maxWood));
	return text;
}

FText UUIManagerBFN::GetPlayerMaxStone(AActor* manager) {

	UPlayerProgressManager* reference = manager->GetComponentByClass<UPlayerProgressManager>();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Manager curr wood: %d"), reference->CurrWood));
	FText text = FText::AsNumber(static_cast<int32>(reference->maxStone));
	return text;
}