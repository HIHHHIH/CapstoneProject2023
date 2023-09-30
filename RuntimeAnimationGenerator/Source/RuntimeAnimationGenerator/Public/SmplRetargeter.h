#pragma once

#include "CoreMinimal.h"
#include "Retargeter/IKRetargeter.h"
#include "SmplRetargeter.generated.h"

UCLASS()
class RUNTIMEANIMATIONGENERATOR_API USmplRetargeter : public UObject
{
	GENERATED_BODY()

public:

	void Initialize(UIKRetargeter* InRetargeter, USkeletalMesh* InSourceMesh, USkeletalMesh* InTargetMesh);

	UAnimSequence* RetargetAnimation(UAnimSequence* SMPLAnim) const;

private:

	UPROPERTY()
	UIKRetargeter* Retargeter;

	UPROPERTY()
	USkeletalMesh* TargetMesh;

	UPROPERTY()
	USkeletalMesh* SourceMesh;
};
