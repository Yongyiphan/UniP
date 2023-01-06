// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 2 Introduction to C Programming
@date 09-14-2022 
@brief 
*//*______________________________________________________________________*/
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of function temp_converter to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...

// @todo: Add necessary C standard library headers here ...
#include <stdio.h>

// @todo: Provide the definition of function temp_converter that
// matches the declaration in q.h ...

//takes in a int input representing fahrenheit
//and outputs its equivalent in celcius and kelvin
void temp_converter(int fInput){
    //Formula for Fahrenheit to Celsius
    //(fInput − 32) × 5/9 = N°C
    float FtoCelsius = ((float) fInput - 32) * (5.0f/9.0f);

    //Formula for Fahrenheit to Kelvin
    //(32°F − 32) × 5/9 + 273.15 = 273.15K
    // == Formula for fahrenheit to celsius + 273.15;
    float FtoKelvin = FtoCelsius + 273.15f;

    //Format results for output print;
    printf("%-15s%-15s%-15s\n", "Fahrenheit", "Celsius", "Kelvin");
    printf("---------------------------------------------\n");
    printf("%-15d%-15.2f%-15.2f\n", fInput, FtoCelsius, FtoKelvin);

}
 

