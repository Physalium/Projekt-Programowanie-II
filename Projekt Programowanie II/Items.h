#pragma once
#include <vector>
#include <string>

class Items
{
	std::vector <Items*> rand_items;
public:
	int id;
	std::string name;
	int value;
	void randItems();
	Items(int xid, std::string xname, int xvalue);
	~Items();
};


