#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Auction.h"
#include <vector>
#include <iostream>
#include "game.h"
#include "gamestate.h"
using std::cout;
using std::endl;

void Game::pushState(GameState* state)
{
	this->states.push(state);

	return;
}

void Game::popState()
{
	delete this->states.top();
	this->states.pop();

	return;
}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
		popState();
	pushState(state);

	return;
}

GameState* Game::peekState()
{
	if (this->states.empty()) return nullptr;
	return this->states.top();
}



void Game::gameLoop()
{
	while (this->window.isOpen())
	{

		

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update();
		this->window.clear(sf::Color::Black);
		peekState()->draw();
		this->window.display();
	}
}

Game::Game()
{

	this->window.create(sf::VideoMode(900, 900), "Symulator Aukcji Garazowych");
	this->window.setFramerateLimit(60);

	bot1.setPlayerName("Adam");
	
	bot2.setPlayerName("Marcin");
	
	bot3.setPlayerName("Roman");
	
}

Game::~Game()
{
	while (!this->states.empty()) popState();
}