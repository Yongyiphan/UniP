// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 8 Character Counter
@date 28/10/2022
@brief This contains the declaration of functions that
    : Initialize() resets the arr and counter variables to 0
    : wc() {word count} counts the chars free
    : print() printttttt out results from wc()

*//*______________________________________________________________________*/

#include <stdio.h> // for FILE*

// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the functions 
// initialize, wc, and print_freqs
void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt);

/*takes in parameters of 
    :file to open
    :array that contains frequencies of alphabet
    :number count for control characters
    :number count for any other characters
*/
void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt);


/*takes in parameter
    :array that contains frequencies of alphabet
    :number of control characters found
    :number of non latin characters found
prints out 
    :every latin alphabet with its respective number of character found below
    :the total number of latin characters found
    :total number of Non latin characters found
    :total number of control characters found
*/
void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt);