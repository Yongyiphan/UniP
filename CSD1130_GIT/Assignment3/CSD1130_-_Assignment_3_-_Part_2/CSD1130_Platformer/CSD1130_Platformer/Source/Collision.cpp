/******************************************************************************/
/*!
\file		Collision.cpp
\author 	Edgar Yong
\par    	email: y.yiphanedgar\@digipen.edu
\date   	March 6, 2023
\brief		This file contains definition for the Axis Aligned Bounding Box Collision 
			between two rectangle.

Copyright (C) 20xx DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#include "main.h"

/**************************************************************************/
/*!
	Check for collision between two rectangle object using bounding box	
*/
/**************************************************************************/
bool CollisionIntersection_RectRect(const AABB& aabb1, const AEVec2& vel1,
	const AABB& aabb2, const AEVec2& vel2)
{
	AABB a = aabb1, b = aabb2;
	//UNREFERENCED_PARAMETER(aabb1);
	//UNREFERENCED_PARAMETER(vel1);
	//UNREFERENCED_PARAMETER(aabb2);
	//UNREFERENCED_PARAMETER(vel2);

	//Implement the collision intersection over here.
	/*
	The steps are:
	Step 1: Check for collision detection between rectangles (assuming static here).
			If the check returns no overlap you continue with the following steps.
	*/
	if ((a.max.x < b.min.x || a.max.y < b.min.y) ||
		(a.min.x > b.max.x || a.min.y > b.max.y)) {
		/*
		Step 2: Initialize and calculate the new velocity of Vb
				tFirst = 0
				tLast = dt
		*/
		AEVec2 vb{ vel2.x - vel1.x, vel2.y - vel1.y }, tFirst, tLast{ g_dt, g_dt };
		AEVec2Zero(&tFirst);

		/*
		Step 3: Working with one dimension (x-axis).
				if(Vb < 0)
					case 1
					case 4
				if(Vb > 0)
					case 2
					case 3

				case 5
		*/
		//X-axis case
		if (vb.x < 0)
		{
			//Case 1
			if (a.min.x > b.max.x)
				return false;
			//Case 4 tFirst
			if (a.max.x < b.min.x)
				tFirst.x = max((a.max.x - b.min.x) / vb.x, tFirst.x);
			//Case 4 tLast
			if (a.min.x < b.max.x)
				tLast.x = min((a.min.x - b.max.x) / vb.x, tLast.x);
		}
		else
		{
			//Case 2 tFirst
			if (a.min.x > b.max.x)
				tFirst.x = max((a.min.x - b.max.x) / vb.x, tFirst.x);
			//Case 2 tLast
			if (a.max.x > b.min.x)
				tLast.x = min((a.max.x - b.min.x) / vb.x, tLast.x);
			//Case 3
			if (a.max.x < b.min.x)
				return false;
		}
		//Step 4: Repeat step 3 on the y-axis
		//Y-axis case
		if (vb.y < 0)
		{
			if (a.min.y > b.max.y) //case 1
				return false;
			//Case 4 tFirst
			if (a.max.y < b.min.y)
				tFirst.y = max((a.max.y - b.min.y) / vb.y, tFirst.y);
			//Case 4 tLast
			if (a.min.y < b.max.y)
				tLast.y = min((a.min.y - b.max.y) / vb.y, tLast.y);
		}
		else
		{
			//Case 2 tFirst
			if (a.min.y > b.max.y)
				tFirst.y = max((a.min.y - b.max.y) / vb.y, tFirst.y);
			//Case 2 tLast
			if (a.max.y > b.min.y)
				tLast.y = min((a.max.y - b.min.y) / vb.y, tLast.y);
			if (a.max.y < b.min.y)
				return false;
		}

		if (tFirst.x > tLast.x && tFirst.y > tLast.y) {
			return false;
		}
		if (tFirst.y > tLast.x || tFirst.x > tLast.y) {
			return false;
		}
		//Check if boxes will collide within next frame
		if (tFirst.x > tFirst.y) {
			if (tFirst.x < 0 || tFirst.x > g_dt) {
				return false;
			}
		}
		else {
			if (tFirst.y < 0 || tFirst.y > g_dt) {
				return false;
			}
		}
	}


	//Step 5: Otherwise the rectangles intersect

	return true;
}