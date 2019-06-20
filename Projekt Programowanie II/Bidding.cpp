#include "Bidding.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameState.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
enum Key { Enter = 13 };

Bidding::Bidding(Game * game)
{
	
	bots.push_back(game->bot1);
	bots.push_back(game->bot2);
	bots.push_back(game->bot3);

	this->game = game;

	int height = game->window.getSize().y;
	int width = game->window.getSize().x;

	if (!font.loadFromFile("consola.ttf"))
	{
		std::cout << "Cant find consola.ttf file" << std::endl;
	}

	
	Chat.setFont(font);
	Chat.setCharacterSize(40);
	Chat.setFillColor(sf::Color::White);
	Chat.setString("Napisz wiadomosc: ");
	Chat.setPosition(sf::Vector2f(10, height - 50));

	Log.push_back(new sf::Text);
	Log[0]->setFont(font);
	Log[0]->setCharacterSize(60);
	Log[0]->setFillColor(sf::Color::White);
	Log[0]->setString("Start licytacji!");
	Log[0]->setPosition(sf::Vector2f(width / 2 - 200, 10));
	Log.push_back(new sf::Text); //przygotowanie kolejnej linijki do pisania
	Log.back()->setFont(font);
	Log.back()->setCharacterSize(30);
	Log.back()->setFillColor(sf::Color::White);
	Log.back()->setPosition(sf::Vector2f(10, 80));
	sf::Clock clock;
	sf::Time elapsed = clock.restart();
	float time = elapsed.asSeconds();
}


Bidding::~Bidding()
{
}


void Bidding::draw()
{
	for (auto i:Log)
	{
		this->game->window.draw(*i);
	}

	this->game->window.draw(Chat);

	return;
}

void Bidding::handleInput()
{

	int height = game->window.getSize().y;
	int width = game->window.getSize().x;

	sf::Event event;
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{

		case sf::Event::Closed:
			this->game->window.close();
			break;
		case sf::Event::TextEntered:
			if (event.text.unicode < 58 && event.text.unicode > 47)
			{
				
				input += static_cast<char>(event.text.unicode);
				cout << input << endl;
				
				
			
				std::string chat = "Napisz wiadomosc: ";
				chat += input;
				Chat.setString(chat);
			}
			if (event.text.unicode == Key::Enter)
			{
				if (input == "")
					break;
				std::string name = game->player.getPlayerName();
				name += ": ";
				name += input;
				Log.back()->setString(name);
				input = "";
				name = "";
				Chat.setString("Napisz wiadomosc: ");
				cout << "Line counter: " << lineCounter << endl;
				Log.push_back(new sf::Text);
				Log.back()->setFont(font);
				Log.back()->setCharacterSize(30);
				Log.back()->setFillColor(sf::Color::White);
				Log.back()->setPosition(sf::Vector2f(10, (120+lineCounter*40) ) );
				lineCounter++;
			}

		default:
			break;

		}
	}
}

void Bidding::update()
{
	

}
