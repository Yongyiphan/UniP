// @todo: Add a file-level documentation header as explained in Lab 2 specs ...

/***
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 10 String Library
@date   12/11/2022
@brief      This file contains definition for functions
            build_path() -> which takes in parameters and returns a file path to given subdirectories
            compare_string() -> which compares two given string 
            describe_string() -> which prints out the length of the given text
            find_string() -> which finds and prints out the position which the substring is at
*//*______________________________________________________________________*/
// @todo: Copy type aliases and macros from the current specs
#include <stdio.h>
#ifdef USE_STRING
#include <string.h>
#define STRLEN strlen
#define STRCPY strcpy
#define STRCAT strcat
#define STRCMP strcmp
#define STRSTR strstr
#else
#include "my_string.h"
#define STRLEN my_strlen
#define STRCPY my_strcpy
#define STRCAT my_strcat
#define STRCMP my_strcmp
#define STRSTR my_strstr
#endif

void* debug_malloc(size_t size);
void  debug_free(void* ptr);
// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the functions 
// build_path, compare_string, describe_string, and find_string


/**
* @brief            Function takes builds a path that combines parent folder and the subdirectories 
                    into a single path using the separator.
* @param parent     string of parent folder
* @param separator  path separator sequence 
* @param folders    array of subdirectories with its element count.
* @returns          It combines the parent folder and the subdirectories into a single path using the separator.
*/
const char* build_path(const char*parent, const char*separator, const char* const folders[], size_t count);

/**
 * @brief       Funtion comapres string 
 * 
 * @param lhs   string 1 to be compared
 * @param rhs   string 2 to be compared against
 * @returns     Print result whether both strings are equal. or which string is shorter
 */
void compare_string(const char *lhs, const char*rhs);

/**
 * @brief       Function to get the length of a text
 * 
 * @param text  Text to be evaluated
 * @returns     Nothing, Prints out the length of the text given;
 */
void describe_string(const char*text);

/**
 * @brief           Function find_string check is substring is found in string
 * 
 * @param string    Pointer to start of string to be checked against
 * @param substring Pointer to start of substring to be found from given string
 */
void find_string(const char* string, const char*substring);
