// RAGComponent.cpp

#include "RAGComponent.h"

void URAGComponent::SetRAGConfig(ACharacter* InTargetCharacter, UIKRetargeter* Retargeter)
{
	TargetCharacter = InTargetCharacter;
    USkeletalMesh* TargetMesh = TargetCharacter->GetMesh()->SkeletalMesh;

	RAGManager = NewObject<URAGManager>();
	RAGManager->Initialize(Retargeter, TargetMesh);
    RAGManager->OnAnimationGenerated.AddDynamic(this, &URAGComponent::HandleOnAnimationGenerated);
}

void URAGComponent::GenerateAnimation(FString UserText) const
{
    UserText = UserText.Replace(TEXT(" "), TEXT("_"));
	RAGManager->GenerateAnimationInternal(UserText);
}

void URAGComponent::PlayAnimation(UAnimSequence* AnimSequence, FString UserText) const
{
	if (UAnimInstance* AnimInstance = TargetCharacter->GetMesh()->GetAnimInstance())
    {
        if (UAnimMontage* Montage = UAnimMontage::CreateSlotAnimationAsDynamicMontage(AnimSequence, FName("DefaultSlot")))
        {
            AnimInstance->Montage_Play(Montage);
        }
    }
}

void URAGComponent::HandleOnAnimationGenerated(UAnimSequence* GeneratedAnimation, FString UserText)
{
    OnAnimationGenerated.Broadcast(GeneratedAnimation, UserText);
}
