#pragma once
#include "GameState.h"

#include <SFML/Graphics.hpp>
class Upgrades :
	public GameState
{
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[2];
public:
	virtual void update();
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	virtual void draw();
	virtual void handleInput();
	Upgrades(Game* game);
	~Upgrades();
};

