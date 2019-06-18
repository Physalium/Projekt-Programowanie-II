#include "Auction.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameState.h"
#include <iostream>
#include "Items.h"
#include "Auction.h"
using std::cout;
using std::endl;


Auction::Auction(Game * game)
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
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Start");
	menu[0].setPosition(sf::Vector2f(width / 2 - 444, 10));
	
	game->player.items->randItems();
	cout << game->player.items->rand_items[0]->name << endl;

}


Auction::~Auction()
{
}

void Auction::draw()
{
	for (int i = 0; i < MAX_NUMBER; i++)
	{
		this->game->window.draw(menu[i]);
	}

	return;
}

void Auction::handleInput()
{

}