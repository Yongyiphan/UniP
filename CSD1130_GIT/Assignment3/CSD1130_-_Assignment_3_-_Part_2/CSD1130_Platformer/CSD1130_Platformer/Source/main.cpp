/******************************************************************************/
/*!
\file		main.cpp
\author 	Edgar Yong
\par    	email: y.yiphanedgar\@digipen.edu
\date   	March 6, 2023
\brief		This file contains the definition for the main.cpp

Copyright (C) 2023 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#include "main.h"


// ---------------------------------------------------------------------------
// Globals
float	g_dt;
double	g_appTime;
s8		FontID;
f32		winw;
f32		winh;

#include <iostream>


/******************************************************************************/
/*!
	Starting point of the application
*/
/******************************************************************************/
int WINAPI WinMain(HINSTANCE instanceH, HINSTANCE prevInstanceH, LPSTR command_line, int show)
{
	UNREFERENCED_PARAMETER(prevInstanceH);
	UNREFERENCED_PARAMETER(command_line);
	// Initialize the system
	AESysInit (instanceH, show, 800, 600, 1, 60, false, NULL);
	
	AESysSetWindowTitle("CSD1130 Platformer");
	//Create your font here, and use it for all your levels
	FontID = AEGfxCreateFont("../Resources/Fonts/Arial Italic.ttf", 25);
	winw = (f32)AEGetWindowWidth();
	winh = (f32)AEGetWindowHeight();
	std::cout << winw << " " << winh << std::endl;

	//GameStateMgrInit(GS_LEVEL2);
	GameStateMgrInit(GS_MAINMENU);

	while(gGameStateCurr != GS_QUIT)
	{
		// reset the system modules
		AESysReset();

		// If not restarting, load the gamestate
		if(gGameStateCurr != GS_RESTART)
		{
			GameStateMgrUpdate();
			GameStateLoad();
		}
		else
			gGameStateNext = gGameStateCurr = gGameStatePrev;

		// Initialize the gamestate
		GameStateInit();

		while(gGameStateCurr == gGameStateNext)
		{
			AESysFrameStart();

			AEInputUpdate();

			GameStateUpdate();
		

			GameStateDraw();
			
			AESysFrameEnd();

			// check if forcing the application to quit
			if (AESysDoesWindowExist() == false)
				gGameStateNext = GS_QUIT;

			g_dt = (f32)AEFrameRateControllerGetFrameTime();
			
			//capping the game loop - delta time, to 1/60.0f
			if (g_dt > 0.01667f)	//0.01667f = 1/60.0f
				g_dt = 0.01667f;
				
			g_appTime += g_dt;
		}
		
		GameStateFree();

		if(gGameStateNext != GS_RESTART)
			GameStateUnload();

		gGameStatePrev = gGameStateCurr;
		gGameStateCurr = gGameStateNext;
	}

	//free you font here
	AEGfxDestroyFont(FontID);
	// free the system
	AESysExit();
}