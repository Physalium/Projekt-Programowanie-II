#pragma once
#include <string>
#include "Items.h"
#include <vector>
class Player
{
	
	int currentBidding = 0;
	std::string PlayerName = "default";
	// vector <Upgrade> upgrade 
	int Balance = 10000;
	int BotAi(int bid);
public:
	int BotMaxBit = 0;
	bool X = 0;
	std::vector <Items*> rand_items;
	std::string getPlayerName();
	int getBalance();
	void setPlayerName(std::string name);
	void setBalance(int balance);
	Player();
	~Player();
};

