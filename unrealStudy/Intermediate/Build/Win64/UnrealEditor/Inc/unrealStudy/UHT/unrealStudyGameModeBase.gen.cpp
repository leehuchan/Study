// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "unrealStudy/unrealStudyGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeunrealStudyGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UNREALSTUDY_API UClass* Z_Construct_UClass_AunrealStudyGameModeBase();
	UNREALSTUDY_API UClass* Z_Construct_UClass_AunrealStudyGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_unrealStudy();
// End Cross Module References
	void AunrealStudyGameModeBase::StaticRegisterNativesAunrealStudyGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AunrealStudyGameModeBase);
	UClass* Z_Construct_UClass_AunrealStudyGameModeBase_NoRegister()
	{
		return AunrealStudyGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AunrealStudyGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AunrealStudyGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_unrealStudy,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AunrealStudyGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "unrealStudyGameModeBase.h" },
		{ "ModuleRelativePath", "unrealStudyGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AunrealStudyGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AunrealStudyGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AunrealStudyGameModeBase_Statics::ClassParams = {
		&AunrealStudyGameModeBase::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AunrealStudyGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AunrealStudyGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AunrealStudyGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AunrealStudyGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AunrealStudyGameModeBase.OuterSingleton, Z_Construct_UClass_AunrealStudyGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AunrealStudyGameModeBase.OuterSingleton;
	}
	template<> UNREALSTUDY_API UClass* StaticClass<AunrealStudyGameModeBase>()
	{
		return AunrealStudyGameModeBase::StaticClass();
	}
	AunrealStudyGameModeBase::AunrealStudyGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AunrealStudyGameModeBase);
	AunrealStudyGameModeBase::~AunrealStudyGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_github_Study_unrealStudy_Source_unrealStudy_unrealStudyGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_github_Study_unrealStudy_Source_unrealStudy_unrealStudyGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AunrealStudyGameModeBase, AunrealStudyGameModeBase::StaticClass, TEXT("AunrealStudyGameModeBase"), &Z_Registration_Info_UClass_AunrealStudyGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AunrealStudyGameModeBase), 227082139U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_github_Study_unrealStudy_Source_unrealStudy_unrealStudyGameModeBase_h_3834740848(TEXT("/Script/unrealStudy"),
		Z_CompiledInDeferFile_FID_github_Study_unrealStudy_Source_unrealStudy_unrealStudyGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_github_Study_unrealStudy_Source_unrealStudy_unrealStudyGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
