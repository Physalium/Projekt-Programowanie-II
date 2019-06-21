#include "game.h"
#include "Menu.h"
#include "Start.h"
#include <iostream>
int main()
{
	std::cout << "wakacyjnie pierdolenie twojej starej na basenie";
	Game game;
	game.pushState(new Start(&game));
	game.gameLoop();
	

	return 0;
}