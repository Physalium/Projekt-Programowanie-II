#include "Auction.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameState.h"
#include <iostream>
#include "Bidding.h"
using std::cout;
using std::endl;
#include <fstream>
#include <ctime>
enum Key {Enter=13};
void Auction::update()
{
}
void Auction::randItems()
{
	std::vector <int> list_of_randoms;
	std::fstream plik;
	srand(time(0));
	
	for (int i = 0; i < 6; i++)
	{
		int random = (rand() % 35);
		list_of_randoms.push_back(random);

		std::string rand_item = {};

		plik.open("items.txt", std::ios::in);
		if (plik.is_open())
		{
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
			cout << "Nie mozna otworzyc pliku .txt" << endl;
			break;
		}

		plik.close();
	}
	/**/
	for (auto i : game->player.rand_items)
	{
		cout << i->name << "," << i->value << endl;
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
	sf::Event event;
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		
		case sf::Event::Closed:
			this->game->window.close();
			break;
		case sf::Event::TextEntered:
			if(event.text.unicode == Key::Enter )
			{
				this->game->pushState(new Bidding(this->game));
				//randItems();
			}
				
		default:
			break;

		}
	}
}