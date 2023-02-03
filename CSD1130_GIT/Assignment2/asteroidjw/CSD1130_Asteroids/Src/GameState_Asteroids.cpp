/******************************************************************************/
/*!
\file		GameState_Asteroids.cpp
\author 	DigiPen
\par    	email: digipen\@digipen.edu
\date   	January 01, 20xx
\brief		ToDo: give a brief explanation here

Copyright (C) 20xx DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#include "main.h"
#include <iostream>
#include <cstdlib>

/******************************************************************************/
/*!
	Defines
*/
/******************************************************************************/
const unsigned int	GAME_OBJ_NUM_MAX		= 32;			// The total number of different objects (Shapes)
const unsigned int	GAME_OBJ_INST_NUM_MAX	= 2048;			// The total number of different game object instances


const unsigned int	SHIP_INITIAL_NUM		= 3;			// initial number of ship lives
const float			SHIP_SIZE				= 16.0f;		// ship size
const float			SHIP_ACCEL_FORWARD		= 150.0f;		// ship forward acceleration (in m/s^2)
const float			SHIP_ACCEL_BACKWARD		= 150.0f;		// ship backward acceleration (in m/s^2)
const float			SHIP_ROT_SPEED			= (2.0f * PI);	// ship rotation speed (degree/second)

const float			BULLET_SPEED			= 350.0f;		// bullet speed (m/s)
const float			BULLET_SIZE				= 10.0f;		// bullet size

const float         BOUNDING_RECT_SIZE      = 1.0f;         // this is the normalized bounding rectangle (width and height) sizes - AABB collision data
static bool onValueChange = true;

// -----------------------------------------------------------------------------
enum TYPE
{
	// list of game object types
	TYPE_SHIP = 0, 
	TYPE_BULLET,
	TYPE_ASTEROID,

	TYPE_NUM
};

// -----------------------------------------------------------------------------
// object flag definition

const unsigned long FLAG_ACTIVE				= 0x00000001;

/******************************************************************************/
/*!
	Struct/Class Definitions
*/
/******************************************************************************/

//Game object structure
struct GameObj
{
	unsigned long		type;		// object type
	AEGfxVertexList *	pMesh;		// This will hold the triangles which will form the shape of the object
};

// ---------------------------------------------------------------------------

//Game object instance structure
struct GameObjInst
{
	GameObj *			pObject;	// pointer to the 'original' shape
	unsigned long		flag;		// bit flag or-ed together
	float				scale;		// scaling value of the object instance
	AEVec2				posCurr;	// object current position
	AEVec2				velCurr;	// object current velocity
	float				dirCurr;	// object current direction
	AABB				boundingBox;// object bouding box that encapsulates the object
	AEMtx33				transform;	// object transformation matrix: Each frame, 
									// calculate the object instance's transformation matrix and save it here

	//void				(*pfUpdate)(void);
	//void				(*pfDraw)(void);
};

/******************************************************************************/
/*!
	Static Variables
*/
/******************************************************************************/

// list of original object
static GameObj				sGameObjList[GAME_OBJ_NUM_MAX];				// Each element in this array represents a unique game object (shape)
static unsigned long		sGameObjNum;								// The number of defined game objects

// list of object instances
static GameObjInst			sGameObjInstList[GAME_OBJ_INST_NUM_MAX];	// Each element in this array represents a unique game object instance (sprite)
static unsigned long		sGameObjInstNum;							// The number of used game object instances

// pointer to the ship object
static GameObjInst *		spShip;										// Pointer to the "Ship" game object instance

// number of ship available (lives 0 = game over)
static long					sShipLives;									// The number of lives left

// the score = number of asteroid destroyed
static unsigned long		sScore;										// Current score
static 

// ---------------------------------------------------------------------------

// functions to create/destroy a game object instance
GameObjInst *		gameObjInstCreate (unsigned long type, float scale, 
											   AEVec2 * pPos, AEVec2 * pVel, float dir);
void				gameObjInstDestroy(GameObjInst * pInst);

void				createAsteroidObject();


/******************************************************************************/
/*!
	"Load" function of this state
*/
/******************************************************************************/
void GameStateAsteroidsLoad(void)
{
	// zero the game object array
	memset(sGameObjList, 0, sizeof(GameObj) * GAME_OBJ_NUM_MAX);
	// No game objects (shapes) at this point
	sGameObjNum = 0;

	// zero the game object instance array
	memset(sGameObjInstList, 0, sizeof(GameObjInst) * GAME_OBJ_INST_NUM_MAX);
	// No game object instances (sprites) at this point
	sGameObjInstNum = 0;

	// The ship object instance hasn't been created yet, so this "spShip" pointer is initialized to 0
	spShip = nullptr;

	// load/create the mesh data (game objects / Shapes)
	GameObj * pObj;

	// =====================
	// create the ship shape
	// =====================

	pObj		= sGameObjList + sGameObjNum++;
	pObj->type	= TYPE_SHIP;

	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.5f,  0.5f, 0xFFFF0000, 0.0f, 0.0f, 
		-0.5f, -0.5f, 0xFFFF0000, 0.0f, 0.0f,
		 0.5f,  0.0f, 0xFFFFFFFF, 0.0f, 0.0f );  

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");


	// =======================
	// create the bullet shape
	// =======================


	pObj = sGameObjList + sGameObjNum++;
	pObj->type = TYPE_BULLET;

	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.5f, -0.1f, 0xFFFFFF00, 0.0f, 0.0f,
		-0.5f, 0.1f, 0xFFFFFF00, 0.0f, 0.0f,
		0.5f, -0.1f, 0xFFFFFF00, 0.0f, 0.0f);

	AEGfxTriAdd(
		0.5f, -0.1f, 0xFFFFFF00, 0.0f, 0.0f,
		-0.5f, 0.1f, 0xFFFFFF00, 0.0f, 0.0f,
		0.5f, 0.1f, 0xFFFFFF00, 0.0f, 0.0f);

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");



	// =========================
	// create the asteroid shape
	// =========================

	pObj = sGameObjList + sGameObjNum++;
	pObj->type = TYPE_ASTEROID;

	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.5f, -0.5f, 0xFF808080, 0.0f, 0.0f,
		-0.5f, 0.5f, 0xFF808080, 0.0f, 0.0f,
		0.5f, 0.5f, 0xFF808080, 0.0f, 0.0f);

	AEGfxTriAdd(
		0.5f, -0.5f, 0xFF808080, 0.0f, 0.0f,
		-0.5f, -0.5f, 0xFF808080, 0.0f, 0.0f,
		0.5f, 0.5f, 0xFF808080, 0.0f, 0.0f);

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");
}

/******************************************************************************/
/*!
	"Initialize" function of this state
*/
/******************************************************************************/
void GameStateAsteroidsInit(void)
{
	// create the main ship
	spShip = gameObjInstCreate(TYPE_SHIP, SHIP_SIZE, nullptr, nullptr, 0.0f);
	AE_ASSERT(spShip);	

	// CREATE THE INITIAL ASTEROIDS INSTANCES USING THE "gameObjInstCreate" FUNCTION
	for (int i = 0; i < 4; ++i)
	{
		createAsteroidObject();
	}

	// reset the score and the number of ships
	sScore      = 0;
	sShipLives  = SHIP_INITIAL_NUM;
}

/******************************************************************************/
/*!
	"Update" function of this state
*/
/******************************************************************************/
void GameStateAsteroidsUpdate(void)
{
	// =========================
	// update according to input
	// =========================

	// This input handling moves the ship without any velocity nor acceleration
	// It should be changed when implementing the Asteroids project
	//
	// Updating the velocity and position according to acceleration is 
	// done by using the following:
	// Pos1 = 1/2 * a*t*t + v0*t + Pos0
	//
	// In our case we need to divide the previous equation into two parts in order 
	// to have control over the velocity and that is done by:
	//
	// v1 = a*t + v0		//This is done when the UP or DOWN key is pressed 
	// Pos1 = v1*t + Pos0

	if (sShipLives >= 0 && sScore < 5000)
	{
		if (AEInputCheckCurr(AEVK_UP))
		{
			AEVec2 added{};
			AEVec2Set(&added, cosf(spShip->dirCurr), sinf(spShip->dirCurr));
			AEVec2Scale(&added, &added, SHIP_ACCEL_FORWARD * AEFrameRateControllerGetFrameTime());

			// Find the velocity according to the acceleration
			AEVec2Add(&spShip->velCurr, &spShip->velCurr, &added);

		}

		if (AEInputCheckCurr(AEVK_DOWN))
		{
			AEVec2 added{};
			AEVec2Set(&added, -cosf(spShip->dirCurr), -sinf(spShip->dirCurr));
			AEVec2Scale(&added, &added, SHIP_ACCEL_BACKWARD * AEFrameRateControllerGetFrameTime());

			// Find the velocity according to the decceleration		
			AEVec2Add(&spShip->velCurr, &spShip->velCurr, &added);

		}

		if (AEInputCheckCurr(AEVK_LEFT))
		{
			spShip->dirCurr += SHIP_ROT_SPEED * (float)(AEFrameRateControllerGetFrameTime());
			spShip->dirCurr = AEWrap(spShip->dirCurr, -PI, PI);
		}

		if (AEInputCheckCurr(AEVK_RIGHT))
		{
			spShip->dirCurr -= SHIP_ROT_SPEED * (float)(AEFrameRateControllerGetFrameTime());
			spShip->dirCurr = AEWrap(spShip->dirCurr, -PI, PI);
		}


		// Shoot a bullet if space is triggered (Create a new object instance)
		if (AEInputCheckTriggered(AEVK_SPACE))
		{
			// Get the bullet's direction according to the ship's direction
			AEVec2 dir{};
			AEVec2Set(&dir, cosf(spShip->dirCurr), sinf(spShip->dirCurr));

			// Set the velocity
			AEVec2 vel{};
			AEVec2Scale(&vel, &dir, BULLET_SPEED);

			// Create an instance
			gameObjInstCreate(TYPE_BULLET, BULLET_SIZE, &spShip->posCurr, &vel, spShip->dirCurr);

		}
	}
	AEVec2Scale(&spShip->velCurr, &spShip->velCurr, 0.99);

	// ======================================================
	// update physics of all active game object instances
	//  -- Get the AABB bounding rectangle of every active instance:
	//		boundingRect_min = -(BOUNDING_RECT_SIZE/2.0f) * instance->scale + instance->pos
	//		boundingRect_max = +(BOUNDING_RECT_SIZE/2.0f) * instance->scale + instance->pos
	//
	//	-- Positions of the instances are updated here with the already computed velocity (above)
	// ======================================================
	
	for (GameObjInst& objI : sGameObjInstList)
	{
		if ((objI.flag & FLAG_ACTIVE) == 0) continue;
		//objI.boundingBox.min = -(BOUNDING_RECT_SIZE / 2.0f) * objI.scale + objI.posCurr;
		AEVec2 bBoxOffset{};
		AEVec2Set(&bBoxOffset, (BOUNDING_RECT_SIZE / 2.0f) * objI.scale, (BOUNDING_RECT_SIZE / 2.0f) * objI.scale);
		AEVec2Sub(&objI.boundingBox.min, &objI.posCurr, &bBoxOffset);
		AEVec2Add(&objI.boundingBox.max, &objI.posCurr, &bBoxOffset);

		// Uppdate position with velocity
		AEVec2 vel{};
		AEVec2Scale(&vel, &objI.velCurr, AEFrameRateControllerGetFrameTime());
			
		AEVec2Add(&objI.posCurr, &objI.posCurr, &vel);
	}



	// ====================
	// check for collision
	// ====================

	/*
	for each object instance: oi1
		if oi1 is not active
			skip

		if oi1 is an asteroid
			for each object instance oi2
				if(oi2 is not active or oi2 is an asteroid)
					skip

				if(oi2 is the ship)
					Check for collision between ship and asteroids (Rectangle - Rectangle)
					Update game behavior accordingly
					Update "Object instances array"
				else
				if(oi2 is a bullet)
					Check for collision between bullet and asteroids (Rectangle - Rectangle)
					Update game behavior accordingly
					Update "Object instances array"
	*/

	if (sShipLives >= 0 && sScore  < 5000)
	{
		bool spawnExtra = false;
		for (unsigned long i = 0; i < GAME_OBJ_INST_NUM_MAX; i++)
		{
			GameObjInst* pInst = sGameObjInstList + i;
			// skip non-active object
			if ((pInst->flag & FLAG_ACTIVE) == 0)
				continue;

			// check if the object is a ship
			if (pInst->pObject->type == TYPE_ASTEROID)
			{
				for (unsigned long j = 0; j < GAME_OBJ_INST_NUM_MAX; j++)
				{
					GameObjInst* pInst2 = sGameObjInstList + j;
					if ((pInst2->flag & FLAG_ACTIVE) == 0 || pInst2->pObject->type == TYPE_ASTEROID)
						continue;
					//Ship
					if (pInst2->pObject->type == TYPE_SHIP)
					{
						if (CollisionIntersection_RectRect(pInst->boundingBox, pInst->velCurr, pInst2->boundingBox, pInst2->velCurr)) //ship collided with astroid
						{
							std::cout << "ship col with asteroid pos " << pInst->posCurr.x << " " << pInst->posCurr.y << "\n";
							sShipLives--;
							AEVec2Set(&pInst2->posCurr, 0.0f, 0.0f); // Move ship to center
							AEVec2Set(&pInst2->velCurr, 0.0f, 0.0f);
							pInst->flag = 0; //remove asteroid
							sScore += 100;
							spawnExtra = true;
						}
					}
					else if (pInst2->pObject->type == TYPE_BULLET)
					{
						if (CollisionIntersection_RectRect(pInst->boundingBox, pInst->velCurr, pInst2->boundingBox, pInst2->velCurr))
						{
							pInst2->flag = 0; //remove bullet
							pInst->flag = 0; //remove asteroid
							sScore += 100;
							spawnExtra = true;
						}
					}
				}
			}
		}
		if (spawnExtra)
		{
			for (int i{}; i < 2; ++i)
			{
				createAsteroidObject();
			}
			onValueChange = true;
			spawnExtra = false;
		}
	}


	// ===================================
	// update active game object instances
	// Example:
	//		-- Wrap specific object instances around the world (Needed for the assignment)
	//		-- Removing the bullets as they go out of bounds (Needed for the assignment)
	//		-- If you have a homing missile for example, compute its new orientation 
	//			(Homing missiles are not required for the Asteroids project)
	//		-- Update a particle effect (Not required for the Asteroids project)
	// ===================================
	for (unsigned long i = 0; i < GAME_OBJ_INST_NUM_MAX; i++)
	{
		GameObjInst * pInst = sGameObjInstList + i;

		// skip non-active object
		if ((pInst->flag & FLAG_ACTIVE) == 0)
			continue;
		
		// check if the object is a ship
		if (pInst->pObject->type == TYPE_SHIP)
		{
			// warp the ship from one end of the screen to the other
			pInst->posCurr.x = AEWrap(pInst->posCurr.x, AEGfxGetWinMinX() - SHIP_SIZE, 
														AEGfxGetWinMaxX() + SHIP_SIZE);
			pInst->posCurr.y = AEWrap(pInst->posCurr.y, AEGfxGetWinMinY() - SHIP_SIZE, 
														AEGfxGetWinMaxY() + SHIP_SIZE);
		}

		// Wrap asteroids here
		if (pInst->pObject->type == TYPE_ASTEROID)
		{
			// warp the ship from one end of the screen to the other
			pInst->posCurr.x = AEWrap(pInst->posCurr.x, AEGfxGetWinMinX() - pInst->scale,
				AEGfxGetWinMaxX() + pInst->scale);
			pInst->posCurr.y = AEWrap(pInst->posCurr.y, AEGfxGetWinMinY() - pInst->scale,
				AEGfxGetWinMaxY() + pInst->scale);
		}

		// Remove bullets that go out of bounds
		if (pInst->pObject->type == TYPE_BULLET)
		{
			// Remove bullets that go out of bounds

			if (pInst->posCurr.x > AEGfxGetWinMaxX() + 100.0f
				|| pInst->posCurr.x < AEGfxGetWinMinX() - 100.0f
				|| pInst->posCurr.y > AEGfxGetWinMaxY() + 100.0f
				|| pInst->posCurr.y < AEGfxGetWinMinY() - 100.0f)
			{
				pInst->flag = 0;
			}
		}
	}


	

	// =====================================
	// calculate the matrix for all objects
	// =====================================

	for (unsigned long i = 0; i < GAME_OBJ_INST_NUM_MAX; i++)
	{
		GameObjInst* pInst = sGameObjInstList + i;
		AEMtx33		 trans{ 0 }, rot{ 0 }, scale{ 0 };

		// skip non-active object
		if ((pInst->flag & FLAG_ACTIVE) == 0)
			continue;

		// Compute the scaling matrix
		AEMtx33Scale(&scale, pInst->scale, pInst->scale);
		// Compute the rotation matrix 
		if (pInst->pObject->type == TYPE_ASTEROID)
		{
			AEMtx33Rot(&rot, 0);
		}
		else
		{
			AEMtx33Rot(&rot, pInst->dirCurr);
		}
		// Compute the translation matrix
		AEMtx33Trans(&trans, pInst->posCurr.x, pInst->posCurr.y);
		// Concatenate the 3 matrix in the correct order in the object instance's "transform" matrix
		AEMtx33Concat(&pInst->transform, &rot, &scale);
		AEMtx33Concat(&pInst->transform, &trans, &pInst->transform);
		
	}
}

/******************************************************************************/
/*!
	
*/
/******************************************************************************/
void GameStateAsteroidsDraw(void)
{
	char strBuffer[1024];
	
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxTextureSet(NULL, 0, 0);

	// draw all object instances in the list
	for (unsigned long i = 0; i < GAME_OBJ_INST_NUM_MAX; i++)
	{
		GameObjInst * pInst = sGameObjInstList + i;

		// skip non-active object
		if ((pInst->flag & FLAG_ACTIVE) == 0)
			continue;
		
		AEGfxSetTransform(pInst->transform.m);
		AEGfxMeshDraw(pInst->pObject->pMesh, AE_GFX_MDM_TRIANGLES);
		// Set the current object instance's transform matrix using "AEGfxSetTransform"
		// Draw the shape used by the current object instance using "AEGfxMeshDraw"
	}

	//You can replace this condition/variable by your own data.
	//The idea is to display any of these variables/strings whenever a change in their value happens
	if(onValueChange)
	{
		sprintf_s(strBuffer, "Score: %d", sScore);
		//AEGfxPrint(10, 10, (u32)-1, strBuffer);
		printf("%s \n", strBuffer);

		sprintf_s(strBuffer, "Ship Left: %d", sShipLives >= 0 ? sShipLives : 0);
		//AEGfxPrint(600, 10, (u32)-1, strBuffer);
		printf("%s \n", strBuffer);

		// display the game over message
		if (sShipLives < 0)
		{
			//AEGfxPrint(280, 260, 0xFFFFFFFF, "       GAME OVER       ");
			printf("       GAME OVER       \n");
		}
		else if (sScore >= 5000)
		{
			printf("YOU ROCK\n");
		}
		onValueChange = false;
	}
}

/******************************************************************************/
/*!
	
*/
/******************************************************************************/
void GameStateAsteroidsFree(void)
{
	// kill all object instances in the array using "gameObjInstDestroy"
	for (unsigned long i = 0; i < GAME_OBJ_INST_NUM_MAX; i++)
	{
		GameObjInst* pInst = sGameObjInstList + i;
		if (pInst->flag == FLAG_ACTIVE)
		{
			pInst->flag == 0;
		}
	}
	
}

/******************************************************************************/
/*!
	
*/
/******************************************************************************/
void GameStateAsteroidsUnload(void)
{
	// free all mesh data (shapes) of each object using "AEGfxTriFree"
	for (unsigned long i = 0; i < GAME_OBJ_NUM_MAX; i++)
	{
		GameObj* pObj = sGameObjList + i;
		if (pObj->pMesh != nullptr)
		{
			AEGfxMeshFree(pObj->pMesh);
			//pObj->pMesh = nullptr;
		}
	}

	
}

/******************************************************************************/
/*!
	
*/
/******************************************************************************/
GameObjInst * gameObjInstCreate(unsigned long type, 
							   float scale, 
							   AEVec2 * pPos, 
							   AEVec2 * pVel, 
							   float dir)
{
	AEVec2 zero;
	AEVec2Zero(&zero);

	AE_ASSERT_PARM(type < sGameObjNum);
	
	// loop through the object instance list to find a non-used object instance
	for (unsigned long i = 0; i < GAME_OBJ_INST_NUM_MAX; i++)
	{
		GameObjInst * pInst = sGameObjInstList + i;

		// check if current instance is not used
		if (pInst->flag == 0)
		{
			// it is not used => use it to create the new instance
			pInst->pObject	= sGameObjList + type;
			pInst->flag		= FLAG_ACTIVE;
			pInst->scale	= scale;
			pInst->posCurr	= pPos ? *pPos : zero;
			pInst->velCurr	= pVel ? *pVel : zero;
			pInst->dirCurr	= dir;
			
			// return the newly created instance
			return pInst;
		}
	}

	// cannot find empty slot => return 0
	return 0;
}

/******************************************************************************/
/*!
	
*/
/******************************************************************************/
void gameObjInstDestroy(GameObjInst * pInst)
{
	// if instance is destroyed before, just return
	if (pInst->flag == 0)
		return;

	// zero out the flag
	pInst->flag = 0;
}

void createAsteroidObject() {
	float size = 20.0f + rand() % 51; // size 20 to 70
	float dir = rand() * 10 / 360.0f;
	dir *= PI / 180;
	AEVec2 vel{};

	AEVec2Set(&vel, cosf(dir), sinf(dir));
	AEVec2Scale(&vel, &vel, 50 + rand() % 151); // speed 50 to 200

	AEVec2 pos{};
	if (rand() % 2) // move on y axis
	{
		if (vel.y < 0) //moving downwards, set pos above
		{
			pos.y = AEGfxGetWinMaxY() + 55.0f;
		}
		else //moving upwards, set pos below
		{
			pos.y = AEGfxGetWinMinY() - 55.0f;
		}
		pos.x = AEGfxGetWinMinX() + rand() % AEGetWindowWidth();
	}
	else // move on x axis
	{
		if (vel.x < 0) //moving left, set pos right
		{
			pos.x = AEGfxGetWinMaxX() + 55.0f;
		}
		else //moving right, set pos left
		{
			pos.x = AEGfxGetWinMinX() - 55.0f;
		}
		pos.y = AEGfxGetWinMinY() + rand() % AEGetWindowHeight();
	}

	GameObjInst* temp = gameObjInstCreate(TYPE_ASTEROID, size, &pos, &vel, dir);
}