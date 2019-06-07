#pragma once
#include "GameState.h"
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3
#define INFO_NUMBER_OF_ITEMS 3

class Menu : public GameState
{
public:
	Menu(float width, float height);
	~Menu();
	virtual void handleInput();
	virtual void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	Menu(Game* game);
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Text info[INFO_NUMBER_OF_ITEMS];
	void loadgame();

};
