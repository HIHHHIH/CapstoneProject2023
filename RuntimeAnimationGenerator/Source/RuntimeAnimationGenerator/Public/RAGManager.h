// RAGManager.h

#pragma once

#include "CoreMinimal.h"
#include "SmplRetargeter.h"
#include "AssimpAnimLoader.h"
#include "RAGManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAnimationGenerated, UAnimSequence*, GeneratedAnimation, FString, UserText);

UCLASS()
class RUNTIMEANIMATIONGENERATOR_API URAGManager : public UObject
{
	GENERATED_BODY()

	URAGManager();
	virtual ~URAGManager() override;

	UPROPERTY()
	USmplRetargeter* SmplRetargeter;

	UPROPERTY()
	UAssimpAnimLoader* AnimLoader;

	bool IsClientTest = true;
	

	void SetTestFbxName(const TArray<FString>& Args);
	void ToggleClientTestMode();

	TFuture<FString> RequestAnimationData(FString UserInput) const;

public:

	void Initialize(UIKRetargeter* InRetargeter, USkeletalMesh* SkeletalMesh);

	void GenerateAnimationInternal(FString UserText) const;

	FOnAnimationGenerated OnAnimationGenerated;

};
