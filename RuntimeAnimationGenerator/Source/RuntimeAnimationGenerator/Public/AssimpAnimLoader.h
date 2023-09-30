#pragma once

#include "CoreMinimal.h"
#include "assimp/scene.h"
#include "assimp/Importer.hpp"
#include "AssimpAnimLoader.generated.h"

UCLASS()
class RUNTIMEANIMATIONGENERATOR_API UAssimpAnimLoader: public UObject
{
	GENERATED_BODY()

public:

	void Initialize(USkeletalMesh* InSourceMesh);
	const aiScene* ImportAiScene(const FString& FilePath) const;
	UAnimSequence* CreateAnimSequenceFromAiScene(const aiScene* Scene) const;
	Assimp::Importer* Importer;

private:

	UPROPERTY()
	USkeletalMesh* SourceMesh;

	static void AddPositionalKeys(TArray<FVector3f>& Keys, const aiNodeAnim* NodeAnim, const bool UseFirstOnly);
	static void AddRotationalKeys(TArray<FQuat4f>& Keys, const aiNodeAnim* NodeAnim, const bool UseFirstOnly);
	static void AddScalingKeys(TArray<FVector3f>& Keys, const aiNodeAnim* NodeAnim, const bool UseFirstOnly);
	static void FilterKeyFrameOutliers(TArray<FQuat4f>& RotationalKeys, FString* LogMessage = nullptr);
	static void FixRootOrientation(TArray<FVector3f>& PositionalKeys, TArray<FQuat4f>& RotationalKeys);
};
