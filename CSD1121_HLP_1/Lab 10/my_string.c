// @todo: Add a file documentation header as explained in the specs ...

// @todo: Add necessary C standard library headers here ...
// Provide file-level documentation block as described in tutorial specification
/**!
@file my_string.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 10 String Library
@date   12/11/2022
@brief     This file contains reimplementation of the string.h library functions suchs as
            my_strlen() -> getting length of a string
            my_strcpy() -> copying a string from a given src onto a given destination
            my_strcat() -> concatenate a string onto another string
            my_strcmp() -> compare a string against another string
            my_strstr() -> evaluate if a string contains a given substring

*//*______________________________________________________________________*/

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in my_string.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in my_string.h ...
#include "my_string.h"
// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in my_string.h ...
/**
 * @brief       Funtion to get the length of a string
 * 
 * @param str   string to evaluated its length with;
 * @return size_t type representing the length of string
 */
size_t my_strlen(const char* str){
    size_t len = 0; //len counter
    while(*str++ != '\0')
        //loop through str, incrementing len until str = '\0'
        len++;
    return len;
}

/**
 * @brief       Function that copy string to another string
 * 
 * @param dest  Pointer to start of string to begin copying over to
 * @param src   Pointer to start of string to copy values from 
 * @return char* Pointer to start of string that contains the copied values
 */
char* my_strcpy(char* dest, const char* src){
    //pointer to the start of dest;
    char* start = dest;
    while(*src){
        //assign src's value to dest
        //then increment both pointers
        *dest++ = *src++;
    }
    //add null terminator;
    *dest = '\0';
    //return start of dest;
    return start;
}

/**
 * @brief       Function to join to strings together
 * 
 * @param dest      Pointer to start of string to add new string onto
 * @param src       Pointer to string to add onto dest
 * @return char*    Pointer to string that contains both dest + src 's string
 */
char* my_strcat(char* dest, const char* src){
    //size_t destLen = my_strlen(dest);
    //char* start = dest;
    //dest+= destLen;
    //my_strcpy(dest, src);
    //return start;
    
    my_strcpy(dest + my_strlen(dest), src);
    return dest;
}

/**
 * @brief       Function to compare two strings
 * 
 * @param lhs   Pointer to string on left hand side value
 * @param rhs   Pointer to string on right hand side value 
 * @return int   0 is both strings are equal
 *               1 if rhs is smaller
 *              -1 if lhs is smaller
 */
int my_strcmp(const char* lhs, const char* rhs){
    //while both value at current pointer index is the same
    while(*lhs && *rhs && *lhs==*rhs){
        //if hit a null terminator
        if(*lhs =='\0'){
            return (int)(lhs - rhs);
        }
        //else increment both pointer's location
        lhs++;
        rhs++;
    }
    return (int)(lhs-rhs);
}
/**
 * @brief           Function to find is sting is a substring of another string
 * 
 * @param str       String to find substring from
 * @param substr    substring to find in string
 * @return char*    Return pointer to the begining of substring's first occurence
 *                  else return NULL;
 */
#include <stdio.h>
char* my_strstr(const char* str, const char* substr){
    //loop through string
    while(*str){
        //pointer to start of str
        //                and substr
        char *Begin = (char* )str;
        char *sub = (char*)substr;
        //if start of substr is the same as str
        //start comparing
        while(*str && sub && *str == *sub){
            str++;
            sub++;
        }
        //if complete match with substr, return str position
        if(!*sub)
            return Begin;
        str = Begin + 1;
    } 
    return NULL;
}