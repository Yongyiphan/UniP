#include "pch.h"

#include "Level1.h"
std::string Lvl1 = "Level 1";
int Level1_Counter;

void Level1_Load()
{

	Level1_Counter = 0;
	std::ifstream ifs1{"Level1_Counter.txt"};
	ifs1 >> Level1_Counter;
	ifs1.close();
	std::cout << "Level1:Load" << std::endl;
	
	//some code here
}

void Level1_Initialize()
{
	std::cout << Lvl1 << ":Initialize" << std::endl;
	//some code here
}

void Level1_Update()
{
	std::cout << Lvl1 << ":Update" << std::endl;
	//some code here
	if (!Level1_Counter)
		next = GS_LEVEL2;
	Level1_Counter--;
}

void Level1_Draw()
{
	std::cout << Lvl1 << ":Draw" << std::endl;
	//some code here
}

void Level1_Free()
{
	std::cout << Lvl1 << ":Free" << std::endl;
	//some code here
}

void Level1_Unload()
{	
	std::cout << Lvl1 << ":Unload" << std::endl;
	//some code here
}