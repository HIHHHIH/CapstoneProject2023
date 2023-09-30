// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RuntimeAnimationGenerator/Public/RAGManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRAGManager() {}
// Cross Module References
	RUNTIMEANIMATIONGENERATOR_API UFunction* Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RuntimeAnimationGenerator();
	ENGINE_API UClass* Z_Construct_UClass_UAnimSequence_NoRegister();
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_URAGManager_NoRegister();
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_URAGManager();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_USmplRetargeter_NoRegister();
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_UAssimpAnimLoader_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics
	{
		struct _Script_RuntimeAnimationGenerator_eventOnAnimationGenerated_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::NewProp_GeneratedAnimation = { "GeneratedAnimation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_RuntimeAnimationGenerator_eventOnAnimationGenerated_Parms, GeneratedAnimation), Z_Construct_UClass_UAnimSequence_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::NewProp_UserText = { "UserText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_RuntimeAnimationGenerator_eventOnAnimationGenerated_Parms, UserText), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::NewProp_GeneratedAnimation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::NewProp_UserText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RAGManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RuntimeAnimationGenerator, nullptr, "OnAnimationGenerated__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::_Script_RuntimeAnimationGenerator_eventOnAnimationGenerated_Parms), Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_RuntimeAnimationGenerator_OnAnimationGenerated__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void URAGManager::StaticRegisterNativesURAGManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URAGManager);
	UClass* Z_Construct_UClass_URAGManager_NoRegister()
	{
		return URAGManager::StaticClass();
	}
	struct Z_Construct_UClass_URAGManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SmplRetargeter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SmplRetargeter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimLoader_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimLoader;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URAGManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeAnimationGenerator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URAGManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RAGManager.h" },
		{ "ModuleRelativePath", "Public/RAGManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URAGManager_Statics::NewProp_SmplRetargeter_MetaData[] = {
		{ "ModuleRelativePath", "Public/RAGManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URAGManager_Statics::NewProp_SmplRetargeter = { "SmplRetargeter", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URAGManager, SmplRetargeter), Z_Construct_UClass_USmplRetargeter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URAGManager_Statics::NewProp_SmplRetargeter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URAGManager_Statics::NewProp_SmplRetargeter_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URAGManager_Statics::NewProp_AnimLoader_MetaData[] = {
		{ "ModuleRelativePath", "Public/RAGManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URAGManager_Statics::NewProp_AnimLoader = { "AnimLoader", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(URAGManager, AnimLoader), Z_Construct_UClass_UAssimpAnimLoader_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URAGManager_Statics::NewProp_AnimLoader_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URAGManager_Statics::NewProp_AnimLoader_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URAGManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URAGManager_Statics::NewProp_SmplRetargeter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URAGManager_Statics::NewProp_AnimLoader,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URAGManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URAGManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URAGManager_Statics::ClassParams = {
		&URAGManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URAGManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URAGManager_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_URAGManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URAGManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URAGManager()
	{
		if (!Z_Registration_Info_UClass_URAGManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URAGManager.OuterSingleton, Z_Construct_UClass_URAGManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URAGManager.OuterSingleton;
	}
	template<> RUNTIMEANIMATIONGENERATOR_API UClass* StaticClass<URAGManager>()
	{
		return URAGManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URAGManager);
	struct Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URAGManager, URAGManager::StaticClass, TEXT("URAGManager"), &Z_Registration_Info_UClass_URAGManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URAGManager), 1567006353U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_1051313850(TEXT("/Script/RuntimeAnimationGenerator"),
		Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
