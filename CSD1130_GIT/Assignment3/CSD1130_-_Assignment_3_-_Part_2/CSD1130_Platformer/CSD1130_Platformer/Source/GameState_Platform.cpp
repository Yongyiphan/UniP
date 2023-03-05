/******************************************************************************/
/*!
\file		GameState_Asteroids.cpp
\author 	DigiPen
\par    	email: digipen\@digipen.edu
\date   	February 01, 20xx
\brief

Copyright (C) 20xx DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#include "main.h"
#include <fstream>
#include <iostream>

/******************************************************************************/
/*!
	Defines
*/
/******************************************************************************/
const unsigned int	GAME_OBJ_NUM_MAX		= 32;	//The total number of different objects (Shapes)
const unsigned int	GAME_OBJ_INST_NUM_MAX	= 2048;	//The total number of different game object instances

//Gameplay related variables and values
const float			GRAVITY					= -20.0f;
const float			JUMP_VELOCITY			= 11.0f;
const float			MOVE_VELOCITY_HERO		= 4.0f;
const float			MOVE_VELOCITY_ENEMY		= 7.5f;
const double		ENEMY_IDLE_TIME			= 2.0;
const int			HERO_LIVES				= 3;
const float			BOUNDING_RECT_SIZE		= 0.5f;

//Flags
const unsigned int	FLAG_ACTIVE				= 0x00000001;
const unsigned int	FLAG_VISIBLE			= 0x00000002;
const unsigned int	FLAG_NON_COLLIDABLE		= 0x00000004;

//Collision flags
const unsigned int	COLLISION_LEFT			= 0x00000001;	//0001
const unsigned int	COLLISION_RIGHT			= 0x00000002;	//0010
const unsigned int	COLLISION_TOP			= 0x00000004;	//0100
const unsigned int	COLLISION_BOTTOM		= 0x00000008;	//1000


enum TYPE_OBJECT
{
	TYPE_OBJECT_EMPTY,			//0
	TYPE_OBJECT_COLLISION,		//1
	TYPE_OBJECT_HERO,			//2
	TYPE_OBJECT_ENEMY1,			//3
	TYPE_OBJECT_COIN			//4
};

//State machine states
enum STATE
{
	STATE_NONE,
	STATE_GOING_LEFT,
	STATE_GOING_RIGHT
};

//State machine inner states
enum INNER_STATE
{
	INNER_STATE_ON_ENTER,
	INNER_STATE_ON_UPDATE,
	INNER_STATE_ON_EXIT
};

/******************************************************************************/
/*!
	Struct/Class Definitions
*/
/******************************************************************************/
struct GameObj
{
	unsigned int		type;		// object type
	AEGfxVertexList *	pMesh;		// pbject
};


struct GameObjInst
{
	GameObj *		pObject;	// pointer to the 'original'
	unsigned int	flag;		// bit flag or-ed together
	float			scale;
	AEVec2			posCurr;	// object current position
	AEVec2			velCurr;	// object current velocity
	float			dirCurr;	// object current direction

	AEMtx33			transform;	// object drawing matrix
	
	AABB			boundingBox;// object bouding box that encapsulates the object

	//Used to hold the current 
	int				gridCollisionFlag;

	// pointer to custom data specific for each object type
	void*			pUserData;

	//State of the object instance
	enum			STATE state;
	enum			INNER_STATE innerState;

	//General purpose counter (This variable will be used for the enemy state machine)
	double			counter;
};


/******************************************************************************/
/*!
	File globals
*/
/******************************************************************************/
static int				HeroLives;
static int				Hero_Initial_X;
static int				Hero_Initial_Y;
static int				TotalCoins;

// list of original objects
static GameObj			*sGameObjList;
static unsigned int		sGameObjNum;

// list of object instances
static GameObjInst		*sGameObjInstList;
static unsigned int		sGameObjInstNum;

//Binary map data
static int				**MapData;
static int				**BinaryCollisionArray;
static int				BINARY_MAP_WIDTH;
static int				BINARY_MAP_HEIGHT;
static GameObjInst		*pBlackInstance;
static GameObjInst		*pWhiteInstance;
static AEMtx33			MapTransform;

int						GetCellValue(int X, int Y);
int						CheckInstanceBinaryMapCollision(float PosX, float PosY, 
														float scaleX, float scaleY);
void					SnapToCell(float *Coordinate);
int						ImportMapDataFromFile(char *FileName);
void					FreeMapData(void);

// function to create/destroy a game object instance
static GameObjInst*		gameObjInstCreate (unsigned int type, float scale, 
											AEVec2* pPos, AEVec2* pVel, 
											float dir, enum STATE startState);
static void				gameObjInstDestroy(GameObjInst* pInst);

//We need a pointer to the hero's instance for input purposes
static GameObjInst		*pHero;

//State machine functions
void					EnemyStateMachine(GameObjInst *pInst);


void					PrintRetrievedInformation(void);

/******************************************************************************/
/*!

*/
/******************************************************************************/
void GameStatePlatformLoad(void)
{
	
	sGameObjList	 = (GameObj *)calloc(GAME_OBJ_NUM_MAX, sizeof(GameObj));
	sGameObjInstList = (GameObjInst *)calloc(GAME_OBJ_INST_NUM_MAX, sizeof(GameObjInst));
	sGameObjNum = 0;


	GameObj* pObj;

	//Creating the black object
	pObj		= sGameObjList + sGameObjNum++;
	pObj->type	= TYPE_OBJECT_EMPTY;


	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.5f, -0.5f, 0xFF000000, 0.0f, 0.0f,
		 0.5f,  -0.5f, 0xFF000000, 0.0f, 0.0f, 
		-0.5f,  0.5f, 0xFF000000, 0.0f, 0.0f);
	
	AEGfxTriAdd(
		-0.5f, 0.5f, 0xFF000000, 0.0f, 0.0f,
		 0.5f,  -0.5f, 0xFF000000, 0.0f, 0.0f, 
		0.5f,  0.5f, 0xFF000000, 0.0f, 0.0f);

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");
		
	
	//Creating the white object
	pObj		= sGameObjList + sGameObjNum++;
	pObj->type	= TYPE_OBJECT_COLLISION;


	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.5f, -0.5f, 0xFFFFFFFF, 0.0f, 0.0f,
		 0.5f,  -0.5f, 0xFFFFFFFF, 0.0f, 0.0f, 
		-0.5f,  0.5f, 0xFFFFFFFF, 0.0f, 0.0f);
	
	AEGfxTriAdd(
		-0.5f, 0.5f, 0xFFFFFFFF, 0.0f, 0.0f, 
		 0.5f,  -0.5f, 0xFFFFFFFF, 0.0f, 0.0f, 
		0.5f,  0.5f, 0xFFFFFFFF, 0.0f, 0.0f);

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");


	//Creating the hero object
	pObj		= sGameObjList + sGameObjNum++;
	pObj->type	= TYPE_OBJECT_HERO;


	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.5f, -0.5f, 0xFF0000FF, 0.0f, 0.0f, 
		 0.5f,  -0.5f, 0xFF0000FF, 0.0f, 0.0f, 
		-0.5f,  0.5f, 0xFF0000FF, 0.0f, 0.0f);
	
	AEGfxTriAdd(
		-0.5f, 0.5f, 0xFF0000FF, 0.0f, 0.0f,
		 0.5f,  -0.5f, 0xFF0000FF, 0.0f, 0.0f, 
		0.5f,  0.5f, 0xFF0000FF, 0.0f, 0.0f);

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");


	//Creating the enemey1 object
	pObj		= sGameObjList + sGameObjNum++;
	pObj->type	= TYPE_OBJECT_ENEMY1;


	AEGfxMeshStart();
	AEGfxTriAdd(
		-0.5f, -0.5f, 0xFFFF0000, 0.0f, 0.0f, 
		 0.5f,  -0.5f, 0xFFFF0000, 0.0f, 0.0f, 
		-0.5f,  0.5f, 0xFFFF0000, 0.0f, 0.0f);
	
	AEGfxTriAdd(
		-0.5f, 0.5f, 0xFFFF0000, 0.0f, 0.0f, 
		 0.5f,  -0.5f, 0xFFFF0000, 0.0f, 0.0f, 
		0.5f,  0.5f, 0xFFFF0000, 0.0f, 0.0f);

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");


	//Creating the Coin object
	pObj		= sGameObjList + sGameObjNum++;
	pObj->type	= TYPE_OBJECT_COIN;


	AEGfxMeshStart();
	//Creating the circle shape
	int Parts = 12;
	for(float i = 0; i < Parts; ++i)
	{
		AEGfxTriAdd(
		0.0f, 0.0f, 0xFFFFFF00, 0.0f, 0.0f, 
		cosf(i*2*PI/Parts)*0.5f,  sinf(i*2*PI/Parts)*0.5f, 0xFFFFFF00, 0.0f, 0.0f, 
		cosf((i+1)*2*PI/Parts)*0.5f,  sinf((i+1)*2*PI/Parts)*0.5f, 0xFFFFFF00, 0.0f, 0.0f);
	}

	pObj->pMesh = AEGfxMeshEnd();
	AE_ASSERT_MESG(pObj->pMesh, "fail to create object!!");

	//Setting intital binary map values
	MapData = 0;
	BinaryCollisionArray = 0;
	BINARY_MAP_WIDTH = 0;
	BINARY_MAP_HEIGHT = 0;

	//Importing Data
	s8* FileToLoad{};
	switch (gGameStateCurr) {
	case GS_LEVEL1:
		FileToLoad = "../Resources/Levels/Exported.txt";
		break;
	case GS_LEVEL2:
		FileToLoad = "../Resources/Levels/Exported2.txt";
		break;
	}
	if(!ImportMapDataFromFile(FileToLoad))
		gGameStateNext = GS_QUIT;
	
	PrintRetrievedInformation();

	//Computing the matrix which take a point out of the normalized coordinates system
	//of the binary map
	/***********
	Compute a transformation matrix and save it in "MapTransform".
	This transformation transforms any point from the normalized coordinates system of the binary map.
	Later on, when rendering each object instance, we should concatenate "MapTransform" with the
	object instance's own transformation matrix

	Compute a translation matrix (-Grid width/2, -Grid height/2) and save it in "trans"
	Compute a scaling matrix and save it in "scale". The scale must account for the window width and height.
		Alpha engine has 2 helper functions to get the window width and height: AEGetWindowWidth() and AEGetWindowHeight()
	Concatenate scale and translate and save the result in "MapTransform"
	***********/
	AEMtx33 scale, trans;

	//UNREFERENCED_PARAMETER(scale);
	//UNREFERENCED_PARAMETER(trans);
	AEMtx33Trans(&trans, -winw / 2.f, -winh / 2.f);
	AEMtx33Scale(&scale, winw/BINARY_MAP_WIDTH, winh/BINARY_MAP_HEIGHT);
	AEMtx33Concat(&MapTransform, &trans, &scale);
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
void GameStatePlatformInit(void)
{
	int i, j;
	UNREFERENCED_PARAMETER(j);

	pHero = 0;
	pBlackInstance = 0;
	pWhiteInstance = 0;
	TotalCoins = 0;

	//Create an object instance representing the black cell.
	//This object instance should not be visible. When rendering the grid cells, each time we have
	//a non collision cell, we position this instance in the correct location and then we render it
	pBlackInstance = gameObjInstCreate(TYPE_OBJECT_EMPTY, 1.0f, 0, 0, 0.0f, STATE_NONE);
	pBlackInstance->flag ^= FLAG_VISIBLE;
	pBlackInstance->flag |= FLAG_NON_COLLIDABLE;

	//Create an object instance representing the white cell.
	//This object instance should not be visible. When rendering the grid cells, each time we have
	//a collision cell, we position this instance in the correct location and then we render it
	pWhiteInstance = gameObjInstCreate(TYPE_OBJECT_COLLISION, 1.0f, 0, 0, 0.0f, STATE_NONE);
	pWhiteInstance->flag ^= FLAG_VISIBLE;
	pWhiteInstance->flag |= FLAG_NON_COLLIDABLE;

	//Setting the inital number of hero lives
	HeroLives = HERO_LIVES;

	GameObjInst *pInst;
	AEVec2 Pos;

	//UNREFERENCED_PARAMETER(pInst);
	//UNREFERENCED_PARAMETER(Pos);

	// creating the main character, the enemies and the coins according 
	// to their initial positions in MapData

	/***********
	Loop through all the array elements of MapData 
	(which was initialized in the "GameStatePlatformLoad" function
	from the .txt file
		if the element represents a collidable or non collidable area
			don't do anything

		if the element represents the hero
			Create a hero instance
			Set its position depending on its array indices in MapData
			Save its array indices in Hero_Initial_X and Hero_Initial_Y 
			(Used when the hero dies and its position needs to be reset)

		if the element represents an enemy
			Create an enemy instance
			Set its position depending on its array indices in MapData
			
		if the element represents a coin
			Create a coin instance
			Set its position depending on its array indices in MapData
			
	***********/
	for(i = 0; i < BINARY_MAP_HEIGHT; ++i)
		for(j = 0; j < BINARY_MAP_WIDTH; ++j)
		{
			AEVec2Set(&Pos, (f32)i + 0.5f, (f32)j + 0.5f);
			switch (MapData[j][i]) {
			case TYPE_OBJECT_EMPTY:
				continue;
			case TYPE_OBJECT_COLLISION:
				continue;
			case TYPE_OBJECT_HERO:
				Hero_Initial_X = i;
				Hero_Initial_Y = j;
				pHero = gameObjInstCreate(TYPE_OBJECT_HERO,		1.f, &Pos, 0, 0.f, STATE_NONE);
				printf("Creating Hero\n");
				break;
			case TYPE_OBJECT_ENEMY1:
				pInst = gameObjInstCreate(TYPE_OBJECT_ENEMY1,	1.f, &Pos, 0, 0.f, STATE_GOING_RIGHT);
				printf("Creating Enemy\n");
				break;
			case TYPE_OBJECT_COIN:
				++TotalCoins;
				pInst = gameObjInstCreate(TYPE_OBJECT_COIN,		1.f, &Pos, 0, 0.f, STATE_NONE);
				break;
			}
			
		}
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
void GameStatePlatformUpdate(void)
{
	int i, j;
	GameObjInst *pInst;

	UNREFERENCED_PARAMETER(j);
	//UNREFERENCED_PARAMETER(pInst);
	//Handle Input
	/***********
	if right is pressed
		Set hero velocity X to MOVE_VELOCITY_HERO
	else
	if left is pressed
		Set hero velocity X to -MOVE_VELOCITY_HERO
	else
		Set hero velocity X to 0

	if space is pressed AND Hero is colliding from the bottom
		Set hero velocity Y to JUMP_VELOCITY

	if Escape is pressed
		Exit to menu
	***********/
	if (AEInputCheckCurr(AEVK_RIGHT)) {
		pHero->velCurr.x = MOVE_VELOCITY_HERO;
		
	}
	else if (AEInputCheckCurr(AEVK_LEFT)) {
		pHero->velCurr.x = -MOVE_VELOCITY_HERO;
	}
	else{
		pHero->velCurr.x = 0;
	}
	if (AEInputCheckTriggered(AEVK_SPACE)) {
		pHero->velCurr.y = JUMP_VELOCITY;
	}


	//Update object instances physics and behavior
	for(i = 0; i < GAME_OBJ_INST_NUM_MAX; ++i)
	{
		pInst = sGameObjInstList + i;

		// skip non-active object
		if (0 == (pInst->flag & FLAG_ACTIVE))
			continue;


		/****************
		Apply gravity
			Velocity Y = Gravity * Frame Time + Velocity Y

		If object instance is an enemy
			Apply enemy state machine
		****************/
		if (pInst->pObject->type != TYPE_OBJECT_COIN) {
			pInst->velCurr.y += GRAVITY * g_dt;
		}
		if (pInst->pObject->type == TYPE_OBJECT_ENEMY1) {
			//EnemyStateMachine(pInst);
		}
		
	}

	//Update object instances positions
	for(i = 0; i < GAME_OBJ_INST_NUM_MAX; ++i)
	{
		pInst = sGameObjInstList + i;

		// skip non-active object
		if (0 == (pInst->flag & FLAG_ACTIVE))
			continue;

		/**********
		update the position using: P1 = V1*dt + P0
		Get the bouding rectangle of every active instance:
			boundingRect_min = -BOUNDING_RECT_SIZE * instance->scale + instance->pos
			boundingRect_max = BOUNDING_RECT_SIZE * instance->scale + instance->pos
		**********/
		AEVec2 scale;
		AEVec2Scale(&scale, &pInst->velCurr, g_dt);
		AEVec2Add(&pInst->posCurr, &scale, &pInst->posCurr);

		pInst->boundingBox.min.x = -BOUNDING_RECT_SIZE * pInst->scale + pInst->posCurr.x;
		pInst->boundingBox.min.y = -BOUNDING_RECT_SIZE * pInst->scale + pInst->posCurr.y;
		pInst->boundingBox.max.x =  BOUNDING_RECT_SIZE * pInst->scale + pInst->posCurr.x;
		pInst->boundingBox.max.y =  BOUNDING_RECT_SIZE * pInst->scale + pInst->posCurr.y;

	}

	//Check for grid collision
	for(i = 0; i < GAME_OBJ_INST_NUM_MAX; ++i)
	{
		pInst = sGameObjInstList + i;

		// skip non-active object instances
		if (0 == (pInst->flag & FLAG_ACTIVE))
			continue;

		/*************
		Update grid collision flag

		if collision from bottom
			Snap to cell on Y axis
			Velocity Y = 0

		if collision from top
			Snap to cell on Y axis
			Velocity Y = 0
	
		if collision from left
			Snap to cell on X axis
			Velocity X = 0

		if collision from right
			Snap to cell on X axis
			Velocity X = 0
		*************/
		pInst->gridCollisionFlag = CheckInstanceBinaryMapCollision(pInst->posCurr.x, pInst->posCurr.y, pInst->scale, pInst->scale);
		if (pInst->pObject->type == TYPE_OBJECT_HERO)
			std::cout << pInst->gridCollisionFlag << std::endl;
		if (pInst->gridCollisionFlag & COLLISION_BOTTOM) {
			SnapToCell(&pInst->posCurr.y);
			pInst->velCurr.y = 0;
		}
		if (pInst->gridCollisionFlag & COLLISION_TOP) {
			SnapToCell(&pInst->posCurr.y);
			pInst->velCurr.y = 0;
		}
		if (pInst->gridCollisionFlag & COLLISION_LEFT) {
			SnapToCell(&pInst->posCurr.x);
			pInst->velCurr.x = 0;
		}
		if (pInst->gridCollisionFlag & COLLISION_RIGHT) {
			SnapToCell(&pInst->posCurr.x);
			pInst->velCurr.x = 0;
		}
	}


	//Checking for collision among object instances:
	//Hero against enemies
	//Hero against coins

	/**********
	for each game object instance
		Skip if it's inactive or if it's non collidable

		If it's an enemy
			If collision between the enemy instance and the hero (rectangle - rectangle)
				Decrement hero lives
				Reset the hero's position in case it has lives left, otherwise RESTART the level

		If it's a coin
			If collision between the coin instance and the hero (rectangle - rectangle)
				Remove the coin and decrement the coin counter.
				Go to level2, in case no more coins are left and you are at Level1.
				Quit the game level to the main menu, in case no more coins are left and you are at Level2.
	**********/
	
	for(i = 0; i < GAME_OBJ_INST_NUM_MAX; ++i)
	{
	}

	
	//Computing the transformation matrices of the game object instances
	for(i = 0; i < GAME_OBJ_INST_NUM_MAX; ++i)
	{
		AEMtx33 scale, rot, trans;
		pInst = sGameObjInstList + i;

		// skip non-active object
		if (0 == (pInst->flag & FLAG_ACTIVE))
			continue;

		AEMtx33Scale(&scale, pInst->scale, pInst->scale);
		AEMtx33Rot(&rot, pInst->dirCurr);
		AEMtx33Trans(&trans, pInst->posCurr.x, pInst->posCurr.y);
		AEMtx33Concat(&pInst->transform, &trans, &rot);
		AEMtx33Concat(&pInst->transform, &pInst->transform , &scale);


		
	}
	
	if (AEInputCheckTriggered(AEVK_P)) {
		PrintRetrievedInformation();
	}
	
	
	// Update Camera position, for Level2
		// To follow the player's position
		// To clamp the position at the level's borders, between (0,0) and and maximum camera position
			// You may use an alpha engine helper function to clamp the camera position: AEClamp()
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
void GameStatePlatformDraw(void)
{
	//Drawing the tile map (the grid)
	int x, y, i;
	AEMtx33 cellTranslation, cellFinalTransformation;

	//UNREFERENCED_PARAMETER(cellTranslation);
	//UNREFERENCED_PARAMETER(cellFinalTransformation);

	//Drawing the tile map

	/******REMINDER*****
	You need to concatenate MapTransform with the transformation matrix 
	of any object you want to draw. MapTransform transform the instance 
	from the normalized coordinates system of the binary map
	*******************/

	/*********
	for each array element in BinaryCollisionArray (2 loops)
		Compute the cell's translation matrix acoording to its 
		X and Y coordinates and save it in "cellTranslation"
		Concatenate MapTransform with the cell's transformation 
		and save the result in "cellFinalTransformation"
		Send the resultant matrix to the graphics manager using "AEGfxSetTransform"

		Draw the instance's shape depending on the cell's value using "AEGfxMeshDraw"
			Use the black instance in case the cell's value is TYPE_OBJECT_EMPTY
			Use the white instance in case the cell's value is TYPE_OBJECT_COLLISION
	*********/
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxTextureSet(NULL, 0, 0);
	for (x = 0; x < BINARY_MAP_WIDTH; ++x) {
		for(y = 0; y < BINARY_MAP_HEIGHT; ++y)
		{
			AEMtx33Identity(&cellTranslation);
			AEMtx33Trans(&cellTranslation, (f32)x + 0.5f, (f32)y + 0.5f);
			AEMtx33Concat(&cellFinalTransformation, &MapTransform, &cellTranslation);
			AEGfxSetTransform(cellFinalTransformation.m);
			switch (BinaryCollisionArray[y][x]) {
			case TYPE_OBJECT_EMPTY:
				AEGfxMeshDraw(pBlackInstance->pObject->pMesh, AE_GFX_MDM_TRIANGLES);
				break;
			case TYPE_OBJECT_COLLISION:
				AEGfxMeshDraw(pWhiteInstance->pObject->pMesh, AE_GFX_MDM_TRIANGLES);
				break;
			}
		}
	}



	//Drawing the object instances
	/**********
	For each active and visible object instance
		Concatenate MapTransform with its transformation matrix
		Send the resultant matrix to the graphics manager using "AEGfxSetTransform"
		Draw the instance's shape using "AEGfxMeshDraw"
	**********/
	for (i = 0; i < GAME_OBJ_INST_NUM_MAX; i++)
	{
		GameObjInst* pInst = sGameObjInstList + i;

		// skip non-active object
		if (0 == (pInst->flag & FLAG_ACTIVE) || 0 == (pInst->flag & FLAG_VISIBLE))
			continue;
		
		//Don't forget to concatenate the MapTransform matrix with the transformation of each game object instance
		AEMtx33Concat(&pInst->transform, &MapTransform, &pInst->transform);
		AEGfxSetTransform(pInst->transform.m);
		
		AEGfxMeshDraw(pInst->pObject->pMesh, AE_GFX_MDM_TRIANGLES);
		AEGfxSetTintColor(1.f, 1.f, 1.f, 1.f);
		AEGfxSetTransparency(1.f);

	}

	char strBuffer[100];
	memset(strBuffer, 0, 100*sizeof(char));
	
	sprintf_s(strBuffer, "Lives:  %i", HeroLives);
	float fontscale = 0.35f;
	AEGfxPrint(FontID, strBuffer, 0.6f, 0.9f, fontscale, 0.f,0.f,1.f);	

	sprintf_s(strBuffer, "Coins Left:  %d", TotalCoins);
	AEGfxPrint(FontID, strBuffer, -0.9f, 0.9f, fontscale, 0.f,0.f,1.f);	
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
void GameStatePlatformFree(void)
{
	// kill all object in the list
	for (unsigned int i = 0; i < GAME_OBJ_INST_NUM_MAX; i++)
		gameObjInstDestroy(sGameObjInstList + i);
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
void GameStatePlatformUnload(void)
{
	// free all CREATED mesh
	for (u32 i = 0; i < sGameObjNum; i++)
		AEGfxMeshFree(sGameObjList[i].pMesh);
	
	free(sGameObjList);
	free(sGameObjInstList);
	/*********
	Free the map data
	*********/
	FreeMapData();

}

/******************************************************************************/
/*!

*/
/******************************************************************************/
GameObjInst* gameObjInstCreate(unsigned int type, float scale, 
							   AEVec2* pPos, AEVec2* pVel, 
							   float dir, enum STATE startState)
{
	AEVec2 zero;
	AEVec2Zero(&zero);

	AE_ASSERT_PARM(type < sGameObjNum);
	
	// loop through the object instance list to find a non-used object instance
	for (unsigned int i = 0; i < GAME_OBJ_INST_NUM_MAX; i++)
	{
		GameObjInst* pInst = sGameObjInstList + i;

		// check if current instance is not used
		if (pInst->flag == 0)
		{
			// it is not used => use it to create the new instance
			pInst->pObject			 = sGameObjList + type;
			pInst->flag				 = FLAG_ACTIVE | FLAG_VISIBLE;
			pInst->scale			 = scale;
			pInst->posCurr			 = pPos ? *pPos : zero;
			pInst->velCurr			 = pVel ? *pVel : zero;
			pInst->dirCurr			 = dir;
			pInst->pUserData		 = 0;
			pInst->gridCollisionFlag = 0;
			pInst->state			 = startState;
			pInst->innerState		 = INNER_STATE_ON_ENTER;
			pInst->counter			 = 0;
			
			// return the newly created instance
			return pInst;
		}
	}

	return 0;
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
void gameObjInstDestroy(GameObjInst* pInst)
{
	// if instance is destroyed before, just return
	if (pInst->flag == 0)
		return;

	// zero out the flag
	pInst->flag = 0;
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
int GetCellValue(int X, int Y)
{
	//UNREFERENCED_PARAMETER(X);
	//UNREFERENCED_PARAMETER(Y);
	if (X >= 0 && X < BINARY_MAP_WIDTH && Y >= 0 && Y < BINARY_MAP_HEIGHT) {
		return BinaryCollisionArray[Y][X];
	}
	return 0;
}

void PrintRetrievedInformation(void)
{
	std::cout << " Width: " << BINARY_MAP_WIDTH << std::endl;
	std::cout << "Height: " << BINARY_MAP_HEIGHT << std::endl;
	for (int i{BINARY_MAP_HEIGHT - 1}; i >= 0; --i) {
		for (int j{}; j < BINARY_MAP_WIDTH; ++j) {
			//std::cout << MapData[i][j] << " ";
			std::cout << BinaryCollisionArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
int CheckInstanceBinaryMapCollision(float PosX, float PosY, float scaleX, float scaleY)
{
	//At the end of this function, "Flag" will be used to determine which sides
	//of the object instance are colliding. 2 hot spots will be placed on each side.

	float lx1, ly1, lx2, ly2;
	float rx1, ry1, rx2, ry2;
	float tx1, ty1, tx2, ty2;
	float bx1, by1, bx2, by2;
	int FLAG = 0;
	//Creating Hotspots
	//Left two
	lx1 = PosX - scaleX / 2.f;
	ly1 = PosX + scaleY / 4.f;

	lx2 = PosX - scaleX / 2.f;
	ly2 = PosY - scaleY / 4.f;
	//check left
	if(GetCellValue((int)lx1, (int)ly2) || GetCellValue((int)lx2, (int)ly2))
		FLAG |= COLLISION_LEFT;
	//Right two
	rx1 = PosX + scaleX / 2.f;
	ry1 = PosX + scaleY / 4.f;

	rx2 = PosX + scaleX / 2.f;
	ry2 = PosY - scaleY / 4.f;
	//check right 
	if(GetCellValue((int)rx1, (int)ry1) || GetCellValue((int)rx2, (int)ry2))
		FLAG |= COLLISION_RIGHT;
	//Top two
	tx1 = PosX - scaleX / 4.f;
	ty1 = PosY + scaleY / 2.f;

	tx2 = PosX + scaleX / 4.f;
	ty2 = PosY + scaleY / 2.f;
	//check top
	if(GetCellValue((int)tx1, (int)ty1) || GetCellValue((int)tx2, (int)ty2))
		FLAG |= COLLISION_TOP;
	//Bottom two
	bx1 = PosX - scaleX / 4.f;
	by1 = PosY - scaleY / 2.f;

	bx2 = PosX + scaleX / 4.f;
	by2 = PosY - scaleY / 2.f;
	//check btm
	if(GetCellValue((int)bx1, (int)by1) || GetCellValue((int)bx2, (int)by2))
		FLAG |= COLLISION_BOTTOM;

	

	return FLAG;
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
void SnapToCell(float *Coordinate)
{
	//UNREFERENCED_PARAMETER(Coordinate);
	*Coordinate = (int)*Coordinate + 0.5f;
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
int ImportMapDataFromFile(char *FileName)
{
	//UNREFERENCED_PARAMETER(FileName);
	std::ifstream ifs{ FileName };
	std::string s;
	if (!ifs)
		return 0;
	ifs >> s >> BINARY_MAP_WIDTH;
	ifs >> s >> BINARY_MAP_HEIGHT;
	MapData				 = new int* [BINARY_MAP_HEIGHT];
	BinaryCollisionArray = new int* [BINARY_MAP_HEIGHT];
	
	if (MapData && BinaryCollisionArray) {
		for (int i = 0; i < BINARY_MAP_HEIGHT; ++i) {
			MapData[i]				= new int[BINARY_MAP_WIDTH];
			BinaryCollisionArray[i] = new int[BINARY_MAP_WIDTH];

			for (int j = 0; j < BINARY_MAP_WIDTH; ++j) {
				int value = 0;
				ifs >> value;
				MapData[i][j]= value;
				BinaryCollisionArray[i][j] = value == 1 ? 1 : 0;

			}
		}
	}
	ifs.close();

	return 1;
}

/******************************************************************************/
/*!

*/
/******************************************************************************/
void FreeMapData(void)
{
	for (int i = 0; i < BINARY_MAP_HEIGHT; i++) {
		delete[] MapData[i];
		delete[] BinaryCollisionArray[i];
	}
	delete[] MapData;
	delete[] BinaryCollisionArray;

}

/******************************************************************************/
/*!

*/
/******************************************************************************/
void EnemyStateMachine(GameObjInst *pInst)
{
	/***********
	This state machine has 2 states: STATE_GOING_LEFT and STATE_GOING_RIGHT
	Each state has 3 inner states: INNER_STATE_ON_ENTER, INNER_STATE_ON_UPDATE, INNER_STATE_ON_EXIT
	Use "switch" statements to determine which state and inner state the enemy is currently in.


	STATE_GOING_LEFT
		INNER_STATE_ON_ENTER
			Set velocity X to -MOVE_VELOCITY_ENEMY
			Set inner state to "on update"

		INNER_STATE_ON_UPDATE
			If collision on left side OR bottom left cell is non collidable
				Initialize the counter to ENEMY_IDLE_TIME
				Set inner state to on exit
				Set velocity X to 0


		INNER_STATE_ON_EXIT
			Decrement counter by frame time
			if counter is less than 0 (sprite's idle time is over)
				Set state to "going right"
				Set inner state to "on enter"

	STATE_GOING_RIGHT is basically the same, with few modifications.

	***********/

	UNREFERENCED_PARAMETER(pInst);
}