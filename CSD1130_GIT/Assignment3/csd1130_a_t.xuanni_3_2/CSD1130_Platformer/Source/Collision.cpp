/******************************************************************************/
/*!
\file		Collision.cpp
\author 	Teo Xuan Ni
\par    	email: t.xuanni@digipen.edu
\date   	February 28, 2022
\brief		Contains collision code to check for collision between two objects

Copyright (C) 2022 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the
prior written consent of DigiPen Institute of Technology is prohibited.
 */
/******************************************************************************/

#include "main.h"

/**************************************************************************/
/*!
	Check collision between two objects
*/
/**************************************************************************/
bool CollisionIntersection_RectRect(const AABB &aabb1, const AEVec2 &vel1, 
									const AABB &aabb2, const AEVec2 &vel2)
{
	/*
	Implement the collision intersection over here.

	The steps are:	
	Step 1: Check for collision detection between rectangles (assuming static here). 
			If the check returns no overlap you continue with the following steps.

	Step 2: Initialize and calculate the new velocity of Vb
			tFirst = 0
			tLast = dt

	Step 3: Working with one dimension (x-axis).
			if(Vb < 0)
				case 1
				case 4
			if(Vb > 0)
				case 2
				case 3

			case 5

	Step 4: Repeat step 3 on the y-axis

	Step 5: Otherwise the rectangles intersect

	*/
	if ((aabb1.max.x < aabb2.min.x) || (aabb1.max.y < aabb2.min.y) ||
		(aabb1.min.x > aabb2.max.x) || (aabb1.min.y > aabb2.max.y)) //no intersection
	{
		/*Step 2: Initialize and calculate the new velocity of Vb
				tFirst = 0
				tLast = dt*/
		float tFirst = 0;
		float tLast = g_dt;

		AEVec2 velRel;
		velRel.x = vel2.x - vel1.x;
		velRel.y = vel2.y - vel1.y;

		/*Step 3: Working with one dimension(x - axis).
				if(Vb < 0)
					case 1
					case 4
				if(Vb > 0)
					case 2
					case 3

				case 5*/
		if (velRel.x <= 0)
		{
			if (aabb1.min.x > aabb2.max.x) //case 1
				return false; //No intersection and B is moving away
			//B moving left towards A
			if (aabb1.max.x < aabb2.min.x) //case 4 tFirst
				tFirst = max((aabb1.max.x - aabb2.min.x) / velRel.x, tFirst);
			if (aabb1.min.x < aabb2.max.x) //case 4 tLast
				tLast = min((aabb1.min.x - aabb2.max.x) / velRel.x, tLast);
		}
		if (velRel.x >= 0)
		{
			if (aabb1.min.x > aabb2.max.x) //case 2 tFirst
				tFirst = max((aabb1.min.x - aabb2.max.x) / velRel.x, tFirst);
			//B moving right towards A
			if (aabb1.max.x > aabb2.min.x) //case 2 tLast
				tLast = min((aabb1.max.x - aabb2.min.x) / velRel.x, tLast);
			if (aabb1.max.x < aabb2.min.x)
				return false; //No intersection and B is moving away
		}

		/*Step 4: Repeat step 3 on the y-axis*/
		if (velRel.y <= 0)
		{
			if (aabb1.min.y > aabb2.max.y) //case 1
				return false; //No intersection and B is moving away
			//B moving left towards A
			if (aabb1.max.y < aabb2.min.y) //case 4 tFirst
				tFirst = max((aabb1.min.y - aabb2.max.y) / velRel.y, tFirst);
			if (aabb1.min.x < aabb2.max.x) //case 4 tLast
				tLast = min((aabb1.min.y - aabb2.max.y) / velRel.y, tLast);
		}
		if (velRel.y >= 0)
		{
			if (aabb1.min.y > aabb2.max.y) //case 2 tFirst
				tFirst = max((aabb1.min.y - aabb2.max.y) / velRel.y, tFirst);
			//B moving right towards A
			if (aabb1.max.y > aabb2.min.y) //case 2 tLast
				tLast = min((aabb1.max.y - aabb2.min.y) / velRel.y, tLast);
			if (aabb1.max.y < aabb2.min.y)
				return false; //No intersection and B is moving away
		}

		if (tFirst > tLast)
		{
			return false;
		}
	}
	return true;
}