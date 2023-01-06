// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 3: Problem Solving, I/O, and Expressions
@date 09/16/2022
@brief contains declaration for tile() and dispense_change() functions
*//*______________________________________________________________________*/

// @todo: Provide function-level documentation header for function tile
// as explained in Assignment 2 specs ...

//Takes in 2 float inputs for wall length and tile width
//and returns number of tiles and gaps at each end
void tile(double,double);

// It is important that you provide function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of function dispense_change ...
//Reads user's input of a item's price in dollar.cents format and notes input in dolars format
//returns changes in the form of loonies, half-loonies, quarters, dimes, nickels and pennies
void dispense_change(void);