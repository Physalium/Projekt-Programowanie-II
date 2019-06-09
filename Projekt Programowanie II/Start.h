#pragma once
#ifndef START_H
#define SMART_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <string>
#define MAX_NUMBER_OF_OPTIONS 2
class Start :
	public GameState
{
	std::string input = "";
	void loadgame();
	std::string PlayerName="Nazwa gracza: ";
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_OPTIONS];
public:
	
	Start(Game* game);
	virtual void draw();
	virtual void handleInput();
};

#endif // !START_H