#include "PlayerMovement.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

APlayerMovement::APlayerMovement() {
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerMovement::BeginPlay() {
	Super::BeginPlay();

	if(APlayerController* PlayerController = Cast<APlayerController>(GetController())) {
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(PlayerMappingContext, 0);
		}
	}
}

void APlayerMovement::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void APlayerMovement::Move(const FInputActionValue& Value) {
	FVector DirVal = Value.Get<FVector>();

	if(Controller && (DirVal.X != 0 || DirVal.Y != 0)) {
		FVector _Forward = GetActorForwardVector();
		FVector _Sidewards = GetActorRightVector();

		AddMovementInput(_Forward, DirVal.Y);
		AddMovementInput(_Sidewards, DirVal.X);
	}
}

void APlayerMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &APlayerMovement::Move);
	}
}