#include "CBullet.h"
#include "GameFramework/ProjectileMovementComponent.h"


ACBullet::ACBullet()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StaticMeshes/SM_Sphere"));
	if (MeshAsset.Succeeded()) {
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}

	ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset( TEXT("/Game/Materials/M_Bullet"));
	if (MeshAsset.Succeeded()) {
		MeshComp->SetMaterial(0, MaterialAsset.Object);
	}


	MeshComp->SetWorldScale3D(FVector(1.f, 0.025f, 0.025f));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->CastShadow = false;

	MoveComp = CreateDefaultSubobject<UProjectileMovementComponent>("MoveComp");
	MoveComp->InitialSpeed = 2e+4f;
	MoveComp->MaxSpeed = 2e+4f;
	MoveComp->ProjectileGravityScale = 0.f;

	InitialLifeSpan = 3.f;
}

