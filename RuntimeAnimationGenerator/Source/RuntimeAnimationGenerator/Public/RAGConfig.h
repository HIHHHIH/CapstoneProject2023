// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IKRigDefinition.h"
#include "RAGConfig.generated.h"

USTRUCT(BlueprintType)
struct FRAGConfig
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "RAG")
	UIKRigDefinition* TargetIKRig;

	UPROPERTY(BlueprintReadWrite, Category = "RAG")
	ACharacter* TargetCharacter;

};