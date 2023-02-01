// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeapon.h"

// Sets default values
AMyWeapon::AMyWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Weapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WEAPON"));

	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UStaticMesh> SW;

		FConstructorStatics()
			:SW(TEXT("StaticMesh'/Game/ParagonGreystone/FX/Meshes/Heroes/Greystone/SM_Greystone_Blade_01.SM_Greystone_Blade_01'"))
		{}
	};

	static FConstructorStatics ConstructStatics;

	if (ConstructStatics.SW.Succeeded())
	{
		Weapon->SetStaticMesh(ConstructStatics.SW.Object);
		Weapon->SetRelativeScale3D(FVector(5.f, 5.f, 5.f));
	}

	Weapon->SetCollisionProfileName(TEXT("NoCollision"));
}

// Called when the game starts or when spawned
void AMyWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}


