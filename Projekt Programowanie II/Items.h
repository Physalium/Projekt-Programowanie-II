#pragma once
#ifndef ITEMS_H
#define ITEMS_H
#include <string>
#include "Player.h"

class Items
{
public:
	std::vector <Items*> rand_items;
	int id;
	std::string name;
	int value;
	void randItems();
	Items(int xid, std::string xname, int xvalue);
	~Items();
};


#endif