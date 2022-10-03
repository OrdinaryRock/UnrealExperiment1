// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "UltimateGameState.generated.h"

/**
 * 
 */
UCLASS()
class UNREALEXPERIMENT1_API AUltimateGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	AUltimateGameState();

	int8 Points;
};
