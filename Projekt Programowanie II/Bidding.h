#pragma once
#include "GameState.h"
#include "Auction.h"
#include <vector>
class Bidding :
	public GameState
{
	sf::Text clock[2];
	sf::Text Message;
	bool playerResponse = 0;
	int lastId = 0;
	int Counter=0;
	bool FirstRound = true;
	sf::Clock timer;
	sf::Clock error;
	bool errorr = 0;
	sf::Time Delay=sf::seconds(4);
	friend class Auction;
	float time;
	std::vector <Player> bots;
	int lineCounter = 0;
	std::string input = "";
	sf::Font font;
	std::vector <sf::Text*> Log;
	sf::Text Chat;
	bool Response = 0;
	sf::Text Error;
	std::array <sf::Texture, 6> Textures;
	std::array <sf::Sprite, 6> Sprites;
	sf::Texture garageClosed;
	sf::Texture garageOpen;
	sf::Sprite Garage;
public:
	void showItems();
	void loadgame();
	int highestBid = 0;
	void BotResponse();
	Bidding(Game* game);
	~Bidding();
	virtual void draw();
	virtual void handleInput();
	virtual void update();
	void setMaxValue();
	void botBidding(Player &bot);
};

