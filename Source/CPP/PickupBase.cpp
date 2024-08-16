// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupBase.h"
#include "Components/SphereComponent.h"
#include "CPPCharacter.h"

// Sets default values
APickupBase::APickupBase()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetCollisionProfileName(TEXT("NoCollision"));

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Sphere->SetCollisionProfileName(TEXT("Trigger"));
	Sphere->SetSphereRadius(SphereRadius);

	//Attachmenta
	Sphere->SetupAttachment(RootComponent);
	StaticMesh->SetupAttachment(Sphere);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OnActorBeginOverlap.AddDynamic(this, &APickupBase::OnOverlap);

}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldRotation(FRotator(0, RotationRate * DeltaTime, 0));

}

void APickupBase::OnOverlap(AActor* OverlapedActor, AActor* OtherActor)
{
	if (Cast<ACPPCharacter>(OtherActor) != nullptr)
	{
		Destroy();
	}
}

void APickupBase::Print() const
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2, FColor::Green, TEXT("Hello World!"));
}

void APickupBase::ShowDebug(const FColor& color)
{
	DrawDebugSphere(GetWorld(), GetActorLocation(), SphereRadius, 12, color);
}

