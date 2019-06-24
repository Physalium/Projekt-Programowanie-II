#include "Upgrades.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Menu.h"
#include "GameState.h"
#include <iostream>

Upgrades::Upgrades(Game* game)
{
	
	this->game = game;
	int height = game->window.getSize().y;
	int width = game->window.getSize().x;

	if (!font.loadFromFile("consola.ttf"))
	{
		std::cout << "Cant find consola.ttf file" << std::endl;
	}
	
	menu[0].setFont(font);
	menu[0].setCharacterSize(40);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("X-RAY");
	menu[0].setPosition(sf::Vector2f(300, 200));

	menu[1].setFont(font);
	menu[1].setCharacterSize(40);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Wyjdz");
	menu[1].setPosition(sf::Vector2f(300, 500));
}


Upgrades::~Upgrades()
{
}

void Upgrades::draw()
{
	
	for (int i = 0; i < 2; i++)
	{
		this->game->window.draw(menu[i]);
	}
	
	return;
}


void Upgrades::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				this->MoveUp();
				break;

			case sf::Keyboard::Down:
				this->MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (this->GetPressedItem())
				{
				case 0:
					menu[0].setString("ZAKUPIONE");
					this->game->player.X = 1;
					break;
				case 1:
					this->game->changeState(new Menu(this->game));
					return;
					break;
				}
			}

			break;
		case sf::Event::Closed:
			this->game->window.close();

			break;

		}
	}

}

void Upgrades::update()
{
}

void Upgrades::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Upgrades::MoveDown()
{
	if (selectedItemIndex + 1 <2)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}