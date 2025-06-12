// Fill out your copyright notice in the Description page of Project Settings.
//https://www.youtube.com/watch?v=nvruYLgjKkk&list=PL-m4pn2uJvXHL5rxdudkhqrSRM5gN43YN&index=1


#include "GameCharcter.h"

// Sets default values
AGameCharcter::AGameCharcter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create components
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CameraMesh"));


	// Setup camera
	Camera->FieldOfView = 120.f;
	Camera->SetupAttachment(CameraMesh);
	Camera->SetRelativeLocation(FVector(-200.0f, 0.0f, 150.0f));
}

void AGameCharcter::MoveLR(float movementDelta) 
{
	FVector newLocation = GetActorLocation();
	newLocation.Y += movementDelta * MovementSpeed;
	SetActorLocation(newLocation);
}

// Called when the game starts or when spawned
void AGameCharcter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameCharcter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameCharcter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Register for LR Movement 
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AGameCharcter::MoveLR);

}

