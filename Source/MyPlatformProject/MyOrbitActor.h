#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyOrbitActor.generated.h"

UCLASS()
class MYPLATFORMPROJECT_API AMyOrbitActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyOrbitActor();

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;	// Root 컴포넌트가 될 Scene 컴포넌트

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UInstancedStaticMeshComponent* InstancedMesh;	// 동일한 Static Mesh를 인스턴싱하여 여러번 사용

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	float RotationSpeed;	// 회전 속도

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	int32 PlatformShapeCount;	// 인스턴스의 정N각형 모양을 결정하는 인자

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	int32 PlatformRenderCount;	// 실제 렌더링 될 인스턴스 개수

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	float PlatformRadius;	// 중심으로부터 떨어진 거리 = 반지름

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Item|Properties")
	float PlatformDeltaHeight;	// 중심으로부터 각 플랫폼끼리의 높이 차이

};
