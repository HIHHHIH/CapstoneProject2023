// RuntimeAnimationGeneratorBPLibrary.h
#pragma once

#include "SmplRetargeter.h"
#include "assimp/postprocess.h"
#include "assimp/scene.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "assimp/Importer.hpp"
#include "GameFramework/Character.h"
#include "UObject/SavePackage.h"
#include "Serialization/JsonSerializer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RuntimeAnimationGeneratorBPLibrary.generated.h"

UCLASS()
class URuntimeAnimationGeneratorBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	inline static ACharacter* TargetCharacter = nullptr;
	inline static UAnimSequence* GeneratedAnim = nullptr;

	UFUNCTION(BlueprintCallable, Category = "RAG")
	static UAnimSequence* GenerateAnimation(FString UserText)
	{
		// Get Scene
		TFuture<const aiScene*> Future = MotionHttpRequest(UserText);
		Future.Then([UserText](TFuture<const aiScene*> ResponseFuture)
			{
			const aiScene* Response = ResponseFuture.Get();
			//UE_LOG(LogTemp, Warning, TEXT("Response Animation name: %s"), *FString(Response->mAnimations[0]->mName.C_Str()));

			// Set source animation
			GeneratedAnim =  FSmplRetargeter::GenerateSmplAnim(Response);
            //GeneratedAnim = FSmplRetargeter::RetargetAnimation4();
			//UE_LOG(LogTemp, Warning, TEXT("Animation Retargeted: %s"), *GeneratedAnim->GetName());
			SaveAnimSequence(UserText, GeneratedAnim);

            return GeneratedAnim;
			});

        return nullptr;
	}

	static void GenerateAnimationCommandHandler(const TArray<FString>& Args);

    static TFuture<const aiScene*> MotionHttpRequest(FString UserInput)
    {
        TSharedRef<TPromise<const aiScene*>, ESPMode::ThreadSafe> Promise = MakeShared<TPromise<const aiScene*>, ESPMode::ThreadSafe>();
        TFuture<const aiScene*> Future = Promise->GetFuture();

        // Create Http request
        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
        HttpRequest->SetURL("https://localhost:8000/mdm/");
        HttpRequest->SetVerb("GET");

        HttpRequest->OnProcessRequestComplete().BindLambda([Promise](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
            {
                if (bSuccess && Response.IsValid())
                {
                    //FString PluginName = "RuntimeAnimationGenerator";
                    //FString RelativeFilePath = "/Content/FBX/kicking.fbx";
                    //FString AbsoluteFilePath = FPaths::Combine(FPaths::ProjectPluginsDir(), PluginName, RelativeFilePath);
                    //UE_LOG(LogTemp, Warning, TEXT("SMPL Fbx path: %s"), *AbsoluteFilePath);
                    //std::string FileName(TCHAR_TO_UTF8(*AbsoluteFilePath));

                    //Assimp::Importer Importer;
                    //const aiScene* Scene = Importer.ReadFile(FileName, aiProcessPreset_TargetRealtime_MaxQuality);
                    //if (!Scene)
                    //{
                    //    UE_LOG(LogTemp, Warning, TEXT("Failed to load Smpl fbx Scene"));
                    //}
                    Promise->SetValue(Response->GetContentAsString());
                    Promise->SetValue(Scene);
                }
                else
                {
                    // Handle error.
                    Promise->SetValue(nullptr);
                    UE_LOG(LogTemp, Warning, TEXT("Failed to get response"));
                }
            });

        // Send the request.
        HttpRequest->ProcessRequest();

        return Future;
    }

    static void SaveAnimSequence(FString UserText, UAnimSequence* AnimSequence)
    {
        FDateTime Now = FDateTime::Now();
        //FString Timestamp = Now.ToString(TEXT("%Y%m%d_%H%M%S"));
        FString AssetPath = "/RuntimeAnimationGenerator/GeneratedAnim/";
        FString AnimationSequenceName = UserText;
        FString PackageName = AssetPath + AnimationSequenceName;
        //PackageName.Append(Timestamp);
        UPackage* Package = CreatePackage(*PackageName);

        AnimSequence->Rename(*AnimationSequenceName, Package);
        AnimSequence->SetFlags(RF_Public | RF_Standalone);

        FAssetRegistryModule::AssetCreated(AnimSequence);

        FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

        // Package save arguments
        FSavePackageArgs SaveArgs;
        SaveArgs.TopLevelFlags = EObjectFlags::RF_Public | EObjectFlags::RF_Standalone;
        SaveArgs.SaveFlags = SAVE_NoError;
        SaveArgs.bForceByteSwapping = true;

        bool bSaved = UPackage::SavePackage(Package, AnimSequence, *PackageFileName, SaveArgs);

        if (bSaved)
        {
            UE_LOG(LogTemp, Warning, TEXT("Saved animation sequence to content browser."));
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to save animation sequence to content browser."));
        }
    }

    UFUNCTION(BlueprintCallable, Category = "RAG")
    static void PlayGeneratedAnim(FString UserText)
    {
        FString AssetPath = TEXT("/RuntimeAnimationGenerator/GeneratedAnim/");
        AssetPath.Append(UserText + "." + UserText);
        UAnimSequence* AnimSequence = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), nullptr, *AssetPath));
        UAnimInstance* AnimInstance = TargetCharacter->GetMesh()->GetAnimInstance();
        UE_LOG(LogTemp, Warning, TEXT("Animation Name: %s"), *AnimSequence->GetName())

            if (AnimInstance != nullptr)
            {
                // Create a new montage
                UAnimMontage* Montage = UAnimMontage::CreateSlotAnimationAsDynamicMontage(AnimSequence, FName("DefaultSlot"));

                if (Montage)
                {
                	float MontageLength = AnimInstance->Montage_Play(Montage);
                    UE_LOG(LogTemp, Warning, TEXT("playing montage of %f seconds"), MontageLength);
                }
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Failed to create AnimMontage"));
                }
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("AnimInstance is null"));
            }
    }
};
