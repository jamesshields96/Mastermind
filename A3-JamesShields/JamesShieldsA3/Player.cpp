#include "Player.h"
#include "Board.h"

Player::Player()
{

}
//constructer to set up a player object, requiring a name
Player::Player(std::string aName)
{
	playerName = aName;

}

Player::~Player()
{

}
//getter to retrive the playerName variable
std::string Player::getName()
{
	return playerName;
}
//setter to set the playerName variable
void Player::setName(std::string newName)
{
	playerName = newName;
}



	



