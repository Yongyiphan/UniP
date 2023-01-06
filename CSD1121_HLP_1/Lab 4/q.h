// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 4: Formatted Console I/O
@date 23/09/22
@brief This header files containst the delcaration of the functions that prints
    and breakdown money input into small denominations. as well as a functions go(), 
    which runs the whole program indefinitely until a break conditions occurs. 
*//*______________________________________________________________________*/



//declaration of functions
//print_line receives a index value, no. of denomination and the denomination itself
void print_line(int, int, int);
//this function, receives a int input of dollar.cents converted to cents and 
//break it down into smaller denominations
void break_down(int);
//allows user to continuously input dollar.cents value and exits
//upon receiving any form of invalid input.
void go(void);