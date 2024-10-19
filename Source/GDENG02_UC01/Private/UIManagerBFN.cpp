// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManagerBFN.h"

UPlayerProgressManager* UUIManagerBFN::GetPlayerProgressManagerRef() {
	static UWorld* CurrWorld = GEngine->GetWorld();
	if (CurrWorld != nullptr) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("CurrWorld is not null"));
	}

	TArray<AActor*> WorldActors;
	AActor* FoundActor = NewObject<AActor>();
	
	
	UGameplayStatics::GetAllActorsOfClass(CurrWorld, UUIManagerBFN::StaticClass(), WorldActors);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Number of elements in MyArray: %d"), WorldActors.Num()));
	
	for (AActor* Actor : WorldActors) {
		if (Actor->GetName() == "PlayerProgressManager") {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Found intended actor"));
			FoundActor = Actor;
		}
	}

	/*if (FoundActor == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("FoundActor is null"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Actor Name: %s"), *FoundActor->GetName()));
	}*/

	UPlayerProgressManager* manager = FoundActor->GetComponentByClass<UPlayerProgressManager>();
	/*if (manager == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("manager is null"));
	}*/
	return manager;
}

FText UUIManagerBFN::GetPlayerCurrentWood() {
	UPlayerProgressManager* reference = GetPlayerProgressManagerRef();
	FText text = FText::AsNumber(static_cast<int32>(0));
	if (reference == nullptr) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("reference is null"));
		return text;
	}
	int wood = reference->CurrWood;
	text = FText::AsNumber(static_cast<int32>(wood));
	return text;
}

