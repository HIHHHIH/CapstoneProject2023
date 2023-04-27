// Copyright Epic Games, Inc. All Rights Reserved.

#include "RuntimeAnimationGeneratorBPLibrary.h"
#include "RuntimeAnimationGenerator.h"
#include "RuntimeFbxImporter.h"

URuntimeAnimationGeneratorBPLibrary::URuntimeAnimationGeneratorBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float URuntimeAnimationGeneratorBPLibrary::RuntimeAnimationGeneratorSampleFunction(float Param)
{
	return -1;
}

UAnimSequence* URuntimeAnimationGeneratorBPLibrary::GenerateAnimation(FString TextInput)
{
	return nullptr;
}

void URuntimeAnimationGeneratorBPLibrary::SpawnFbxTest()
{
	UStaticMesh* ImportedMesh;
	FString FbxFilePath = FPaths::ProjectContentDir() + "Generated/" + "Chair.fbx";
	if (bool ImportSuccess = RuntimeFbxImporter::ImportFbxFile(FbxFilePath, ImportedMesh))
	{
		UE_LOG(LogTemp, Warning, TEXT("holly shit"));
	}
}




