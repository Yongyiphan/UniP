/******************************************************************************/
/*!
\file		GameState_Asteroids.h
\author 	Yong Yip Han, Edgar
\par    	email: y.yiphanedgar\@digipen.edu
\date   	February 02, 2023
\brief		This File contains the delcarations for functions to
			GameStateAsteroidsLoad() -> to load in all meshes for drawing
			GameStateAsteroidsInit() -> initialize starting variables and locations of space ship and asteroids
			GameStateAsteroidsUpdate() -> game loops which contains the game's logic
			GameStateAsteroidsDraw() -> draw game objects into the screen
			GameStateAsteroidsFree() -> release game objects
			GameStateAsteroidsUnload() -> release previously created sprites
			This Files also contains the declarations for structs that represent
			Unique object types
			Object Instance


Copyright (C) 2023 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#ifndef CSD1130_GAME_STATE_PLAY_H_
#define CSD1130_GAME_STATE_PLAY_H_

// ---------------------------------------------------------------------------

void GameStateAsteroidsLoad(void);
void GameStateAsteroidsInit(void);
void GameStateAsteroidsUpdate(void);
void GameStateAsteroidsDraw(void);
void GameStateAsteroidsFree(void);
void GameStateAsteroidsUnload(void);

// ---------------------------------------------------------------------------


#endif // CSD1130_GAME_STATE_PLAY_H_


