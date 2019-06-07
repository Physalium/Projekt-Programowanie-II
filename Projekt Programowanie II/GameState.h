#pragma once
#include "Game.h"
class GameState
{


public:
	Game* game;
	virtual void draw(sf::RenderWindow &window);
	virtual void update();
	virtual void handleInput();
	GameState();
	virtual ~GameState();
};

