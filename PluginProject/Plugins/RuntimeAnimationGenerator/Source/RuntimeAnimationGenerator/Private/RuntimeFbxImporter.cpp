// Fill out your copyright notice in the Description page of Project Settings.

#include "RuntimeFbxImporter.h"

#include "Engine/StaticMesh.h"
#include "RawMesh.h"
#include "StaticMeshResources.h"
#include "AssetRegistry/AssetRegistryModule.h"

bool RuntimeFbxImporter::ImportFbxFile(const FString& FilePath, UStaticMesh*& OutStaticMesh)
{
	Assimp::Importer Importer;

	std::string stdFilePath(TCHAR_TO_UTF8(*FilePath));

	const aiScene* scene = Importer.ReadFile(stdFilePath, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR::ASSIMP::%s"), *FString(Importer.GetErrorString()));
		return false;
	}

	aiMesh* mesh = nullptr;
	for (unsigned int i =0 ; i < scene->mNumMeshes; ++i)
	{
		mesh = scene->mMeshes[i];
		if (mesh)
		{
			break;
		}
	}

	if (!mesh)
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR: No mesh found in the FBX file."));
		return false;
	}

	// Create a new UStaticMesh
	FString PackageName = TEXT("/Game/Generated");
	FString AssetName = TEXT("Chair");
	UPackage* Package = CreatePackage(*PackageName);
	OutStaticMesh = NewObject<UStaticMesh>(Package, *AssetName, RF_Public | RF_Standalone);
	OutStaticMesh->InitResources();

	FRawMesh RawMesh;

	// Fill out the RawMesh with vertex data from the imported mesh
	for (unsigned int i = 0; i < mesh->mNumVertices; ++i)
	{
		aiVector3D& vertex = mesh->mVertices[i];
		RawMesh.VertexPositions.Add(FVector3f(vertex.x, vertex.y, vertex.z));
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; ++i)
	{
		aiFace& face = mesh->mFaces[i];
		for (unsigned int j = 0; j < face.mNumIndices; ++j)
		{
			RawMesh.WedgeIndices.Add(face.mIndices[j]);
		}
	}

	if (mesh->mTextureCoords[0])
	{
		for (unsigned int i = 0; i < mesh->mNumVertices; ++i)
		{
			aiVector3D& texCoord = mesh->mTextureCoords[0][i];
			RawMesh.WedgeTexCoords[0].Add(FVector2f(texCoord.x, texCoord.y));
		}
	}

	FStaticMeshSourceModel& SrcModel = OutStaticMesh->AddSourceModel();

	// Set the mesh data and build the static mesh
	SrcModel.BuildSettings.bRecomputeNormals = false;
	SrcModel.BuildSettings.bRecomputeTangents = false;
	SrcModel.BuildSettings.bRemoveDegenerates = false;
	SrcModel.BuildSettings.bUseHighPrecisionTangentBasis = false;
	SrcModel.BuildSettings.bUseFullPrecisionUVs = false;
	SrcModel.BuildSettings.bGenerateLightmapUVs = true;

	SrcModel.SaveRawMesh(RawMesh);

	UE_LOG(LogTemp, Log, TEXT("OutStaticMesh created: %s"), *OutStaticMesh->GetName());
	UE_LOG(LogTemp, Log, TEXT("RawMesh.VertexPositions.Num(): %d"), RawMesh.VertexPositions.Num());
	UE_LOG(LogTemp, Log, TEXT("RawMesh.WedgeIndices.Num(): %d"), RawMesh.WedgeIndices.Num());

	OutStaticMesh->CreateBodySetup();
	OutStaticMesh->SetLightingGuid(FGuid::NewGuid());

	OutStaticMesh->Build(false);

	// Set the package dirty flag so the user can save the asset
	Package->SetDirtyFlag(true);

	// Notify the asset registry of the new asset
	FAssetRegistryModule::AssetCreated(OutStaticMesh);

	// Mark the package as dirty so that the user will be prompted to save it
	Package->MarkPackageDirty();

	return true;
}
