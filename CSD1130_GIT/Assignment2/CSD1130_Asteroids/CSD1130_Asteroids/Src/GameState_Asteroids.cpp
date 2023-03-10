/******************************************************************************/
/*!
\file		GameState_Asteroids.cpp
\author 	Yong Yip Han, Edgar
\par    	email: y.yiphanedgar\@digipen.edu
\date   	February 02, 2023
\brief		This File contains the defnitions for functions to
			GameStateAsteroidsLoad() -> to load in all meshes for drawing
			GameStateAsteroidsInit() -> initialize starting variables and locations of space ship and asteroids
			GameStateAsteroidsUpdate() -> game loops which contains the game's logic
			GameStateAsteroidsDraw() -> draw game objects into the screen
			GameStateAsteroidsFree() -> release game objects
			GameStateAsteroidsUnload() -> release previously created sprites
			This Files also contains the definitions for structs that represent
			Unique object types
			Object Instance


Copyright (C) 2023 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#include "main.h"


/******************************************************************************/
/*!
	Defines
*/
/******************************************************************************/
const unsigned int	GAME_OBJ_NUM_MAX		= 32;			// The total number of different objects (Shapes)
const unsigned int	GAME_OBJ_INST_NUM_MAX	= 2048;			// The total number of different game object instances


const unsigned int	SHIP_INITIAL_NUM		= 3;			// initial number of ship lives
const float			SHIP_SIZE				= 16.0f;		// ship size
const float			SHIP_ACCEL_FORWARD		= 140.0f;		// ship forward acceleration (in m/s^2)
const float			SHIP_ACCEL_BACKWARD		= 140.0f;		// ship backward acceleration (in m/s^2)
const float			SHIP_ROT_SPEED			= (2.0f * PI);	// ship rotation speed (degree/second)

const float			BULLET_SPEED			= 100.0f;		// bullet speed (m/s)

const float         BOUNDING_RECT_SIZE      = 1.0f;         // this is the normalized bounding rectangle (width and height) sizes - AABB collision data

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

// to signal print an update of the player's remaining lives and score
static bool onValueChange = true;
// ---------------------------------------------------------------------------

// functions to create/destroy a game object instance
GameObjInst *		gameObjInstCreate (unsigned long type, float scale, 
											   AEVec2 * pPos, AEVec2 * pVel, float dir);
void					gameObjInstDestroy(GameObjInst * pInst);
void					GenerateAsteroid();
f32							acceleration{ 0.f };						// Value for keeping track of acceleration
f32							accspeed{ 15.f };							// Value to increment acceleration by

enum BULLET_TYPES {
	DEFAULT,
	SPRAY,
	CIRCLE
};
BULLET_TYPES  CurrentBT;
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

	pObj		= sGameObjList + sGameObjNum++; //*(ptr + 1)
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
	
	//Yellow Mesh to create bullet
	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.75f, -0.15f, 0xFFFFFF00, 0.0f, 0.0f,
		0.75f, -0.15f, 0xFFFFFF00, 0.0f, 0.0f,
		0.75f, 0.15f, 0xFFFFFF00, 0.0f, 0.0f
	);
	AEGfxTriAdd(
		-0.75f, 0.15f, 0xFFFFFF00, 0.0f, 0.0f,
		-0.75f, -0.15f, 0xFFFFFF00, 0.0f, 0.0f,
		0.75f, 0.15f, 0xFFFFFF00, 0.0f, 0.0f
	);

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");


	// =========================
	// create the asteroid shape
	// =========================
	pObj = sGameObjList + sGameObjNum++;
	pObj->type = TYPE_ASTEROID;
	
	//Gray Mesh to create square asteroids
	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.5f, -0.5f, 0xFF4B4B4B, 0.0f, 0.0f,
		0.5f, -0.5f, 0xFF4B4B4B, 0.0f, 0.0f,
		0.5f, 0.5f, 0xFF4B4B4B, 0.0f, 0.0f
	);
	AEGfxTriAdd(
		-0.5f, 0.5f, 0xFF4B4B4B, 0.0f, 0.0f,
		-0.5f, -0.5f, 0xFF4B4B4B, 0.0f, 0.0f,
		0.5f, 0.5f, 0xFF4B4B4B, 0.0f, 0.0f
	);

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");
	
	

	
}
#include <time.h>
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

	// CREATE 4 INITIAL ASTEROIDS INSTANCES USING THE "gameObjInstCreate" FUNCTION
	const int startingAsteroidCount = 4;
	AEVec2 startpos[startingAsteroidCount] = { {-80,100} ,{350,50},{150,-200},{-100,-250} };
	AEVec2 startvel[startingAsteroidCount] = { 
		{20,20} ,
		{30,30},
		{40,40},
		{50,50} 
	};
	for (int i = 0; i < startingAsteroidCount; i++) {
		GenerateAsteroid();
		//gameObjInstCreate(TYPE_ASTEROID, 20.f * (i + 1), &startpos[i], &startvel[i], AERandFloat() * 2 * PI);
	}

	// reset the score and the number of ships
	sScore      = 0;
	sShipLives  = SHIP_INITIAL_NUM;
	CurrentBT = DEFAULT;

}

/******************************************************************************/
/*!
	"Update" function of this state
*/
/******************************************************************************/
void GameStateAsteroidsUpdate(void)
{
	f32 dt = f32(AEFrameRateControllerGetFrameTime());
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
	if (AEInputCheckCurr(AEVK_UP))
	{
		AEVec2 mv{};
		AEVec2Set(&mv, cosf(spShip->dirCurr), sinf(spShip->dirCurr) );
		AEVec2Scale(&mv, &mv, SHIP_ACCEL_FORWARD * dt);
		AEVec2Add(&spShip->velCurr, &spShip->velCurr, &mv);
			
		AEVec2Scale(&spShip->velCurr, &spShip->velCurr, 0.99f);
		// Find the velocity according to the acceleration
		// Limit your speed over here
	}
	if (AEInputCheckCurr(AEVK_DOWN))
	{
		AEVec2 mv{};
		AEVec2Set(&mv, -cosf(spShip->dirCurr), -sinf(spShip->dirCurr) );
		AEVec2Scale(&mv, &mv, SHIP_ACCEL_BACKWARD * dt);
		AEVec2Add(&spShip->velCurr, &spShip->velCurr, &mv);
			
		AEVec2Scale(&spShip->velCurr, &spShip->velCurr, 0.99f);
		// Find the velocity according to the acceleration
		// Limit your speed over here

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
	
	
	if (AEInputCheckTriggered(AEVK_1)) {
		CurrentBT = DEFAULT;
	}
	if (AEInputCheckTriggered(AEVK_2)) {
		CurrentBT = SPRAY;
	}
	if (AEInputCheckTriggered(AEVK_3)) {
		CurrentBT = CIRCLE;
	}

	// Shoot a bullet if space is triggered (Create a new object instance)
	if (AEInputCheckTriggered(AEVK_SPACE))
	{
		// Get the bullet's direction according to the ship's direction
		// Set the velocity
		// Create an instance
		AEVec2 bulletpos = spShip->posCurr, bulletvel{ spShip->velCurr };
		/*
		*/
		int bullet;
		switch (CurrentBT) {
		case DEFAULT:
			gameObjInstCreate(TYPE_BULLET, 10, &bulletpos, &bulletvel, spShip->dirCurr);
			break;
		case SPRAY:
			gameObjInstCreate(TYPE_BULLET, 10, &bulletpos, &bulletvel, spShip->dirCurr - 1 * PI / 12);
			gameObjInstCreate(TYPE_BULLET, 10, &bulletpos, &bulletvel, spShip->dirCurr + 0 * PI / 12);
			gameObjInstCreate(TYPE_BULLET, 10, &bulletpos, &bulletvel, spShip->dirCurr + 1 * PI / 12);
			break;
		case CIRCLE:
			bullet = 36;
			for (int i = 0; i < bullet; i++) {
				gameObjInstCreate(TYPE_BULLET, 10, &bulletpos, &bulletvel, spShip->dirCurr + i * 2 * PI / bullet);
			}
			break;
		};
	}

	// ======================================================
	// update physics of all active game object instances
	//  -- Get the AABB bounding rectangle of every active instance:
	//		boundingRect_min = -(BOUNDING_RECT_SIZE/2.0f) * instance->scale + instance->pos
	//		boundingRect_max = +(BOUNDING_RECT_SIZE/2.0f) * instance->scale + instance->pos
	//
	//	-- Positions of the instances are updated here with the already computed velocity (above)
	// ======================================================
	
	for (GameObjInst& o : sGameObjInstList){
		if ((o.flag & FLAG_ACTIVE) == 0) continue;
		//Get AABB
		AEVec2 boundingOffset{ BOUNDING_RECT_SIZE / 2.f, BOUNDING_RECT_SIZE / 2.f };
		AEVec2Scale(&boundingOffset, &boundingOffset, o.scale);
		AEVec2Sub(&o.boundingBox.min, &o.posCurr, &boundingOffset);
		AEVec2Add(&o.boundingBox.max, &o.posCurr, &boundingOffset);

		//Update Instances's position
		AEVec2 v0{ 0 };
		AEVec2Scale(&v0, &o.velCurr, dt);
		if (o.pObject->type == TYPE_BULLET) {
			AEVec2Set(&v0, cosf(o.dirCurr), sinf(o.dirCurr));
			AEVec2Scale(&v0, &v0, BULLET_SPEED * dt * 2);
		}
		AEVec2Add(&o.posCurr, &o.posCurr, &v0);
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
	if (sShipLives >= 0 && sScore < 5000) {
		
		bool spawnAsteroids = false;
		for (unsigned int i = 0; i < GAME_OBJ_NUM_MAX; i++) {
			GameObjInst* oi1 = sGameObjInstList + i;
			if ((oi1->flag & FLAG_ACTIVE) == 0)
				continue;
			if (oi1->pObject->type == TYPE_ASTEROID) {
				for (auto& oi2 : sGameObjInstList) {
					if ((oi2.flag & FLAG_ACTIVE) == 0)
						continue;
					if (oi2.posCurr.x == oi1->posCurr.x && oi2.posCurr.y == oi1->posCurr.y) {
						//Found ownself
						continue;
					}
					if (oi2.pObject->type == TYPE_SHIP) {
						if (CollisionIntersection_RectRect(oi1->boundingBox, oi1->velCurr, oi2.boundingBox, oi2.velCurr)) {
							AEVec2Set(&oi2.posCurr, 0.f, 0.f);
							AEVec2Set(&oi2.velCurr, 0.f, 0.f);
							gameObjInstDestroy(oi1);
							//Decrement Ship Lives
							sScore += 100;
							sShipLives--;
							spawnAsteroids = true;
						}
					}
					if (oi2.pObject->type == TYPE_BULLET) {
						if (CollisionIntersection_RectRect(oi1->boundingBox, oi1->posCurr, oi2.boundingBox, oi2.posCurr)) {
							gameObjInstDestroy(oi1);
							gameObjInstDestroy(&oi2);
							//Generate new asteroids
							sScore += 100;
							spawnAsteroids = true;
						}
					}
				}
			}

		}
		if (spawnAsteroids) {
			for (int i = 0; i < 2; ++i) {
				GenerateAsteroid();
			}
			onValueChange = true;
			spawnAsteroids = false;
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
		GameObjInst* pInst = sGameObjInstList + i;
		
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
		if (pInst->pObject->type == TYPE_ASTEROID) {
			AEVec2 v0;
			AEVec2Set(&v0, -cosf(pInst->dirCurr), -sinf(pInst->dirCurr));
			AEVec2Add(&pInst->posCurr, &pInst->posCurr, &v0);
			pInst->posCurr.x = AEWrap(pInst->posCurr.x, AEGfxGetWinMinX() - pInst->scale, AEGfxGetWinMaxX() + pInst->scale);
			pInst->posCurr.y = AEWrap(pInst->posCurr.y, AEGfxGetWinMinY() - pInst->scale, AEGfxGetWinMaxY() + pInst->scale);
			
		}


		// Remove bullets that go out of circular bounds
		if (pInst->pObject->type == TYPE_BULLET) {
			/* Circular implementation of boundary
			*/
			int ww = AEGetWindowWidth(), wh = AEGetWindowHeight();
			//window offset in x and y axis, boundary = offsetx^2 + offsety^2
			float wwos = ww / 2.f, whos = wh / 2.f, boundary = wwos * wwos + whos * whos;
			
			//Checking boundary using radius (from sqrt(width/2 ^2 + height/2 ^2)
			if (pInst->posCurr.x * pInst->posCurr.x + pInst->posCurr.y * pInst->posCurr.y >= boundary) {
				gameObjInstDestroy(pInst);
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

		//UNREFERENCED_PARAMETER(trans);
		//UNREFERENCED_PARAMETER(rot);
		//UNREFERENCED_PARAMETER(scale);

		// skip non-active object
		if ((pInst->flag & FLAG_ACTIVE) == 0)
			continue;

		// Compute the scaling matrix
		AEMtx33Scale(&scale, pInst->scale, pInst->scale);
		// Compute the rotation matrix 
		AEMtx33Rot(&rot, pInst->dirCurr);
		// Compute the translation matrix
		AEMtx33Trans(&trans, pInst->posCurr.x, pInst->posCurr.y);
		// Concatenate the 3 matrix in the correct order in the object instance's "transform" matrix
		AEMtx33Concat(&pInst->transform, &rot, &scale);
		AEMtx33Concat(&pInst->transform, &trans, &pInst->transform);
	}
}

/******************************************************************************/
/*!
	"Draw" function of this state
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
		
		// Set the current object instance's transform matrix using "AEGfxSetTransform"
		// Draw the shape used by the current object instance using "AEGfxMeshDraw"
		AEGfxSetTransform(pInst->transform.m);
		AEGfxMeshDraw(pInst->pObject->pMesh, AE_GFX_MDM_TRIANGLES);
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
		else if (sScore >= 5000) {
			printf("YOU ROCK\n");
		}

		onValueChange = false;
	}
}

/******************************************************************************/
/*!
	"Free" function of this state	
*/
/******************************************************************************/
void GameStateAsteroidsFree(void)
{
	// kill all object instances in the array using "gameObjInstDestroy"
	for (auto& c : sGameObjInstList) {
		gameObjInstDestroy(&c);
	}
}

/******************************************************************************/
/*!
	"Unload" function of this state	
*/
/******************************************************************************/
void GameStateAsteroidsUnload(void)
{
	// free all mesh data (shapes) of each object using "AEGfxTriFree"
	for (auto& c : sGameObjList) {
		if(c.pMesh)
			AEGfxMeshFree(c.pMesh);
	}
	
}

/******************************************************************************/
/*!
	\brief		Creates a game object instance if available slot found in main game object list
	\param[in]	type	-> type of game object
	\param[in]	scale	-> size of game object
	\param[in]	pPos	-> starting position of game object
	\param[in]	pVel	-> starting velocity of game object
	\param[in]	dir		-> direction game object is facing towards
	\returns	a pointer to instance of an object in a slot on the main object instance list
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
	\brief		Set a game object to be free for overrided with new values
	\param[in]	pInst	-> pointer to object instance to be flagged as available to override
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


/******************************************************************************/
/*!
	\brief		Function to generate a asteroid of random size at random location
*/
/******************************************************************************/
void GenerateAsteroid() {

	AEVec2 posCurr{ 0 }, velCurr{ 0 }, relCurr{ 0 };
	f32 angle{ 0 }, scale{ 0 }, spawnbuffer = 10.f;
	/*Creation of Asteroid Requires
	Direction: Radians (Random)
	Velocity: Random
	Position: Random
	*/
	
	//Generating size for game object
	scale = 20.f + (rand() % 4) * 10, spawnbuffer += (scale / 2.f);
	angle = AERandFloat() * 2 * PI;
	int dir = rand() % 2 == 0 ? -1 : 1;
	AEVec2Set(&velCurr, cosf(angle) * dir, sinf(angle) * dir);
	//Generate Random Position
	//Position will be re-generated if it is too close to player
	do {
		//Combination of generating in 4 quadrants of the screen
		dir = rand() % 2 == 0 ? -1 : 1;
		posCurr.x = AERandFloat() * AEGfxGetWinMaxX() * dir;
		dir = rand() % 2 == 0 ? -1 : 1;
		posCurr.y = AERandFloat() * AEGfxGetWinMaxY() * dir;
		AEVec2Sub(&relCurr, &spShip->posCurr, &posCurr);
	} while (AEVec2Length(&relCurr) <= spawnbuffer);

	//calling to set a game object on the main list
	gameObjInstCreate(TYPE_ASTEROID, scale, &posCurr, &velCurr, angle);
}
