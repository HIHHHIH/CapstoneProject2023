// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeAnimationComponent.h"

// Sets default values for this component's properties
URuntimeAnimationComponent::URuntimeAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URuntimeAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

FString URuntimeAnimationComponent::AddAnimationSequence(UAnimSequence* AnimSequence, FString StateName)
{
	FString temp = "Hello";
	return temp;
}

