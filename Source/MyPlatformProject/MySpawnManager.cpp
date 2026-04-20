#include "MySpawnManager.h"
#include "MyVerticalActor.h"
#include "Kismet/KismetMathLibrary.h"

ASpawnManager::ASpawnManager()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	PrimaryActorTick.bCanEverTick = false;
}

void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();

	if (!PlatformClass) {
		return;
	}

	for (int i = 0; i < SpawnCount; i++)
	{
		FVector Center = GetActorLocation();

		FVector Location;
		Location.X = Center.X + FMath::RandRange(-SpawnRange.X, SpawnRange.X);
		Location.Y = Center.Y + FMath::RandRange(-SpawnRange.Y, SpawnRange.Y);
		Location.Z = Center.Z + SpawnRange.Z;

		FRotator Rotation(0.f, FMath::RandRange(0.f, 360.f), 0.f);

		GetWorld()->SpawnActor<AMyVerticalActor>(
			PlatformClass,
			Location,
			Rotation
		);
	}
}