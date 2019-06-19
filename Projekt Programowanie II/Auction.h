#pragma once

#ifndef START_H
#define SMART_H

#include "GameState.h"

#define MAX_NUMBER 1

class Auction :
	public GameState
{

	sf::Font font;
	sf::Text menu[MAX_NUMBER];

public:
	void randItems();
	virtual ~Auction();
	Auction(Game* game);
	virtual void draw();
	virtual void handleInput();
};

#endif