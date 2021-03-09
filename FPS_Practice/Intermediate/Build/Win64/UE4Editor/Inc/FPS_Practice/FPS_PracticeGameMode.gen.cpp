// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPS_Practice/FPS_PracticeGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPS_PracticeGameMode() {}
// Cross Module References
	FPS_PRACTICE_API UClass* Z_Construct_UClass_AFPS_PracticeGameMode_NoRegister();
	FPS_PRACTICE_API UClass* Z_Construct_UClass_AFPS_PracticeGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_FPS_Practice();
// End Cross Module References
	void AFPS_PracticeGameMode::StaticRegisterNativesAFPS_PracticeGameMode()
	{
	}
	UClass* Z_Construct_UClass_AFPS_PracticeGameMode_NoRegister()
	{
		return AFPS_PracticeGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AFPS_PracticeGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPS_PracticeGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FPS_Practice,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPS_PracticeGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FPS_PracticeGameMode.h" },
		{ "ModuleRelativePath", "FPS_PracticeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPS_PracticeGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPS_PracticeGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFPS_PracticeGameMode_Statics::ClassParams = {
		&AFPS_PracticeGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AFPS_PracticeGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_PracticeGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFPS_PracticeGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFPS_PracticeGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFPS_PracticeGameMode, 528620564);
	template<> FPS_PRACTICE_API UClass* StaticClass<AFPS_PracticeGameMode>()
	{
		return AFPS_PracticeGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFPS_PracticeGameMode(Z_Construct_UClass_AFPS_PracticeGameMode, &AFPS_PracticeGameMode::StaticClass, TEXT("/Script/FPS_Practice"), TEXT("AFPS_PracticeGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPS_PracticeGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
