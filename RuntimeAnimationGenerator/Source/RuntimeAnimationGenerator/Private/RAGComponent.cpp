// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeAnimationGeneratorBPLibrary.h"
#include "SmplRetargeter.h"
#include "RAGComponent.h"

// Sets default values for this component's properties
URAGComponent::URAGComponent()
{

}

// Called when the game starts
void URAGComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void URAGComponent::SetRAGController(URAGComponent* RAGComponent)
{
	URuntimeAnimationGeneratorBPLibrary::TargetCharacter = TargetCharacter;
}

void URAGComponent::SetRAGConfig(FRAGConfig RAGConfig)
{
	TargetCharacter = RAGConfig.TargetCharacter;
	TargetIKRig = RAGConfig.TargetIKRig;
	FSmplRetargeter::SetTarget(TargetIKRig);
	URuntimeAnimationGeneratorBPLibrary::TargetCharacter = TargetCharacter;
}

void URAGComponent::PlayGeneratedAnim(FString UserText)
{
	GeneratedAnim = URuntimeAnimationGeneratorBPLibrary::GeneratedAnim;
	UAnimInstance* AnimInstance = TargetCharacter->GetMesh()->GetAnimInstance();
	UE_LOG(LogTemp, Warning, TEXT("Animation Name: %s"), *GeneratedAnim->GetName())

	if (AnimInstance != nullptr)
	{
		// Create a new montage
		UAnimMontage* Montage = UAnimMontage::CreateSlotAnimationAsDynamicMontage(GeneratedAnim, FName("DefaultSlot"));

		if (Montage)
		{
			float MontageLength = AnimInstance->Montage_Play(Montage);
			UE_LOG(LogTemp, Warning, TEXT("playing montage of %f seconds"), MontageLength);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create AnimMontage"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AnimInstance is null"));
	}
}
