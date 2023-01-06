// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 8 Character Counter
@date 28/10/2022
@brief This contains the definition of functions that
    : Initialize() resets the arr and counter variables to 0
    : wc() {word count} counts the chars free
    : print() printttttt out results from wc()

*//*______________________________________________________________________*/
#include <stdio.h>   // do not remove

// IMPORTANT NOTE: Other than functions fgetc, printf, or fprintf [which are declared in <stdio.h>],
// you must not use any other C standard library function in your submission.

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

void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt){
    for (int i = 0; i<size;i++){
        //Loops through latin array
        //set each quantities into 0
        latin_freq[i] = 0;
    }
    //reset ctrl_cnt to 0
    *ctrl_cnt = 0;
    //reset latin_cnt = 0
    *non_latin_cnt = 0;
}



void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt){
    int ch;
    //Loop through file by each char as int value
    while((ch = fgetc(ifs)) != EOF){
        //if is between A and Z Case sensitive
        if (ch >= 'A' && ch <= 'Z'){
            //Update quantity of said index
            /*
            Assuming ch == equivalent of 'A'
            'A' == 65
            if ch == 65, ch - 'A' == 0 (index)
            */
            latin_freq[ch - 'A'] += 1;
            continue;
        }
        if (ch >= 'a' && ch <= 'z'){
            latin_freq[ch - 'a'] += 1;
            continue;
        }
        //Check if hits any of the parameters
        if (ch == '\a' || ch == '\b'|| ch == '\f' ||  ch == '\n' || ch == '\r' ||ch == '\t' || ch =='\v'){
            *ctrl_cnt += 1;
            continue;
        }
        //else add onto non latin cnt
        *non_latin_cnt += 1;
    }
}

void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt){
    int total = 0;
    //print the alphabet row first
    for(int i = 0; i < size; i++){
        printf("%-10c", 'a' + i);
    }
    printf("\n");
    //print respective freq count
    //add up total count simultaniously 
    for(int i = 0; i < size; i++){
        printf("%-10d", latin_freq[i]);
        total += latin_freq[i];
    }
    //PRINTTTTTT
    printf(
       "\n\nLatin Letters     :%8d\n", total);
    printf("Non-Latin Letters :%8d\n", *non_latin_cnt);
    printf("Control Letters   :%8d\n", *ctrl_cnt);

}