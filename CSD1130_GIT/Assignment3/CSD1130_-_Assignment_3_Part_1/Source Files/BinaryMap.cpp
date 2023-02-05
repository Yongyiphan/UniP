/******************************************************************************/
/*!
\file		BinaryMap.cpp
\author 	DigiPen
\par    	email: digipen\@digipen.edu
\date   	February 1, 20xx
\brief		This file contains six functions that load and unload map data from
			text files and check/determine collisions using a Binary Collision Map.

Copyright (C) 20xx DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior 
written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/


#include "BinaryMap.h"



/*The number of horizontal elements*/
static int BINARY_MAP_WIDTH;

/*The number of vertical elements*/
static int BINARY_MAP_HEIGHT;

/*This will contain all the data of the map, which will be retreived from a file
when the "ImportMapDataFromFile" function is called*/
static int **MapData;

/*This will contain the collision data of the binary map. It will be filled in the 
"ImportMapDataFromFile" after filling "MapData". Basically, if an array element 
in MapData is 1, it represents a collision cell, any other value is a non-collision
cell*/
static int **BinaryCollisionArray;


/******************************************************************************/
/*!
	This function opens the file name "FileName" and retrieves all the map data.
	It allocates memory for the 2 arrays: MapData & BinaryCollisionArray
	The first line in this file is the width of the map.
	The second line in this file is the height of the map.
	The remaining part of the file is a series of numbers
	Each number represents the ID (or value) of a different element in the 
	double dimensionaly array.

	Example:

	Width 5
	Height 5
	1 1 1 1 1
	1 1 1 3 1
	1 4 2 0 1
	1 0 0 0 1
	1 1 1 1 1


	After importing the above data, "MapData" and " BinaryCollisionArray" 
	should be

	1 1 1 1 1
	1 1 1 3 1
	1 4 2 0 1
	1 0 0 0 1
	1 1 1 1 1

	and

	1 1 1 1 1
	1 1 1 0 1
	1 0 0 0 1
	1 0 0 0 1
	1 1 1 1 1

	respectively.
	
	Finally, the function returns 1 if the file named "FileName" exists, 
	otherwise it returns 0
 */
/******************************************************************************/
int ImportMapDataFromFile(const char *FileName)
{

	return 0;
}

/******************************************************************************/
/*!
	This function frees the memory that was allocated for the 2 arrays MapData 
	& BinaryCollisionArray which was allocated in the "ImportMapDataFromFile" 
	function
 */
/******************************************************************************/
void FreeMapData(void)
{
	
}

/******************************************************************************/
/*!
	This function prints out the content of the 2D array �MapData�
	You must print to the console, the same information you are reading from "Exported.txt" file
	Follow exactly the same format of the file, including the print of the width and the height
	Add spaces and end lines at convenient places
 */
/******************************************************************************/
void PrintRetrievedInformation(void)
{
	
}

/******************************************************************************/
/*!
	This function retrieves the value of the element (X;Y) in BinaryCollisionArray.
	Before retrieving the value, it should check that the supplied X and Y values
	are not out of bounds (in that case return 0)
 */
/******************************************************************************/
int GetCellValue(int X, int Y)
{
	return 0;
}

/******************************************************************************/
/*!
	This function snaps the value sent as parameter to the center of the cell.
	It is used when a sprite is colliding with a collision area from one 
	or more side.
	To snap the value sent by "Coordinate", find its integral part by type 
	casting it to an integer, then add 0.5 (which is half the cell's width 
	or height)
 */
/******************************************************************************/
void SnapToCell(float *Coordinate)
{
	
}

/******************************************************************************/
/*!
	This function creates 2 hot spots on each side of the object instance, 
	and checks if each of these hot spots is in a collision area (which means 
	the cell if falls in has a value of 1).
	At the beginning of the function, a "Flag" integer should be initialized to 0.
	Each time a hot spot is in a collision area, its corresponding bit 
	in "Flag" is set to 1.
	Finally, the function returns the integer "Flag"
	The position of the object instance is received as PosX and PosY
	The size of the object instance is received as scaleX and scaleY

	Note: This function assume the object instance's size is 1 by 1 
		  (the size of 1 tile)

	Creating the hotspots:
		-Handle each side separately.
		-2 hot spots are needed for each collision side.
		-These 2 hot spots should be positioned on 1/4 above the center 
		and 1/4 below the center

	Example: Finding the hots spots on the left side of the object instance

	float x1, y1, x2, y2;

	-hotspot 1
	x1 = PosX + scaleX/2	To reach the right side
	y1 = PosY + scaleY/4	To go up 1/4 of the height
	
	-hotspot 2
	x2 = PosX + scaleX/2	To reach the right side
	y2 = PosY - scaleY/4	To go down 1/4 of the height
 */
/******************************************************************************/
int CheckInstanceBinaryMapCollision(float PosX, float PosY, 
									float scaleX, float scaleY)
{

	return 0;
}