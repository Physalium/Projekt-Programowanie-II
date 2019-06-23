#include "Auction.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameState.h"
#include <iostream>
#include "Bidding.h"
using std::cout;
using std::endl;
<<<<<<< HEAD
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream> 
#include <iterator> 
#include <iostream> 
enum Key { Enter = 13 };
int EnterPressed = 0;
=======
#include <fstream>
#include <ctime>
#include <sstream> 
#include <iterator> 
#include <iostream> 
enum Key { Enter = 13 };
>>>>>>> parent of e7cd5a3... 231231
void Auction::showItems()
{

	int height = game->window.getSize().y;
	int width = game->window.getSize().x;
<<<<<<< HEAD

	

	for (int i = 0; i < 6; i++)
	{

	std::string number_of_pic = "Images/" + std::to_string(list_of_randoms[i]) + ".png";
=======
	for (int i = 0; i < 6; i++)
	{

		std::string number_of_pic = "Images/" + std::to_string(list_of_randoms[i]) + ".png";
>>>>>>> parent of e7cd5a3... 231231
		if (!Textures[i].loadFromFile(number_of_pic))
		{
			cout << "Nie mozna znalezc pliku z tekstura" << endl;
			return;
		}

		Sprites[i].setTexture(Textures[i]);
<<<<<<< HEAD
		Sprites[i].setPosition(sf::Vector2f(width / 2.5 + 60*i, height / 2));
		this->game->window.draw(Sprites[i]);
	}
	
=======
		Sprites[i].setPosition(sf::Vector2f(width / 2.5 + 60 * i, height / 2));
		this->game->window.draw(Sprites[i]);
	}
>>>>>>> parent of e7cd5a3... 231231
	this->game->window.display();


	sf::Clock clock;
	sf::Time time = clock.getElapsedTime();
	sf::Time timer = sf::seconds(10);
	bool b = (time < timer);
	while (b)
	{
		sf::Time time = clock.getElapsedTime();
		b = (time < timer);
		//cout << time.asSeconds() << endl;
		//cout << timer.asSeconds() << endl;
	}

}
void Auction::update()
{
}
void Auction::randItems()
{
	std::fstream plik;
	srand(time(0));
<<<<<<< HEAD
	int non_dupes=0;
	while(non_dupes<6)
	{
		int random = (rand() % 35 );
		int random1 = random + 1;
		if (std::find(list_of_randoms.begin(), list_of_randoms.end(), random1) != list_of_randoms.end())
		{
			continue;
		}
		non_dupes++;
		list_of_randoms.push_back(random1);
		
=======

	for (int i = 0; i < 6; i++)
	{
		int random = (rand() % 35);
		int random1 = random + 1;
		list_of_randoms.push_back(random1);

>>>>>>> parent of e7cd5a3... 231231
		std::string rand_item = {};

		plik.open("items.txt", std::ios::in);
		if (plik.is_open())
		{
			for (int a = 0; a < random; a++)
			{
				getline(plik, rand_item);
			}
			int a;
			std::string b;
			int c;
			plik >> a >> b >> c;

<<<<<<< HEAD
			items_in_garage.push_back(new Items(a, b, c));
		}
		else
		{
			cout << "Nie mozna otworzyc pliku .txt" << endl;
=======
			game->player.rand_items.push_back(new Items(a, b, c));
		}
		else
		{
			cout << "Nie mozna otworzyc pliku i chuj .txt" << endl;
>>>>>>> parent of e7cd5a3... 231231
			break;
		}
		rand_item = {};
		plik.close();
	}
<<<<<<< HEAD
	for (auto i : items_in_garage)
	{
		cout << i->id << ", "<< i->name << "," << i->value << endl;
=======
	for (auto i : game->player.rand_items)
	{
		cout << i->id << ", " << i->name << "," << i->value << endl;
>>>>>>> parent of e7cd5a3... 231231
	}
}
Auction::Auction(Game * game)
{

	this->game = game;

	int height = game->window.getSize().y;
	int width = game->window.getSize().x;

<<<<<<< HEAD
	
	if (!font.loadFromFile("consola.ttf"))
	{
		std::cout << "Cant find consola.ttfs file" << std::endl;
=======
	if (!font.loadFromFile("consola.ttf"))
	{
		std::cout << "Cant find consola.ttf file" << std::endl;
>>>>>>> parent of e7cd5a3... 231231
	}

	menu[0].setFont(font);
	menu[0].setCharacterSize(60);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Start");
	menu[0].setPosition(sf::Vector2f(width / 2 - 444, 10));

<<<<<<< HEAD
	if (!garageClosed.loadFromFile("Images/garage_closed.png"))
		cout << "Nie ma garage_closed.png";
	if (!garageOpen.loadFromFile("Images/garage_open.png"))
		cout << "Nie ma garage_open.png";
	Garage.setTexture(garageClosed);
	Garage.setPosition(sf::Vector2f(200,200));
=======

>>>>>>> parent of e7cd5a3... 231231
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
<<<<<<< HEAD
	
	this->game->window.draw(Garage);
=======

>>>>>>> parent of e7cd5a3... 231231
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
			if (event.text.unicode == Key::Enter)
			{
<<<<<<< HEAD
				if (EnterPressed==0)
				{
					
					cout << "Pokazywanie itemow prototyp xD " << endl;
					Garage.setTexture(garageOpen);
					menu->setString("");
					game->window.draw(menu[0]);
					game->window.draw(Garage);
					randItems();
					
					//showItems();
					
				}
				if (EnterPressed == 1)
				{
					this->game->pushState(new Bidding(this->game));
				}
				EnterPressed++;
=======
				cout << "Pokazywanie itemow prototyp xD " << endl;
				randItems();
				showItems();
				
				this->game->pushState(new Bidding(this->game));
>>>>>>> parent of e7cd5a3... 231231
			}

		default:
			break;

		}
	}
<<<<<<< HEAD
}
=======
}

>>>>>>> parent of e7cd5a3... 231231
