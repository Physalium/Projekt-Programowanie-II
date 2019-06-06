#pragma once
#include "SFML/Graphics.hpp"
#define NUMBER_OF_OPTIONS
class Start
{
	sf::Text menu[NUMBER_OF_OPTIONS];

public:
	void draw(sf::RenderWindow &window);
	Start();
	~Start();
};

