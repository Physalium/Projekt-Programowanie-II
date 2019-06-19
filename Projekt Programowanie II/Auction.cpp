#include "Auction.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameState.h"
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
#include <ctime>

void Auction::randItems()
{
	std::vector <int> list_of_randoms;
	std::fstream plik;
	srand(time(nullptr));
	plik.open("items.txt", std::ios::in);
	for (int i = 0; i < 6; i++)
	{
		int random = (rand() % 35);
		list_of_randoms.push_back(random);

		std::string rand_item = {};

		
		if (plik.is_open())
		{
			cout << "Plik sie otworzyl"<<endl; // w ogole tego nie pokazuje w konsoli 
			for (int a = 0; a <= random; a++)
			{
				getline(plik, rand_item);
			}
			int a;
			std::string b;
			int c;
			plik >> a >> b >> c;

			game->player.rand_items.push_back(new Items(a, b, c));
		}
		else
		{
			//exit(0); tego nie dawaj bo wtedy wyl¹czy caly program 
		}

		plik.close();
	}
}
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
	randItems();
	for (auto i : game->player.rand_items)
	{
		cout << i->name << endl;
	}
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