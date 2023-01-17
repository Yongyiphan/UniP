#pragma once
/* Start Header ************************************************************************/ 
/*! 
\file   GameStateManager.h
\author Yong Yip Han Edgar, y.yiphanedgar, 2202206 
\par    y.yiphanedgar@digipen.edu
\date   Jan 14, 2023 
\brief	This file contains the declaration for functions to
			Initialize and Update the Game state manager
		variables of type function pointer to point to methods for each states (Level1 | Level2)
					type int that keep tracks for current, previous and next states


Copyright (C) 2023 DigiPen Institute of Technology. 
Reproduction or disclosure of this file or its contents 
without the prior written consent of DigiPen Institute of 
Technology is prohibited. 
*/ 
/* End Header **************************************************************************/

/*
\brief	type declaration for a Function pointer 
\param[in] void
*/
typedef void(*FP)(void);

//Global Variable that records the current, previous and next states
extern int current, previous, next;

//Global function pointers that points to subfunction of each respective states
extern FP fpLoad, fpInitialize, fpUpdate, fpDraw, fpFree, fpUnload;

/*
\brief		Function to initialize Game State Manager
\param[in]	startingState 
				value of the starting state
\return		None
*/
void GSM_Initialize(int startingState);

/*
\brief Function to Update Game State Manager
*/
void GSM_Update();