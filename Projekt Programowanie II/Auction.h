#pragma once

#ifndef AUCTION_H
#define AUCTION_H

#include "GameState.h"
#include <array>
#define MAX_NUMBER 1

class Auction :
	public GameState
{

	sf::Font font;
	sf::Text menu[MAX_NUMBER];
	std::array <sf::Texture,6> Textures;
	std::array <sf::Sprite,6> Sprites;
	sf::Texture garageClosed;
	sf::Texture garageOpen;
	sf::Sprite Garage;
	
public:
	
	std::vector<int> list_of_randoms;
	void showItems();
	virtual void update();
	void randItems();
	virtual ~Auction();
	Auction(Game* game);
	virtual void draw();
	virtual void handleInput();
	friend class Game;
};

#endif