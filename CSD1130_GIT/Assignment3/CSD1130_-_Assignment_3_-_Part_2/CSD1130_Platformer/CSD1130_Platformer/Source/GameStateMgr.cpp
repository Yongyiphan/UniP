/******************************************************************************/
/*!
\file		GameStateMgr.cpp
\author 	Edgar Yong
\par    	email: y.yiphanedgar\@digipen.edu
\date   	March 6, 2023
\brief		This file contains the definition of the Game State Manager
			Function pointer for game loop functions for 
				Load(), Unload()
				Init(), Free()
				Update()
				Draw()
			Functions to reassign which state's functions are to be executed

Copyright (C) 2023 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#include "main.h"

// ---------------------------------------------------------------------------
// globals

// variables to keep track the current, previous and next game state
unsigned int	gGameStateInit;
unsigned int	gGameStateCurr;
unsigned int	gGameStatePrev;
unsigned int	gGameStateNext;

// pointer to functions for game state life cycles functions
void (*GameStateLoad)()		= 0;
void (*GameStateInit)()		= 0;
void (*GameStateUpdate)()	= 0;
void (*GameStateDraw)()		= 0;
void (*GameStateFree)()		= 0;
void (*GameStateUnload)()	= 0;

/******************************************************************************/
/*!
	Initialize the Game State Manager
*/
/******************************************************************************/
void GameStateMgrInit(unsigned int gameStateInit)
{
	// set the initial game state
	gGameStateInit = gameStateInit;

	// reset the current, previoud and next game
	gGameStateCurr = 
	gGameStatePrev = 
	gGameStateNext = gGameStateInit;

	// call the update to set the function pointers
	GameStateMgrUpdate();
}

/******************************************************************************/
/*!
	Handles reassigning functions pointers from different states to be run. in the game loop
*/
/******************************************************************************/
void GameStateMgrUpdate()
{
	if ((gGameStateCurr == GS_RESTART) || (gGameStateCurr == GS_QUIT))
		return;

	switch (gGameStateCurr)
	{
	case GS_MAINMENU:
		GameStateLoad	= GameStateMainMenuLoad;
		GameStateInit	= GameStateMainMenuInit;
		GameStateUpdate	= GameStateMainMenuUpdate;
		GameStateDraw	= GameStateMainMenuDraw;
		GameStateFree	= GameStateMainMenuFree;
		GameStateUnload	= GameStateMainMenuUnload;
		break;
	case GS_LEVEL1:
		GameStateLoad	= GameStatePlatformLoad;
		GameStateInit	= GameStatePlatformInit;
		GameStateUpdate	= GameStatePlatformUpdate;
		GameStateDraw	= GameStatePlatformDraw;
		GameStateFree	= GameStatePlatformFree;
		GameStateUnload	= GameStatePlatformUnload;
		break;
	case GS_LEVEL2:
		GameStateLoad	= GameStatePlatformLoad;
		GameStateInit	= GameStatePlatformInit;
		GameStateUpdate	= GameStatePlatformUpdate;
		GameStateDraw	= GameStatePlatformDraw;
		GameStateFree	= GameStatePlatformFree;
		GameStateUnload	= GameStatePlatformUnload;
		break;
	default:
		AE_FATAL_ERROR("invalid state!!");
	}
}
