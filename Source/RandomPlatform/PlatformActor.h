
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

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> actorToSpawn;

	UPROPERTY(EditAnywhere)
	AActor* currentPlatform;

public:
	AActor* instantiatedActor;
	FVector newPos;
	int32 a, b;
	bool hasSpawnPlatform;
	float _dis, spawnTime, spawnPlatformTime, destroyTime;

	virtual void Tick(float DeltaTime) override;
};
