#include "Menu.h"
#include "GameState.h"
#include <iostream>

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("consola.ttf"))
	{
		std::cout << "Cant find consola.ttf file" << std::endl;
	}
	info[0].setFont(font);
	info[0].setCharacterSize(30);
	info[0].setFillColor(sf::Color::White);
	info[0].setString("nazwa gracza: tomek");
	info[0].setPosition(sf::Vector2f(0, height / (INFO_NUMBER_OF_ITEMS + 1) * 1 -100));

	info[1].setFont(font);
	info[1].setCharacterSize(30);
	info[1].setFillColor(sf::Color::White);
	info[1].setString("Ulepszenia: ");
	info[1].setPosition(sf::Vector2f(0, height / (INFO_NUMBER_OF_ITEMS + 1) * 2 - 100));

	info[2].setFont(font);
	info[2].setCharacterSize(30);
	info[2].setFillColor(sf::Color::White);
	info[2].setString("Stan Konta: ");
	info[2].setPosition(sf::Vector2f(0, height / (INFO_NUMBER_OF_ITEMS + 1) * 3 - 100));

	menu[0].setFont(font);
	menu[0].setCharacterSize(30);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("ULEPSZENIA");
	menu[0].setPosition(sf::Vector2f(width / 2+100, height / (MAX_NUMBER_OF_ITEMS+1) * 1));

	menu[1].setFont(font);
	menu[1].setCharacterSize(30);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("SPRZEDAJ PRZEDMIOTY");
	menu[1].setPosition(sf::Vector2f(width / 2 + 100, height / (MAX_NUMBER_OF_ITEMS+1 ) * 2));

	menu[2].setFont(font);
	menu[2].setCharacterSize(30);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("LICYTUJ");
	menu[2].setPosition(sf::Vector2f(width / 2 + 100, height / (MAX_NUMBER_OF_ITEMS+1) * 3));

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::handleInput()
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
					std::cout << "ULEPSZENIA---" << std::endl;
					break;
				case 1:
					std::cout << "SPRZEDAJ PRZEDMIOTY----" << std::endl;
					break;
				case 2:
					std::cout << "LICYTUJ----" << std::endl;;

					break;
				}

				break;
			}

			break;
		case sf::Event::Closed:
			this->game->window.close();

			break;

		}
	}

}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}

	for (int i = 0; i < INFO_NUMBER_OF_ITEMS; i++)
	{
		window.draw(info[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}