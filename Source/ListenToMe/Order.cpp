// Fill out your copyright notice in the Description page of Project Settings.


#include "Order.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "SG_SaveGame.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOrder::AOrder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOrder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOrder::GetOrderWidget()
{
	if (WidgetClass)
	{
		OrderWidget = CreateWidget<UUserWidget>(GetWorld(),WidgetClass);
		OrderWidget->AddToViewport();
		if (OrderWidget)
		{
			OrderText = Cast<UTextBlock>(OrderWidget->GetWidgetFromName(TEXT("OrderText")));
			
		}
	}
}

int AOrder::RandomOrder()
{
	int32 RandomNumber = FMath::RandRange(0,TextArray.Num()-1);

	if (OrderText)
	{
		OrderText->SetText(FText::FromString(TextArray[RandomNumber]));
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("현재 OrderText가 없습니다."));
	}

	return RandomNumber;
}

void AOrder::CompleteOrder()
{
	if (OrderText)
	{
		OrderText->SetText(FText::FromString(TEXT("옳지!")));
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("현재 OrderText가 없습니다."));
	}
}

void AOrder::FailOrder()
{
	if (OrderText)
	{
		OrderText->SetText(FText::FromString(TEXT("아이고...")));
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("현재 OrderText가 없습니다."));
	}
}

bool AOrder::CompareScore(int32 score)
{
	USG_SaveGame* SaveGame = Cast<USG_SaveGame>(UGameplayStatics::LoadGameFromSlot("ScoreSlot", 0));
	if (nullptr == SaveGame)
	{
		USG_SaveGame* SaveGameInstance = Cast<USG_SaveGame>(UGameplayStatics::CreateSaveGameObject(USG_SaveGame::StaticClass()));
    
		if (SaveGameInstance)
		{
			SaveGameInstance->Score = score;
			UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("ScoreSlot"), 0);
		}
		return true;
	}

	if (score>SaveGame->Score)
	{
		SaveGame->Score = score;
		UGameplayStatics::SaveGameToSlot(SaveGame, TEXT("ScoreSlot"), 0);
		return true;
	}

	return false;
	

	
}






