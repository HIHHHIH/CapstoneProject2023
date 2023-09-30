// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimSequence;
#ifdef RUNTIMEANIMATIONGENERATOR_RAGManager_generated_h
#error "RAGManager.generated.h already included, missing '#pragma once' in RAGManager.h"
#endif
#define RUNTIMEANIMATIONGENERATOR_RAGManager_generated_h

#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_10_DELEGATE \
struct _Script_RuntimeAnimationGenerator_eventOnAnimationGenerated_Parms \
{ \
	UAnimSequence* GeneratedAnimation; \
	FString UserText; \
}; \
static inline void FOnAnimationGenerated_DelegateWrapper(const FMulticastScriptDelegate& OnAnimationGenerated, UAnimSequence* GeneratedAnimation, const FString& UserText) \
{ \
	_Script_RuntimeAnimationGenerator_eventOnAnimationGenerated_Parms Parms; \
	Parms.GeneratedAnimation=GeneratedAnimation; \
	Parms.UserText=UserText; \
	OnAnimationGenerated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_SPARSE_DATA
#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_RPC_WRAPPERS
#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURAGManager(); \
	friend struct Z_Construct_UClass_URAGManager_Statics; \
public: \
	DECLARE_CLASS(URAGManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RuntimeAnimationGenerator"), NO_API) \
	DECLARE_SERIALIZER(URAGManager)


#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_INCLASS \
private: \
	static void StaticRegisterNativesURAGManager(); \
	friend struct Z_Construct_UClass_URAGManager_Statics; \
public: \
	DECLARE_CLASS(URAGManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RuntimeAnimationGenerator"), NO_API) \
	DECLARE_SERIALIZER(URAGManager)


#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URAGManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URAGManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URAGManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URAGManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URAGManager(URAGManager&&); \
	NO_API URAGManager(const URAGManager&); \
public:


#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URAGManager(URAGManager&&); \
	NO_API URAGManager(const URAGManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URAGManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URAGManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(URAGManager)


#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_12_PROLOG
#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_SPARSE_DATA \
	FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_RPC_WRAPPERS \
	FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_INCLASS \
	FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_SPARSE_DATA \
	FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_INCLASS_NO_PURE_DECLS \
	FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RUNTIMEANIMATIONGENERATOR_API UClass* StaticClass<class URAGManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PluginProject_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
