#include "Player.h"
#include "string.h"


int Player::BotAi(int bid)
{
	if (bid < Balance)
	{
		int diff = Balance - bid;
		return (bid + diff * 0.2);
	}
}

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
