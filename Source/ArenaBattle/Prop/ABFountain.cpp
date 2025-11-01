// Fill out your copyright notice in the Description page of Project Settings.


#include "Prop/ABFountain.h"

// Sets default values
AABFountain::AABFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Water"));

	// 루트 컴포넌트 지정은 필수
	RootComponent = Body;
	Water->SetupAttachment(Body);
	Water->SetRelativeLocation(FVector(0, 0, 132));

	ConstructorHelpers::FObjectFinder<UStaticMesh> BodyRef(TEXT("/Game/ArenaBattle/Environment/Props/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01"));
	check(BodyRef.Object);
	if (BodyRef.Object)
	{
		Body->SetStaticMesh(BodyRef.Object);
	}

	ConstructorHelpers::FObjectFinder<UStaticMesh> WaterRef(TEXT("/Game/ArenaBattle/Environment/Props/SM_Plains_Fountain_02.SM_Plains_Fountain_02"));
	check(WaterRef.Object);
	if (WaterRef.Object)
	{
		Water->SetStaticMesh(WaterRef.Object);
	}
}

// Called when the game starts or when spawned
void AABFountain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AABFountain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

