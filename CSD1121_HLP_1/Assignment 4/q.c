// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 4_ Converting to Roman inputs
@date 21/09/22
@brief This file contains the implementation for the func that takes in a 
    int value in dec form and prints out its roman numeral equivalent'

*//*______________________________________________________________________*/

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of function decimal_to_roman to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...

// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
// @todo: Provide the definition of function decimal_to_roman that
// matches the declaration in q.h ...



void decimal_to_roman(int input){
    //while loop which cycles through different conditions
    //check if input contians value, print out value condition's equivalent. 
    //decrement input by value
    //repeat until the smallest divisor of 1 and or input becomes 0; 
    while (input > 0){
        if (input >= 1000){
            printf("M");
            input -= 1000;
        }
        else if(input >= 900){
            printf("CM");
            input -= 900;
        }
        else if(input >= 500){
            printf("D");
            input -= 500;
        }
        else if(input >= 400){
            printf("CD");
            input -= 400;
        }
        else if(input >= 100){
            printf("C");
            input -= 100;
        }
        else if(input >= 90){
            printf("XC");
            input -= 90;
        }
        else if(input >= 50){
            printf("L");
            input -= 50;
        }
        else if(input >= 40){
            printf("XL");
            input -= 40;
        }
        else if(input >= 10){
            printf("X");
            input -= 10;
        }
        else if(input >= 9){
            printf("IX");
            input -= 9;
        }
        else if(input >= 5){
            printf("V");
            input -= 5;
        }
        else if(input >= 4){
            printf("IV");
            input -= 4;
        }
        else{
            printf("I");
            input -= 1;
        }
    }
    printf("\n");
}

