// AssimpImporterComponent.cpp


#include "AssimpImporterComponent.h"
#include "AssetToolsModule.h"
#include "AssetRegistryModule.h"
#include "MeshDescription.h"
#include "MeshDescriptionBuilder.h"
#include "Engine/StaticMesh.h"
#include "StaticMeshAttributes.h"
#include "Misc/NamePermissionList.h"

// Sets default values for this component's properties
UAssimpImporterComponent::UAssimpImporterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAssimpImporterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

bool UAssimpImporterComponent::OpenMesh(FString Path, int32& SectionCount, FString& ErrorCode)
{
	Assimp::Importer Importer;
	std::string FileName(TCHAR_TO_UTF8(*Path));
	const aiScene* Scene = Importer.ReadFile(FileName, aiProcessPreset_TargetRealtime_MaxQuality);
	if (!Scene)
	{
		ErrorCode = Importer.GetErrorString();
		return false;
	}

	MeshCurrentProcessed = 0;
	ProcessNode(Scene->mRootNode, Scene);
	SectionCount = MeshCurrentProcessed;
	UE_LOG(LogTemp, Warning, TEXT("Current Mesh: %d"), MeshCurrentProcessed);

	return true;
}

bool UAssimpImporterComponent::GetSection(int32 Index, TArray<FVector>& Vertices, TArray<int32>& Faces, TArray<FVector>& Normals, TArray<FVector2D>& UV, TArray<FVector>& Tangents)
{
	if (Index >= MeshCurrentProcessed) return false;

	Vertices = this->VerticesGlobal[Index];
	Faces = this->IndicesGlobal[Index];
	Normals = this->NormalsGlobal[Index];
	Tangents = this->TangentsGlobal[Index];

	return true;
}

void UAssimpImporterComponent::Clear()
{
	VerticesGlobal.Empty();
	IndicesGlobal.Empty();
	NormalsGlobal.Empty();
	UVsGlobal.Empty();
	TangentsGlobal.Empty();
	VertexColorsGlobal.Empty();
	MeshCurrentProcessed = 0;
}

void UAssimpImporterComponent::ProcessMesh(aiMesh* Mesh, const aiScene* Scene)
{
	if (VerticesGlobal.Num() <= MeshCurrentProcessed)
	{
		VerticesGlobal.AddZeroed();
		IndicesGlobal.AddZeroed();
		NormalsGlobal.AddZeroed();
		UVsGlobal.AddZeroed();
		TangentsGlobal.AddZeroed();
		VertexColorsGlobal.AddZeroed();
	}

	if (Mesh->mNumVertices != VerticesGlobal[MeshCurrentProcessed].Num())
		RequiresFullRecreation = true;

	VerticesGlobal[MeshCurrentProcessed].Empty();
	NormalsGlobal[MeshCurrentProcessed].Empty();
	UVsGlobal[MeshCurrentProcessed].Empty();
	TangentsGlobal[MeshCurrentProcessed].Empty();
	VertexColorsGlobal[MeshCurrentProcessed].Empty();
	IndicesGlobal[MeshCurrentProcessed].Empty();

	for (unsigned int i = 0; i < Mesh->mNumVertices; i++)
	{
		FVector Vertex, Normal;

		Vertex.X = Mesh->mVertices[i].x;
		Vertex.Y = Mesh->mVertices[i].y;
		Vertex.Z = Mesh->mVertices[i].z;

		Normal.X = Mesh->mNormals[i].x;
		Normal.Y = Mesh->mNormals[i].y;
		Normal.Z = Mesh->mNormals[i].z;

		if (Mesh->mTextureCoords[0])
		{
			FVector2D UVs;
			UVs.X = Mesh->mTextureCoords[0][i].x;
			UVs.Y = Mesh->mTextureCoords[0][i].y;
			UVsGlobal[MeshCurrentProcessed].Add(UVs);
		}
		else
		{
			UVsGlobal[MeshCurrentProcessed].Add(FVector2D(0.f, 0.f));
		}

		VerticesGlobal[MeshCurrentProcessed].Add(Vertex);
		NormalsGlobal[MeshCurrentProcessed].Add(Normal);
	}

	if (RequiresFullRecreation)
	{
		for (uint32 i = 0; i < Mesh->mNumFaces; i++)
		{
			aiFace Face = Mesh->mFaces[i];
			IndicesGlobal[MeshCurrentProcessed].Add(Face.mIndices[2]);
			IndicesGlobal[MeshCurrentProcessed].Add(Face.mIndices[1]);
			IndicesGlobal[MeshCurrentProcessed].Add(Face.mIndices[0]);
		}
	}

}

void UAssimpImporterComponent::ProcessNode(aiNode* Node, const aiScene* Scene)
{
	for (uint32 i = 0; i < Node->mNumMeshes; i++)
	{
		aiMesh* Mesh = Scene->mMeshes[Node->mMeshes[i]];
		ProcessMesh(Mesh, Scene);
		++MeshCurrentProcessed;
	}

	uint32 Nodes = Node->mNumMeshes;
	for (uint32 i = 0; i < Node->mNumChildren; i++)
	{
		ProcessNode(*Node->mChildren, Scene);
	}
}

UStaticMesh* UAssimpImporterComponent::CreateStaticMeshFromImportedData(int32 Index, FString MeshName)
{
	if (Index >= MeshCurrentProcessed)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid index for CreateStaticMeshFromImportedData."));
		return nullptr;
	}

	TArray<FVector> Vertices = VerticesGlobal[Index];
	TArray<int32> Indices = IndicesGlobal[Index];

	// Assuming you have already imported the data and filled Vertices and Indices arrays.
	// ...

	FMeshDescription MeshDescription;
	FStaticMeshAttributes Attributes(MeshDescription);
	Attributes.Register();

	FMeshDescriptionBuilder meshDescBuilder;
	meshDescBuilder.SetMeshDescription(&MeshDescription);
	meshDescBuilder.EnablePolyGroups();
	meshDescBuilder.SetNumUVLayers(1);

	TArray<FVertexID> VertexIDs;
	for (const FVector& Vertex : Vertices)
	{
		FVertexID VertexID = meshDescBuilder.AppendVertex(Vertex);
		VertexIDs.Add(VertexID);
	}

	TArray<FVertexInstanceID> VertexInstanceIDs;
	for (const FVertexID& VertexID : VertexIDs)
	{
		FVertexInstanceID VertexInstanceID = meshDescBuilder.AppendInstance(VertexID);
		VertexInstanceIDs.Add(VertexInstanceID);
	}

	FPolygonGroupID PolygonGroupID = meshDescBuilder.AppendPolygonGroup();

	for (int32 i = 0; i < Indices.Num(); i += 3)
	{
		meshDescBuilder.AppendTriangle(
			VertexInstanceIDs[Indices[i]],
			VertexInstanceIDs[Indices[i + 1]],
			VertexInstanceIDs[Indices[i + 2]],
			PolygonGroupID
		);
	}

	UStaticMesh* staticMesh = NewObject<UStaticMesh>(this, FName(*MeshName));
	staticMesh->GetStaticMaterials().Add(FStaticMaterial());

	UStaticMesh::FBuildMeshDescriptionsParams mdParams;
	mdParams.bBuildSimpleCollision = true;
	mdParams.bFastBuild = true;

	TArray<const FMeshDescription*> meshDescPtrs;
	meshDescPtrs.Emplace(&MeshDescription);
	staticMesh->BuildFromMeshDescriptions(meshDescPtrs, mdParams);

	return staticMesh;
}

bool UAssimpImporterComponent::SaveStaticMeshToContentBrowser(UStaticMesh* StaticMesh, FString AssetPath, FString& OutAssetPath)
{
	if (!StaticMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot save a null static mesh to the Content Browser."));
		return false;
	}

	FString DesiredPackageName = FString::Printf(TEXT("/Game/%s/%s"), *AssetPath, *StaticMesh->GetName());
	FString Filename;
	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
	AssetToolsModule.Get().CreateUniqueAssetName(DesiredPackageName, TEXT(""), DesiredPackageName, Filename);

	UPackage* Package = CreatePackage(nullptr, *DesiredPackageName);
	Package->FullyLoad();
	Package->Modify();

	UStaticMesh* NewStaticMesh = DuplicateObject<UStaticMesh>(StaticMesh, Package, *StaticMesh->GetName());
	NewStaticMesh->MarkPackageDirty();

	FAssetRegistryModule::AssetCreated(NewStaticMesh);
	NewStaticMesh->PostEditChange();

	FString PackageFileName = FPackageName::LongPackageNameToFilename(DesiredPackageName, FPackageName::GetAssetPackageExtension());
	bool bSaved = UPackage::SavePackage(Package, NewStaticMesh, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName);

	if (bSaved)
	{
		OutAssetPath = DesiredPackageName;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to save static mesh to the Content Browser."));
	}

	return bSaved;
}

void UAssimpImporterComponent::Test(FString MeshPath)
{
	int32 SectionCount;
	FString ErrorCode;
	bool bSuccess = OpenMesh(MeshPath, SectionCount, ErrorCode);

	if (bSuccess)
	{
		for (int32 i = 0; i < SectionCount; ++i)
		{
			FString MeshName = FString::Printf(TEXT("ImportedMesh_%d"), i);
			UStaticMesh* staticMesh = CreateStaticMeshFromImportedData(i, MeshName);

			FString AssetPath = "ImportedMeshes";
			FString SavedAssetPath;
			bool bSaved = SaveStaticMeshToContentBrowser(staticMesh, AssetPath, SavedAssetPath);

			if (bSaved)
			{
				UE_LOG(LogTemp, Log, TEXT("Saved static mesh to: %s"), *SavedAssetPath);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to save static mesh to Content Browser."));
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to open mesh: %s"), *ErrorCode);
	}
}

TArray<UStaticMesh*> UAssimpImporterComponent::Test3(FString MeshPath)
{
	TArray<UStaticMesh*> MeshArray;
	int32 SectionCount;
	FString ErrorCode;
	bool bSuccess = OpenMesh(MeshPath, SectionCount, ErrorCode);
	UE_LOG(LogTemp, Warning, TEXT("SectionCount: %d"), SectionCount);
	if (bSuccess)
	{
		for (int32 i = 0; i < SectionCount; ++i)
		{
			FString MeshName = FString::Printf(TEXT("ImportedMesh_%d"), i);
			UStaticMesh* staticMesh = CreateStaticMeshFromImportedData(i, MeshName);
			MeshArray.Add(staticMesh);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to open mesh: %s"), *ErrorCode);
	}

	return MeshArray;
}

UStaticMesh* UAssimpImporterComponent::SaveStaticMeshToContentBrowser2(UStaticMesh* StaticMesh, FString MeshName)
{
	if (!StaticMesh)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to save static mesh to content browser. Invalid static mesh."));
		return nullptr;
	}

	FString AssetPath = "/Game/ImportedMeshes/";
	FString PackageName = AssetPath + MeshName;
	UPackage* Package = CreatePackage(*PackageName);

	Package->FullyLoad();
	Package->Modify();

	FString NewAssetName = FPackageName::GetShortName(PackageName);
	NewAssetName = MakeUniqueObjectName(nullptr, StaticMesh->GetClass(), FName(*NewAssetName)).ToString();

	UStaticMesh* NewStaticMesh = DuplicateObject<UStaticMesh>(StaticMesh, Package, *NewAssetName);
	NewStaticMesh->SetFlags(RF_Public | RF_Standalone);

	FAssetRegistryModule::AssetCreated(NewStaticMesh);

	NewStaticMesh->MarkPackageDirty();

	FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
	EPackageFlags PackageFlags = PKG_None;

	bool bSaved = UPackage::SavePackage(Package, NewStaticMesh, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName, nullptr, nullptr, true, true, PackageFlags);

	if (bSaved)
	{
		UE_LOG(LogTemp, Log, TEXT("Saved static mesh to content browser."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to save static mesh to content browser."));
	}

	return NewStaticMesh;
}

TArray<UStaticMesh*> UAssimpImporterComponent::Test2(FString MeshPath)
{
	TArray<UStaticMesh*> MeshArray;
	int32 SectionCount;
	FString ErrorCode;
	bool bSuccess = OpenMesh(MeshPath, SectionCount, ErrorCode);

	if (bSuccess)
	{
		for (int32 i = 0; i < SectionCount; ++i)
		{
			FString MeshName = FString::Printf(TEXT("ImportedMesh_%d"), i);
			UStaticMesh* staticMesh = CreateStaticMeshFromImportedData(i, MeshName);

			FString SavedAssetPath;
			MeshArray.Add(SaveStaticMeshToContentBrowser2(staticMesh, MeshName));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to open mesh: %s"), *ErrorCode);
	}

	return MeshArray;
}
