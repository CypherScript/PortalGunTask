// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef FPS_PRACTICE_FPS_PracticeProjectile_generated_h
#error "FPS_PracticeProjectile.generated.h already included, missing '#pragma once' in FPS_PracticeProjectile.h"
#endif
#define FPS_PRACTICE_FPS_PracticeProjectile_generated_h

#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_SPARSE_DATA
#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPS_PracticeProjectile(); \
	friend struct Z_Construct_UClass_AFPS_PracticeProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPS_PracticeProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPS_Practice"), NO_API) \
	DECLARE_SERIALIZER(AFPS_PracticeProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFPS_PracticeProjectile(); \
	friend struct Z_Construct_UClass_AFPS_PracticeProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPS_PracticeProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPS_Practice"), NO_API) \
	DECLARE_SERIALIZER(AFPS_PracticeProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPS_PracticeProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPS_PracticeProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPS_PracticeProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPS_PracticeProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPS_PracticeProjectile(AFPS_PracticeProjectile&&); \
	NO_API AFPS_PracticeProjectile(const AFPS_PracticeProjectile&); \
public:


#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPS_PracticeProjectile(AFPS_PracticeProjectile&&); \
	NO_API AFPS_PracticeProjectile(const AFPS_PracticeProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPS_PracticeProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPS_PracticeProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPS_PracticeProjectile)


#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AFPS_PracticeProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AFPS_PracticeProjectile, ProjectileMovement); }


#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_9_PROLOG
#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_SPARSE_DATA \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_RPC_WRAPPERS \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_INCLASS \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_PRIVATE_PROPERTY_OFFSET \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_SPARSE_DATA \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_INCLASS_NO_PURE_DECLS \
	FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPS_PRACTICE_API UClass* StaticClass<class AFPS_PracticeProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPS_Practice_Source_FPS_Practice_FPS_PracticeProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
