// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.h
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial   Lab 12 Tutorial 11: Struct Arrays 
@date   18/11/2022
@brief  this file contains delcaration of the function 
        print_data() -> that prints out addresses given in a format similar to that of a hex editor

*//*______________________________________________________________________*/

// @todo: Copy type aliases and macros from the current specs

// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the function print_data
struct Datum
{
    char upper;
    char lower;
    unsigned short int value;
};
typedef struct Datum DATUM;
typedef DATUM DATA[2];

/**
 * @brief       that takes in the address of an object of any type, 
 *              its size, 
 *              with the number of hexadecimal digits per line of output 
 * @param ptr   void pointer to start of array of objects
 * @param size  size of array of objects
 * @param span  span limit of chars per line
 * @return      out to the console a layout similar to a hex editor interface.
 */
void print_data(const void* ptr, size_t size, size_t span);
