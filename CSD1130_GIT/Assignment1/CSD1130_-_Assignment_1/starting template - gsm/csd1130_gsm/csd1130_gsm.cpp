// csd1130_gsm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* Start Header ************************************************************************/ 
/*! 
\file   csd1130_gsm.cpp 
\author Yong Yip Han Edgar, y.yiphanedgar, 2202206 
\par    y.yiphanedgar@digipen.edu
\date   Jan 14, 2023 
\brief  This file contains the main function that 
        Initializes the system,
        Initializes and start the game manager
        Starts a loop that execute functions using function pointers when appropriate
        such as load, initialize, free and unload states when state changes
                input handle, update, draw during game state loop.
        system exits when quit triggers.
Copyright (C) 2023 DigiPen Institute of Technology. 
Reproduction or disclosure of this file or its contents 
without the prior written consent of DigiPen Institute of 
Technology is prohibited. 
*/ 
/* End Header **************************************************************************/

#include "pch.h"
//Implement the pseudo-code of A1_P1 here
int main()
{
    //Systems initialize
    System_Initialize();
    //GSM initialize
    GSM_Initialize(GS_LEVEL1);

    //Runs game loop while current game state is not QUIT
    while (current != GS_QUIT)
    {
        //If current game stae != restart
        if (current != GS_RESTART) {
			//Update function pointers.
			GSM_Update();
            //Load using updated function pointers
            fpLoad();
        }
        else {
            //retrieve previous game state
            current = previous;
            next = previous;
        }
        //Initialise game state using function pointers
        fpInitialize();
        while (current == next) {
            Input_Handle();
            fpUpdate();
            fpDraw();
        }
        //If next state changed, unload
        fpFree();
        //If current state request for restart, continue to next game cycle, no cycle of load. 
        if (next != GS_RESTART) {
            fpUnload();
        }
        //shift state storing variables, 
        previous = current;
        current = next;
    }
    //Systems exit (terminate)
    System_Exit();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
