// Fill out your copyright notice in the Description page of Project Settings.


#include "MYGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = AMyCharacter::StaticClass();

	static ConstructorHelpers::FClassFinder<ACharacter> BP_Charac(TEXT("Blueprint'/Game/BluePrints/BP_MyCharacter.BP_MyCharacter_C'"));
	

	if (BP_Charac.Succeeded())
	{
		DefaultPawnClass = BP_Charac.Class;
	}
}
