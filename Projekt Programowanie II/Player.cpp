#include "Player.h"



std::string Player::getPlayerName()
{
	return PlayerName;
}

int Player::getBalance()
{
	return Balance;
}

void Player::setPlayerName(std::string name)
{
	PlayerName = name;
}

void Player::setBalance(int balance)
{
	Balance = balance;
}

Player::Player()
{
}


Player::~Player()
{
}
