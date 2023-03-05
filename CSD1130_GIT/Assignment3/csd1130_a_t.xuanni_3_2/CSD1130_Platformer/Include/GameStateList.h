/******************************************************************************/
/*!
\file		GameStateList.h
\author 	Teo Xuan Ni
\par    	email: t.xuanni@digipen.edu
\date   	February 28, 2022
\brief		This file contains function to manage the game states.

Copyright (C) 2022 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#ifndef CSD1130_GAME_STATE_LIST_H_
#define CSD1130_GAME_STATE_LIST_H_

// ---------------------------------------------------------------------------
// game state list

enum
{
	// list of all game states 
	GS_MAINMENU = 0,
	GS_PLATFORM, 
	GS_PLATFORM2,
	
	// special game state. Do not change
	GS_RESTART,
	GS_QUIT, 
	GS_NUM
};

// ---------------------------------------------------------------------------

#endif // CSD1130_GAME_STATE_LIST_H_