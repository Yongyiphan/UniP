/******************************************************************************/
/*!
\file		GameState_Platform.h
\author 	Teo Xuan Ni
\par    	email: t.xuanni@digipen.edu
\date   	February 28, 2022
\brief		This file includes all the function to display and play the
			platformer game.

Copyright (C) 2022 DigiPen Institute of Technology.
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