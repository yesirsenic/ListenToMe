// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SG_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class LISTENTOME_API USG_SaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="SaveGame")
	int32 Score = 0;
	
};
