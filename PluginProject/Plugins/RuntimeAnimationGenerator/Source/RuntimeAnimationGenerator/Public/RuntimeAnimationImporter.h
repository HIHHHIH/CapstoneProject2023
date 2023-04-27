// FRuntimeAnimationImporter.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RuntimeAnimationImporter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNTIMEANIMATIONGENERATOR_API URuntimeAnimationImporter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URuntimeAnimationImporter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintCallable, Category = "Assimp")
	bool OpenMesh(FString Path, FString& ErrorCode);

private:

	UFUNCTION(BlueprintCallable, Category = "Assimp")
	UAnimSequence* GenerateAnimation();

	UFUNCTION(BlueprintCallable, Category = "Assimp")
	bool SaveAnimation(UAnimSequence* GeneratedAnim);

	const aiScene* Scene;
	USkeleton* Skeleton;
};
