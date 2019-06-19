#pragma once
#include <string>
class Player
{
	std::string PlayerName="default";
	// vector <Upgrade> upgrade 
	int Balance=0;
public:
	std::string getPlayerName();
	int getBalance();
	void setPlayerName(std::string name);
	void setBalance(int balance);
	Player();
	~Player();
};

