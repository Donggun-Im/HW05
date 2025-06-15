// Copyright Epic Games, Inc. All Rights Reserved.

#include "HW05GameMode.h"
#include "HW05PlayerController.h"
#include "HW05Character.h"
#include "UObject/ConstructorHelpers.h"

AHW05GameMode::AHW05GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHW05PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}