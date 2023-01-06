
// add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file calc.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 2: Single and Multiple File Programs
@date 09-09-2022 
@brief This file provides a collection of functions to draw 
        a tree and an animal in console
*//*______________________________________________________________________*/
#include "calc.h"
// provide the definition of function squared
// that matches the declaration in calc.h ...
int squared(int x){
    return x * x;
}


// provide the definition of function cubed
// that matches the declaration in calc.h ...
double cubed(double x){
    return x * x * x;    
}

// provide the definition of function minus
// that matches the declaration in calc.h ...
double minus(double sValue){
    return -sValue;
}