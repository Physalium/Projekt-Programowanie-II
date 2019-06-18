#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
class Items;

class Player
{
	
	std::string PlayerName="default";
	// vector <Upgrade> upgrade 
	int Balance=0;
public:
	Items* items;
	std::string getPlayerName();
	int getBalance();
	void setPlayerName(std::string name);
	void setBalance(int balance);
	Player();
	~Player();
	
};

#endif