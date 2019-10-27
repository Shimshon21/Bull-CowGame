// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
	PrintLine(TEXT("Mooorning player,welcom to Bull & Cow game. "));
	PrintLine(TEXT("Gauss the X numbers"));
	PrintLine(TEXT("Press 'Enter' button to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

	ClearScreen();
	FString HiddenWord = TEXT("car");
	FString PlayerGauss = Input;
	if (HiddenWord == PlayerGauss)
	{
		PrintLine("You have won!");
	}
	else {
		PrintLine("You have lost!");
	}
/*	while (HiddenWord != PlayerGauss) {

	}*/
}