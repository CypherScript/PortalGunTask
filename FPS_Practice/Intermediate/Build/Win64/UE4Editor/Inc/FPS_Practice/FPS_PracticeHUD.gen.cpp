// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPS_Practice/FPS_PracticeHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPS_PracticeHUD() {}
// Cross Module References
	FPS_PRACTICE_API UClass* Z_Construct_UClass_AFPS_PracticeHUD_NoRegister();
	FPS_PRACTICE_API UClass* Z_Construct_UClass_AFPS_PracticeHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_FPS_Practice();
// End Cross Module References
	void AFPS_PracticeHUD::StaticRegisterNativesAFPS_PracticeHUD()
	{
	}
	UClass* Z_Construct_UClass_AFPS_PracticeHUD_NoRegister()
	{
		return AFPS_PracticeHUD::StaticClass();
	}
	struct Z_Construct_UClass_AFPS_PracticeHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPS_PracticeHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_FPS_Practice,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPS_PracticeHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "FPS_PracticeHUD.h" },
		{ "ModuleRelativePath", "FPS_PracticeHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPS_PracticeHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPS_PracticeHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFPS_PracticeHUD_Statics::ClassParams = {
		&AFPS_PracticeHUD::StaticClass,
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
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AFPS_PracticeHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFPS_PracticeHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFPS_PracticeHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFPS_PracticeHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFPS_PracticeHUD, 3866020146);
	template<> FPS_PRACTICE_API UClass* StaticClass<AFPS_PracticeHUD>()
	{
		return AFPS_PracticeHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFPS_PracticeHUD(Z_Construct_UClass_AFPS_PracticeHUD, &AFPS_PracticeHUD::StaticClass, TEXT("/Script/FPS_Practice"), TEXT("AFPS_PracticeHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPS_PracticeHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
