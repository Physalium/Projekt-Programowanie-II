#include "Start.h"
#include <iostream>
using std::cout;
using std::endl;
#include "Menu.h"
#include "Player.h"
//#include "Game.h"
Start::Start(Game* game)
{
	this->game = game;

	int height = game->window.getSize().y;
	int width = game->window.getSize().x;

	if (!font.loadFromFile("consola.ttf"))
	{
		std::cout << "Cant find consola.ttf file" << std::endl;
	}

	menu[0].setFont(font);
	menu[0].setCharacterSize(60);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("Aukcje garazowe");
	menu[0].setPosition(sf::Vector2f(width/2 - 100, 10));

	menu[1].setFont(font);
	menu[1].setCharacterSize(30);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString(PlayerName);
	menu[1].setPosition(sf::Vector2f(50, height / (MAX_NUMBER_OF_OPTIONS + 1) * 1 - 100));
}



void Start::draw()
{
	for (int i = 0; i < MAX_NUMBER_OF_OPTIONS; i++)
	{
		this->game->window.draw(menu[i]);
	}

	return;
}


void Start::handleInput()
{
	sf::Event event;
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::TextEntered:
		{
			if (event.text.unicode < 128 && event.text.unicode > 47 || event.text.unicode == 13
				|| event.text.unicode == 32)
			{
				
				if (event.text.unicode == 13) // Enter ASCII = 13, zatwierdzenie nazwy
				{
					game->player.setPlayerName(input);
					loadgame();
					break;
				}
				
				input +=static_cast<char>(event.text.unicode);
				
				PlayerName += static_cast<char>(event.text.unicode);
				menu[1].setString(PlayerName);
			}

		break;
		}
		
		case sf::Event::Closed:
			this->game->window.close();
			break;

		default:
			break;

		}
	}

}

void Start::loadgame()
{
    this->game->pushState(new Menu(this->game));
    return;
}