/******************************************************************************/
/*!
\file		main.h
\author 	Edgar Yong
\par    	email: y.yiphanedgar\@digipen.edu
\date   	March 6, 2023
\brief		This File contains the main function to run the whole program
			And includes that will be used throughout the source files.

Copyright (C) 2023 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/


#ifndef CSD1130_MAIN_H_
#define CSD1130_MAIN_H_

//------------------------------------
// Globals

extern float	g_dt;
extern double	g_appTime;


// ---------------------------------------------------------------------------
// includes

#include "AEEngine.h"
#include "Math.h"

#include "GameStateMgr.h"
#include "GameState_MainMenu.h"
#include "GameState_Platform.h"
#include "Collision.h"
//Custom Variables
extern f32	winw;
extern f32	winh;
extern s8	FontID;


#endif // CSD1130_MAIN_H_










