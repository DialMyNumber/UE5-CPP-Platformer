#include "MyOrbitActor.h"
#include "Components/InstancedStaticMeshComponent.h"


AMyOrbitActor::AMyOrbitActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	InstancedMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedMesh"));
	InstancedMesh->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

	RotationSpeed = 45.0f;
	PlatformShapeCount = 2;
	PlatformRenderCount = 2;
	PlatformRadius = 600.0f;
	PlatformDeltaHeight = 0.0f;

}

void AMyOrbitActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AMyOrbitActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMyOrbitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed)) {
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

void AMyOrbitActor::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    if (!InstancedMesh || !InstancedMesh->GetStaticMesh())
        return;

    InstancedMesh->ClearInstances();

    float DeltaHeightSum = 0;
    for (int32 i = 0; i < PlatformRenderCount; ++i) // PlatformRenderCount 만큼만 반복 렌더링
    {
        float AngleDeg = (360.f / PlatformShapeCount) * i;  // 각도는 PlatformShapeCount를 이용
        float AngleRad = FMath::DegreesToRadians(AngleDeg);

        DeltaHeightSum += PlatformDeltaHeight;
        FVector Location;
        Location.X = FMath::Cos(AngleRad) * PlatformRadius;
        Location.Y = FMath::Sin(AngleRad) * PlatformRadius;
        Location.Z = 0.f + DeltaHeightSum;

        FTransform InstanceTransform;
        InstanceTransform.SetLocation(Location);

        /* 바깥을 바라보게 회전
        FRotator Rotation = FRotationMatrix::MakeFromX(Location).Rotator();
        InstanceTransform.SetRotation(Rotation.Quaternion());
        */

        InstancedMesh->AddInstance(InstanceTransform);
    }
}