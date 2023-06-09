// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IKRigDefinition.h"
#include "RAGConfig.h"
#include "GameFramework/Character.h"
#include "RAGComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNTIMEANIMATIONGENERATOR_API URAGComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URAGComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	ACharacter* TargetCharacter;
	UIKRigDefinition* TargetIKRig;

	UAnimSequence* GeneratedAnim;

	void SetRAGController(URAGComponent* RAGComponent);

public:	

	UFUNCTION(BlueprintCallable, Category = "RAG")
	void SetRAGConfig(FRAGConfig RAGConfig);

	UFUNCTION(BlueprintCallable, Category = "RAG")
	void PlayGeneratedAnim(FString UserText);

};
