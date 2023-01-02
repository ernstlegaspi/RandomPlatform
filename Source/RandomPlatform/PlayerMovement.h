
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerMovement.generated.h"

UCLASS()
class RANDOMPLATFORM_API APlayerMovement : public APawn {
	GENERATED_BODY()

public:
	APlayerMovement();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
