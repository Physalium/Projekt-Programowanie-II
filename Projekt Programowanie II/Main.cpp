#include "game.h"
#include "Menu.h"
#include "Start.h"
#include <Windows.h>

void HideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}
#include <iostream>
int main()
{
	HideConsole();
	Game game;
	game.pushState(new Start(&game));
	game.gameLoop();

	return 0;
}