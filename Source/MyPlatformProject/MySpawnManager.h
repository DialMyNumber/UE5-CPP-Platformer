#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MySpawnManager.generated.h"

class AMyVerticalActor;

UCLASS()
class MYPLATFORMPROJECT_API ASpawnManager : public AActor
{
	GENERATED_BODY()

public:
	ASpawnManager();

protected:
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AMyVerticalActor> PlatformClass;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 SpawnCount = 4;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	FVector SpawnRange = FVector(500.0f, 500.0f, 0.0f);
};