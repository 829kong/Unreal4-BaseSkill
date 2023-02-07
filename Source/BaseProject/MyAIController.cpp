// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "NavigationSystem.h"
#include "BluePrint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController()
{
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UBehaviorTree> BT;
		ConstructorHelpers::FObjectFinder<UBlackboardData> BB;

		FConstructorStatics()
			:BT(TEXT("BehaviorTree'/Game/AI/BT_MyCharacter.BT_MyCharacter'")),
			BB(TEXT("BlackboardData'/Game/AI/BB_MyCharacter.BB_MyCharacter'"))
		{}
	};

	static FConstructorStatics ConstructorStatics;

	if (ConstructorStatics.BT.Succeeded())
		BehaviorTree = ConstructorStatics.BT.Object;
	if (ConstructorStatics.BB.Succeeded())
		BlackboardData = ConstructorStatics.BB.Object;

}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//GetWorld()->GetTimerManager().SetTimer(TimerHandle,this, &AMyAIController::RandomMove, 2.f, true);

	if (UseBlackboard(BlackboardData, Blackboard))
	{
		if (RunBehaviorTree(BehaviorTree))
		{

		}
	}
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();

	//GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void AMyAIController::RandomMove()
{
	auto CurrentPawn = GetPawn();

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
		return;

	FNavLocation RandomLocation;
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
	}
}
