/******************************************************************************/
/*!
\file		Collision.cpp
\author 	Yong Yip Han, Edgar
\par    	email: y.yiphanedgar\@digipen.edu
\date   	February 02, 2023
\brief		This File contains the defnitions for functions to
			Check for Collision between 2 rectangular object

Copyright (C) 2023 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/
#include "main.h"

/**************************************************************************/
/*!
	\brief		This function calculates between two rectangle's border to determine
				whether the two rectangle is colliding.
				An Implementation of Axis Aligned Bounding Box (AABB)
	\param[in]	aabb1 -> bounding box of first object
	\param[in]	vel1  -> velocity of first object
	\param[in]	aabb2 -> bounding box of second object
	\param[in]	vel12 -> velocity of second object
	\return		boolean value representing if the two object collides.
	*/
/**************************************************************************/
bool CollisionIntersection_RectRect(const AABB & aabb1, const AEVec2 & vel1, 
									const AABB & aabb2, const AEVec2 & vel2)
{
	UNREFERENCED_PARAMETER(aabb1);
	UNREFERENCED_PARAMETER(vel1);
	UNREFERENCED_PARAMETER(aabb2);
	UNREFERENCED_PARAMETER(vel2);

	/*
	Implement the collision intersection over here.

	The steps are:	
	Step 1: Check for static collision detection between rectangles (before moving). 
				If the check returns no overlap you continue with the following next steps (dynamics).
				Otherwise you return collision true
	*/
	/*
			  1#
			2#
		  1#
		2#
	IF	=>	1.max < 2.min || 1.min > 2.max == no overlap
		=>	1.max < 2.min || 2.max < 1.min
	THEN	1.max > 2.min && 2.max > 1.min == overlap 
	*/
	if ((aabb1.max.x > aabb2.min.x && aabb1.max.y > aabb2.min.y) && 
		(aabb2.max.x > aabb1.min.x && aabb2.max.y > aabb1.min.y)) {
		return true;
	}

	/*Step 2: Initialize and calculate the new velocity of Vb
			tFirst = 0
			tLast = dt
	*/
	AEVec2 vb{ vel2.x - vel1.x, vel2.y - vel1.y }, tFirst{ 0 }, tLast{ f32(AEFrameRateControllerGetFrameTime()), f32(AEFrameRateControllerGetFrameTime()) };
	AABB a = aabb1, b = aabb2;
	/*Step 3: Working with one dimension (x-axis).
			if(Vb < 0)
				case 1
				case 4
			if(Vb > 0)
				case 2
				case 3
			case 5
	*/
	//aabb1  == a, aabb2 == b
	//x-axis
	/*4 cases
	b moving left , right (left of A)
	b moving left , right (right of A)
	*/

	if (vb.x < 0) {
		//case 1
		if (a.min.x > b.max.x) {
			return false;
		}
		//case 4
		if (a.max.x < b.min.x) {
			tFirst.x = (a.max.x - b.min.x) / vb.x;
			tLast.x = (a.min.x - b.max.x) / vb.x;
		}

	}
	else { //vb.x > 0
		//case 2
		if (a.max.x > b.min.x) {
			tFirst.x = (a.min.x - b.max.x) / vb.x;
			tLast.x = (a.max.x - b.min.x) / vb.x;
		}
		//case 3
		if (a.max.x < b.min.x) {
			return false;
		}

	}


	if (vb.y < 0) {
		//case 1
		if (a.min.y > b.max.y) {
			return false;
		}
		//case 4
		if (a.max.y < b.min.y) {
			tFirst.y = (a.max.y - b.min.y) / vb.y;
			tLast.y = (a.min.y - b.max.y) / vb.y;
		}

	}
	else { //vb.y > 0
		//case 2
		if (a.max.y > b.min.y) {
			tFirst.y = (a.min.y - b.max.y) / vb.y;
			tLast.y = (a.max.y - b.min.y) / vb.y;
		}
		//case 3
		if (a.max.y < b.min.y) {
			return false;
		}

	}
	if (tFirst.y > tLast.x || tFirst.x > tLast.y) {
		return false;
	}
	//Check if boxes will collide within next frame
	if (tFirst.x > tFirst.y) {
		if (tFirst.x < 0 || tFirst.x > AEFrameRateControllerGetFrameTime()) {
			return false;
		}
	}
	else {
		if (tFirst.y < 0 || tFirst.y > AEFrameRateControllerGetFrameTime()) {
			return false;
		}
	}

	/*Step 5: Otherwise the rectangles intersect*/
	return true;
}