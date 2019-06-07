#include "Game.h"
#include "GameState.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "City Builder");
	this->window.setFramerateLimit(60);
}

void Game::gameLoop()
{
	while (this->window.isOpen())
	{
		
		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		this->window.clear(sf::Color::Black);
		peekState()->draw(this->window);
		this->window.display();
	}
}

Game::~Game()
{
}

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