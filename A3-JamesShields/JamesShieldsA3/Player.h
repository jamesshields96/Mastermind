#ifndef PLAYER_H
#define PLAYER_H
#include <string>
class Player
{

private:

	std::string playerName;
	
	


public:
	Player();
	Player(std::string aName);
	~Player();

	std::string getName();
	

	void setName(std::string newName);

	
	
	
	


};

#endif

