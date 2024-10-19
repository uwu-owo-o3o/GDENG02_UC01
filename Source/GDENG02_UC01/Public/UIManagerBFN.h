// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../PlayerProgressManager.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Components/TextBlock.h"
#include "UIManagerBFN.generated.h"

/**
 * 
 */
UCLASS()
class GDENG02_UC01_API UUIManagerBFN : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:
		UFUNCTION(BlueprintCallable, Category = "UI Manager BFN")
		static void test(AActor* manager);

		UFUNCTION(BlueprintCallable, Category = "UI Manager BFN")
		static FText GetPlayerCurrentWood(AActor* manager);

		UFUNCTION(BlueprintCallable, Category = "UI Manager BFN")
		static FText GetPlayerCurrentStone(AActor* manager);

		UFUNCTION(BlueprintCallable, Category = "UI Manager BFN")
		static FText GetPlayerMaxWood(AActor* manager);


		UFUNCTION(BlueprintCallable, Category = "UI Manager BFN")
		static FText GetPlayerMaxStone(AActor* manager);
};
