#pragma once

#include <string>

class Items
{
	
public:
	int id;
	std::string name;
	int value;
	
	Items(int xid, std::string xname, int xvalue);
	~Items();
};


