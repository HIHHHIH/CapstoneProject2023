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
	RUNTIMEANIMATIONGENERATOR_API UScriptStruct* Z_Construct_UScriptStruct_FRAGConfig();
// End Cross Module References
	DEFINE_FUNCTION(URAGComponent::execPlayGeneratedAnim)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_UserText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PlayGeneratedAnim(Z_Param_UserText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URAGComponent::execSetRAGConfig)
	{
		P_GET_STRUCT(FRAGConfig,Z_Param_RAGConfig);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRAGConfig(Z_Param_RAGConfig);
		P_NATIVE_END;
	}
	void URAGComponent::StaticRegisterNativesURAGComponent()
	{
		UClass* Class = URAGComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PlayGeneratedAnim", &URAGComponent::execPlayGeneratedAnim },
			{ "SetRAGConfig", &URAGComponent::execSetRAGConfig },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics
	{
		struct RAGComponent_eventPlayGeneratedAnim_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::NewProp_UserText = { "UserText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RAGComponent_eventPlayGeneratedAnim_Parms, UserText), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::NewProp_UserText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::Function_MetaDataParams[] = {
		{ "Category", "RAG" },
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URAGComponent, nullptr, "PlayGeneratedAnim", nullptr, nullptr, sizeof(Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::RAGComponent_eventPlayGeneratedAnim_Parms), Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics
	{
		struct RAGComponent_eventSetRAGConfig_Parms
		{
			FRAGConfig RAGConfig;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RAGConfig;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::NewProp_RAGConfig = { "RAGConfig", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RAGComponent_eventSetRAGConfig_Parms, RAGConfig), Z_Construct_UScriptStruct_FRAGConfig, METADATA_PARAMS(nullptr, 0) }; // 2990342484
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URAGComponent_SetRAGConfig_Statics::NewProp_RAGConfig,
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
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URAGComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeAnimationGenerator,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_URAGComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_URAGComponent_PlayGeneratedAnim, "PlayGeneratedAnim" }, // 3887962447
		{ &Z_Construct_UFunction_URAGComponent_SetRAGConfig, "SetRAGConfig" }, // 2527280631
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URAGComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "RAGComponent.h" },
		{ "ModuleRelativePath", "Public/RAGComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URAGComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URAGComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URAGComponent_Statics::ClassParams = {
		&URAGComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
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
	struct Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URAGComponent, URAGComponent::StaticClass, TEXT("URAGComponent"), &Z_Registration_Info_UClass_URAGComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URAGComponent), 4260595228U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_1697580439(TEXT("/Script/RuntimeAnimationGenerator"),
		Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
