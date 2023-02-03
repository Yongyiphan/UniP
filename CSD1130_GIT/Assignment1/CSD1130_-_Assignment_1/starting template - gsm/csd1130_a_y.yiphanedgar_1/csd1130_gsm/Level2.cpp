/* Start Header ************************************************************************/ 
/*! 
\file   Level2.cpp 
\author Yong Yip Han Edgar, y.yiphanedgar, 2202206 
\par    y.yiphanedgar@digipen.edu
\date   Jan 14, 2023 
\brief	This file contains the definition for functions that represent the behavior of Level 2
		Functions include
			Load() load variables from a file, intialize assets
			Initialize() set starting variables
			Update() called every frame cycle
			Draw()	outputs what the level would look like
			Free()	unintialize variables used, notably pointers
			Unload() free all assets initialized in Load()
Copyright (C) 2023 DigiPen Institute of Technology. 
Reproduction or disclosure of this file or its contents 
without the prior written consent of DigiPen Institute of 
Technology is prohibited. 
*/ 
/* End Header **************************************************************************/


#include "pch.h"
#include "Level2.h"
int Level2_Counter, Level2_Lives;

void Level2_Load()
{
	//Initialize Level2_Lives
	Level2_Lives = 0;
	//Open file
	std::ifstream ifs{ "Level2_Lives.txt" };
	//Save variable from file onto Level2_Lives
	ifs >> Level2_Lives;
	//Close file
	ifs.close();
	//Print to console
	std::cout << "Level2:Load" << std::endl;
}

void Level2_Initialize()
{
	//Initialize Level2_Counter
	Level2_Counter = 0;
	//File Open
	std::ifstream ifs{ "Level2_Counter.txt" };
	//Save value from file onto Level2_Counter;
	ifs >> Level2_Counter;
	ifs.close();
	//Print to console
	std::cout << "Level2:Initialize" << std::endl;
}

void Level2_Update()
{
	//Decrement Counter
	Level2_Counter--;
	//Check if counter == 0
	if (!Level2_Counter) {
		//Decrement lives counter
		Level2_Lives--;
		if (!Level2_Lives) {
			//Update/Change State
			next = GS_QUIT;
		}
		else {
			//Update/Change Ssp
			next = GS_RESTART;
		}
	}
	//Print to console
	std::cout << "Level2:Update" << std::endl;
}

void Level2_Draw()
{
	//Print to console
	std::cout << "Level2:Draw" << std::endl;
}

void Level2_Free()
{
	//Print to console
	std::cout << "Level2:Free" << std::endl;
}

void Level2_Unload()
{
	//Print to console
	std::cout << "Level2:Unload" << std::endl;
}
