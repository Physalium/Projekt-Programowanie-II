#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "Player.h"
class GameState;

class Game
{
public:

	std::stack<GameState*> states;

	sf::RenderWindow window;
	Player player;
	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
};

#endif /* GAME_HPP */