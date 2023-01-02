
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorPlatform.generated.h"

UCLASS()
class RANDOMPLATFORM_API AActorPlatform : public AActor {
	GENERATED_BODY()
	
public:	
	AActorPlatform();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
