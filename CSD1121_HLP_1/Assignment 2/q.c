// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 2 Introduction to C Programming
@date 09-09-2022 
@brief This file provides a collection of functions to draw 
        a tree and an animal in console
*//*______________________________________________________________________*/



#include <stdio.h>
// Provide function-level documentation block as described in tutorial
// specification for function draw_tree
void draw_tree(void){
    printf("    *\n");
    printf("   ***\n");
    printf("  *****\n");
    printf(" *******\n");
    printf("*********\n");
    printf("    #\n");
    printf("    #\n");
    printf("    #\n");
    printf("    #\n");

}

// Provide function-level documentation block as described in tutorial
// specification for function draw_animal
void draw_animal(void){
    printf("  /\\     /\\\n");                   
    printf(" /  \\___/  \\\n");
    printf("(           )    -------\n");
    printf("(   '   '   )   / Hello  \\\n");
    printf("(     _     )  <  Junior  |\n");
    printf("(           )   \\ Coder! /\n");
    printf(" |         |     -------\n");
    printf(" |    |    |\n");
    printf(" |    |    |\n");
    printf("(_____|_____)\n");
}
