#include "CAR4.h"
#include "Utilities/CLog.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"

ACAR4::ACAR4()
{
 	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/Weapons/Meshes/AR4/SK_AR4"));
	if (MeshAsset.Succeeded()) {
		MeshComp->SetSkeletalMesh(MeshAsset.Object);
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> EquipMontageAsset(TEXT("/Game/Character/Animations/Rifle/Rifle_Equip_Montage"));
	if (EquipMontageAsset.Succeeded()) {
		EquipMontage = EquipMontageAsset.Object;
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> UnequipMontageAsset(TEXT("/Game/Character/Animations/Rifle/Rifle_Unequip_Montage"));
	if (UnequipMontageAsset.Succeeded()) {
		UnequipMontage = UnequipMontageAsset.Object;
	}

	HolsterSoket = "Holster_AR4";
	HandSoket = "Hand_AR4";
}

void ACAR4::BeginPlay()
{
	Super::BeginPlay();
	
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	AttachToComponent(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative,true),
		HolsterSoket
	);
}

void ACAR4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACAR4::Equip()
{
	if (bEquipped) return;
	if (bPlayingMontage) return;

	PrintLine();

	bEquipped = true;
	bPlayingMontage = true;

	OwnerCharacter->PlayAnimMontage(EquipMontage);
}

void ACAR4::Unequip()
{
}

