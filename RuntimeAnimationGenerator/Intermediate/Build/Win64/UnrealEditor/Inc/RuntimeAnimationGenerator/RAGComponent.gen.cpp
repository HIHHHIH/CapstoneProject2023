// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RuntimeAnimationGenerator/Public/RAGComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRAGComponent() {}
// Cross Module References
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_URAGComponent_NoRegister();
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_URAGComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RuntimeAnimationGenerator();
	ENGINE_API UClass* Z_Construct_UClass_UAnimSequence_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
	IKRIG_API UClass* Z_Construct_UClass_UIKRetargeter_NoRegister();
	RUNTIMEANIMATIONGENERATOR_API UFunction* Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature();
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_URAGManager_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(URAGComponent::execHandleOnAnimationGenerated)
	{
		P_GET_OBJECT(UAnimSequence,Z_Param_GeneratedAnimation);
		P_GET_PROPERTY(FStrProperty,Z_Param_UserText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleOnAnimationGenerated(Z_Param_GeneratedAnimation,Z_Param_UserText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URAGComponent::execPlayAnimation)
	{
		P_GET_OBJECT(UAnimSequence,Z_Param_AnimSequence);
		P_GET_PROPERTY(FStrProperty,Z_Param_UserText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlayAnimation(Z_Param_AnimSequence,Z_Param_UserText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URAGComponent::execGenerateAnimation)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_UserText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GenerateAnimation(Z_Param_UserText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URAGComponent::execSetRAGConfig)
	{
		P_GET_OBJECT(ACharacter,Z_Param_InTargetCharacter);
		P_GET_OBJECT(UIKRetargeter,Z_Param_Retargeter);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRAGConfig(Z_Param_InTargetCharacter,Z_Param_Retargeter);
		P_NATIVE_END;
	}
	void URAGComponent::StaticRegisterNativesURAGComponent()
	{
		UClass* Class = URAGComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateAnimation", &URAGComponent::execGenerateAnimation },
			{ "HandleOnAnimationGenerated", &URAGComponent::execHandleOnAnimationGenerated },
			{ "PlayAnimation", &URAGComponent::execPlayAnimation },
			{ "SetRAGConfig", &URAGComponent::execSetRAGConfig },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics
	{
		struct RAGComponent_eventGenerateAnimation_Parms
		{
			FString UserText;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::NewProp_UserText = { "UserText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RAGComponent_eventGenerateAnimation_Parms, UserText), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::NewProp_UserText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "RAG" },
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URAGComponent, nullptr, "GenerateAnimation", nullptr, nullptr, sizeof(Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::RAGComponent_eventGenerateAnimation_Parms), Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URAGComponent_GenerateAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URAGComponent_GenerateAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics
	{
		struct RAGComponent_eventHandleOnAnimationGenerated_Parms
		{
			UAnimSequence* GeneratedAnimation;
			FString UserText;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GeneratedAnimation;
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::NewProp_GeneratedAnimation = { "GeneratedAnimation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RAGComponent_eventHandleOnAnimationGenerated_Parms, GeneratedAnimation), Z_Construct_UClass_UAnimSequence_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::NewProp_UserText = { "UserText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RAGComponent_eventHandleOnAnimationGenerated_Parms, UserText), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::NewProp_GeneratedAnimation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::NewProp_UserText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URAGComponent, nullptr, "HandleOnAnimationGenerated", nullptr, nullptr, sizeof(Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::RAGComponent_eventHandleOnAnimationGenerated_Parms), Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics
	{
		struct RAGComponent_eventPlayAnimation_Parms
		{
			UAnimSequence* AnimSequence;
			FString UserText;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimSequence;
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::NewProp_AnimSequence = { "AnimSequence", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RAGComponent_eventPlayAnimation_Parms, AnimSequence), Z_Construct_UClass_UAnimSequence_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::NewProp_UserText = { "UserText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RAGComponent_eventPlayAnimation_Parms, UserText), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::NewProp_AnimSequence,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::NewProp_UserText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "RAG" },
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URAGComponent, nullptr, "PlayAnimation", nullptr, nullptr, sizeof(Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::RAGComponent_eventPlayAnimation_Parms), Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URAGComponent_PlayAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URAGComponent_PlayAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics
	{
		struct RAGComponent_eventSetRAGConfig_Parms
		{
			ACharacter* InTargetCharacter;
			UIKRetargeter* Retargeter;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InTargetCharacter;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Retargeter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::NewProp_InTargetCharacter = { "InTargetCharacter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RAGComponent_eventSetRAGConfig_Parms, InTargetCharacter), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::NewProp_Retargeter = { "Retargeter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RAGComponent_eventSetRAGConfig_Parms, Retargeter), Z_Construct_UClass_UIKRetargeter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::NewProp_InTargetCharacter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::NewProp_Retargeter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::Function_MetaDataParams[] = {
		{ "Category", "RAG" },
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URAGComponent, nullptr, "SetRAGConfig", nullptr, nullptr, sizeof(Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::RAGComponent_eventSetRAGConfig_Parms), Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URAGComponent_SetRAGConfig()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URAGComponent);
	UClass* Z_Construct_UClass_URAGComponent_NoRegister()
	{
		return URAGComponent::StaticClass();
	}
	struct Z_Construct_UClass_URAGComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetCharacter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetCharacter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnAnimationGenerated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAnimationGenerated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RAGManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RAGManager;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GeneratedAnim_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GeneratedAnim;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URAGComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeAnimationGenerator,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_URAGComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_URAGComponent_GenerateAnimation, "GenerateAnimation" }, // 1637168285
		{ &Z_Construct_UFunction_URAGComponent_HandleOnAnimationGenerated, "HandleOnAnimationGenerated" }, // 3684831756
		{ &Z_Construct_UFunction_URAGComponent_PlayAnimation, "PlayAnimation" }, // 1665298743
		{ &Z_Construct_UFunction_URAGComponent_SetRAGConfig, "SetRAGConfig" }, // 1975760636
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URAGComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "RAGComponent.h" },
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URAGComponent_Statics::NewProp_TargetCharacter_MetaData[] = {
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URAGComponent_Statics::NewProp_TargetCharacter = { "TargetCharacter", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URAGComponent, TargetCharacter), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URAGComponent_Statics::NewProp_TargetCharacter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URAGComponent_Statics::NewProp_TargetCharacter_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URAGComponent_Statics::NewProp_OnAnimationGenerated_MetaData[] = {
		{ "Category", "RAG" },
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_URAGComponent_Statics::NewProp_OnAnimationGenerated = { "OnAnimationGenerated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URAGComponent, OnAnimationGenerated), Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_URAGComponent_Statics::NewProp_OnAnimationGenerated_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URAGComponent_Statics::NewProp_OnAnimationGenerated_MetaData)) }; // 3025896904
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URAGComponent_Statics::NewProp_RAGManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URAGComponent_Statics::NewProp_RAGManager = { "RAGManager", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URAGComponent, RAGManager), Z_Construct_UClass_URAGManager_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URAGComponent_Statics::NewProp_RAGManager_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URAGComponent_Statics::NewProp_RAGManager_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URAGComponent_Statics::NewProp_GeneratedAnim_MetaData[] = {
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URAGComponent_Statics::NewProp_GeneratedAnim = { "GeneratedAnim", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URAGComponent, GeneratedAnim), Z_Construct_UClass_UAnimSequence_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URAGComponent_Statics::NewProp_GeneratedAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URAGComponent_Statics::NewProp_GeneratedAnim_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URAGComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URAGComponent_Statics::NewProp_TargetCharacter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URAGComponent_Statics::NewProp_OnAnimationGenerated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URAGComponent_Statics::NewProp_RAGManager,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URAGComponent_Statics::NewProp_GeneratedAnim,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URAGComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URAGComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URAGComponent_Statics::ClassParams = {
		&URAGComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_URAGComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_URAGComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_URAGComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URAGComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URAGComponent()
	{
		if (!Z_Registration_Info_UClass_URAGComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URAGComponent.OuterSingleton, Z_Construct_UClass_URAGComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URAGComponent.OuterSingleton;
	}
	template<> RUNTIMEANIMATIONGENERATOR_API UClass* StaticClass<URAGComponent>()
	{
		return URAGComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URAGComponent);
	struct Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URAGComponent, URAGComponent::StaticClass, TEXT("URAGComponent"), &Z_Registration_Info_UClass_URAGComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URAGComponent), 1764150038U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_1045604245(TEXT("/Script/RuntimeAnimationGenerator"),
		Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
