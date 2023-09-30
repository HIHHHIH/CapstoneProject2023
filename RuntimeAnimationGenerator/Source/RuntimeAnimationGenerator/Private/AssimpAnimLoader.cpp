#include "AssimpAnimLoader.h"
#include <assimp/postprocess.h>
#include "RAGLog.h"

static constexpr int FbxNumFrames = 120;
static constexpr float FilterThreshold = 1.f;

void UAssimpAnimLoader::Initialize(USkeletalMesh* InSourceMesh)
{
	SourceMesh = InSourceMesh;
	Importer = new Assimp::Importer();
}

const aiScene* UAssimpAnimLoader::ImportAiScene(const FString& FilePath) const
{
	return Importer->ReadFile(TCHAR_TO_UTF8(*FilePath), aiProcessPreset_TargetRealtime_MaxQuality);
}

UAnimSequence* UAssimpAnimLoader::CreateAnimSequenceFromAiScene(const aiScene* Scene) const
{
#define LOCTEXT_NAMESPACE "CreateSMPLAnimSequence"

	UAnimSequence* AnimSequence = NewObject<UAnimSequence>(GetTransientPackage(), FName(TEXT("AnimSequenceName")));
	AnimSequence->SetSkeleton(SourceMesh->GetSkeleton());
	const FReferenceSkeleton SourceRefSkeleton = SourceMesh->GetSkeleton()->GetReferenceSkeleton();
	const aiAnimation* Animation = Scene->mAnimations[0];

	const float AnimationTicksPerSecond = Animation->mTicksPerSecond;
	const float AnimationDuration = Animation->mDuration;
	const float AnimationSeconds = AnimationDuration / AnimationTicksPerSecond;

	IAnimationDataController& Controller = AnimSequence->GetController();
	Controller.OpenBracket(LOCTEXT("Init Anim", "Initialize New Animation"));
	Controller.SetFrameRate(FFrameRate(AnimationTicksPerSecond, 1));
	Controller.SetPlayLength(AnimationSeconds, true);

	for (unsigned int ChannelIndex = 0; ChannelIndex < Animation->mNumChannels; ++ChannelIndex)
	{
		const aiNodeAnim* NodeAnim = Animation->mChannels[ChannelIndex];
		FName BoneName = FName(NodeAnim->mNodeName.C_Str());
		const int32 SourceBoneIndex = SourceRefSkeleton.FindBoneIndex(BoneName);

		if (SourceBoneIndex == INDEX_NONE)
		{
			UE_LOG(LogRAG, Warning, TEXT("%s bone is not found in skeleton"), *BoneName.ToString());
			continue;
		}

		TArray<FVector3f> PositionalKeys;
		TArray<FQuat4f> RotationalKeys;
		TArray<FVector3f> ScalingKeys;

		if (BoneName.IsEqual(TEXT("m_avg_root")))
		{
			AddPositionalKeys(PositionalKeys, NodeAnim, false);
			AddRotationalKeys(RotationalKeys, NodeAnim, true);
			AddScalingKeys(ScalingKeys, NodeAnim, true);

			FixRootOrientation(PositionalKeys, RotationalKeys);
		}
		else if (BoneName.IsEqual(TEXT("m_avg_Pelvis")))
		{
			AddPositionalKeys(PositionalKeys, NodeAnim, false);
			AddRotationalKeys(RotationalKeys, NodeAnim, false);
			AddScalingKeys(ScalingKeys, NodeAnim, true);
			FilterKeyFrameOutliers(RotationalKeys);
		}
		else
		{
			AddPositionalKeys(PositionalKeys, NodeAnim, true);
			AddRotationalKeys(RotationalKeys, NodeAnim, false);
			AddScalingKeys(ScalingKeys, NodeAnim, true);

			if (BoneName.IsEqual(TEXT("m_avg_R_Elbow")) || BoneName.IsEqual(TEXT("m_avg_L_Elbow")))
			{
				FilterKeyFrameOutliers(RotationalKeys);
			}
		}

		const bool AddingBoneTrack = (Controller.AddBoneTrack(BoneName, true) != INDEX_NONE);
		const bool SettingBoneTrackKeys = Controller.SetBoneTrackKeys(BoneName, PositionalKeys, RotationalKeys, ScalingKeys);
		if (!AddingBoneTrack || !SettingBoneTrackKeys)
		{
			UE_LOG(LogRAG, Warning, TEXT("Failed adding %s bone track"), *BoneName.ToString());
			return nullptr;
		}
	}
	Controller.NotifyPopulated();
	Controller.CloseBracket();
#undef LOCTEXT_NAMESPACE

	return AnimSequence;
}

void UAssimpAnimLoader::AddPositionalKeys(TArray<FVector3f>& Keys, const aiNodeAnim* NodeAnim, const bool UseFirstOnly)
{
	if (UseFirstOnly)
	{
		const aiVectorKey& PosKey = NodeAnim->mPositionKeys[0];
		for (unsigned int PosKeyIndex = 0; PosKeyIndex < FbxNumFrames; ++PosKeyIndex)
		{
			FVector3f Position(PosKey.mValue.x, -PosKey.mValue.y, PosKey.mValue.z);
			Keys.Add(Position);
		}
	}
	else
	{
		for (unsigned int PosKeyIndex = 0; PosKeyIndex < FbxNumFrames; ++PosKeyIndex)
		{
			const aiVectorKey& PosKey = NodeAnim->mPositionKeys[PosKeyIndex];
			FVector3f Position(PosKey.mValue.x, -PosKey.mValue.y, PosKey.mValue.z);
			Keys.Add(Position);
		}
	}
}

void UAssimpAnimLoader::AddRotationalKeys(TArray<FQuat4f>& Keys, const aiNodeAnim* NodeAnim, const bool UseFirstOnly)
{
	if (UseFirstOnly)
	{
		const aiQuatKey& RotKey = NodeAnim->mRotationKeys[0];
		for (unsigned int RotKeyIndex = 0; RotKeyIndex < FbxNumFrames; ++RotKeyIndex)
		{
			FQuat4f Rotation(-RotKey.mValue.x, RotKey.mValue.y, -RotKey.mValue.z, RotKey.mValue.w);
			Keys.Add(Rotation);
		}
	}
	else
	{
		for (unsigned int RotKeyIndex = 0; RotKeyIndex < FbxNumFrames; ++RotKeyIndex)
		{
			const aiQuatKey& RotKey = NodeAnim->mRotationKeys[RotKeyIndex];
			FQuat4f Rotation(-RotKey.mValue.x, RotKey.mValue.y, -RotKey.mValue.z, RotKey.mValue.w);
			Keys.Add(Rotation);
		}
	}
}

void UAssimpAnimLoader::AddScalingKeys(TArray<FVector3f>& Keys, const aiNodeAnim* NodeAnim, const bool UseFirstOnly)
{
	if (UseFirstOnly)
	{
		const aiVectorKey& ScaleKey = NodeAnim->mScalingKeys[0];
		for (unsigned int ScaleKeyIndex = 0; ScaleKeyIndex < FbxNumFrames; ++ScaleKeyIndex)
		{
			FVector3f Scale(ScaleKey.mValue.x, ScaleKey.mValue.y, ScaleKey.mValue.z);
			Keys.Add(Scale);
		}
	}
	else
	{
		for (unsigned int ScaleKeyIndex = 0; ScaleKeyIndex < FbxNumFrames; ++ScaleKeyIndex)
		{
			const aiVectorKey& ScaleKey = NodeAnim->mScalingKeys[ScaleKeyIndex];
			FVector3f Scale(ScaleKey.mValue.x, ScaleKey.mValue.y, ScaleKey.mValue.z);
			Keys.Add(Scale);
		}
	}
}

void UAssimpAnimLoader::FilterKeyFrameOutliers(TArray<FQuat4f>& RotationalKeys, FString* LogMessage)
{
	const int InitialKeyNum = RotationalKeys.Num();
	int Count = 0;

	for (int i = 1; i < RotationalKeys.Num() - 1; i++)
	{
		const float Angle = RotationalKeys[i].AngularDistance(RotationalKeys[i - 1]);
		if (Angle > FilterThreshold)
		{
			RotationalKeys.RemoveAt(i);
			Count++;
			i--;
		}
	}
	RotationalKeys.SetNum(120);

	if (LogMessage)
	{
		*LogMessage = FString::Printf(TEXT("Removed %d outliers among %d key frames"), Count, InitialKeyNum);
	}
}

void UAssimpAnimLoader::FixRootOrientation(TArray<FVector3f>& PositionalKeys, TArray<FQuat4f>& RotationalKeys)
{
	const FRotator RotationAdjustment(0.f, 0.f, 90.0f);
	const FQuat QuatRotationAdjustment = FQuat(RotationAdjustment);

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
