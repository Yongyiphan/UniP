/* Start Header ************************************************************************/ 
/*! 
\file   GameStateManager.cpp
\author Yong Yip Han Edgar, y.yiphanedgar, 2202206 
\par    y.yiphanedgar@digipen.edu
\date   Jan 14, 2023 
\brief	This file contains the definition for functions to
			Initialize and Update the Game state manager
		variables of type function pointer to point to methods for each states (Level1 | Level2)
					type int that keep tracks for current, previous and next states


Copyright (C) 2023 DigiPen Institute of Technology. 
Reproduction or disclosure of this file or its contents 
without the prior written consent of DigiPen Institute of 
Technology is prohibited. 
*/ 
/* End Header **************************************************************************/

#include "pch.h"

#include "GameStateManager.h"
#include "Level1.h"
#include "Level2.h"

//Initialize variables to record current, previous and next states
int current = 0, previous = 0, next = 0;

//Initialise Function pointers to type nullptr
FP fpLoad = nullptr, fpInitialize = nullptr, fpUpdate = nullptr, fpDraw = nullptr, fpFree = nullptr, fpUnload = nullptr;

void GSM_Initialize(int startingState)
{
	//Update variables with state provided
	current = previous = next = startingState;
	//Print out to console current status
	std::cout << "GSM:Initialize" << std::endl;

}

void GSM_Update()
{
	//Using switch statements to assignemd function for funciton pointers to point to
	switch (current) {
	case GS_LEVEL1:
		fpLoad = Level1_Load;
		fpInitialize = Level1_Initialize;
		fpUpdate = Level1_Update;
		fpDraw = Level1_Draw;
		fpFree = Level1_Free;
		fpUnload = Level1_Unload;
		break;
	case GS_LEVEL2:
		fpLoad = Level2_Load;
		fpInitialize = Level2_Initialize;
		fpUpdate = Level2_Update;
		fpDraw = Level2_Draw;
		fpFree = Level2_Free;
		fpUnload = Level2_Unload;
		break;
	case GS_RESTART:
		break;
	case GS_QUIT:
		break;
	default:
		break;
	}
	//Print out to console current status
	std::cout << "GSM:Update" << std::endl;
}
	