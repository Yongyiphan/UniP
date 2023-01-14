
#include "pch.h"
#include "Level2.h"
std::string Lvl2 = "Level 2";
int Level2_Counter, Level2_Lives;

void Level2_Load()
{
	Level2_Lives = 0;
	std::ifstream ifs{ "Level2_Lives.txt" };
	ifs >> Level2_Lives;
	ifs.close();
	std::cout << Lvl2 << ":Load" << std::endl;
	//some code here
}

void Level2_Initialize()
{
	Level2_Counter = 0;
	std::ifstream ifs{ "Level2_Counter.txt" };
	ifs >> Level2_Counter;
	ifs.close();
	std::cout << Lvl2 << ":Initialize" << std::endl;
	//some code here
}

void Level2_Update()
{

	Level2_Counter--;
	if (!Level2_Counter) {
		Level2_Lives--;
		if (!Level2_Lives) {
			next = GS_QUIT;
		}
		else {
			next = GS_RESTART;
		}
	}
	std::cout << Lvl2 << ":Update" << std::endl;
	//some code here
}

void Level2_Draw()
{
	std::cout << Lvl2 << ":Draw" << std::endl;
	//some code here
}

void Level2_Free()
{
	std::cout << Lvl2 << ":Free" << std::endl;
	//some code here
}

void Level2_Unload()
{
	std::cout << Lvl2 << ":Unload" << std::endl;
	//some code here
}
