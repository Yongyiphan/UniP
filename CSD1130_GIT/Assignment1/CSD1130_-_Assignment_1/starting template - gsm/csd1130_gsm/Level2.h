#pragma once
/* Start Header ************************************************************************/ 
/*! 
\file   Level2.h 
\author Yong Yip Han Edgar, y.yiphanedgar, 2202206 
\par    y.yiphanedgar@digipen.edu
\date   Jan 14, 2023 
\brief	This file contains the declaration for functions that represent the behavior of Level 2
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

/*
\brief		Load Assets for Level 1
*/
void Level2_Load();

/*
\brief		Initialize variables for Level 1
*/
void Level2_Initialize();

/*
\brief		Updates Level 1's logic on every frame
*/
void Level2_Update();

/*
\brief		Draws out level1 output onto an interface
*/
void Level2_Draw();

/*
\brief		Uninitialized variables
*/
void Level2_Free();

/*
\brief		Free Assets from Load()
*/
void Level2_Unload();
