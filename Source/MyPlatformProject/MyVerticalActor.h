#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyVerticalActor.generated.h"

UCLASS()
class MYPLATFORMPROJECT_API AMyVerticalActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyVerticalActor();

	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void SetActorStartPosition();

	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	void SetActorDestination();

	UFUNCTION(Category = "Item|Actions")
	void SetActorMoveSpeed();


protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	FTimerHandle MyTimerHandle;	// 타이머

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;	// Root 컴포넌트가 될 Scene 컴포넌트

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp; // Static Mesh 컴포넌트

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	FVector StartLocation;	// 시작 위치

	FVector Destination;	// 도착 위치, 리플렉션 시스템에 필요없음

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	FVector MoveOffset;		// (도착점-시작위치)의 절대값

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	bool bRepeat;		// 왕복 이동 여부

	bool bTowardDest = true;	// 리플렉션 시스템에 필요 없음

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	float MoveSpeed;	// 이동 속도

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	float TimerOffset;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	bool bSetTimer;		// 타이머 사용 여부
};
