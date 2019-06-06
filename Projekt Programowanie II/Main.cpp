#include "SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"

int main()
{
	int Option=0;
	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML WORK!");

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "ULEPSZENIA---" << std::endl;
						break;
					case 1:
						std::cout << "SPRZEDAJ PRZEDMIOTY----" << std::endl;
						break;
					case 2:
						std::cout << "LICYTUJ----" << std::endl;;
						Option = 3;
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();
		if(Option==0)
			menu.draw(window);
		if (Option == 3)
			window.clear();
		window.display();
	}
}