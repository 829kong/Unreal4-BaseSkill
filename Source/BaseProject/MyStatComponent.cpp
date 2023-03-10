// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStatComponent.h"
#include "MyGameInstance.h"
#include "kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	bWantsInitializeComponent = true;
	m_Level = 1;
}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMyStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetLevel(m_Level);
}

void UMyStatComponent::SetLevel(int32 Level)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(Level);
		if (StatData)
		{
			m_Level = StatData->Level;
			SetHp(StatData->MaxHp);
			m_MaxHp = StatData->MaxHp;
			m_Attack = StatData->Attack;
		}
	}
}

void UMyStatComponent::SetHp(int32 NewHp)
{
	m_Hp = NewHp;
	if (m_Hp < 0)
		m_Hp = 0;

	OnHpChanged.Broadcast();
}

void UMyStatComponent::OnAttacked(float DamageAmount)
{
	int32 NewHp = m_Hp - DamageAmount;
	SetHp(NewHp);
}

