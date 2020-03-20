// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

	SetupGame();
	PrintInterduction();

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
	ClearScreen();
	
	FString PlayerGuess = Input;
	if (BGameOver) {
		SetupGame();
		ClearScreen();
		PrintInterduction();
	}
	else {
		ProcessGame(PlayerGuess);
	}
}

//Set up the game word and the  player lives
void UBullCowCartridge::SetupGame() {

	HiddenWord = TEXT("car");
	PlayerLives = HiddenWord.Len();
	BGameOver = false;

	const TCHAR HW[] = TEXT("cakes");
	const TCHAR HW[] = { TEXT('c'),TEXT('a') ,TEXT('k') ,TEXT('e') ,TEXT('s'),TEXT('\0') };
	PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWord[0]);
	PrintLine(TEXT("The 4th character of HW is:%c"), HW[3]);//print the letter e

}

//Print interduction
void UBullCowCartridge::PrintInterduction() {
	//PrintLine(FString::Printf(TEXT("The HiddenWord is:%s with the length: %i"), *HiddenWord, HiddenWord.Len()));//debug line
	PrintLine(TEXT("Moorning player,welcome to Bull & Cow game."));
	PrintLine(FString::Printf(TEXT("Guess the %i characters in the word,you got %i lives to guess."), HiddenWord.Len(),PlayerLives));
	PrintLine(TEXT("Type in your guess and press 'Enter' button to continue..."));	//Ask from the player to gauess a word
}

//Set finishes game ,ask to play again.
void UBullCowCartridge::EndGame() {
	BGameOver = true;
}

// Check the player word
void UBullCowCartridge::ProcessGame(FString PlayerGuess) {
	//If correct the player win the game
	if (HiddenWord == PlayerGuess)
	{
		PrintLine(TEXT("You have won!"));
		PrintLine(TEXT("Press enter to continue...."));
		EndGame();
		return;
	}
	
	//If the player wrong one life is subbtrect
	else if(HiddenWord != PlayerGuess) {
		PlayerLives--;
		//If the player lives is 0 the game is lost
		if (PlayerLives == 0) {
			PrintLine(TEXT("You have lost!"));
			PrintLine(FString::Printf(TEXT("The hidden word was %s \n"), *HiddenWord));
			PrintLine(TEXT("Press enter to continue...."));
			EndGame();
			return;
		}
		//If The length word is not match loose 1 life
		else if (HiddenWord.Len() != PlayerGuess.Len()) {
			PrintLine(FString::Printf(TEXT("The hidden word is %i charachter long,try again..."), HiddenWord.Len()));
		}
		else if (!IsIsogram(HiddenWord)) {
			PrintLine(TEXT("No repeating letters, guess again"));

		}
		else {
			PrintLine(TEXT("Wrong word try again..."));
		}
		PrintLine(FString::Printf(TEXT("You have %i tries left"), PlayerLives));
	}
	
}


//Show player the bulls and cow letters
bool UBullCowCartridge:: IsIsogram(FString Word) {
	//For each letter.
	//Start at element[0].
	//Compare against the next letter.
	//Until we reach[word.Len() -1]
	//if any are the same return false.



	return true;
}

