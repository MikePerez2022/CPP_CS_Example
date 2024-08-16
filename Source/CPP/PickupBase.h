// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

UCLASS()
class CPP_API APickupBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlap(AActor* OverlapedActor, AActor* OtherActor);

	UFUNCTION(BlueprintCallable, Category = "Action")
	void Print() const;

	UFUNCTION(BlueprintCallable, Category = "Action")
	void ShowDebug(const FColor& color);

	UPROPERTY(EditAnywhere, Category = "Gameplay", meta = (ToolTip = "Rotation rate of Object.", ClampMin = "0", ClampMax = "100"))
	float RotationRate = 0;

	UPROPERTY(EditAnywhere, Category = "Gameplay")
	float SphereRadius = 32;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	class USphereComponent* Sphere;
	

};
