#pragma once
#include "GameState.h"
#include <vector>
class Bidding :
	public GameState
{
	float time;
	std::vector <Player> bots;
	int lineCounter = 0;
	std::string input = "";
	sf::Font font;
	std::vector <sf::Text*> Log;
	sf::Text Chat;
public:
	Bidding(Game* game);
	~Bidding();
	virtual void draw();
	virtual void handleInput();
	virtual void update();
};

