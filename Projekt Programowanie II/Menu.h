#pragma once
#ifndef MENU_H		
#define MENU_H
#include "GameState.h"

#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
#define INFO_NUMBER_OF_ITEMS 3

class Menu :
	public GameState
{
	int sum = 0;
	int selectedItemIndex=1;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Text info[INFO_NUMBER_OF_ITEMS];
public:
	virtual void update();
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	virtual void draw();
	virtual void handleInput();
	Menu(Game* game);	
};
#endif
