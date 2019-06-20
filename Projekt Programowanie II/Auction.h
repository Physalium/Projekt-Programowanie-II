#pragma once

#ifndef AUCTION_H
#define AUCTION_H

#include "GameState.h"

#define MAX_NUMBER 1

class Auction :
	public GameState
{

	sf::Font font;
	sf::Text menu[MAX_NUMBER];

public:
	virtual void update();
	void randItems();
	virtual ~Auction();
	Auction(Game* game);
	virtual void draw();
	virtual void handleInput();
};

#endif