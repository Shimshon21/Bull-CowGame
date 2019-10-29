// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

	SetupGame();

	PrintInterduction();
	//Set the player lives number
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();
	
	FString PlayerGauss = Input;

	if (HiddenWord == PlayerGauss)
	{
		
		PrintLine(TEXT("You have won!"));
		
	}
	else {
		if (HiddenWord.Len() != PlayerGauss.Len()) {
			PrintLine(FString::Printf(TEXT("The hidden word is %i charachter long,try again."),HiddenWord.Len()));
		}
	/*	if (PlayerLives == 0) {
			PrintLine("You have lost!");
		}
		else {
			PrintLine("Wrong answer try again!");
			PlayerLives--;
		}*/

	}
}

// Check the player word

//If correct the player win the game
//Ask the player to play again

//If the player wrong one life is subbtrect
//Ask the player to play again


//Set up the game word and the  player lives
void UBullCowCartridge::SetupGame() {
	HiddenWord = TEXT("car");
	PlayerLives = 3;
}

//Print interduction
void UBullCowCartridge::PrintInterduction() {
	PrintLine(FString::Printf(TEXT("The HiddenWord is:%s with the length: %i"), *HiddenWord, HiddenWord.Len()));//debug line
	PrintLine(TEXT("Moorning player,welcome to Bull & Cow game."));
	PrintLine(FString::Printf(TEXT("Guess the %i characters in the word"), HiddenWord.Len()));
	PrintLine(TEXT("Type in your guess and press 'Enter' button to continue..."));	//Ask from the player to gauess a word
}