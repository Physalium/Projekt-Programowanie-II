#pragma once
#include <string>
#include "Items.h"
#include <vector>
class Player
{
	std::string PlayerName="default";
	// vector <Upgrade> upgrade 
	int Balance=0;
public:

	std::vector <Items*> rand_items;
	std::string getPlayerName();
	int getBalance();
	void setPlayerName(std::string name);
	void setBalance(int balance);
	Player();
	~Player();
};

