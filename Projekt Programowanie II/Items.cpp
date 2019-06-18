#include "Items.h"
#include <fstream>
#include <ctime>

void Items::randItems()
{
	std::vector <int> list_of_randoms;
	std::fstream plik;
	srand(time(nullptr));
	for (int i = 0; i < 6; i++)
	{
		int random = (rand() % 35);
		list_of_randoms[i] = random;
		
		std::string rand_item = {};

		plik.open("items.txt", std::ios::in);
		if (plik.is_open())
		{
			for (int a = 0; a <= random; a++)
			{
				getline(plik, rand_item);
			}
			int a;
			std::string b;
			int c;
			plik >> a >> b >> c;
			
			rand_items.push_back(new Items(a, b, c));
		}
		else
		{
			exit(0);
		}

		plik.close();
	}
}

Items::Items(int xid, std::string xname, int xvalue) : id(xid), name(xname), value(xvalue)
{

}


Items::~Items()
{
}


