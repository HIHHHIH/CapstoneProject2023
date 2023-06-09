// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimSequence;
#ifdef RUNTIMEANIMATIONGENERATOR_RuntimeAnimationGeneratorBPLibrary_generated_h
#error "RuntimeAnimationGeneratorBPLibrary.generated.h already included, missing '#pragma once' in RuntimeAnimationGeneratorBPLibrary.h"
#endif
#define RUNTIMEANIMATIONGENERATOR_RuntimeAnimationGeneratorBPLibrary_generated_h

#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_SPARSE_DATA
#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPlayGeneratedAnim); \
	DECLARE_FUNCTION(execGenerateAnimation);


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPlayGeneratedAnim); \
	DECLARE_FUNCTION(execGenerateAnimation);


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURuntimeAnimationGeneratorBPLibrary(); \
	friend struct Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics; \
public: \
	DECLARE_CLASS(URuntimeAnimationGeneratorBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RuntimeAnimationGenerator"), NO_API) \
	DECLARE_SERIALIZER(URuntimeAnimationGeneratorBPLibrary)


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_INCLASS \
private: \
	static void StaticRegisterNativesURuntimeAnimationGeneratorBPLibrary(); \
	friend struct Z_Construct_UClass_URuntimeAnimationGeneratorBPLibrary_Statics; \
public: \
	DECLARE_CLASS(URuntimeAnimationGeneratorBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RuntimeAnimationGenerator"), NO_API) \
	DECLARE_SERIALIZER(URuntimeAnimationGeneratorBPLibrary)


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URuntimeAnimationGeneratorBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URuntimeAnimationGeneratorBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URuntimeAnimationGeneratorBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URuntimeAnimationGeneratorBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URuntimeAnimationGeneratorBPLibrary(URuntimeAnimationGeneratorBPLibrary&&); \
	NO_API URuntimeAnimationGeneratorBPLibrary(const URuntimeAnimationGeneratorBPLibrary&); \
public:


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URuntimeAnimationGeneratorBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URuntimeAnimationGeneratorBPLibrary(URuntimeAnimationGeneratorBPLibrary&&); \
	NO_API URuntimeAnimationGeneratorBPLibrary(const URuntimeAnimationGeneratorBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URuntimeAnimationGeneratorBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URuntimeAnimationGeneratorBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URuntimeAnimationGeneratorBPLibrary)


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_16_PROLOG
#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_SPARSE_DATA \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_RPC_WRAPPERS \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_INCLASS \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_SPARSE_DATA \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_INCLASS_NO_PURE_DECLS \
	FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h_19_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class RuntimeAnimationGeneratorBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RUNTIMEANIMATIONGENERATOR_API UClass* StaticClass<class URuntimeAnimationGeneratorBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MyProject8_Plugins_RuntimeAnimationGenerator_Source_RuntimeAnimationGenerator_Public_RuntimeAnimationGeneratorBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
