// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UDataTable> DATA;

		FConstructorStatics()
			: DATA(TEXT("DataTable'/Game/Data/StatTable.StatTable'"))
		{}
	};

	static FConstructorStatics ConstructorStatics;

	MyStat = ConstructorStatics.DATA.Object;
}

void UMyGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("MyGameInstance %d"), GetStatData(1)->Attack);
}

FMyCharacterData* UMyGameInstance::GetStatData(int32 Level)
{
	return MyStat->FindRow<FMyCharacterData>(*FString::FromInt(Level), TEXT(""));
}
