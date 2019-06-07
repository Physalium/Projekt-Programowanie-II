#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "game.h"

class GameState
{
public:
	Game* game=nullptr;
	virtual void draw() = 0;
	virtual void handleInput() = 0;
};

#endif /* GAME_STATE_HPP */