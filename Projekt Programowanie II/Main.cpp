#include "game.h"
#include "Menu.h"
#include "Start.h"
#include <iostream>
int main()
{
	Game game;
	game.pushState(new Start(&game));
	game.gameLoop();
	

	return 0;
}