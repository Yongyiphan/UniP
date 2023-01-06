// @todo: Add a file documentation header as explained in the specs ...
/**
@file: q.c
@author: Koh Wei Jie (weijie.koh)
@course: CSD1121
@section: Section A
@tutorial: Tutorial 9
@date: 04/11/2022
@brief: HLP1, lab 9 making a spell checker
*/
// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include <stdlib.h>

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
#include "q.h"

// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in q.h ...


/**
 @brief: makes use of a while loop and pointer arimetic to cycle through
 all chars in the string until it hits the '\0' char. For each cycle to check
 if the current letter is lowercase, if it is then find the offset and add it
 to 'A' char to get the uppercase letter.
*/
char* str_to_upper(char* string){
    char *temp  = string;
    int letter,offset;

    while (*temp != '\0') // checking the end of string which ends with '\0'
    {
        if(*temp >= 'a' && *temp <= 'z'){
            offset = (int)*temp - (int)'a'; 
            letter = offset + (int)'A';
            *temp = (char)letter;
        }
        temp++;
    }
    return string;
}

/**
 @brief: uses fgets to get each line, and checking if the first char
 of the line is the same as the param "letter" using fileline[0] 
 if it is then increment word count by 1 else continue, till end of file.
 Not case sensative due to the str_to_upper() function.
*/
WordCount words_starting_with(const char* dictionary, char letter){
    FILE *textfile  = fopen(dictionary, "r");
    WordCount count = 0; char fileline[255];

    if( textfile == NULL){
        fclose(textfile);
        return FILE_ERR_OPEN;
    }
    
    while(fgets(fileline,255,textfile)){
        str_to_upper(fileline);
        str_to_upper(&letter);
        if (fileline[0] == letter){
            count++;
        }
    }
    fclose(textfile);
    return count;
}

/**
 @brief:  finds the size of the word param and converts the word param into uppercase
 then using fgets and converting it to uppercase as well. then it compares the letters
 of the converted uppercase word and the fgets strline if the number of letter matches the
 size of the word return WORD_OK. else return WORD_BAD
*/
ErrorCode spell_check(const char* dictionary, const char* word){

    FILE *textfile = fopen(dictionary,"r");
    char fileline[100]; char upperword [100]; int wordSize;

    if( textfile == NULL){
        fclose(textfile);
        return FILE_ERR_OPEN;
    }

    // since the "word" param is const clone the word param and convert it into uppercase
    // Also count the number of letters in the word string which ends with '\0'
    for (wordSize = 0;*(word + wordSize) != '\0' ; wordSize++){ 
        upperword[wordSize] = *(word + wordSize);
        str_to_upper(upperword+wordSize);
    }

    // check through the file for the exact word
    while(fgets(fileline,255,textfile)){
        str_to_upper(fileline);
        
        int count = 0;
        while (fileline[count] == upperword[count]){ // if char is the same increment the count
            ++count;
        }
        if (count == wordSize){ // if the count is the same as wordsize return 
            fclose(textfile);
            return WORD_OK;
        }
    }

    fclose(textfile);
    return WORD_BAD;
}

/**
 @brief: makes use of fgets to get each line of file and a while loop to count the number
 of letters in each line. if the line word count is between 1 and "count" param add it
 into the lengths array.
*/
ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count){
    FILE *textfile = fopen(dictionary,"r");

    if( textfile == NULL){
        fclose(textfile);
        return FILE_ERR_OPEN;
    }

    char fileline[255];
    int wordcount;

    while(fgets(fileline,255,textfile)){
        wordcount = 0;
        while(*(fileline+wordcount) != '\n'){ // '\n' used to check the end of the line for fgets
                                              // where as '\0' is used for strings only
            wordcount++;
        }
        if (wordcount <= count){
            lengths[wordcount] += 1;
        }
    }

    fclose(textfile);
    return FILE_OK;
}

/**
 @brief: makes use of fgets to check every lines of text and a while
 loop to check the word count of the line. then it compares the wordcount
 to find the largest and smallest wordcount. It also counts the total number
 of words in the files. And it assigns all the data into the struct DictionaryInfo info.
*/
ErrorCode info(const char* dictionary, DictionaryInfo* info){
    FILE *textfile = fopen(dictionary,"r");

    if( textfile == NULL){
        fclose(textfile);
        return FILE_ERR_OPEN;
    }
    WordLength wordcount = 0, countLargest = 0, countSmol = 100;
    WordCount countTotal = 0;
    char fileline[255];
    while(fgets(fileline,255,textfile)){
        wordcount = 0;
        while (*(fileline+wordcount) != '\n'){
            ++wordcount;
        }

        if (wordcount > countLargest ){
            countLargest = wordcount;
            info -> longest = wordcount;
        }
        if (wordcount < countSmol){
            countSmol = wordcount;
            info -> shortest = wordcount;
        }
        countTotal++;
        
    }
    info -> count = countTotal;
    fclose(textfile);
    return FILE_OK;
}