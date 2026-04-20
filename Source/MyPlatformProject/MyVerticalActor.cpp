#include "MyVerticalActor.h"

AMyVerticalActor::AMyVerticalActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

	StartLocation = FVector(0.0f);
	Destination = FVector(0.0f);
	MoveOffset = FVector(0.0f, 0.0f, 500.0f);
	bRepeat = true;
	MoveSpeed = 100.0f;
	bSetTimer = true;
	TimerOffset = 3.0f;
}

void AMyVerticalActor::SetActorStartPosition()
{
}

void AMyVerticalActor::SetActorDestination()
{
}

void AMyVerticalActor::SetActorMoveSpeed()
{
	MoveSpeed = FMath::RandRange(100.0f, 700.0f);
}

void AMyVerticalActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AMyVerticalActor::BeginPlay()
{
	Super::BeginPlay();

	bTowardDest = true;
	StartLocation = GetActorLocation();
	Destination = StartLocation + MoveOffset;

	if (bSetTimer) {
		GetWorld()->GetTimerManager().SetTimer(
			MyTimerHandle,
			this,
			&AMyVerticalActor::SetActorMoveSpeed,
			TimerOffset,
			bSetTimer
		);	// TimerOffset 초마다 AMyVerticalActor::SetActorMoveSpeed() 반복(bSetTimer == true) 호출
	}
}

void AMyVerticalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(MoveSpeed)) {
		FVector CurrentLocation = GetActorLocation();
		FVector Target = bTowardDest ? Destination : StartLocation;
		// TowardDest 가 true일땐 Destination이 Target, False 일땐 StartLocalLoction이 Target

		FVector Direction = (Target - CurrentLocation).GetSafeNormal();
		FVector Move = Direction * MoveSpeed * DeltaTime;
		AddActorWorldOffset(Move);

		if (FVector::Dist(CurrentLocation, Target) < 5.0f)
		{
			bTowardDest = !bTowardDest;
		}
	}
}

void AMyVerticalActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

}
