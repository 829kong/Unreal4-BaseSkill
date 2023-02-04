// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnHpChanged);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASEPROJECT_API UMyStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:
	void SetLevel(int32 Level);
	void SetHp(int32 NewHp);
	void OnAttacked(float DamageAmount);

	int32 GetLevel() { return m_Level; }
	int32 GetHp() { return m_Hp; }
	int32 GetMaxHp() { return m_MaxHp; }
	float GetHpRatio() { return m_Hp / (float)m_MaxHp; }
	int32 GetAttack() { return m_Attack; }

private:
	UPROPERTY(EditAnywhere,Category=Stat,Meta=(AllowPrivateAccess=true))
	int32 m_Level;
	UPROPERTY(EditAnywhere,Category=Stat,Meta=(AllowPrivateAccess=true))
	int32 m_Hp;	

	UPROPERTY(EditAnywhere,Category=Stat,Meta=(AllowPrivateAccess=true))
	int32 m_MaxHp;
	UPROPERTY(EditAnywhere,Category=Stat,Meta=(AllowPrivateAccess=true))
	int32 m_Attack;

public:
	FOnHpChanged OnHpChanged;
};
