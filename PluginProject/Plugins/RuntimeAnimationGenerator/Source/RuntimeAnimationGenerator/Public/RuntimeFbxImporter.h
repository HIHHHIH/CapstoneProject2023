// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "assimp/postprocess.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "CoreMinimal.h"

/**
 * 
 */
class RUNTIMEANIMATIONGENERATOR_API RuntimeFbxImporter
{
public:

	bool static ImportFbxFile(const FString& FilePath, UStaticMesh*& OutStaticMesh);
};
