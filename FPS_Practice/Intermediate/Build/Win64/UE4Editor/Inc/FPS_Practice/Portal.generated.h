// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef FPS_PRACTICE_Portal_generated_h
#error "Portal.generated.h already included, missing '#pragma once' in Portal.h"
#endif
#define FPS_PRACTICE_Portal_generated_h

#define FPS_Practice_Source_FPS_Practice_Portal_h_14_SPARSE_DATA
#define FPS_Practice_Source_FPS_Practice_Portal_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEnterPortal);


#define FPS_Practice_Source_FPS_Practice_Portal_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEnterPortal);


#define FPS_Practice_Source_FPS_Practice_Portal_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPortal(); \
	friend struct Z_Construct_UClass_APortal_Statics; \
public: \
	DECLARE_CLASS(APortal, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPS_Practice"), NO_API) \
	DECLARE_SERIALIZER(APortal)


#define FPS_Practice_Source_FPS_Practice_Portal_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAPortal(); \
	friend struct Z_Construct_UClass_APortal_Statics; \
public: \
	DECLARE_CLASS(APortal, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPS_Practice"), NO_API) \
	DECLARE_SERIALIZER(APortal)


#define FPS_Practice_Source_FPS_Practice_Portal_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APortal(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APortal) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APortal); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APortal); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APortal(APortal&&); \
	NO_API APortal(const APortal&); \
public:


#define FPS_Practice_Source_FPS_Practice_Portal_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APortal(APortal&&); \
	NO_API APortal(const APortal&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APortal); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APortal); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APortal)


#define FPS_Practice_Source_FPS_Practice_Portal_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Collision() { return STRUCT_OFFSET(APortal, Collision); }


#define FPS_Practice_Source_FPS_Practice_Portal_h_11_PROLOG
#define FPS_Practice_Source_FPS_Practice_Portal_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_PRIVATE_PROPERTY_OFFSET \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_SPARSE_DATA \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_RPC_WRAPPERS \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_INCLASS \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPS_Practice_Source_FPS_Practice_Portal_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_PRIVATE_PROPERTY_OFFSET \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_SPARSE_DATA \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_INCLASS_NO_PURE_DECLS \
	FPS_Practice_Source_FPS_Practice_Portal_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPS_PRACTICE_API UClass* StaticClass<class APortal>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPS_Practice_Source_FPS_Practice_Portal_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
