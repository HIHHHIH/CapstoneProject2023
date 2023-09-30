// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RuntimeAnimationGenerator/Public/SmplRetargeter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSmplRetargeter() {}
// Cross Module References
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_USmplRetargeter_NoRegister();
	RUNTIMEANIMATIONGENERATOR_API UClass* Z_Construct_UClass_USmplRetargeter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_RuntimeAnimationGenerator();
	IKRIG_API UClass* Z_Construct_UClass_UIKRetargeter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
// End Cross Module References
	void USmplRetargeter::StaticRegisterNativesUSmplRetargeter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USmplRetargeter);
	UClass* Z_Construct_UClass_USmplRetargeter_NoRegister()
	{
		return USmplRetargeter::StaticClass();
	}
	struct Z_Construct_UClass_USmplRetargeter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Retargeter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Retargeter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SourceMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USmplRetargeter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_RuntimeAnimationGenerator,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USmplRetargeter_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SmplRetargeter.h" },
		{ "ModuleRelativePath", "Public/SmplRetargeter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USmplRetargeter_Statics::NewProp_Retargeter_MetaData[] = {
		{ "ModuleRelativePath", "Public/SmplRetargeter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USmplRetargeter_Statics::NewProp_Retargeter = { "Retargeter", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USmplRetargeter, Retargeter), Z_Construct_UClass_UIKRetargeter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USmplRetargeter_Statics::NewProp_Retargeter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USmplRetargeter_Statics::NewProp_Retargeter_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USmplRetargeter_Statics::NewProp_TargetMesh_MetaData[] = {
		{ "ModuleRelativePath", "Public/SmplRetargeter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USmplRetargeter_Statics::NewProp_TargetMesh = { "TargetMesh", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USmplRetargeter, TargetMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USmplRetargeter_Statics::NewProp_TargetMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USmplRetargeter_Statics::NewProp_TargetMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USmplRetargeter_Statics::NewProp_SourceMesh_MetaData[] = {
		{ "ModuleRelativePath", "Public/SmplRetargeter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USmplRetargeter_Statics::NewProp_SourceMesh = { "SourceMesh", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USmplRetargeter, SourceMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USmplRetargeter_Statics::NewProp_SourceMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USmplRetargeter_Statics::NewProp_SourceMesh_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USmplRetargeter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USmplRetargeter_Statics::NewProp_Retargeter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USmplRetargeter_Statics::NewProp_TargetMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USmplRetargeter_Statics::NewProp_SourceMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USmplRetargeter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USmplRetargeter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USmplRetargeter_Statics::ClassParams = {
		&USmplRetargeter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USmplRetargeter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USmplRetargeter_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USmplRetargeter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USmplRetargeter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USmplRetargeter()
	{
		if (!Z_Registration_Info_UClass_USmplRetargeter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USmplRetargeter.OuterSingleton, Z_Construct_UClass_USmplRetargeter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USmplRetargeter.OuterSingleton;
	}
	template<> RUNTIMEANIMATIONGENERATOR_API UClass* StaticClass<USmplRetargeter>()
	{
		return USmplRetargeter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USmplRetargeter);
	struct Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_SmplRetargeter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_SmplRetargeter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USmplRetargeter, USmplRetargeter::StaticClass, TEXT("USmplRetargeter"), &Z_Registration_Info_UClass_USmplRetargeter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USmplRetargeter), 423228239U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_SmplRetargeter_h_2449433676(TEXT("/Script/RuntimeAnimationGenerator"),
		Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_SmplRetargeter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_SmplRetargeter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
