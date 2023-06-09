// MotionDataExtractor.h
#pragma once

#include "CoreMinimal.h"
#include "Animation/Skeleton.h"
#include "IKRigDefinition.h"
#include "UObject/UObjectGlobals.h"
#include "RigEditor/IKRigController.h"
#include "assimp/scene.h"


class RUNTIMEANIMATIONGENERATOR_API FSmplRetargeter
{
public:
    static void SetTarget(UIKRigDefinition* IKRig);
    static TMap<FName, FName> BoneMapping;
    static UAnimSequence* RetargetAnimation(const aiScene* Scene);
    static UAnimSequence* RetargetAnimation2(const aiScene* Scene);
    static UAnimSequence* GenerateSmplAnim(const aiScene* Scene);
    static UAnimSequence* RetargetAnimation4();
    static UAnimSequence* RetargetAnimation(UAnimSequence* SmplAnim);

    static FQuat4f GetBoneOrientation(USkeleton* Skeleton, FName BoneName);
private:
    static void InitializeSource();
    static UIKRigDefinition* LoadSmplIKRig();

    static USkeleton* TargetSkeleton;
    static USkeleton* SourceSkeleton;

    static FReferenceSkeleton SourceRefSkeleton;
    static FReferenceSkeleton TargetRefSkeleton;

    static UIKRigDefinition* SourceIKRig;
    static UIKRigDefinition* TargetIKRig;

    static UIKRigController* SourceIKRigController;
    static UIKRigController* TargetIKRigController;
};