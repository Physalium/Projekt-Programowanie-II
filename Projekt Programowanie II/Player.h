#pragma once
#include <string>
using namespace std;
#define StartMoney 1000
class Player
{
	string name;
	int money;
	//vector <Upgrade> upgrade; 

public:
	Player(string Name);
	~Player();
};

