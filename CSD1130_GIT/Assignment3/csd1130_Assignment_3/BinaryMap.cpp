/******************************************************************************/
/*!
\file		BinaryMap.cpp
\author 	Yong Yip Han, Edgar
\par    	email: y.yiphanedgar\@digipen.edu
\date   	February 14, 2023
\brief		This file contains six functions that load and unload map data from
			text files and check/determine collisions using a Binary Collision Map.

Copyright (C) 2023 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior 
written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/


#include "BinaryMap.h"
#include <iostream>
#include <fstream>



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
	std::ifstream ifs{ FileName };
	if (!ifs)
		return 0;
	
	//Hold trash line of "Width" and "Height"
	std::string B;
	//First Line = Width
	ifs >> B >> BINARY_MAP_WIDTH;
	//Second Line = Height
	ifs >> B >> BINARY_MAP_HEIGHT;
	//Init two nested array
	/*TODO: DONE
	* Get Map Array
	* Get Binary Collision Array
	*/
	MapData = new int* [BINARY_MAP_HEIGHT];
	BinaryCollisionArray = new int* [BINARY_MAP_HEIGHT];
	for (int i{}, t{}; i < BINARY_MAP_HEIGHT; i++) {
		MapData[i] = new int[BINARY_MAP_WIDTH];
		BinaryCollisionArray[i] = new int[BINARY_MAP_WIDTH];
		for (int j{}; j < BINARY_MAP_WIDTH; j++) {
			ifs >> t;
			MapData[i][j] = t;
			BinaryCollisionArray[i][j] = t == 1 ? 1 : 0;
		}
	}
	ifs.close();

	return 1;
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
	
	for (int i{}; i < BINARY_MAP_HEIGHT; i++) {
		delete[] MapData[i];
		delete[] BinaryCollisionArray[i];
	}
	delete[] MapData;
	delete[] BinaryCollisionArray;

}

/******************************************************************************/
/*!
	This function prints out the content of the 2D array “MapData”
	You must print to the console, the same information you are reading from "Exported.txt" file
	Follow exactly the same format of the file, including the print of the width and the height
	Add spaces and end lines at convenient places
 */
/******************************************************************************/
void PrintRetrievedInformation(void)
{
	std::cout << " Width: " << BINARY_MAP_WIDTH << std::endl;
	std::cout << "Height: " << BINARY_MAP_HEIGHT << std::endl;
	for (int i{}; i < BINARY_MAP_HEIGHT; i++) {
		for (int j{}; j < BINARY_MAP_WIDTH; j++) {
			std::cout << MapData[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
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
	if (0 <= X && X < BINARY_MAP_WIDTH && 0 <= Y && Y < BINARY_MAP_HEIGHT)
		return BinaryCollisionArray[Y][X];
	//else
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
	*Coordinate = (int)*Coordinate + 0.5f;
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
	//if value == 1 => sprite in a solid area
	/*if (GetCellValue(int(PosX), int(PosY)))
		return 1;*/


	float lx1, ly1, lx2, ly2;
	float rx1, ry1, rx2, ry2;
	float tx1, ty1, tx2, ty2;
	float bx1, by1, bx2, by2;
	//Creating Hotspots
	//Left two
	lx1 = PosX - scaleX / 2.f;
	ly1 = PosX + scaleY / 4.f;

	lx2 = PosX - scaleX / 2.f;
	ly2 = PosY - scaleY / 4.f;
	//Right two
	rx1 = PosX + scaleX / 2.f;
	ry1 = PosX + scaleY / 4.f;

	rx2 = PosX + scaleX / 2.f;
	ry2 = PosY - scaleY / 4.f;
	//Top two
	tx1 = PosX + scaleX / 4.f;
	ty1 = PosY + scaleY / 2.f;

	tx2 = PosX - scaleX / 4.f;
	ty2 = PosY + scaleY / 2.f;
	//Bottom two
	bx1 = PosX + scaleX / 4.f;
	by1 = PosY - scaleY / 2.f;

	bx2 = PosX - scaleX / 4.f;
	by2 = PosY - scaleY / 2.f;

	
	int FLAG = 0;
	//check left
	FLAG = GetCellValue(int(lx1), int(ly1)) ? FLAG | COLLISION_LEFT : FLAG;
	FLAG = GetCellValue(int(lx2), int(ly2)) ? FLAG | COLLISION_LEFT : FLAG;
	//check right 
	FLAG = GetCellValue(int(rx1), int(ry1)) ? FLAG | COLLISION_RIGHT : FLAG;
	FLAG = GetCellValue(int(rx2), int(ry2)) ? FLAG | COLLISION_RIGHT : FLAG;
	//check top
	FLAG = GetCellValue(int(tx1), int(ty1)) ? FLAG | COLLISION_TOP : FLAG;
	FLAG = GetCellValue(int(tx2), int(ty2)) ? FLAG | COLLISION_TOP : FLAG;
	//check btm
	FLAG = GetCellValue(int(bx1), int(by1)) ? FLAG | COLLISION_BOTTOM : FLAG;
	FLAG = GetCellValue(int(bx2), int(by2)) ? FLAG | COLLISION_BOTTOM : FLAG;
	
	/*
	* Test Output 
	std::cout << "Center:          (" << PosX << "," << PosY << ")" << std::endl;
	std::cout << "Left Hotspot 1:  (" << lx1 << "," << ly1 << ")" << std::endl;
	std::cout << "Left Hotspot 2:  (" << lx2 << "," << ly2 << ")" << std::endl;
	std::cout << "Right Hotspot 1: (" << rx1 << "," << ry1 << ")" << std::endl;
	std::cout << "Right Hotspot 2: (" << rx2 << "," << ry2 << ")" << std::endl;
	std::cout << "Top Hotspot 1:   (" << tx1 << "," << ty1 << ")" << std::endl;
	std::cout << "Top Hotspot 2:   (" << tx2 << "," << ty2 << ")" << std::endl;
	std::cout << "Btm Hotspot 1:   (" << bx1 << "," << by1 << ")" << std::endl;
	std::cout << "Btm Hotspot 2:   (" << bx2 << "," << by2 << ")" << std::endl;
	std::cout << std::internal << std::hex << std::showbase << FLAG << std::endl;
	*/
	return FLAG;
}