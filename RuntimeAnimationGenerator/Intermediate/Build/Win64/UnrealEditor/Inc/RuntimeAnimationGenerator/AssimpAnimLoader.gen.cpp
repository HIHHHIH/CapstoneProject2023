// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RuntimeAnimationGenerator/Public/AssimpAnimLoader.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssimpAnimLoader() {}
// Cross Module References
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_UAssimpAnimLoader_NoRegister();
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_UAssimpAnimLoader();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_RuntimeAnimationGenerator();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
// End Cross Module References
	void UAssimpAnimLoader::StaticRegisterNativesUAssimpAnimLoader()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAssimpAnimLoader);
	UClass* Z_Construct_UClass_UAssimpAnimLoader_NoRegister()
	{
		return UAssimpAnimLoader::StaticClass();
	}
	struct Z_Construct_UClass_UAssimpAnimLoader_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SourceMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAssimpAnimLoader_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeAnimationGenerator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssimpAnimLoader_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AssimpAnimLoader.h" },
		{ "ModuleRelativePath", "Public/AssimpAnimLoader.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAssimpAnimLoader_Statics::NewProp_SourceMesh_MetaData[] = {
		{ "ModuleRelativePath", "Public/AssimpAnimLoader.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAssimpAnimLoader_Statics::NewProp_SourceMesh = { "SourceMesh", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAssimpAnimLoader, SourceMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UAssimpAnimLoader_Statics::NewProp_SourceMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAssimpAnimLoader_Statics::NewProp_SourceMesh_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAssimpAnimLoader_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssimpAnimLoader_Statics::NewProp_SourceMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAssimpAnimLoader_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssimpAnimLoader>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAssimpAnimLoader_Statics::ClassParams = {
		&UAssimpAnimLoader::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAssimpAnimLoader_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UAssimpAnimLoader_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAssimpAnimLoader_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAssimpAnimLoader_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAssimpAnimLoader()
	{
		if (!Z_Registration_Info_UClass_UAssimpAnimLoader.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAssimpAnimLoader.OuterSingleton, Z_Construct_UClass_UAssimpAnimLoader_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAssimpAnimLoader.OuterSingleton;
	}
	template<> RUNTIMEANIMATIONGENERATOR_API UClass* StaticClass<UAssimpAnimLoader>()
	{
		return UAssimpAnimLoader::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAssimpAnimLoader);
	struct Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_AssimpAnimLoader_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_AssimpAnimLoader_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAssimpAnimLoader, UAssimpAnimLoader::StaticClass, TEXT("UAssimpAnimLoader"), &Z_Registration_Info_UClass_UAssimpAnimLoader, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAssimpAnimLoader), 1390770449U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_AssimpAnimLoader_h_2566743267(TEXT("/Script/RuntimeAnimationGenerator"),
		Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_AssimpAnimLoader_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_AssimpAnimLoader_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
