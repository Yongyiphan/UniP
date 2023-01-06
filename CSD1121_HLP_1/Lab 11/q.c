// @todo: Add a file documentation header as explained in the specs ...
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial   Lab 12 Tutorial 11: Struct Arrays 
@date   18/11/2022
@brief  this file contains delcaration of the function 
        print_data() -> that prints out addresses given in a format similar to that of a hex editor

*//*______________________________________________________________________*/

// @todo: Add necessary C standard library headers here ...

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in q.h ...

// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in q.h ...
#include <stdio.h>
#include "q.h"
    /*
	0   { {0x41, 0x61, 0x4161}, {0x42, 0x62, 0x4262} },
	1   { {0x43, 0x63, 0x4363}, {0x44, 0x64, 0x4464} },
	2   { {0x45, 0x65, 0x4565}, {0x46, 0x66, 0x4666} },
	3   { {0x47, 0x67, 0x4767}, {0x48, 0x68, 0x4868} },
	4   { {0x49, 0x69, 0x4969}, {0x4A, 0x6A, 0x4A6A} },
	5   { {0x4B, 0x6B, 0x4B6B}, {0x4C, 0x6C, 0x4C6C} },
	6   { {0x4D, 0x6D, 0x4D6D}, {0x4E, 0x6E, 0x4E6E} },
	7   { {0x4F, 0x6F, 0x4F6F}, {0x50, 0x70, 0x5070} }
    */


/**
 * @brief       that takes in the address of an object of any type, 
 *              its size, 
 *              with the number of hexadecimal digits per line of output 
 * @param ptr   void pointer to start of array of objects
 * @param size  size of array of objects
 * @param span  span limit of chars per line
 * @return      out to the console a layout similar to a hex editor interface.
 */
void print_data(const void* ptr, size_t size, size_t span){
    const char* dptr = (const char*)ptr;
    size_t spacebreak = sizeof(DATUM);
    for(size_t i = 0, step = 0; i <size; i++){
        printf("%x ", *(dptr + i));
        step++;
        if(step % spacebreak == 0){
            printf("  ");
        }
        if(step % (span) == 0){
            printf("|   ");
            for(size_t u = step - span, j = 1; u < step; u++, j++){
                printf("%c ", *(dptr + u));
                if(j % spacebreak == 0){
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
}