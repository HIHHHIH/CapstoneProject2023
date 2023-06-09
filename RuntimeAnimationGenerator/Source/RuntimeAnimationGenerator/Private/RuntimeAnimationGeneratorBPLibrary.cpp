// Copyright Epic Games, Inc. All Rights Reserved.

#include "RuntimeAnimationGeneratorBPLibrary.h"

URuntimeAnimationGeneratorBPLibrary::URuntimeAnimationGeneratorBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void URuntimeAnimationGeneratorBPLibrary::GenerateAnimationCommandHandler(const TArray<FString>& Args)
{
	if (Args.Num() > 0)
	{
		GenerateAnimation(Args[0]);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Please provide a user text argument"));
	}
}

// Register the console command
FAutoConsoleCommand GenerateAnimationCommand(
	TEXT("RAG.GenerateAnimation"),
	TEXT("Generates an animation using the Runtime Animation Generator"),
	FConsoleCommandWithArgsDelegate::CreateStatic(&URuntimeAnimationGeneratorBPLibrary::GenerateAnimationCommandHandler)
);