#include "Board.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>



Board::Board()
{
}

Board::~Board()
{

}

//method to draw up a board and also print out the current score
void Board::drawBoard()
{

	std::cout << "  .----.  .----.  .----.  .----.    |  \n";
	std::cout << "  | " << guess[0] << "  |  |  " << guess[1] << " |  |  " << guess[2] << " |  | " << guess[3] << "  |    | " << accurateCode[0] << accurateCode[1] << accurateCode[2] << accurateCode[3] << " \n ";
	std::cout << " '----'  '----'  '----'  '----'    |   \n";
	std::cout << "Score: " << score << " \n ";

}
//method to ask the player for the code and take 100 points away from score for each guess
void Board::askForCode()
{
	
	std::cout << "Player guess (or type 'quit' to exit) : ";
	std::cin >> guess[0] >> guess[1] >> guess[2] >> guess[3];
	if (guess[0] == 'q' && guess[1] == 'u' && guess[2] == 'i' && guess[3] == 't')
	{
		gameOver = true;
		score = score - score + 100;
	}
	score -= 100;
	
}

//method to check to see if the player entered code matched the generated secret code
void Board::checkForWin()
{
	if (secretCode[0] == guess[0] && secretCode[1] == guess[1] && secretCode[2] == guess[2] && secretCode[3] == guess[3])
	{
		gameOver = true;
		score = score * difficultyMultiplyer;
		std::cout << "Congratulations, you have cracked the code! " << std::endl;
		std::cout << "Score: " << score << " \n ";
		
	}
	
}

int Board::getScore()
{
	return score;
}

//main method which asks for the code, verifys code, draws the board then checks for a win, repeats this 10 times or until check for win becomes true
void Board::createBoard()
{
	score = 1200;
	int i;
	std::cout << "Game difficulty. " << std::endl;
	std::cout << "1. Easy " << "\n";
	std::cout << "2. Trickey " << "\n";
	std::cout << "3. MasterMind " << "\n";
	std::cout << "Please select: ";
	std::cin >> difficulty;

	switch (difficulty)
	{
	case 1:
		difficulty = 12;
		difficultyMultiplyer = 1;
		break;
	case 2:
		difficulty = 10;
		difficultyMultiplyer = 2;
		break;
	case 3:
		difficulty = 8;
		difficultyMultiplyer = 3;
		break;
	}
	//looping the game until the code has been cracked or the player is out of turns	
	getScore();
	for (i = 0; i < difficulty	; i++)
	{
		askForCode();
		verifyCode();
		drawBoard();
		checkForWin();
		if (gameOver)
		{
			break;
		}
	
	}
	//if the player fails to crack the code, set score to 0
	if (i == difficulty)
	{
		score = 0;
		std::cout << "You have failed to crack the code. " << std::endl;
		std::cout << "Score: " << score << " \n ";
	}
}

//code to give feed back to player about the accuracy of the code
void Board::verifyCode()
{
	//first checks to see if the guess matches any part of the secret code
	//if it does it check to see if the guess also matches the correct part of the secret code
	//else it will show that the guess is incorrect
	if (guess[0] == secretCode[0] || guess[0] == secretCode[1] || guess[0] == secretCode[2] || guess[0] == secretCode[3])
	{
		accurateCode[0] = 'X';

		if (guess[0] == secretCode[0])
		{
			accurateCode[0] = 'Y';
		}
		
	}
	else {
		accurateCode[0] = 'Z';
	}
	
	
	
	if (guess[1] == secretCode[0] || guess[1] == secretCode[1] || guess[1] == secretCode[2] || guess[1] == secretCode[3])
	{
		accurateCode[1] = 'X';
		if (guess[1] == secretCode[1])
		{
			accurateCode[1] = 'Y';
		}

	}
	else {
		accurateCode[1] = 'Z';
	}
	
	if (guess[2] == secretCode[0] || guess[2] == secretCode[1] || guess[2] == secretCode[2] || guess[2] == secretCode[3])
	{
		accurateCode[2] = 'X';
		if (guess[2] == secretCode[2])
		{
			accurateCode[2] = 'Y';
		}
	}
	else {
		accurateCode[2] = 'Z';
	}

	if (guess[3] == secretCode[0] || guess[3] == secretCode[1] || guess[3] == secretCode[2] || guess[3] == secretCode[3])
	{
		accurateCode[3] = 'X';
		if (guess[3] == secretCode[3])
		{
			accurateCode[3] = 'Y';
		}
	}
	else {
		accurateCode[3] = 'Z';
	}
	
	


}


//creating the secrte code
void Board::createCode()
{

	int i = 0;
	int j = 0;
	//getting a random number between 0 and 26, then adding it to 65, then converting that number into a char which represents a letter in the alphabet
	srand(time(NULL));
	for (i = 0; i < 1; i++)
	{
		j = rand() % 26;
		secretCode[0] = (char)(j + 65);

	}
	for (i = 0; i < 1; i++)
	{
		j = rand() % 26;
		secretCode[1] = (char)(j + 65);

	}
	for (i = 0; i < 1; i++)
	{
		j = rand() % 26;
		secretCode[2] = (char)(j + 65);

	}
	for (i = 0; i < 1; i++)
	{
		j = rand() % 26;
		secretCode[3] = (char)(j + 65);

	}
	//Testing to see the code to test other functions
	//std::cout << secretCode[0] << secretCode[1] << secretCode[2] << secretCode[3] << std::endl;
}
//main function for the ai to see how fast it can crack a code
void Board::aiPlay()
{
	while (gameOver != true)
	{
		aiGuessCode();
		aiDrawBoard();
		aiTurnCounter++;
		checkAIWin();
	}
		
}

//drawing the AI's board
void Board::aiDrawBoard()
{
	std::cout << "  .----.  .----.  .----.  .----.    |  \n";
	std::cout << "  | " << aiGuess[0] << "  |  |  " << aiGuess[1] << " |  |  " << aiGuess[2] << " |  | " << aiGuess[3] << "  |    | " << " \n ";
	std::cout << " '----'  '----'  '----'  '----'    |   \n";
	
}

//getting the AI to guess each code, the AI knows when it gets one of the characters correct
void Board::aiGuessCode()
{
	int i;
	int j;
	int k;
	int l;
	
	
	

	//randomly guess letters until the guess matches the secret code
	if (aiGuess[0] != secretCode[0])
	{
		i = rand() % 26;
		aiGuess[0] = (char)(i + 65);
	}
	

	if (aiGuess[1] != secretCode[1])
	{
		j = rand() % 26;
		aiGuess[1] = (char)(j + 65);
	}
	

	if (aiGuess[2] != secretCode[2])
	{
		k = rand() % 26;
		aiGuess[2] = (char)(k + 65);
	}
	

	if (aiGuess[3] != secretCode[3])
	{
		l = rand() % 26;
		aiGuess[3] = (char)(l + 65);
	}
	
	
		
}

//allowing the user to input the code for the AI to crack
void Board::inputSecretCode()
{
	std::cout << "Enter the secret code for the AI to crack: ";
	std::cin >> secretCode[0] >> secretCode[1] >> secretCode[2] >> secretCode[3];
}

//checking to see if the AI has cracked the code
void Board::checkAIWin()
{
	if (secretCode[0] == aiGuess[0] && secretCode[1] == aiGuess[1] && secretCode[2] == aiGuess[2] && secretCode[3] == aiGuess[3])
	{
		gameOver = true;
		std::cout << "The AI cracked the code in " << aiTurnCounter << " turns." << std::endl;

	}
}