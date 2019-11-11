#ifndef BOARD_H
#define BOARD_H
#include <string>
class Board
{
private:
	//char playerMove;
	//bool playerTurn;
	
	char guess[4];
	char aiGuess[4];
	int aiTurnCounter = 0;
	bool gameOver = false;
	char secretCode[4];
	char accurateCode[4];
	int score;
	int difficultyMultiplyer;
	int difficulty;
	
	

public:
	Board();
	~Board();

	void checkAIWin();
	void inputSecretCode();
	void aiGuessCode();
	void aiPlay();
	void aiDrawBoard();
	void askForCode();
	void drawBoard();
	void checkForWin();
	void verifyCode();
	void createBoard();
	int getScore();
	void createCode();

	


	

};

#endif

