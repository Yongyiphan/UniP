/******************************************************************************/
/*!
\file		GameState_Platform.h
\author 	Edgar Yong
\par    	email: y.yiphanedgar\@digipen.edu
\date   	March 6, 2023
\brief		This file contains the declaration for functions to 
			Load(), Unload(), Init(), Free(), Update() and Draw()
			for the Platform states. 

Copyright (C) 2023 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#ifndef CSD1130_GAME_STATE_PLAY_H_
#define CSD1130_GAME_STATE_PLAY_H_


// ---------------------------------------------------------------------------

void GameStatePlatformLoad(void);
void GameStatePlatformInit(void);
void GameStatePlatformUpdate(void);
void GameStatePlatformDraw(void);
void GameStatePlatformFree(void);
void GameStatePlatformUnload(void);

// ---------------------------------------------------------------------------

#endif // CSD1130_GAME_STATE_PLAY_H_