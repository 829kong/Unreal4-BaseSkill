// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFrameWork/Character.h"
#include "GameFrameWork/PawnMovementComponent.h"

UMyAnimInstance::UMyAnimInstance()
{
	struct FConstructStatics
	{
		ConstructorHelpers::FObjectFinder<UAnimMontage> AM;

		FConstructStatics()
			:AM(TEXT("AnimMontage'/Game/Animations/Greystone_Skeleton_Montage.Greystone_Skeleton_Montage'"))
		{

		}
	};

	static FConstructStatics ConstructStatics;

	if (ConstructStatics.AM.Succeeded())
	{
		AttackMomtage = ConstructStatics.AM.Object;
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<ACharacter>(Pawn);
		if (Character)
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();
		}
	}
}


void UMyAnimInstance::PlayAttackMontage()
{

		Montage_Play(AttackMomtage,1.f);
}
