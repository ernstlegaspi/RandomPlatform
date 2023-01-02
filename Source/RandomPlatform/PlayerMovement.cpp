

#include "PlayerMovement.h"

APlayerMovement::APlayerMovement() {
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerMovement::BeginPlay() {
	Super::BeginPlay();
}

void APlayerMovement::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void APlayerMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}