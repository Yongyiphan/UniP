/* Start Header ************************************************************************/ 
/*! 
\file   Level1.cpp
\author Yong Yip Han Edgar, y.yiphanedgar, 2202206 
\par    y.yiphanedgar@digipen.edu
\date   Jan 14, 2023 
\brief	This file contains the definition for functions that represent the behavior of Level 1
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

#include "Level1.h"
int Level1_Counter;

void Level1_Load()
{
	//Initialize Level1_Counter
	Level1_Counter = 0;
	//Open file
	std::ifstream ifs1{"Level1_Counter.txt"};
	//Save file content to Level1_Counter;
	ifs1 >> Level1_Counter;
	//Close file
	ifs1.close();
	//Print to console
	std::cout << "Level1:Load" << std::endl;
}

void Level1_Initialize()
{
	//Print to console
	std::cout << "Level1:Initialize" << std::endl;
}

void Level1_Update()
{
	//Decrement Level1_Counter
	Level1_Counter--;
	//Change state if Level1_Counter == 0
	if (!Level1_Counter)
		next = GS_LEVEL2;
	//Print to console
	std::cout << "Level1:Update" << std::endl;
}

void Level1_Draw()
{
	//Print to console
	std::cout << "Level1:Draw" << std::endl;
}

void Level1_Free()
{
	//Print to console
	std::cout << "Level1:Free" << std::endl;
}

void Level1_Unload()
{	
	//Print to console
	std::cout << "Level1:Unload" << std::endl;
}