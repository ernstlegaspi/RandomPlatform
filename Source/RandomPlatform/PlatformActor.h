
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformActor.generated.h"

UCLASS()
class RANDOMPLATFORM_API APlatformActor : public AActor {
	GENERATED_BODY()
	
public:	
	APlatformActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
