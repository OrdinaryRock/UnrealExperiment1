// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealExperiment1GameMode.h"
#include "UnrealExperiment1Character.h"
#include "UObject/ConstructorHelpers.h"

AUnrealExperiment1GameMode::AUnrealExperiment1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
