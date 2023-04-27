// AssimpImporterComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "assimp/Importer.hpp"
#include "AssimpImporterComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNTIMEANIMATIONGENERATOR_API UAssimpImporterComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAssimpImporterComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintCallable, Category = "Assimp")
	bool OpenMesh(FString Path, int32& SectionCount, FString& ErrorCode);

	UFUNCTION(BlueprintCallable, Category = "Assimp")
	bool GetSection(int32 Index, TArray<FVector>& Vertices, TArray<int32>& Faces, TArray<FVector>& Normals, TArray<FVector2D>& UV, TArray<FVector>& Tangents);

	UFUNCTION(BlueprintCallable, Category = "Assimp")
	void Clear();

	UFUNCTION(BlueprintCallable, Category = "Assimp")
	UStaticMesh* CreateStaticMeshFromImportedData(int32 Index, FString MeshName);

	UFUNCTION(BlueprintCallable, Category = "Assimp")
	bool SaveStaticMeshToContentBrowser(UStaticMesh* StaticMesh, FString AssetPath, FString& OutAssetPath);

	UStaticMesh* SaveStaticMeshToContentBrowser2(UStaticMesh* StaticMesh, FString MeshName);

	UFUNCTION(BlueprintCallable, Category = "Assimp")
	void Test(FString MeshPath);

	UFUNCTION(BlueprintCallable, Category = "Assimp")

	TArray<UStaticMesh*> Test2(FString MeshPath);
	UFUNCTION(BlueprintCallable, Category = "Assimp")
	TArray<UStaticMesh*> Test3(FString MeshPath);
private:
	int32 SelectedVertex;
	int32 MeshCurrentProcessed;
	bool AddModifier;
	int LastModifiedTime;
	bool RequiresFullRecreation;

	TArray<TArray<FVector>> VerticesGlobal;
	TArray<TArray<int32>> IndicesGlobal;
	TArray <TArray<FVector >> NormalsGlobal;
	TArray<TArray<FVector2D>> UVsGlobal;
	TArray<TArray<FVector>> TangentsGlobal;
	TArray<TArray<FColor>> VertexColorsGlobal;

	void ProcessMesh(aiMesh* Mesh, const aiScene* Scene);
	void ProcessNode(aiNode* Node, const aiScene* Scene);
};
