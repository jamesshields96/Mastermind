#include "Board.h"
#include "Player.h"

#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <array>
/*James Shields 30755964
FIT1048 Assignment 3, Mastermind
*/
void runMenu(int& choice);
void aboutGame();
void howToPlay();
int playGame();
void highscores();
void computerPlayer();

int main()
{

	int choice = 0;
	aboutGame();
	runMenu(choice);
	system("pause");
	return 0;
}
//code to run the menu of the game
void runMenu(int& choice)
{
	
	do {
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		std::cout << "Mastermind: Bank Robbery!" << std::endl;
		std::cout << "                         " << std::endl;
		std::cout << "1. Start the Break in             " << std::endl;
		std::cout << "2. About the Heist           " << std::endl;
		std::cout << "3. How to use the Code breaker           " << std::endl;
		std::cout << "4. Recent Scores           " << std::endl;
		std::cout << "5. Auto Code Breaker        " << std::endl;
		std::cout << "0. Exit game             " << std::endl;
		std::cout << "Please, select an option ";
		std::cin >> choice;
		//switch case to control the menu
		switch (choice)
		{
		case 1:
			playGame();
			break;
		case 2:
			aboutGame();
			break;
		case 3:
			howToPlay();
			break;
		case 4:
			highscores();
			break;
		case 5:
			computerPlayer();
			break;
		
		case 0:
			std::cout << "Thank you for playing the game!" << std::endl;
			break;
		default:
			std::cout << "                       " << std::endl;
			std::cout << "Invalid Input, 1-4 or 0 to close game" << std::endl;
			std::cout << "                       " << std::endl;
			break;
		}
	} while (choice != 0);
	

}
//main code to play the game
int playGame()
{
	
	
	
	//creating a new player object and storing the name into variable pName
	std::string pName;
	Player * newPlayer = new Player(pName);
	std::cout << "Enter a player name: ";
	std::cin >> pName;

	//seting the newPlayer objects name to what was stored into pName
	newPlayer->setName(pName);
	std::cout << "Player: " << newPlayer->getName() << std::endl; //Printing out newPlayers name
	
	//creating a new board object
	Board * newBoard = new Board();
	//code to first create the code for the newBoard object, then to create the board for the obejct
	newBoard->createCode();
	newBoard->createBoard();
	 
	//saving the name and score of the player into a file
	std::string line;
	std::ofstream inFile;
	inFile.open("highscore.txt", std::ios::out | std::ios::app);
	inFile << newPlayer->getName() << ": " << newBoard->getScore() << "\n";
	inFile.close();

	return 0;
	

}

//function to print the recent names and scores from a file
void highscores()
{
	char clearFile;
	std::string line;
	std::ifstream outFile;
	outFile.open("highscore.txt");

	while (std::getline(outFile, line))
	{
		std::cout << line << std::endl;
	}
	outFile.close();
	// option to clear the file
	std::cout << "Would you like to clear the score list?(y/n) ";
	std::cin >> clearFile;
	if (clearFile == 'y')
	{
		outFile.open("highscore.txt", std::ofstream::out | std::ofstream::trunc);
		outFile.close();

	}
	
	
}

//function to display the information about the game
void aboutGame()
{
	std::string line;
	std::ifstream outFile;
	outFile.open("aboutGame.txt"); //which file to open

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << R"(  _______ _             _____                _     ____              _      _    _      _     _   
 |__   __| |           / ____|              | |   |  _ \            | |    | |  | |    (_)   | |  
    | |  | |__   ___  | |  __ _ __ ___  __ _| |_  | |_) | __ _ _ __ | | __ | |__| | ___ _ ___| |_ 
    | |  | '_ \ / _ \ | | |_ | '__/ _ \/ _` | __| |  _ < / _` | '_ \| |/ / |  __  |/ _ \ / __| __|
    | |  | | | |  __/ | |__| | | |  __/ (_| | |_  | |_) | (_| | | | |   <  | |  | |  __/ \__ \ |_ 
    |_|  |_| |_|\___|  \_____|_|  \___|\__,_|\__| |____/ \__,_|_| |_|_|\_\ |_|  |_|\___|_|___/\__|)" << '\n';
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	while (std::getline(outFile, line)) //outputting every line in the file
	{
		
		std::cout << line << std::endl;
		
	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	outFile.close();

	system("pause");
}
//function to display instructions on how to play the game
void howToPlay()
{
	std::string line;
	std::ifstream outFile;
	outFile.open("howToPlay.txt"); //which file to open

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	while (std::getline(outFile, line)) //outputting every line in the file
	{

		std::cout << line << std::endl;

	}
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	outFile.close();

	system("pause");
}

//setting up a player object for the AI computer and running its functions
void computerPlayer()
{
	std::string aiName = "Gavin";
	Player * aiPlayer = new Player(aiName);
	Board * newBoard = new Board();

	newBoard->inputSecretCode();
	std::cout << "The computer's name: " << aiPlayer->getName() << std::endl;
	newBoard->aiPlay();
	
}