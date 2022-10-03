// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealExperiment1GameMode.generated.h"

UCLASS(minimalapi)
class AUnrealExperiment1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealExperiment1GameMode();

	void OnTargetHit();

	UPROPERTY(EditAnywhere, Category = "Game Rules")
	int32 PointsToWin;
};



