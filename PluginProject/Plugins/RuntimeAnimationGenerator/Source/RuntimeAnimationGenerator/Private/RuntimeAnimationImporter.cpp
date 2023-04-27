// RuntimeAnimationImporter.cpp


#include "RuntimeAnimationImporter.h"
#include "UObject/SavePackage.h"
#include "Math/Rotator.h"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "assimp/Importer.hpp"
#include "AssetRegistry/AssetRegistryModule.h"


// Sets default values for this component's properties
URuntimeAnimationImporter::URuntimeAnimationImporter()
{
	// The path to the skeleton asset in the content browser
	FString SkeletonPath = TEXT("/Game/Test/Ch06/Capoeira_Skeleton.Capoeira_Skeleton");

	// Load the skeleton asset
	Skeleton = Cast<USkeleton>(StaticLoadObject(USkeleton::StaticClass(), nullptr, *SkeletonPath));

	// Check if the skeleton was loaded successfully
	if (Skeleton)
	{
		// The skeleton was loaded successfully, you can use it now
		UE_LOG(LogTemp, Log, TEXT("Capoeira_Skeleton loaded successfully."));
	}
	else
	{
		// The skeleton failed to load
		UE_LOG(LogTemp, Error, TEXT("Failed to load Capoeira_Skeleton."));
	}
}


// Called when the game starts
void URuntimeAnimationImporter::BeginPlay()
{
	Super::BeginPlay();
	
	FString FbxPath = FPaths::ProjectContentDir().Append("/Generated/Capoeira.fbx");
	FString ErrorCode;
	if (OpenMesh(FbxPath, ErrorCode)) 
	{
		// Save the generated animation sequence
		if (UAnimSequence* GeneratedAnim = GenerateAnimation())
		{
			SaveAnimation(GeneratedAnim);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to generate animation sequence."));
		}
	}
}

bool URuntimeAnimationImporter::OpenMesh(FString Path, FString& ErrorCode)
{
	Assimp::Importer Importer;
	std::string FileName(TCHAR_TO_UTF8(*Path));
	Scene = Importer.ReadFile(FileName, aiProcessPreset_TargetRealtime_MaxQuality);
	if (!Scene)
	{
		ErrorCode = Importer.GetErrorString();
		return false;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Num anim: %d"), Scene->mNumAnimations);

	return true;
}

UAnimSequence* URuntimeAnimationImporter::GenerateAnimation()
{
	UAnimSequence* AnimSequence = NewObject<UAnimSequence>(GetTransientPackage(), FName(TEXT("AnimSequenceName")));
	AnimSequence->SetSkeleton(Skeleton);
	int NumFrames = 30;
	AnimSequence->ImportFileFramerate = StaticCast<float>(NumFrames);
	AnimSequence->ImportResampleFramerate = NumFrames;


	for (unsigned int AnimIndex = 0; AnimIndex < Scene->mNumAnimations; ++AnimIndex)
	{
		aiAnimation* Animation = Scene->mAnimations[AnimIndex];

		FString AnimationName = FString(Animation->mName.C_Str());
		float AnimationTicksPerSecond = Animation->mTicksPerSecond;
		float AnimationDuration = Animation->mDuration;
		float AnimationSeconds = AnimationDuration / AnimationTicksPerSecond;
		UE_LOG(LogTemp, Warning, TEXT("Animation %d: %s"), AnimIndex, *AnimationName);
		UE_LOG(LogTemp, Warning, TEXT("Ticks per second: %f"), AnimationTicksPerSecond);
		UE_LOG(LogTemp, Warning, TEXT("Duration: %f"), AnimationDuration);
		UE_LOG(LogTemp, Warning, TEXT("mNumChannels: %d"), Animation->mNumChannels);

		#if WITH_EDITOR
		#define LOCTEXT_NAMESPACE "UpdateFrameRate"

		// Set the animation sequence properties
		IAnimationDataController& Controller = AnimSequence->GetController();
		Controller.OpenBracket(LOCTEXT("Init Anim","Initialize New Animation"));
		Controller.SetFrameRate(FFrameRate(AnimationTicksPerSecond, 1));
		Controller.SetPlayLength(AnimationSeconds, true);
		
		for (unsigned int ChannelIndex = 0; ChannelIndex < Animation->mNumChannels; ++ChannelIndex)
		{
			aiNodeAnim* NodeAnim = Animation->mChannels[ChannelIndex];

			// Remove the prefix from the bone name
			FString FullBoneName = FString(NodeAnim->mNodeName.C_Str());
			int32 ColonPosition = FullBoneName.Find(TEXT(":"));
			FString BoneNameWithoutPrefix;
			if (ColonPosition != INDEX_NONE)
			{
				BoneNameWithoutPrefix = FullBoneName.Mid(ColonPosition + 1);
			}
			else
			{
				BoneNameWithoutPrefix = FullBoneName;
			}

			FName BoneName = FName(*BoneNameWithoutPrefix);
			UE_LOG(LogTemp, Warning, TEXT("Bone name: %s"), *BoneName.ToString());
			UE_LOG(LogTemp, Warning, TEXT("Channel %d"), ChannelIndex);

			// Find the bone index in the target skeleton
			int32 BoneIndex = Skeleton->GetReferenceSkeleton().FindBoneIndex(BoneName);

			// If the bone exists in the target skeleton, process the animation data
			if (BoneIndex != INDEX_NONE)
			{

				// Process position keys
				TArray<FVector3f> PositionalKeys;
				for (unsigned int PosKeyIndex = 0; PosKeyIndex < NodeAnim->mNumPositionKeys; ++PosKeyIndex)
				{
					aiVectorKey& PosKey = NodeAnim->mPositionKeys[PosKeyIndex];
					float PosX = PosKey.mValue.x;
					float PosY = -PosKey.mValue.y;
					float PosZ = PosKey.mValue.z;

					FVector3f Position(PosX, PosY, PosZ);
					PositionalKeys.Add(Position);
				}

				// If there's only one position key, copy it for the same number of times as there are rotation keys
				if (PositionalKeys.Num() == 1)
				{
					FVector3f FirstPosKey = PositionalKeys[0];
					for (unsigned int i = 1; i < NodeAnim->mNumRotationKeys; ++i)
					{
						PositionalKeys.Add(FirstPosKey);
					}
				}

				// Process rotation keys
				TArray<FQuat4f> RotationalKeys;
				for (unsigned int RotKeyIndex = 0; RotKeyIndex < NodeAnim->mNumRotationKeys; ++RotKeyIndex)
				{
					const aiQuatKey& RotKey = NodeAnim->mRotationKeys[RotKeyIndex];
					const float RotX = -RotKey.mValue.x;
					const float RotY = RotKey.mValue.y;
					const float RotZ = -RotKey.mValue.z;
					const float RotW = RotKey.mValue.w;
					FQuat4f Rotation(RotX, RotY, RotZ, RotW);
					RotationalKeys.Add(Rotation);
				}

				// Process scaling keys
				TArray<FVector3f> ScalingKeys;
				for (unsigned int ScaleKeyIndex = 0; ScaleKeyIndex < NodeAnim->mNumScalingKeys; ++ScaleKeyIndex)
				{
					aiVectorKey& ScaleKey = NodeAnim->mScalingKeys[ScaleKeyIndex];
					float ScaleX = ScaleKey.mValue.x;
					float ScaleY = ScaleKey.mValue.y;
					float ScaleZ = ScaleKey.mValue.z;
					FVector3f Scale(ScaleX, ScaleY, ScaleZ);
					ScalingKeys.Add(Scale);
				}

				// Apply a transformation to the root bone to fix the orientation
				if (BoneIndex == 0)
				{
					FRotator RotationAdjustment(0.f, 0.f, 90.0f); // Adjust these values if needed
					FQuat QuatRotationAdjustment = FQuat(RotationAdjustment);

					for (FVector3f& Position : PositionalKeys)
					{
						FVector UnrealPosition(Position.X, Position.Y, Position.Z);
						UnrealPosition = QuatRotationAdjustment.RotateVector(UnrealPosition);
						Position = FVector3f(UnrealPosition.X, UnrealPosition.Y, UnrealPosition.Z);
					}

					for (FQuat4f& Rotation : RotationalKeys)
					{
						FQuat UnrealRotation(Rotation.X, Rotation.Y, Rotation.Z, Rotation.W);
						UnrealRotation = QuatRotationAdjustment * UnrealRotation;
						Rotation = FQuat4f(UnrealRotation.X, UnrealRotation.Y, UnrealRotation.Z, UnrealRotation.W);
					}
				}

				Controller.AddBoneTrack(BoneName, true);
				Controller.SetBoneTrackKeys(BoneName, PositionalKeys, RotationalKeys, ScalingKeys);
				
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Bone %s not found in skeleton"), *BoneName.ToString());
			}

		}
		Controller.NotifyPopulated();
		Controller.CloseBracket();
		#undef LOCTEXT_NAMESPACE
		#endif
	}
	return AnimSequence;
}

bool URuntimeAnimationImporter::SaveAnimation(UAnimSequence* GeneratedAnim)
{
	FDateTime Now = FDateTime::Now();
	FString Timestamp = Now.ToString(TEXT("%Y%m%d_%H%M%S"));

	FString AssetPath = "/Game/Generated/";
	FString AnimationSequenceName = "GeneratedAnimation";
	FString PackageName = AssetPath + AnimationSequenceName;
	PackageName.Append(Timestamp);
	UPackage* Package = CreatePackage(*PackageName);

	GeneratedAnim->Rename(*AnimationSequenceName, Package);
	GeneratedAnim->SetFlags(RF_Public | RF_Standalone);

	FAssetRegistryModule::AssetCreated(GeneratedAnim);

	FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	// Package save arguments
	FSavePackageArgs SaveArgs;
	SaveArgs.TopLevelFlags = EObjectFlags::RF_Public | EObjectFlags::RF_Standalone;
	SaveArgs.SaveFlags = SAVE_NoError;
	SaveArgs.bForceByteSwapping = true;

	bool bSaved = UPackage::SavePackage(Package, GeneratedAnim, *PackageFileName, SaveArgs);

	if (bSaved)
	{
		UE_LOG(LogTemp, Warning, TEXT("Saved animation sequence to content browser."));
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to save animation sequence to content browser."));
		return false;
	}
}