
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "PlayerMovement.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class RANDOMPLATFORM_API APlayerMovement : public APawn {
	GENERATED_BODY()

public:
	APlayerMovement();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveInputAction;

	void Move(const FInputActionValue& Value);
public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
