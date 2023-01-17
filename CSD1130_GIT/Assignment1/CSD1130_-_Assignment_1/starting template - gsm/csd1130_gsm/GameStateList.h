#pragma once
/* Start Header ************************************************************************/ 
/*! 
\file   GameStateList.h
\author Yong Yip Han Edgar, y.yiphanedgar, 2202206 
\par    y.yiphanedgar@digipen.edu
\date   Jan 14, 2023 
\brief	File contains declaration of the enum that represent all possible game states.

Copyright (C) 2023 DigiPen Institute of Technology. 
Reproduction or disclosure of this file or its contents 
without the prior written consent of DigiPen Institute of 
Technology is prohibited. 
*/ 
/* End Header **************************************************************************/

enum GS_STATES
{
	GS_LEVEL1 = 0,
	GS_LEVEL2,

	GS_QUIT,
	GS_RESTART
};