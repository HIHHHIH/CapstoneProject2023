// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRAGConfig;
#ifdef RUNTIMEANIMATIONGENERATOR_RAGComponent_generated_h
#error "RAGComponent.generated.h already included, missing '#pragma once' in RAGComponent.h"
#endif
#define RUNTIMEANIMATIONGENERATOR_RAGComponent_generated_h

#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_SPARSE_DATA
#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPlayGeneratedAnim); \
	DECLARE_FUNCTION(execSetRAGConfig);


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPlayGeneratedAnim); \
	DECLARE_FUNCTION(execSetRAGConfig);


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURAGComponent(); \
	friend struct Z_Construct_UClass_URAGComponent_Statics; \
public: \
	DECLARE_CLASS(URAGComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RuntimeAnimationGenerator"), NO_API) \
	DECLARE_SERIALIZER(URAGComponent)


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_INCLASS \
private: \
	static void StaticRegisterNativesURAGComponent(); \
	friend struct Z_Construct_UClass_URAGComponent_Statics; \
public: \
	DECLARE_CLASS(URAGComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RuntimeAnimationGenerator"), NO_API) \
	DECLARE_SERIALIZER(URAGComponent)


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URAGComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URAGComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URAGComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URAGComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URAGComponent(URAGComponent&&); \
	NO_API URAGComponent(const URAGComponent&); \
public:


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URAGComponent(URAGComponent&&); \
	NO_API URAGComponent(const URAGComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URAGComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URAGComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(URAGComponent)


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_13_PROLOG
#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_SPARSE_DATA \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_RPC_WRAPPERS \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_INCLASS \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_SPARSE_DATA \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_INCLASS_NO_PURE_DECLS \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RUNTIMEANIMATIONGENERATOR_API UClass* StaticClass<class URAGComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RAGComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
