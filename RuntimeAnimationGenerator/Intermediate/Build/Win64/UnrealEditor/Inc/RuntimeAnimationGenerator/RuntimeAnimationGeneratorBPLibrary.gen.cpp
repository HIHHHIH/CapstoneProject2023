// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RuntimeAnimationGenerator/Public/RuntimeAnimationGeneratorBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRuntimeAnimationGeneratorBPLibrary() {}
// Cross Module References
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_NoRegister();
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_RuntimeAnimationGenerator();
	ENGINE_API UClass* Z_Construct_UClass_UAnimSequence_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(URuntimeAnimationGeneratorBPLibrary::execPlayGeneratedAnim)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_UserText);
		P_FINISH;
		P_NATIVE_BEGIN;
		URuntimeAnimationGeneratorBPLibrary::PlayGeneratedAnim(Z_Param_UserText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URuntimeAnimationGeneratorBPLibrary::execGenerateAnimation)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_UserText);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UAnimSequence**)Z_Param__Result=URuntimeAnimationGeneratorBPLibrary::GenerateAnimation(Z_Param_UserText);
		P_NATIVE_END;
	}
	void URuntimeAnimationGeneratorBPLibrary::StaticRegisterNativesURuntimeAnimationGeneratorBPLibrary()
	{
		UClass* Class = URuntimeAnimationGeneratorBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerateAnimation", &URuntimeAnimationGeneratorBPLibrary::execGenerateAnimation },
			{ "PlayGeneratedAnim", &URuntimeAnimationGeneratorBPLibrary::execPlayGeneratedAnim },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics
	{
		struct RuntimeAnimationGeneratorBPLibrary_eventGenerateAnimation_Parms
		{
			FString UserText;
			UAnimSequence* ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserText;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::NewProp_UserText = { "UserText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RuntimeAnimationGeneratorBPLibrary_eventGenerateAnimation_Parms, UserText), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RuntimeAnimationGeneratorBPLibrary_eventGenerateAnimation_Parms, ReturnValue), Z_Construct_UClass_UAnimSequence_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::NewProp_UserText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::Function_MetaDataParams[] = {
		{ "Category", "RAG" },
		{ "ModuleRelativePath", "Public/RuntimeAnimationGeneratorBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary, nullptr, "GenerateAnimation", nullptr, nullptr, sizeof(Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::RuntimeAnimationGeneratorBPLibrary_eventGenerateAnimation_Parms), Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics
	{
		struct RuntimeAnimationGeneratorBPLibrary_eventPlayGeneratedAnim_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::NewProp_UserText = { "UserText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(RuntimeAnimationGeneratorBPLibrary_eventPlayGeneratedAnim_Parms, UserText), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::NewProp_UserText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::Function_MetaDataParams[] = {
		{ "Category", "RAG" },
		{ "ModuleRelativePath", "Public/RuntimeAnimationGeneratorBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary, nullptr, "PlayGeneratedAnim", nullptr, nullptr, sizeof(Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::RuntimeAnimationGeneratorBPLibrary_eventPlayGeneratedAnim_Parms), Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URuntimeAnimationGeneratorBPLibrary);
	UClass* Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_NoRegister()
	{
		return URuntimeAnimationGeneratorBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeAnimationGenerator,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_GenerateAnimation, "GenerateAnimation" }, // 3228231442
		{ &Z_Construct_UFunction_URuntimeAnimationGeneratorBPLibrary_PlayGeneratedAnim, "PlayGeneratedAnim" }, // 4173585968
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RuntimeAnimationGeneratorBPLibrary.h" },
		{ "ModuleRelativePath", "Public/RuntimeAnimationGeneratorBPLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URuntimeAnimationGeneratorBPLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics::ClassParams = {
		&URuntimeAnimationGeneratorBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary()
	{
		if (!Z_Registration_Info_UClass_URuntimeAnimationGeneratorBPLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URuntimeAnimationGeneratorBPLibrary.OuterSingleton, Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URuntimeAnimationGeneratorBPLibrary.OuterSingleton;
	}
	template<> RUNTIMEANIMATIONGENERATOR_API UClass* StaticClass<URuntimeAnimationGeneratorBPLibrary>()
	{
		return URuntimeAnimationGeneratorBPLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URuntimeAnimationGeneratorBPLibrary);
	struct Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary, URuntimeAnimationGeneratorBPLibrary::StaticClass, TEXT("URuntimeAnimationGeneratorBPLibrary"), &Z_Registration_Info_UClass_URuntimeAnimationGeneratorBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URuntimeAnimationGeneratorBPLibrary), 3864791097U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_1455689788(TEXT("/Script/RuntimeAnimationGenerator"),
		Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
