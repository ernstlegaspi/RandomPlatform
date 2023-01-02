
#include "PlatformActor.h"

APlatformActor::APlatformActor() {
	PrimaryActorTick.bCanEverTick = true;
}

void APlatformActor::BeginPlay() {
	Super::BeginPlay();

	spawnTime = 3.0f;
	spawnPlatformTime = spawnTime;
	destroyTime = 3.0f;
	hasSpawnPlatform = false;
	_dis = 2500.0f;
}

void APlatformActor::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	spawnPlatformTime -= DeltaTime;

	if(spawnPlatformTime <= 0) {
		a = FMath::RandRange(0, 1);
		b = FMath::RandRange(0, 1);

		if (a == 1) newPos.X = b == 1 ? newPos.X + _dis : newPos.X - _dis;
		else newPos.Y = b == 1 ? newPos.Y + _dis : newPos.Y - _dis;

		spawnPlatformTime = spawnTime;
		instantiatedActor = GetWorld()->SpawnActor<AActor>(actorToSpawn, currentPlatform->GetActorTransform());
		instantiatedActor->SetActorLocation(newPos);
		hasSpawnPlatform = true;
	}

	if(hasSpawnPlatform) {
		destroyTime -= DeltaTime;

		if(destroyTime <= 0) {
			currentPlatform->Destroy();
			currentPlatform = instantiatedActor;
			hasSpawnPlatform = false;
			destroyTime = 3.0f;
		}
	}
}