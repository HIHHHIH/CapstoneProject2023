#include "SmplRetargeter.h"
#include "RAGLog.h"
#include "Retargeter/IKRetargetProcessor.h"
#include "AnimPose.h"

void USmplRetargeter::Initialize(UIKRetargeter* InRetargeter, USkeletalMesh* InSourceMesh, USkeletalMesh* InTargetMesh)
{
	Retargeter = InRetargeter;
	SourceMesh = InSourceMesh;
	TargetMesh = InTargetMesh;
}

UAnimSequence* USmplRetargeter::RetargetAnimation(UAnimSequence* SMPLAnim) const
{
	UIKRetargetProcessor* Processor = NewObject<UIKRetargetProcessor>(GetTransientPackage());
	Processor->Initialize(SourceMesh, TargetMesh, Retargeter);
	if (!Processor->IsInitialized())
	{
		UE_LOG(LogRAG, Warning, TEXT("Unable to initialize the IK Retargeter. Newly created animations were not retargeted!"));
		return nullptr;
	}

	UAnimSequence* SourceAnimSequence = SMPLAnim;
	UAnimSequence* TargetAnimSequence = NewObject<UAnimSequence>(GetTransientPackage(), FName(TEXT("RetargetedAnimSequence")));
	TargetAnimSequence->SetSkeleton(TargetMesh->GetSkeleton());

	// source skeleton data
	const FRetargetSkeleton& SourceSkeletonRef = Processor->GetSourceSkeleton();
	const TArray<FName>& SourceBoneNames = SourceSkeletonRef.BoneNames;
	const int32 NumSourceBones = SourceBoneNames.Num();

	// target skeleton data
	const FTargetSkeleton& TargetSkeletonRef = Processor->GetTargetSkeleton();
	const TArray<FName>& TargetBoneNames = TargetSkeletonRef.BoneNames;
	const int32 NumTargetBones = TargetBoneNames.Num();

	// allocate source pose
	TArray<FTransform> SourceComponentPose;
	SourceComponentPose.SetNum(NumSourceBones);

	// get anim controllers
	IAnimationDataController& SourceController = SourceAnimSequence->GetController();
	UAnimDataModel* SourceModel = SourceController.GetModel();
	IAnimationDataController& TargetController = TargetAnimSequence->GetController();

	// number of frames in this animation
	const int32 NumFrames = SourceAnimSequence->GetNumberOfSampledKeys();

	// allocate target keyframe data
	TArray<FRawAnimSequenceTrack> BoneTracks;
	BoneTracks.SetNumZeroed(NumTargetBones);

	// BoneTracks arrays allocation
	for (int32 TargetBoneIndex = 0; TargetBoneIndex < NumTargetBones; ++TargetBoneIndex)
	{
		BoneTracks[TargetBoneIndex].PosKeys.SetNum(NumFrames);
		BoneTracks[TargetBoneIndex].RotKeys.SetNum(NumFrames);
		BoneTracks[TargetBoneIndex].ScaleKeys.SetNum(NumFrames);
	}

#define LOCTEXT_NAMESPACE "Retargeting SMPL Animation"

	TargetController.OpenBracket(FText::FromString("Generating Retargeted Animation Data"), true);
	TargetController.SetFrameRate(SourceModel->GetFrameRate());
	TargetController.SetPlayLength(SourceModel->GetPlayLength(), true);

	// ensure we evaluate the source animation using the skeletal mesh proportions that were evaluated in the viewport
	FAnimPoseEvaluationOptions EvaluationOptions = FAnimPoseEvaluationOptions();
	EvaluationOptions.OptionalSkeletalMesh = SourceSkeletonRef.SkeletalMesh;

	// retarget each frame's pose from source to target
	for (int32 FrameIndex = 0; FrameIndex < NumFrames; ++FrameIndex)
	{
		// get the source global pose
		FAnimPose SourcePoseAtFrame;
		UAnimPoseExtensions::GetAnimPoseAtFrame(SourceAnimSequence, FrameIndex, EvaluationOptions, SourcePoseAtFrame);

		for (int32 BoneIndex = 0; BoneIndex < NumSourceBones; BoneIndex++)
		{
			const FName& BoneName = SourceBoneNames[BoneIndex];
			SourceComponentPose[BoneIndex] = UAnimPoseExtensions::GetBonePose(SourcePoseAtFrame, BoneName, EAnimPoseSpaces::World);
		}

		// update goals
		Processor->CopyAllSettingsFromAsset();

		// run the retarget
		const TArray<FTransform>& TargetComponentPose = Processor->RunRetargeter(SourceComponentPose);

		// convert to a local-space pose
		TArray<FTransform> TargetLocalPose = TargetComponentPose;
		TargetSkeletonRef.UpdateLocalTransformsBelowBone(0, TargetLocalPose, TargetComponentPose);

		// store key data for each bone
		for (int32 TargetBoneIndex = 0; TargetBoneIndex < NumTargetBones; ++TargetBoneIndex)
		{
			const FTransform& LocalPose = TargetLocalPose[TargetBoneIndex];

			FRawAnimSequenceTrack& BoneTrack = BoneTracks[TargetBoneIndex];
			BoneTrack.PosKeys[FrameIndex] = FVector3f(LocalPose.GetLocation());
			BoneTrack.RotKeys[FrameIndex] = FQuat4f(LocalPose.GetRotation());
			BoneTrack.ScaleKeys[FrameIndex] = FVector3f(LocalPose.GetScale3D());
		}
	}

	// add keys to bone tracks
	for (int32 TargetBoneIndex = 0; TargetBoneIndex < NumTargetBones; ++TargetBoneIndex)
	{
		const FName& TargetBoneName = TargetBoneNames[TargetBoneIndex];
		const FRawAnimSequenceTrack& RawTrack = BoneTracks[TargetBoneIndex];
		TargetController.AddBoneTrack(TargetBoneName, true);
		TargetController.SetBoneTrackKeys(TargetBoneName, RawTrack.PosKeys, RawTrack.RotKeys, RawTrack.ScaleKeys);
	}
	TargetController.NotifyPopulated();
	TargetController.CloseBracket(true);

#undef LOCTEXT_NAMESPACE

	return TargetAnimSequence;
}
