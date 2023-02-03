/******************************************************************************/
/*!
\file		Collision.cpp
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
#include <iomanip>
/**************************************************************************/
/*!

	*/
/**************************************************************************/
bool CollisionIntersection_RectRect(const AABB& aabb1, const AEVec2& vel1,
	const AABB& aabb2, const AEVec2& vel2)
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

	if ((aabb1.max.x > aabb2.min.x
		&& aabb1.max.y > aabb2.min.y)
		&&
		(aabb2.max.x > aabb1.min.x
		&& aabb2.max.y > aabb1.min.y))
	{
		//qstd::cout << "collision type 1\n";
		return true;
	}


	AEVec2 velRel{};
	velRel.x = vel2.x - vel1.x;
	velRel.y = vel2.y - vel1.y;
	AEVec2 tFirst{ 0 };
	AEVec2 tLast{ 0 };
	AEVec2Set(&tLast, AEFrameRateControllerGetFrameTime(), AEFrameRateControllerGetFrameTime());


	// x-axis check
	if (velRel.x < 0) // B moving left
	{
		if (aabb1.min.x > aabb2.max.x)  // B left of A
		{
			return false;
		}
		else // B right of A
		{
			tFirst.x = (aabb1.max.x - aabb2.min.x) / velRel.x;
			tLast.x = (aabb1.min.x - aabb2.max.x) / velRel.x;
		}
	}
	 else //B moving right
	{
		if (aabb1.min.x > aabb2.max.x)
		{
			tFirst.x = (aabb1.min.x - aabb2.max.x) / velRel.x;
			tLast.x = (aabb1.max.x - aabb2.min.x) / velRel.x;
		}
		else //A left of B
		{
			return false;
		}
	}

	// y-axis check
	if (velRel.y < 0) //B moving down
	{
		if (aabb1.min.y > aabb2.max.y) //A above B
		{
			return false;
		}
		else // A below B
		{
			tFirst.y = (aabb1.max.y - aabb2.min.y) / velRel.y;
			tLast.y = (aabb1.min.y - aabb2.max.y) / velRel.y;
		}
	}
	else //B moving up
	{
		if (aabb1.min.y > aabb2.max.y) 
		{
			tFirst.y = (aabb1.min.y - aabb2.max.y) / velRel.y;
			tLast.y = (aabb1.max.y - aabb2.min.y) / velRel.y;
		}
		else // A below B
		{
			return false;
		}
	}

	if (tFirst.y > tLast.x || tFirst.x > tLast.y)
	{
		return false;
	}

	if (tFirst.x > tFirst.y)
	{
		if (tFirst.x < 0 || tFirst.x > AEFrameRateControllerGetFrameTime())
		{
			return false;
		}
	}
	else
	{
		if (tFirst.y < 0 || tFirst.y > AEFrameRateControllerGetFrameTime())
		{
			return false;
		}
	}

	//std::cout << "collision type 2\n";

	//std::cout << "aabb1 min : " << std::setprecision(4) << aabb1.min.x << ", " << aabb1.min.y << "\n";
	//std::cout << "aabb1 max : " << std::setprecision(4) << aabb1.max.x << ", " << aabb1.max.y << "\n";
	//std::cout << "aabb1 vel : " << std::setprecision(4) << vel1.x << ", " << vel1.y << "\n\n";
	//std::cout << "aabb2 min : " << std::setprecision(4) << aabb2.min.x << ", " << aabb2.min.y << "\n";
	//std::cout << "aabb2 max : " << std::setprecision(4) << aabb2.max.x << ", " << aabb2.max.y << "\n";
	//std::cout << "aabb2 vel : " << std::setprecision(4) << vel2.x << ", " << vel2.y << "\n\n";
	//std::cout << "tfirst    : " << std::setprecision(4) << tFirst.x << ", " << tFirst.y << "\n";
	//std::cout << "tlast     : " << std::setprecision(4) << tLast.x << ", " << tLast.y << "\n\n\n";
	return true;
}