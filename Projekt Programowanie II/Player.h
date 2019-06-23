#pragma once
#include <string>
#include "Items.h"
#include <vector>
class Player
{
	std::string PlayerName="default";
	// vector <Upgrade> upgrade 
	int Balance = 1000;
	int BotAi(int bid);
public:
	
	std::vector <Items*> rand_items;
	std::string getPlayerName();
	int getBalance();
	void setPlayerName(std::string name);
	void setBalance(int balance);
	Player();
	~Player();
};

