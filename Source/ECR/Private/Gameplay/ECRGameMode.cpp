// Copyright Epic Games, Inc. All Rights Reserved.

#include "Gameplay/ECRGameMode.h"
#include "System/ECRLogChannels.h"
#include "GameFramework/PlayerState.h"
#include "Gameplay/Character/ECRCharacter.h"
#include "Gameplay/Character/ECRPawnExtensionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AECRGameMode::AECRGameMode()
{
}

FString AECRGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId,
                                    const FString& Options, const FString& Portal)
{
	// Setting player display name according to options
	const FString PlayerName = UGameplayStatics::ParseOption(Options, TEXT("DisplayName"));
	ControllersToDisplayNames.Add(NewPlayerController, PlayerName);

	return Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
}
