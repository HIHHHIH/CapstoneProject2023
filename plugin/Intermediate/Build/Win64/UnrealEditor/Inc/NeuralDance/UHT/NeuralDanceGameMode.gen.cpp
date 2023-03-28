// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeuralDance/NeuralDanceGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNeuralDanceGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	NEURALDANCE_API UClass* Z_Construct_UClass_ANeuralDanceGameMode();
	NEURALDANCE_API UClass* Z_Construct_UClass_ANeuralDanceGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeuralDance();
// End Cross Module References
	void ANeuralDanceGameMode::StaticRegisterNativesANeuralDanceGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANeuralDanceGameMode);
	UClass* Z_Construct_UClass_ANeuralDanceGameMode_NoRegister()
	{
		return ANeuralDanceGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ANeuralDanceGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANeuralDanceGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_NeuralDance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeuralDanceGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "NeuralDanceGameMode.h" },
		{ "ModuleRelativePath", "NeuralDanceGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANeuralDanceGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANeuralDanceGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANeuralDanceGameMode_Statics::ClassParams = {
		&ANeuralDanceGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ANeuralDanceGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANeuralDanceGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANeuralDanceGameMode()
	{
		if (!Z_Registration_Info_UClass_ANeuralDanceGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANeuralDanceGameMode.OuterSingleton, Z_Construct_UClass_ANeuralDanceGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANeuralDanceGameMode.OuterSingleton;
	}
	template<> NEURALDANCE_API UClass* StaticClass<ANeuralDanceGameMode>()
	{
		return ANeuralDanceGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANeuralDanceGameMode);
	ANeuralDanceGameMode::~ANeuralDanceGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_cgdon_Documents_Unreal_Projects_NeuralDance_Source_NeuralDance_NeuralDanceGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_cgdon_Documents_Unreal_Projects_NeuralDance_Source_NeuralDance_NeuralDanceGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANeuralDanceGameMode, ANeuralDanceGameMode::StaticClass, TEXT("ANeuralDanceGameMode"), &Z_Registration_Info_UClass_ANeuralDanceGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANeuralDanceGameMode), 2711912078U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_cgdon_Documents_Unreal_Projects_NeuralDance_Source_NeuralDance_NeuralDanceGameMode_h_2462593219(TEXT("/Script/NeuralDance"),
		Z_CompiledInDeferFile_FID_Users_cgdon_Documents_Unreal_Projects_NeuralDance_Source_NeuralDance_NeuralDanceGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_cgdon_Documents_Unreal_Projects_NeuralDance_Source_NeuralDance_NeuralDanceGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
