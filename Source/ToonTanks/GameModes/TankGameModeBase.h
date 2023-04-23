// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTank;
class APawnTurret;
class APlayerControllerBase;

UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	APawnTank* PlayerTank;
	APlayerControllerBase* PlayerControllerRef;

	int32 TargetTurrets = 0;
	int32 PlayerScore = 0;
	int32 GetTurretCount();
	void HandlePlayerStart();
	void HandleGameOver(bool PlayerWon);
	void HandlePlayerScore(int32 Score);

public:
	void ActorDied(AActor* ActorDead);
	UFUNCTION(BlueprintImplementableEvent)
	void PlayerHealth(int32 Health);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop");
	int32 StartDelay = 3;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GameScore(int32 Score);
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
};
