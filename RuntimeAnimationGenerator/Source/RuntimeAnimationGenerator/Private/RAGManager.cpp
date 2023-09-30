// RAGManager.cpp

#include "RAGManager.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "assimp/scene.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/SavePackage.h"
#include "RAGLog.h"

DEFINE_LOG_CATEGORY(LogRAG);

static const FString PluginName = "/RuntimeAnimationGenerator";
static const FString PluginPath = FPaths::Combine(FPaths::ProjectPluginsDir(), PluginName);
static const FString ResponseFbxPath = FPaths::Combine(PluginPath, "/Content/Generated/ResponseFbx");
static const FString RetargetedPackagePath = FPaths::Combine(PluginName, "/Generated/Retargeted/");
static const FString SMPLPackagePath = FPaths::Combine(PluginName, "/Generated/SMPL/");
static const FString SourceMeshPath = FPaths::Combine(PluginName, "/SMPL/SK_SMPL.SK_SMPL");

static const FString URL = "http://localhost:8000/generate";
static FString TestFbxName = "dance_happily.fbx";
static FString TestFbxPath = FPaths::Combine(PluginPath, "/Content/Generated/ResponseFbx", TestFbxName);
static constexpr int FbxNumFrames2 = 120;

URAGManager::URAGManager()
{
	if(!IConsoleManager::Get().FindConsoleObject(TEXT("SetTestFbxName")))
	{
		IConsoleManager::Get().RegisterConsoleCommand(
			TEXT("SetTestFbxName"),
			TEXT("Set fbx path for test without server."),
			FConsoleCommandWithArgsDelegate::CreateUObject(this, &URAGManager::SetTestFbxName),
			ECVF_Default);
	}

	if(!IConsoleManager::Get().FindConsoleObject(TEXT("ToggleClientTestMode")))
	{
		IConsoleManager::Get().RegisterConsoleCommand(
			TEXT("ToggleClientTestMode"),
			TEXT("Toggle if it's client only test mode"),
			FConsoleCommandDelegate::CreateUObject(this, &URAGManager::ToggleClientTestMode),
			ECVF_Default);
	}
}

URAGManager::~URAGManager()
{
	IConsoleManager::Get().UnregisterConsoleObject(TEXT("SetTestFbxName"));
	IConsoleManager::Get().UnregisterConsoleObject(TEXT("ToggleClientTestMode"));
}

void URAGManager::SetTestFbxName(const TArray<FString>& Args)
{
	if (Args.Num() > 0)
	{
		TestFbxName = Args[0];
		TestFbxPath = FPaths::Combine(PluginPath, "/Content/Generated/ResponseFbx", TestFbxName);
		UE_LOG(LogRAG, Log, TEXT("Test fbx is set to: %s"), *TestFbxName);
	}
	else
	{
		UE_LOG(LogRAG, Log, TEXT("Provide a value to set TestFbxName."));
	}
}

void URAGManager::ToggleClientTestMode()
{
	IsClientTest = !IsClientTest;
	UE_LOG(LogRAG, Log, TEXT("IsClientTest set to: %s"), IsClientTest ? TEXT("True") : TEXT("False"));
}

void URAGManager::Initialize(UIKRetargeter* InRetargeter, USkeletalMesh* SkeletalMesh)
{
	USkeletalMesh* SourceMesh = Cast<USkeletalMesh>(StaticLoadObject(USkeletalMesh::StaticClass(), nullptr, *SourceMeshPath));

	SmplRetargeter = NewObject<USmplRetargeter>(GetTransientPackage());
	SmplRetargeter->Initialize(InRetargeter, SourceMesh, SkeletalMesh);

	AnimLoader = NewObject<UAssimpAnimLoader>(GetTransientPackage());
	AnimLoader->Initialize(SourceMesh);
}

TFuture<FString> URAGManager::RequestAnimationData(FString UserInput) const
{
	TSharedRef<TPromise<FString>, ESPMode::ThreadSafe> Promise = MakeShared<TPromise<FString>, ESPMode::ThreadSafe>();
	TFuture<FString> Future = Promise->GetFuture();

	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();

	if (IsClientTest)
	{
		Promise->SetValue(TestFbxPath);
	}
	else
	{
		HttpRequest->SetURL(URL);
		HttpRequest->SetVerb("POST");
		HttpRequest->SetHeader("Content-Type", "application/json");
		HttpRequest->SetTimeout(900);
		const FString JsonPayload = FString::Printf(TEXT("{\"text_prompt\":\"%s\"}"), *UserInput);
		HttpRequest->SetContentAsString(JsonPayload);

		HttpRequest->OnProcessRequestComplete().BindLambda([Promise, this, UserInput](FHttpRequestPtr Request, const FHttpResponsePtr& Response, const bool bSuccess)
			{
				if (bSuccess && Response.IsValid())
				{
					TArray<uint8> Data = Response->GetContent();
					FString FileName = FString::Printf(TEXT("%s.fbx"), *UserInput);
					const FString FilePath = FPaths::Combine(ResponseFbxPath, FileName);
					if (FFileHelper::SaveArrayToFile(Data, *FilePath))
					{
						Promise->SetValue(FilePath);
					}
					else
					{
						UE_LOG(LogRAG, Warning, TEXT("Failed to save temp fbx file"));
						Promise->SetValue(TEXT(""));
					}
				}
				else
				{
					UE_LOG(LogRAG, Warning, TEXT("Failed to get valid HTTP response"));
					Promise->SetValue(TEXT(""));
				}
			});
		HttpRequest->ProcessRequest();
	}
	return Future;
}

void URAGManager::SaveAnimation(const FString& UserText, UAnimSequence* AnimSequence, const FString& SavePath) const
{
	const FString CurrentTime = FDateTime::Now().ToString(TEXT("%Y%m%d%H%M%S"));
	const FString UniqueUserText = UserText + "_" + CurrentTime;
	const FString PackageName = FPaths::Combine(SavePath, UniqueUserText);
	UPackage* Package = CreatePackage(*PackageName);

	AnimSequence->Rename(*UserText, Package);
	AnimSequence->SetFlags(RF_Public | RF_Standalone);

	FAssetRegistryModule::AssetCreated(AnimSequence);

	const FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	// Package save arguments
	FSavePackageArgs SaveArgs;
	SaveArgs.TopLevelFlags = EObjectFlags::RF_Public | EObjectFlags::RF_Standalone;
	SaveArgs.SaveFlags = SAVE_NoError;
	SaveArgs.bForceByteSwapping = true;

	if (bool bSaveFailed = !UPackage::SavePackage(Package, AnimSequence, *PackageFileName, SaveArgs))
	{
		UE_LOG(LogRAG, Error, TEXT("Failed to save animation sequence to content browser."));
	}
}

void URAGManager::GenerateAnimationInternal(FString UserText) const
{
	TFuture<FString> FilePathFuture = RequestAnimationData(UserText);
	FilePathFuture.Then([UserText, this](const TFuture<FString>& ResponseFuture)
		{
			if (const FString FilePath = ResponseFuture.Get(); !FilePath.IsEmpty())
			{
				AsyncTask(ENamedThreads::AnyThread, [FilePath, UserText, this]()
					{
						 if (const aiScene* Scene = AnimLoader->ImportAiScene(FilePath))
						 {
							 AsyncTask(ENamedThreads::GameThread, [Scene, UserText, this]()
								 {
									 if (UAnimSequence* ImportedAnimSequence = AnimLoader->CreateAnimSequenceFromAiScene(Scene))
									 {
										 if (bSaveSMPL) SaveAnimation(UserText, ImportedAnimSequence, SMPLPackagePath);

										 UAnimSequence* GeneratedAnimation = SmplRetargeter->RetargetAnimation(ImportedAnimSequence);
										 SaveAnimation(UserText, GeneratedAnimation, RetargetedPackagePath);
										 OnAnimationGenerated.Broadcast(GeneratedAnimation, UserText);
									 }
								 });
						 }
					});
			}
		});
}

