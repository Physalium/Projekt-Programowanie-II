#pragma once
#include "GameState.h"
#include "Auction.h"
#include <vector>
class Bidding :
	public GameState
{
	friend class Auction;
	float time;
	std::vector <Player> bots;
	int lineCounter = 0;
	std::string input = "";
	sf::Font font;
	std::vector <sf::Text*> Log;
	sf::Text Chat;
public:
	int highestBid = 0;
	Bidding(Game* game);
	~Bidding();
	virtual void draw();
	virtual void handleInput();
	virtual void update();
	void setMaxValue();
	void botBidding(Player &bot);
};

