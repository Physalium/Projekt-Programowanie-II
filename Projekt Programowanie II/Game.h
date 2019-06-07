#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <stack>
class Gamestate;

class Game
{
public:
	std::stack<GameState *> states;
	sf::RenderWindow window;
	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	void gameLoop();
	GameState* peekState();
	Game();
	virtual ~Game();
};

