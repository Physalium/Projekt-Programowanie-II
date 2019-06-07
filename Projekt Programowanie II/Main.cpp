#include "game.h"
#include "Menu.h"
#include <iostream>
int main()
{
	Game game;
	Menu* menu = new Menu(&game);
	
	game.pushState(menu);
	
	game.gameLoop();
	

	return 0;
}