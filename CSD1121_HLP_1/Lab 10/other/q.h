/*!
@file :q.h
@author :Darryl Dan Wah Ping (d.dan@digipen.edu)
@course :HLP1
@section :Section A
@tutorial : Lab 10
@date : 4/11/2022
@brief :This program contains function declaration
*/
/*______________________________________________________________________*/

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

void debug_free(void* ptr);

/*
    Function: build_path
    Parameters: parent, separator, folders, count
    Returns: the combined single path using the separator.
    Description: This function takes in a path to a parent folder, a path 
                 separator sequence and an array of subdirectories with its
                 element count. It combines the parent folder and the subdirectories
                 into a single path using the separator.

                 demonstrate calls to STRCPY and STRCAT
*/
const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count);

/*
    Function: compare_string
    Parameters: lhs,rhs
    Returns: -
    Description: This function prints out a statement about a 3-way comparison of two strings.

                 demonstrate calls to STRCMP.

*/
void compare_string(const char* lhs, const char* rhs);

/*
    Function: describe_string
    Parameters: text
    Returns: -
    Description: This function prints out the lenght of a provided string of text.

                 demonstrate calls to STRLEN
*/
void describe_string(const char* text);

/*
    Function: find_string
    Parameters: string, substring
    Returns: -
    Description: This function prints out a statement describing a result of searchi0ng for a
                 string of text(substring) within another string of text(string).

                 demonstrate calls to STRSTR
*/
void find_string(const char* string, const char* substring);

