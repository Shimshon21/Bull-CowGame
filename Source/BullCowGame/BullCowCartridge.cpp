// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
	PrintLine(TEXT("Moorning player,welcome to Bull & Cow game."));
	PrintLine(TEXT("Guess the X numbers"));
	//Set the player lives number
	PlayerLives = 4;
	PrintLine(TEXT("Press 'Enter' button to continue..."));
	HiddenWord = TEXT("car");
	//Ask from the player to gauess a word

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();

	FString PlayerGauss = Input;

	if (HiddenWord == PlayerGauss)// Check the player word
	{//If correct the player win and should be asked if he want to play again
		PrintLine("You have won!");
	}
	else {//If the player wrong one life is subbtrect
		if (PlayerLives == 0) {
			PrintLine("You have lost!");
			//Ask the player to play again
		}
		else {
			PrintLine("Wrong answer try again!");
			PlayerLives--;
		}
	}
}
