// Fill out your copyright notice in the Description page of Project Settings.
//https://www.youtube.com/watch?v=nvruYLgjKkk&list=PL-m4pn2uJvXHL5rxdudkhqrSRM5gN43YN&index=1
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameCharcter.generated.h"

UCLASS()
class PROJETVULCAIN_API AGameCharcter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGameCharcter();

	// Delta movement
	void MoveLR(float movementDelta);
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Main pawn Camera
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CameraMesh;

	// Movement Speed 
	UPROPERTY(EditAnywhere, Category = "Charcter Settings")
	float MovementSpeed = 1.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
