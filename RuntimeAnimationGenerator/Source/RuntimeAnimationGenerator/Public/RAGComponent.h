// RAGComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "RAGManager.h"
#include "RAGComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNTIMEANIMATIONGENERATOR_API URAGComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY()
	ACharacter* TargetCharacter;

	UFUNCTION(BlueprintCallable, Category = "RAG")
	void SetRAGConfig(ACharacter* InTargetCharacter, UIKRetargeter* Retargeter);

	UFUNCTION(BlueprintCallable, Category = "RAG")
	void GenerateAnimation(FString UserText) const;

	UFUNCTION(BlueprintCallable, Category = "RAG")
	void PlayAnimation(UAnimSequence* AnimSequence,FString UserText) const;

	UPROPERTY(BlueprintAssignable, Category = "RAG")
	FOnAnimationGenerated OnAnimationGenerated;

private:

	UPROPERTY()
	URAGManager* RAGManager;

	UPROPERTY()
	UAnimSequence* GeneratedAnim;

	UFUNCTION()
	void HandleOnAnimationGenerated(UAnimSequence* GeneratedAnimation, FString UserText);
};
