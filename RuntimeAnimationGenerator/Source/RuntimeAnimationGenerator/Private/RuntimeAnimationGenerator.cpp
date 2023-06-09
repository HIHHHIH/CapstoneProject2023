// Copyright Epic Games, Inc. All Rights Reserved.

#include "RuntimeAnimationGenerator.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/MessageDialog.h"

#define LOCTEXT_NAMESPACE "FRuntimeAnimationGeneratorModule"

void FRuntimeAnimationGeneratorModule::StartupModule()
{
    FString PluginDir = IPluginManager::Get().FindPlugin("RuntimeAnimationGenerator")->GetBaseDir();
    FString AssimpDLLPath = FPaths::Combine(PluginDir, TEXT("Binaries/ThirdParty/assimp-vc143-mt.dll"));
    FString ZlibDLLPath = FPaths::Combine(PluginDir, TEXT("Binaries/ThirdParty/zlib1.dll"));
    FString PugixmlDLLPath = FPaths::Combine(PluginDir, TEXT("Binaries/ThirdParty/pugixml.dll"));

    UE_LOG(LogTemp, Log, TEXT("Trying to load Assimp DLL from: %s"), *AssimpDLLPath);

    ZlibDLLHandle = FPlatformProcess::GetDllHandle(*ZlibDLLPath);
    PugixmlDLLHandle = FPlatformProcess::GetDllHandle(*PugixmlDLLPath);
    AssimpDLLHandle = FPlatformProcess::GetDllHandle(*AssimpDLLPath);

    if (!ZlibDLLHandle || !PugixmlDLLHandle)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load the zlib or pugixml DLL"));
        FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Failed to load the zlib or pugixml DLL")));
        FPlatformMisc::RequestExit(false);
    }

    if (!AssimpDLLHandle)
    {
        FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("Failed to load the Assimp DLL")));
        FPlatformMisc::RequestExit(false);
    }
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FRuntimeAnimationGeneratorModule::ShutdownModule()
{
    FPlatformProcess::FreeDllHandle(AssimpDLLHandle);
    AssimpDLLHandle = nullptr;

    if (ZlibDLLHandle)
    {
        FPlatformProcess::FreeDllHandle(ZlibDLLHandle);
        ZlibDLLHandle = nullptr;
    }

    if (PugixmlDLLHandle)
    {
        FPlatformProcess::FreeDllHandle(PugixmlDLLHandle);
        PugixmlDLLHandle = nullptr;
    }
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRuntimeAnimationGeneratorModule, RuntimeAnimationGenerator)