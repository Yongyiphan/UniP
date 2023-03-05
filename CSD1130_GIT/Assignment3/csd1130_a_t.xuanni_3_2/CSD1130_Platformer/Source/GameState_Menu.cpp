/******************************************************************************/
/*!
\file		GameState_Menu.cpp
\author 	Teo Xuan Ni
\par    	email: t.xuanni@digipen.edu
\date   	February 28, 2022
\brief		This file includes all the function to display a menu page

Copyright (C) 2022 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
 /******************************************************************************/

#include "main.h"

/**************************************************************************/
/*!
	To load the background color for menu page
*/
/**************************************************************************/
void GameStateMenuLoad(void)
{
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
}

/**************************************************************************/
/*!
	Initialise
*/
/**************************************************************************/
void GameStateMenuInit(void)
{

}

/**************************************************************************/
/*!
	Update logic to change level
*/
/**************************************************************************/
void GameStateMenuUpdate(void)
{
	if (AEInputCheckCurr(AEVK_1))
	{
		gGameStateNext = GS_PLATFORM;
	}

	if (AEInputCheckCurr(AEVK_2))
	{
		gGameStateNext = GS_PLATFORM2;
	}

	if (AEInputCheckCurr(AEVK_Q))
	{
		gGameStateNext = GS_QUIT;
	}
}

/**************************************************************************/
/*!
	Draws the text
*/
/**************************************************************************/
void GameStateMenuDraw(void)
{
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);
	AEGfxPrint(fontId, "Platformer", -0.3f, 0.5f, 0.4f, 0.6f, 0.0f, 0.6f); // Title
	AEGfxPrint(fontId, "Press '1' for Level 1", -0.3f, 0.2f, 0.4f, 1.0f, 1.0f, 1.0f); // Text for Level 1 prompt
	AEGfxPrint(fontId, "Press '2' for Level 2", -0.3f, 0.1f, 0.4f, 1.0f, 1.0f, 1.0f); // Text for Level 2 prompt
	AEGfxPrint(fontId, "Press 'Q' to quit", -0.3f, 0.0f, 0.4f, 1.0f, 1.0f, 1.0f); // Text to prompt users to quit
}

/**************************************************************************/
/*!
	Free
*/
/**************************************************************************/
void GameStateMenuFree(void)
{

}

/**************************************************************************/
/*!
	Unload
*/
/**************************************************************************/
void GameStateMenuUnload(void)
{

}