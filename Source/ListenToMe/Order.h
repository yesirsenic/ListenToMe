// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Order.generated.h"


class USaveGame;

UCLASS()
class LISTENTOME_API AOrder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere,Category= "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> WidgetClass;

	
	TArray<FString> TextArray ={
		TEXT("짖어!"),
		TEXT("점프해!"),
		TEXT("뛰어"),
		TEXT("뛰면서 점프해!")
	};
	
	UUserWidget* OrderWidget = nullptr;
	class UTextBlock* OrderText = nullptr;

	

protected:
	UFUNCTION(BlueprintCallable, Category = "OrderFunction")
	void GetOrderWidget();
	
	UFUNCTION(BlueprintCallable, Category = "OrderFunction")
	int RandomOrder();

	UFUNCTION(BlueprintCallable, Category = "OrderFunction")
	void CompleteOrder();

	UFUNCTION(BlueprintCallable, Category = "OrderFunction")
	void FailOrder();

	UFUNCTION(BlueprintCallable, Category = "OrderFunction")
	bool CompareScore(int32 score);

};
