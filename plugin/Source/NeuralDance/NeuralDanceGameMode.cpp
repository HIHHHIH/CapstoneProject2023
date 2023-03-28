// Copyright Epic Games, Inc. All Rights Reserved.

#include "NeuralDanceGameMode.h"
#include "NeuralDanceCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANeuralDanceGameMode::ANeuralDanceGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
