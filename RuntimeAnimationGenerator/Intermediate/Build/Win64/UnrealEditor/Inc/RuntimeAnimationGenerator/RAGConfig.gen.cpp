// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RuntimeAnimationGenerator/Public/RAGConfig.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRAGConfig() {}
// Cross Module References
	RUNTIMEANIMATIONGENERATOR_API UScriptStruct* Z_Construct_UScriptStruct_FRAGConfig();
	UPackage* Z_Construct_UPackage__Script_RuntimeAnimationGenerator();
	IKRIG_API UClass* Z_Construct_UClass_UIKRigDefinition_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RAGConfig;
class UScriptStruct* FRAGConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RAGConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RAGConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRAGConfig, Z_Construct_UPackage__Script_RuntimeAnimationGenerator(), TEXT("RAGConfig"));
	}
	return Z_Registration_Info_UScriptStruct_RAGConfig.OuterSingleton;
}
template<> RUNTIMEANIMATIONGENERATOR_API UScriptStruct* StaticStruct<FRAGConfig>()
{
	return FRAGConfig::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FRAGConfig_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetIKRig_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetIKRig;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetCharacter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetCharacter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRAGConfig_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/RAGConfig.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FRAGConfig_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRAGConfig>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetIKRig_MetaData[] = {
		{ "Category", "RAG" },
		{ "ModuleRelativePath", "Public/RAGConfig.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetIKRig = { "TargetIKRig", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRAGConfig, TargetIKRig), Z_Construct_UClass_UIKRigDefinition_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetIKRig_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetIKRig_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetCharacter_MetaData[] = {
		{ "Category", "RAG" },
		{ "ModuleRelativePath", "Public/RAGConfig.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetCharacter = { "TargetCharacter", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRAGConfig, TargetCharacter), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetCharacter_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetCharacter_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRAGConfig_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetIKRig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRAGConfig_Statics::NewProp_TargetCharacter,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRAGConfig_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeAnimationGenerator,
		nullptr,
		&NewStructOps,
		"RAGConfig",
		sizeof(FRAGConfig),
		alignof(FRAGConfig),
		Z_Construct_UScriptStruct_FRAGConfig_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRAGConfig_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FRAGConfig_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRAGConfig_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FRAGConfig()
	{
		if (!Z_Registration_Info_UScriptStruct_RAGConfig.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RAGConfig.InnerSingleton, Z_Construct_UScriptStruct_FRAGConfig_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_RAGConfig.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGConfig_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGConfig_h_Statics::ScriptStructInfo[] = {
		{ FRAGConfig::StaticStruct, Z_Construct_UScriptStruct_FRAGConfig_Statics::NewStructOps, TEXT("RAGConfig"), &Z_Registration_Info_UScriptStruct_RAGConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRAGConfig), 2990342484U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGConfig_h_3336879295(TEXT("/Script/RuntimeAnimationGenerator"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGConfig_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGConfig_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
