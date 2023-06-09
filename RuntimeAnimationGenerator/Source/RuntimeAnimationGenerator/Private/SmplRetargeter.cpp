// MotionDataExtractor.cpp

#include "SmplRetargeter.h"
#include "Math/Vector.h"

USkeleton* FSmplRetargeter::SourceSkeleton = nullptr;
USkeleton* FSmplRetargeter::TargetSkeleton = nullptr;
UIKRigDefinition* FSmplRetargeter::SourceIKRig = nullptr;
UIKRigDefinition* FSmplRetargeter::TargetIKRig = nullptr;
UIKRigController* FSmplRetargeter::SourceIKRigController = nullptr;
UIKRigController* FSmplRetargeter::TargetIKRigController = nullptr;
FReferenceSkeleton FSmplRetargeter::SourceRefSkeleton = nullptr;
FReferenceSkeleton FSmplRetargeter::TargetRefSkeleton = nullptr;
TMap<FName, FName> FSmplRetargeter:: BoneMapping;

UAnimSequence* FSmplRetargeter::RetargetAnimation2(const aiScene* Scene)
{
	UAnimSequence* AnimSequence = NewObject<UAnimSequence>(GetTransientPackage(), FName(TEXT("AnimSequenceName")));
	AnimSequence->SetSkeleton(TargetSkeleton);
	int NumFrames = 60;
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

#if WITH_EDITOR
#define LOCTEXT_NAMESPACE "UpdateFrameRate"

		// Set the animation sequence properties
		IAnimationDataController& Controller = AnimSequence->GetController();
		Controller.OpenBracket(LOCTEXT("Init Anim", "Initialize New Animation"));
		Controller.SetFrameRate(FFrameRate(AnimationTicksPerSecond, 1));
		Controller.SetPlayLength(AnimationSeconds, true);

		const TArray<FTransform> SourceRefBonePose = SourceRefSkeleton.GetRefBonePose();
		const TArray<FTransform> TargetRefBonePose = TargetRefSkeleton.GetRefBonePose();

		for (unsigned int ChannelIndex = 0; ChannelIndex < Animation->mNumChannels; ++ChannelIndex)
		{
			aiNodeAnim* NodeAnim = Animation->mChannels[ChannelIndex];
			FName BoneName = FName(NodeAnim->mNodeName.C_Str());
			if (BoneMapping.Contains(BoneName))
			{
				// Find the bone index in the target skeleton
				FName TargetBoneName = BoneMapping[BoneName];
				int32 SourceBoneIndex = SourceRefSkeleton.FindBoneIndex(BoneName);
				int32 TargetBoneIndex = TargetRefSkeleton.FindBoneIndex(TargetBoneName);
				UE_LOG(LogTemp, Warning, TEXT("Source Bone Name: %s, Target Bone Name: %s"), *BoneName.ToString(), *TargetBoneName.ToString());
				// If the bone exists in the target skeleton, process the animation data
				if (TargetBoneIndex != INDEX_NONE)
				{
					FTransform SourceBoneTransform = SourceRefBonePose[SourceBoneIndex];
					FTransform TargetBoneTransform = TargetRefBonePose[TargetBoneIndex];

					// Process position keys
					TArray<FVector3f> PositionalKeys;
					for (unsigned int PosKeyIndex = 0; PosKeyIndex < NodeAnim->mNumPositionKeys; ++PosKeyIndex)
					{
						aiVectorKey& PosKey = NodeAnim->mPositionKeys[PosKeyIndex];
						float PosX = PosKey.mValue.x;
						float PosY = -PosKey.mValue.y;
						float PosZ = PosKey.mValue.z;
						FVector3f Position(PosX, PosY, PosZ);
						//Position = Position - FVector3f(TargetBoneTransform.GetTranslation());
						//Position = Position + FVector3f(SourceBoneTransform.GetTranslation());
						Position = FVector3f(TargetBoneTransform.GetTranslation());
						PositionalKeys.Add(Position);
					}

					// Process rotation keys
					TArray<FQuat4f> RotationalKeys;

					FQuat4f SourceBoneOrientation = FQuat4f(SourceBoneTransform.GetRotation());
					FQuat4f TargetBoneOrientation = FQuat4f(TargetBoneTransform.GetRotation());
					FQuat4f OrientationDifference = SourceBoneOrientation.Inverse() * TargetBoneOrientation;

					for (unsigned int RotKeyIndex = 0; RotKeyIndex < NodeAnim->mNumRotationKeys; ++RotKeyIndex)
					{
						const aiQuatKey& RotKey = NodeAnim->mRotationKeys[RotKeyIndex];
						const float RotX = -RotKey.mValue.x;
						const float RotY = RotKey.mValue.y;
						const float RotZ = -RotKey.mValue.z;
						const float RotW = RotKey.mValue.w;
						FQuat4f Rotation(RotX, RotY, RotZ, RotW);
						Rotation = Rotation * TargetBoneOrientation;
						//Rotation = OrientationDifference * Rotation * OrientationDifference.Inverse();
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

					// If there's only one position key, copy it for the same number of times as there are rotation keys
					if (PositionalKeys.Num() == 1)
					{
						FVector3f FirstPosKey = PositionalKeys[0];
						for (unsigned int i = 1; i < NodeAnim->mNumRotationKeys; ++i)
						{
							PositionalKeys.Add(FirstPosKey);
						}
					}

					if (RotationalKeys.Num() == 1)
					{
						FQuat4f FirstRotKey = RotationalKeys[0];
						for (unsigned int i = 1; i < NodeAnim->mNumPositionKeys; ++i)
						{
							RotationalKeys.Add(FirstRotKey);
						}
					}

					if (ScalingKeys.Num() == 1)
					{
						FVector3f FirstScaleKey = ScalingKeys[0];
						for (unsigned int i = 1; i < NodeAnim->mNumPositionKeys; ++i)
						{
							ScalingKeys.Add(FirstScaleKey);
						}
					}

					if (Controller.AddBoneTrack(TargetBoneName, true) != INDEX_NONE)
					{
						UE_LOG(LogTemp, Warning, TEXT("Adding %s Bone Track Success"), *TargetBoneName.ToString());
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Adding %s Bone Track Failed"), *TargetBoneName.ToString());
					}
					Controller.SetBoneTrackKeys(TargetBoneName, PositionalKeys, RotationalKeys, ScalingKeys);
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Bone %s not found in skeleton"), *TargetBoneName.ToString());
				}
			}
		}
		Controller.NotifyPopulated();
		Controller.CloseBracket();
#undef LOCTEXT_NAMESPACE
#endif
	}
	return AnimSequence;
}

// apply to smpl
UAnimSequence* FSmplRetargeter::GenerateSmplAnim(const aiScene* Scene)
{
	UAnimSequence* AnimSequence = NewObject<UAnimSequence>(GetTransientPackage(), FName(TEXT("AnimSequenceName")));
	AnimSequence->SetSkeleton(SourceSkeleton);
	int NumFrames = 60;
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

#if WITH_EDITOR
#define LOCTEXT_NAMESPACE "UpdateFrameRate"

		// Set the animation sequence properties
		IAnimationDataController& Controller = AnimSequence->GetController();
		Controller.OpenBracket(LOCTEXT("Init Anim", "Initialize New Animation"));
		Controller.SetFrameRate(FFrameRate(AnimationTicksPerSecond / 3, 1));
		Controller.SetPlayLength(AnimationSeconds * 3, true);

		for (unsigned int ChannelIndex = 0; ChannelIndex < Animation->mNumChannels; ++ChannelIndex)
		{
			aiNodeAnim* NodeAnim = Animation->mChannels[ChannelIndex];
			FName BoneName = FName(NodeAnim->mNodeName.C_Str());
			if (BoneMapping.Contains(BoneName))
			{
				// Find the bone index in the target skeleton
				int32 SourceBoneIndex = SourceRefSkeleton.FindBoneIndex(BoneName);
				// If the bone exists in the target skeleton, process the animation data
				if (SourceBoneIndex != INDEX_NONE)
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

					// If there's only one position key, copy it for the same number of times as there are rotation keys
					if (PositionalKeys.Num() == 1)
					{
						FVector3f FirstPosKey = PositionalKeys[0];
						for (unsigned int i = 1; i < NodeAnim->mNumRotationKeys; ++i)
						{
							PositionalKeys.Add(FirstPosKey);
						}
					}

					if (RotationalKeys.Num() == 1)
					{
						FQuat4f FirstRotKey = RotationalKeys[0];
						for (unsigned int i = 1; i < NodeAnim->mNumPositionKeys; ++i)
						{
							RotationalKeys.Add(FirstRotKey);
						}
					}

					if (ScalingKeys.Num() == 1)
					{
						FVector3f FirstScaleKey = ScalingKeys[0];
						for (unsigned int i = 1; i < NodeAnim->mNumPositionKeys; ++i)
						{
							ScalingKeys.Add(FirstScaleKey);
						}
					}

					//Apply a transformation to the root bone to fix the orientation
					if (SourceBoneIndex == 0)
					{
						UE_LOG(LogTemp, Warning, TEXT("Fix Orientation"));
						UE_LOG(LogTemp, Warning, TEXT("Bone Index 0 Bone: %s"), *BoneName.ToString());
						FRotator RotationAdjustment(0.f, 0.f, 90.0f);
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
					if (Controller.AddBoneTrack(BoneName, true) != INDEX_NONE)
					{
						UE_LOG(LogTemp, Warning, TEXT("Adding %s Bone Track Success"), *BoneName.ToString());
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Adding %s Bone Track Failed"), *BoneName.ToString());
					}
					Controller.SetBoneTrackKeys(BoneName, PositionalKeys, RotationalKeys, ScalingKeys);
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Bone %s not found in skeleton"), *BoneName.ToString());
				}
			}
		}
		Controller.NotifyPopulated();
		Controller.CloseBracket();
#undef LOCTEXT_NAMESPACE
#endif
	}

	AnimSequence = RetargetAnimation(AnimSequence);

	return AnimSequence;
}

UAnimSequence* FSmplRetargeter::RetargetAnimation4()
{
	const FString SourceAnimPath = TEXT("/RuntimeAnimationGenerator/GeneratedAnimation20230607_150411.GeneratedAnimation");
	UAnimSequence* SourceAnimSequence = Cast<UAnimSequence>(StaticLoadObject(UAnimSequence::StaticClass(), nullptr, *SourceAnimPath));
	UAnimSequence* TargetAnimSequence = NewObject<UAnimSequence>(GetTransientPackage(), FName(TEXT("Retargeted")));
	TargetAnimSequence->SetSkeleton(TargetSkeleton);
	
#if WITH_EDITOR
#define  LOCTEXT_NAMESPACE "UpdateFrameRate"

	IAnimationDataController& SourceController = SourceAnimSequence->GetController();
	UAnimDataModel* SourceModel = SourceController.GetModel();

	IAnimationDataController& TargetController = TargetAnimSequence->GetController();
	UAnimDataModel* TargetModel = TargetController.GetModel();

	TargetController.OpenBracket(LOCTEXT("Init Anim", "Initialize New Animation"));
	TargetController.SetFrameRate(SourceModel->GetFrameRate());
	TargetController.SetPlayLength(SourceModel->GetPlayLength(), true);

	TArray<FBoneAnimationTrack> SourceAnimTracks = SourceModel->GetBoneAnimationTracks();

	for (FBoneAnimationTrack SourceAnimTrack : SourceAnimTracks)
	{
		FName SourceBoneName = SourceAnimTrack.Name;
		if (BoneMapping.Contains(SourceBoneName))
		{
			FName TargetBoneName = BoneMapping[SourceBoneName];
			FRawAnimSequenceTrack SourceTrackData = SourceAnimTrack.InternalTrackData;
			TArray<FVector3f> SourcePosKeys = SourceTrackData.PosKeys;
			TArray<FQuat4f> SourceRotKeys = SourceTrackData.RotKeys;
			TArray<FVector3f> SourceScaleKeys = SourceTrackData.ScaleKeys;
			int32 TargetBoneIndex = TargetRefSkeleton.FindBoneIndex(TargetBoneName);

			FQuat4f SourceBoneOrientation = FQuat4f(SourceRefSkeleton.GetRefBonePose()[SourceAnimTrack.BoneTreeIndex].GetRotation());
			FQuat4f TargetBoneOrientation = FQuat4f(TargetRefSkeleton.GetRefBonePose()[TargetBoneIndex].GetRotation());

			FQuat4f OrientationDifference = SourceBoneOrientation.Inverse() * TargetBoneOrientation;

			// Adjust the position and rotation keys
			TArray<FVector3f> AdjustedPosKeys;
			TArray<FQuat4f> AdjustedRotKeys;
			for (int i = 0; i < SourcePosKeys.Num(); ++i)
			{
				FVector3f AdjustedPos = OrientationDifference.RotateVector(SourcePosKeys[i]);
				//AdjustedPos = FVector3f(TargetRefSkeleton.GetRefBonePose()[TargetBoneIndex].GetTranslation());
				AdjustedPosKeys.Add(AdjustedPos);

				FQuat4f AdjustedRot = OrientationDifference * SourceRotKeys[i] * OrientationDifference.Inverse();
				AdjustedRot = TargetBoneOrientation;
				AdjustedRotKeys.Add(AdjustedRot);
			}
			TargetController.AddBoneTrack(TargetBoneName, true);
			TargetController.SetBoneTrackKeys(TargetBoneName, SourcePosKeys, AdjustedRotKeys, SourceScaleKeys);
		}
	}

	TargetController.NotifyPopulated();
	TargetController.CloseBracket();
#undef LOCTEXT_NAMESPACE
#endif

	return TargetAnimSequence;
}

UAnimSequence* FSmplRetargeter::RetargetAnimation(UAnimSequence* SmplAnim)
{
	UAnimSequence* SourceAnimSequence = SmplAnim;
	UAnimSequence* TargetAnimSequence = NewObject<UAnimSequence>(GetTransientPackage(), FName(TEXT("Retargeted")));
	TargetAnimSequence->SetSkeleton(TargetSkeleton);

#if WITH_EDITOR
#define  LOCTEXT_NAMESPACE "UpdateFrameRate"

	IAnimationDataController& SourceController = SourceAnimSequence->GetController();
	UAnimDataModel* SourceModel = SourceController.GetModel();

	IAnimationDataController& TargetController = TargetAnimSequence->GetController();
	UAnimDataModel* TargetModel = TargetController.GetModel();

	TargetController.OpenBracket(LOCTEXT("Init Anim", "Initialize New Animation"));
	TargetController.SetFrameRate(SourceModel->GetFrameRate());
	TargetController.SetPlayLength(SourceModel->GetPlayLength(), true);

	TArray<FBoneAnimationTrack> SourceAnimTracks = SourceModel->GetBoneAnimationTracks();

	for (FBoneAnimationTrack SourceAnimTrack : SourceAnimTracks)
	{
		FName SourceBoneName = SourceAnimTrack.Name;
		if (BoneMapping.Contains(SourceBoneName))
		{
			FName TargetBoneName = BoneMapping[SourceBoneName];
			FRawAnimSequenceTrack SourceTrackData = SourceAnimTrack.InternalTrackData;
			TArray<FVector3f> SourcePosKeys = SourceTrackData.PosKeys;
			TArray<FQuat4f> SourceRotKeys = SourceTrackData.RotKeys;
			TArray<FVector3f> SourceScaleKeys = SourceTrackData.ScaleKeys;
			int32 TargetBoneIndex = TargetRefSkeleton.FindBoneIndex(TargetBoneName);

			FQuat4f SourceBoneOrientation = FQuat4f(SourceRefSkeleton.GetRefBonePose()[SourceAnimTrack.BoneTreeIndex].GetRotation());
			FQuat4f TargetBoneOrientation = FQuat4f(TargetRefSkeleton.GetRefBonePose()[TargetBoneIndex].GetRotation());

			FQuat4f OrientationDifference = SourceBoneOrientation.Inverse() * TargetBoneOrientation;

			// Adjust the position and rotation keys
			TArray<FVector3f> AdjustedPosKeys;
			TArray<FQuat4f> AdjustedRotKeys;
			for (int i = 0; i < SourcePosKeys.Num(); ++i)
			{
				FVector3f AdjustedPos = OrientationDifference.RotateVector(SourcePosKeys[i]);
				//AdjustedPos = FVector3f(TargetRefSkeleton.GetRefBonePose()[TargetBoneIndex].GetTranslation());
				AdjustedPosKeys.Add(AdjustedPos);

				FQuat4f AdjustedRot = OrientationDifference * SourceRotKeys[i] * OrientationDifference.Inverse();
				AdjustedRot = TargetBoneOrientation;
				AdjustedRotKeys.Add(AdjustedRot);
			}
			TargetController.AddBoneTrack(TargetBoneName, true);
			TargetController.SetBoneTrackKeys(TargetBoneName, SourcePosKeys, AdjustedRotKeys, SourceScaleKeys);
		}
	}

	TargetController.NotifyPopulated();
	TargetController.CloseBracket();
#undef LOCTEXT_NAMESPACE
#endif

	return TargetAnimSequence;
}

FQuat4f FSmplRetargeter::GetBoneOrientation(USkeleton* Skeleton, FName BoneName)
{
	int32 BoneIndex = Skeleton->GetReferenceSkeleton().FindBoneIndex(BoneName);
	if (BoneIndex == INDEX_NONE)
	{
		// Bone not found
		return FQuat4f::Identity;
	}

	// Get the transform of the bone and its parent
	FTransform BoneTransform = Skeleton->GetReferenceSkeleton().GetRefBonePose()[BoneIndex];
	FTransform ParentTransform = FTransform::Identity;
	int32 ParentIndex = Skeleton->GetReferenceSkeleton().GetParentIndex(BoneIndex);
	if (ParentIndex != INDEX_NONE)
	{
		ParentTransform = Skeleton->GetReferenceSkeleton().GetRefBonePose()[ParentIndex];
	}

	// Calculate the relative transform
	FTransform RelativeTransform = BoneTransform.GetRelativeTransform(ParentTransform);

	// The relative rotation is the orientation of the bone
	return FQuat4f(RelativeTransform.GetRotation());
}


UAnimSequence* FSmplRetargeter::RetargetAnimation(const aiScene* Scene)
{
    UAnimSequence* AnimSequence = NewObject<UAnimSequence>(GetTransientPackage(), FName(TEXT("Retargeted")));
    AnimSequence->SetSkeleton(TargetSkeleton);
    int NumFrames = 30;
    AnimSequence->ImportFileFramerate = StaticCast<float>(NumFrames);
    AnimSequence->ImportResampleFramerate = NumFrames;

    aiAnimation* Animation = Scene->mAnimations[0];

    float AnimationTicksPerSecond = Animation->mTicksPerSecond;
    float AnimationDuration = Animation->mDuration;
    float AnimationSeconds = AnimationDuration / AnimationTicksPerSecond;
    UE_LOG(LogTemp, Warning, TEXT("Animation Seconds: %f"), AnimationSeconds);

	#if WITH_EDITOR
	#define LOCTEXT_NAMESPACE "UpdateFrameRate"

    // Set the animation sequence properties
    IAnimationDataController& Controller = AnimSequence->GetController();
    Controller.OpenBracket(LOCTEXT("Init Anim", "Initialize New Animation"));
    Controller.SetFrameRate(FFrameRate(AnimationTicksPerSecond, 1));
    Controller.SetPlayLength(AnimationSeconds, true);

	for (unsigned int ChannelIndex = 0; ChannelIndex < Animation->mNumChannels; ++ChannelIndex)
	{
		aiNodeAnim* NodeAnim = Animation->mChannels[ChannelIndex];

		FName BoneName = FName(NodeAnim->mNodeName.C_Str());
		if (BoneMapping.Contains(BoneName))
		{
			UE_LOG(LogTemp, Warning, TEXT("Source Bone: %s"), *BoneName.ToString());
			FName TargetBoneName = BoneMapping[BoneName];
			UE_LOG(LogTemp, Warning, TEXT("Target Bone: %s"), *TargetBoneName.ToString());
			int32 BoneIndex = TargetSkeleton->GetReferenceSkeleton().FindBoneIndex(TargetBoneName);
			if (BoneIndex != INDEX_NONE)
			{
				// Process position keys
				TArray<FVector3f> PositionalKeys;

				for (unsigned int PosKeyIndex = 0; PosKeyIndex < NodeAnim->mNumPositionKeys; ++PosKeyIndex)
				{
					aiVectorKey& PosKey = NodeAnim->mPositionKeys[PosKeyIndex];
					UE_LOG(LogTemp, Warning, TEXT("PosX: %f, PosY: %f, PosZ: %f"), PosKey.mValue.x, PosKey.mValue.y, PosKey.mValue.z);

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
					UE_LOG(LogTemp, Warning, TEXT("RotX: %f"), RotX);
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
				UE_LOG(LogTemp, Warning, TEXT("Adding bone track: %s"), *TargetBoneName.ToString());
				Controller.AddBoneTrack(TargetBoneName, true);
				Controller.SetBoneTrackKeys(TargetBoneName, PositionalKeys, RotationalKeys, ScalingKeys);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Bone %s not found in skeleton"), *BoneName.ToString());
			}
		}
	}

	Controller.NotifyPopulated();
	Controller.CloseBracket();
	#undef LOCTEXT_NAMESPACE
	#endif

	return AnimSequence;
}

void FSmplRetargeter::InitializeSource()
{
    SourceIKRig = LoadSmplIKRig();
    SourceIKRigController = UIKRigController::GetIKRigController(SourceIKRig);
    SourceSkeleton = SourceIKRigController->GetSkeleton();
	SourceRefSkeleton = SourceSkeleton->GetReferenceSkeleton();
    UE_LOG(LogTemp, Warning, TEXT("Source Skeleton: %s"), *SourceSkeleton->GetName());
}

void FSmplRetargeter::SetTarget(UIKRigDefinition* IKRig)
{
    InitializeSource();

    TargetIKRig = IKRig;
    TargetIKRigController = UIKRigController::GetIKRigController(TargetIKRig);
    TargetSkeleton = TargetIKRigController->GetSkeleton();
	TargetRefSkeleton = TargetSkeleton->GetReferenceSkeleton();
    UE_LOG(LogTemp, Warning, TEXT("Target Skeleton: %s"), *TargetSkeleton->GetName());

    const TArray<FBoneChain>& SourceBoneChains = SourceIKRig->GetRetargetChains();
    const TArray<FBoneChain>& TargetBoneChains = TargetIKRig->GetRetargetChains();

	// Make sure the source and target IKRigs have the same number of bone chains
    if (SourceBoneChains.Num() != TargetBoneChains.Num())
    {
        UE_LOG(LogTemp, Warning, TEXT("Source and target IKRigs have a different number of bone chains"));
        return;
    }

	// Iterate over the bone chains of the source and target IKRigs
	for (int i = 0; i < SourceBoneChains.Num(); i++)
	{
		const FBoneChain& SourceBoneChain = SourceBoneChains[i];
		const FBoneChain& TargetBoneChain = TargetBoneChains[i];

		// Get the start and end bones of the source bone chain
		FName SourceStartBoneName = SourceIKRigController->GetRetargetChainStartBone(SourceBoneChain.ChainName);
		FName SourceEndBoneName = SourceIKRigController->GetRetargetChainEndBone(SourceBoneChain.ChainName);

		// Get the start and end bones of the target bone chain
		FName TargetStartBoneName = TargetIKRigController->GetRetargetChainStartBone(TargetBoneChain.ChainName);
		FName TargetEndBoneName = TargetIKRigController->GetRetargetChainEndBone(TargetBoneChain.ChainName);

		// Add the start and end bones to the mapping
		// BoneMapping.Add(SourceStartBoneName, TargetStartBoneName);
		BoneMapping.Add(SourceEndBoneName, TargetEndBoneName);

		// Get the indices of the start and end bones in the bone tree
		int32 SourceStartBoneIndex = SourceRefSkeleton.FindBoneIndex(SourceStartBoneName);
		int32 SourceEndBoneIndex = SourceRefSkeleton.FindBoneIndex(SourceEndBoneName);

		// Get the indices of the start and end bones in the bone tree
		int32 TargetStartBoneIndex = TargetRefSkeleton.FindBoneIndex(TargetStartBoneName);
		int32 TargetEndBoneIndex = TargetRefSkeleton.FindBoneIndex(TargetEndBoneName);

		TArray<int32> SourceBoneIndices;
		TArray<int32> TargetBoneIndices;

		int32 InbetweenIndex = SourceEndBoneIndex;
		while (InbetweenIndex != SourceStartBoneIndex)
		{
			InbetweenIndex = SourceRefSkeleton.GetParentIndex(InbetweenIndex);
			//FName InbetweenBoneName = SourceRefSkeleton.GetBoneName(InbetweenIndex);
			//UE_LOG(LogTemp, Warning, TEXT("Chain Num: %d, Source Inbetween bone name: %s"), i, *InbetweenBoneName.ToString());
			SourceBoneIndices.Add(InbetweenIndex);
		}

		InbetweenIndex = TargetEndBoneIndex;
		while (InbetweenIndex != TargetStartBoneIndex)
		{
			InbetweenIndex = TargetRefSkeleton.GetParentIndex(InbetweenIndex);
			//FName InbetweenBoneName = TargetRefSkeleton.GetBoneName(InbetweenIndex);
			//UE_LOG(LogTemp, Warning, TEXT("Chain Num: %d, Target Inbetween bone name: %s"), i, *InbetweenBoneName.ToString());
			TargetBoneIndices.Add(InbetweenIndex);
		}

		for (int32 Index = 0; Index != SourceBoneIndices.Num(); ++Index)
		{
			int32 SourceIndex = SourceBoneIndices[Index];
			FName SourceChildBoneName = SourceRefSkeleton.GetBoneName(SourceIndex);
			UE_LOG(LogTemp, Warning, TEXT("Source bone name: %s"), *SourceChildBoneName.ToString());
			int32 TargetIndex = TargetBoneIndices[Index];
			FName TargetChildBoneName = TargetRefSkeleton.GetBoneName(TargetIndex);

			BoneMapping.Add(SourceChildBoneName, TargetChildBoneName);
			UE_LOG(LogTemp, Warning, TEXT("Source: %s, Target: %s"), *SourceChildBoneName.ToString(), *TargetChildBoneName.ToString());
		}
	}
}

UIKRigDefinition* FSmplRetargeter::LoadSmplIKRig()
{
    const FString SmplRigPath = TEXT("/RuntimeAnimationGenerator/SMPL/IK_SMPL.IK_SMPL");

    UIKRigDefinition* IKRigDefinitionInstance = Cast<UIKRigDefinition>(StaticLoadObject(UIKRigDefinition::StaticClass(), nullptr, *SmplRigPath));
    if (!IKRigDefinitionInstance) UE_LOG(LogTemp, Warning, TEXT("Failed to load SMPL IK Rig"));

    UIKRigController* IKRigControllerInstance = UIKRigController::GetIKRigController(IKRigDefinitionInstance);
    if (!IKRigControllerInstance) UE_LOG(LogTemp, Warning, TEXT("Failed to load SMPL IK Rig Controller"));

    return IKRigDefinitionInstance;
}

