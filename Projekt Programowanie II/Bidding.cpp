#include "Bidding.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameState.h"
#include <iostream>
#include <string>
#include <random>
#include "Menu.h"
thread_local std::mt19937 gen{ std::random_device{}() };

template<typename T>
T random(T min, T max) {
	using dist = std::conditional_t<
		std::is_integral<T>::value,
		std::uniform_int_distribution<T>,
		std::uniform_real_distribution<T>
	>;
	return dist{ min, max }(gen);
}

using std::cout;
using std::endl;
enum Key { Enter = 13 };
void Bidding::showItems()
{


	Message.setFont(font);
	Message.setCharacterSize(50);
	Message.setFillColor(sf::Color::Red);
	Message.setString("Oto wygrane przedmioty: ");
	Message.setPosition(sf::Vector2f(100, 400));
	int height = game->window.getSize().y;
	int width = game->window.getSize().x;

	
	for (int i = 0; i < 6; i++)
	{

		std::string number_of_pic = "Images/" + std::to_string(game->items_in_garage[i]->id) + ".png";
		if (!Textures[i].loadFromFile(number_of_pic))
		{
			cout << "Nie mozna znalezc pliku z tekstura" << endl;
			return;
		}

		Sprites[i].setTexture(Textures[i]);
		Sprites[i].setPosition(sf::Vector2f(width / 2.5 + 60 * i, height / 2));
		this->game->window.draw(Sprites[i]);

	}
	this->game->window.draw(Message);
	this->game->window.display();


	sf::Clock clock;
	sf::Time time = clock.getElapsedTime();
	sf::Time timer = sf::seconds(5);
	bool b = (time < timer);
	while (b)
	{
		sf::Time time = clock.getElapsedTime();
		b = (time < timer);
		//cout << time.asSeconds() << endl;
		//cout << timer.asSeconds() << endl;
	}
	//game->items_in_garage.clear();
}

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
	if (!garageClosed.loadFromFile("Images/garage_closed.png"))
		cout << "Nie ma garage_closed.png";
	if (!garageOpen.loadFromFile("Images/garage_open.png"))
		cout << "Nie ma garage_open.png";
	Garage.setTexture(garageClosed);
	Garage.setPosition(sf::Vector2f(200, 200));

	Chat.setFont(font);
	Chat.setCharacterSize(40);
	Chat.setFillColor(sf::Color::White);
	Chat.setString("Napisz wiadomosc: ");
	Chat.setPosition(sf::Vector2f(10, height - 50));

	setMaxValue(); // cena max jest ustawiana dla bota tej
	Error.setFont(font);
	Error.setCharacterSize(30);
	Error.setFillColor(sf::Color::Red);
	Error.setString(" ");
	Error.setPosition(sf::Vector2f(width / 2-300 , 600));

	Log.push_back(new sf::Text);
	Log[0]->setFont(font);
	Log[0]->setCharacterSize(60);
	Log[0]->setFillColor(sf::Color::White);
	Log[0]->setOutlineThickness(3);

	Log[0]->setOutlineColor(sf::Color::Red);
	Log[0]->setString("Start licytacji!");
	Log[0]->setPosition(sf::Vector2f(width / 2 - 200, 10));
	Log.push_back(new sf::Text); //przygotowanie kolejnej linijki do pisania
	Log.back()->setFont(font);
	Log.back()->setCharacterSize(30);
	Log.back()->setFillColor(sf::Color::White);
	Log.back()->setPosition(sf::Vector2f(10, 80));
	//sf::Clock clock;
	//sf::Time elapsed = clock.restart();
	//float time = elapsed.asSeconds();
	cout << "wchodza tylko cyferki" << endl;
	clock[0].setFont(font);
	clock[0].setFillColor(sf::Color::White);
	clock[0].setCharacterSize(30);
	clock[0].setPosition(sf::Vector2f(300, 100));
	clock[1].setFont(font);
	clock[1].setFillColor(sf::Color::White);
	clock[1].setCharacterSize(30);
	clock[1].setPosition(sf::Vector2f(300, 140));

}


Bidding::~Bidding()
{
}


void Bidding::draw()
{
	for (auto i : Log)
	{
		this->game->window.draw(*i);
	}

	this->game->window.draw(Chat);
	this->game->window.draw(Error);
	this->game->window.draw(clock[0]);
	this->game->window.draw(clock[1]);
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
			if (event.text.unicode < 58 && event.text.unicode > 47 || event.text.unicode == 8)
			{

				if (event.text.unicode == 8)
				{
					if (input.size() != 0)
					{
						input.pop_back();
						break;
					}
				}

				input += static_cast<char>(event.text.unicode);



				std::string chat = "Napisz wiadomosc: ";
				chat += input;
				Chat.setString(chat);
			}
			

			if (event.text.unicode == Key::Enter)
			{
				if (input == "")
					break;

				if (std::stoi(input) == 0)
				{
					loadgame();
				}
				if (std::stoi(input) <= highestBid)
				{
					Error.setString("Cena nie moze byc nizsza niz obecna stawka");
					error.restart();
					errorr = 1;
					Chat.setString("Napisz wiadomosc: ");
					input = "";
					break;
				}
				if (std::stoi(input) > game->player.getBalance())
				{
					Error.setString("Nie masz tyle pieniedzy");
					error.restart();
					errorr = 1;
					Chat.setString("Napisz wiadomosc: ");
					input = "";
					break;
				}
				
				highestBid = std::stoi(input);
				std::string name = game->player.getPlayerName();
				name += ": ";
				name += input;
				name += "$";
				Log.back()->setString(name);
				input = "";
				name = "";

				Chat.setString("Napisz wiadomosc: ");
				cout << "Line counter: " << lineCounter << endl;
				Log.push_back(new sf::Text);
				Log.back()->setFont(font);
				Log.back()->setCharacterSize(30);
				Log.back()->setFillColor(sf::Color::White);
				Log.back()->setPosition(sf::Vector2f(10, (120 + lineCounter * 40)));
				lineCounter++;
				Delay = sf::seconds(random(1.5, 4.8));
				cout << timer.getElapsedTime().asSeconds() << endl;
				playerResponse = 1;
				timer.restart();
			}

		default:
			break;

		}
	}
}


void Bidding::update()
{
	if (errorr == 1)
	{
		if (error.getElapsedTime().asSeconds() >= 2)
		{
			Error.setString("");
		}
	}//kocham programowanie 2
	//botAI
	BotResponse();
	std::string add;
	std::string clock1 = "Pozostaly czas na";
	std::string clock2 = "przebicie: ";
	add=std::to_string(6 - timer.getElapsedTime().asSeconds());
	add.erase(2, std::string::npos);
	clock2 += add;
	clock[0].setString(clock1);
	clock[1].setString(clock2);
	//cout << timer.getElapsedTime().asSeconds()<<endl;

	if (Log.back()->getPosition().y > 850)
	{
		
		std::string temp;
		
		temp= Log.at(Log.size() - 2)->getString();
		Log.clear();
		lineCounter = 0;
		cout << "Ostatni string::" << temp << endl;
		Log.push_back(new sf::Text);
		Log.back()->setString(temp);
		Log.back()->setFont(font);
		Log.back()->setCharacterSize(30);
		Log.back()->setFillColor(sf::Color::White);
		Log.back()->setPosition(sf::Vector2f(10, (120 + lineCounter * 40)));
		game->window.clear();
		game->window.draw(*Log.back());
		game->window.display();
		lineCounter++;
		Log.push_back(new sf::Text);
		Log.back()->setFont(font);
		Log.back()->setCharacterSize(30);
		Log.back()->setFillColor(sf::Color::White);
		Log.back()->setPosition(sf::Vector2f(10, (120 + lineCounter * 40)));
		lineCounter++;
	}
	
}

void Bidding::setMaxValue()
{
	//liczenie wartosci garazu
	// ------------------------

	int garage_value = 0;;
	for (auto i : game->items_in_garage)
	{
		garage_value += i->value;
	}
	//cout << "Cena garazu: " << garage_value;

	// ----------------------
	double maxValue1 = {};
	double maxValue2 = {};
	double maxValue3 = {};

	double rand1; 
	double rand2; 
	double rand3;
	int rand_range = ((rand() % 20));

	if (rand_range < 16)
	{
		rand1 = ((rand() % 40) + 60) * 0.01;
		rand2 = ((rand() % 40) + 60) * 0.01;
		rand3 = ((rand() % 40) + 60) * 0.01;
	}
	else 
	{
		rand1 = ((rand() % 30) + 100) * 0.01;
		rand2 = ((rand() % 30) + 100) * 0.01;
		rand3 = ((rand() % 30) + 100) * 0.01;
	}

	
	maxValue1 = garage_value * rand1;
	maxValue2 = garage_value * rand2;
	maxValue3 = garage_value * rand3;

	
	game->bot1.BotMaxBit = maxValue1;
	game->bot2.BotMaxBit = maxValue2;
	game->bot3.BotMaxBit = maxValue3;

}
void Bidding::loadgame()
{
	
	this->game->pushState(new Menu(this->game));
	return;
}
void Bidding::BotResponse()
{
	int temp = 0;
	if (temp > 3)
		return;
	
	if (timer.getElapsedTime().asSeconds() >= Delay.asSeconds())
	{
		
		int id = random(1, 3);
		
		while (!Response)
		{
			temp++;
			if (temp > 3)
				return;
			if (lastId == id && Counter>0)
			{
				switch (id)
				{
				case 1:
					id = 2;
					break;
				case 2:
					id = 3;
					break;
				case 3:
					id = 1;
					break;
				default:
					break;
				}
				cout << "Tosamo" << endl;
				
			}

			lastId = id;

			
			switch (id)
			{
			case 1:
				botBidding(game->bot1);
				break;
			case 2:
				botBidding(game->bot2);
				break;
			case 3:
				botBidding(game->bot3);
				break;
			default:
				break;
			}
			if (timer.getElapsedTime().asSeconds() >= 6)
			{

				if (highestBid <= game->player.getBalance() && playerResponse == 1)
				{
					Error.setString("Wygrana!");
					Error.setCharacterSize(100);
					sf::Clock temp;
					this->game->window.draw(Error);
					this->game->window.display();
					while (temp.getElapsedTime().asSeconds() < 1)
					{
					
					}
					game->player.rand_items = game->items_in_garage;
					game->player.setBalance(game->player.getBalance() - highestBid);
					showItems();
					loadgame();
					return;
				}
				else
				{
					Error.setString("Przegrales");
					Error.setCharacterSize(100);
					sf::Clock temp;
					this->game->window.draw(Error);
					this->game->window.display();
					while (temp.getElapsedTime().asSeconds() < 1)
					{

					}
					
					loadgame();
				}
				
			}
			
			
			
		}
		
		Counter++;
		Response = 0;
		Delay = sf::seconds(random(1.0, 4.8));
		timer.restart();
		
		
		
	}
	
}

void Bidding::botBidding(Player &bot)
{
	if (highestBid < bot.BotMaxBit)
	{
		int bid_prob = random(0, 20);
		if (bid_prob < 17)	highestBid += random(20, 100);
		else highestBid += random(101, 400);

		std::string name = bot.getPlayerName();
		name += ": ";
		name += std::to_string(highestBid);
		name += "$";

		Log.back()->setString(name);
		Log.push_back(new sf::Text); //przygotowanie kolejnej linijki do pisania
		Log.back()->setFont(font);
		Log.back()->setCharacterSize(30);
		Log.back()->setFillColor(sf::Color::White);
		Log.back()->setPosition(sf::Vector2f(10, (120 + lineCounter * 40)));
		lineCounter++;
		Response = 1;
		playerResponse = 0;
	}
	
}

