// @todo: Add a file documentation header as explained in the specs ...

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

// @todo: Add necessary C standard library headers here ...
#include "q.h"
#include "my_string.h"
#include <stdio.h>

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
/**
* @brief            Function takes builds a path that combines parent folder and the subdirectories 
                    into a single path using the separator.
* @param parent     string of parent folder
* @param separator  path separator sequence 
* @param folders    array of subdirectories with its element count.
* @returns          It combines the parent folder and the subdirectories into a single path using the separator.
*/
const char* build_path(const char*parent, const char*separator, const char* const folders[], size_t count){
    size_t size = 0;
    //get total size of new path
    //loop through folders and separator using count to get total size first
    for(size_t i = 0; i<count;size += (STRLEN(separator) + STRLEN(folders[i])), i++);
    //using size founf in the previous step, malloc a sufficient memory size
    char* newPath = (char*) debug_malloc((size + STRLEN(parent)) * sizeof(char) + 1);
    //fill up the new memory block with data
    STRCPY(newPath, parent);
    for(size_t i = 0; i<count; i++){
        STRCAT(newPath, folders[i]);
        STRCAT(newPath, separator);
    }
    //return the pointer to start of new block of memory
    return newPath;
}

/**
 * @brief       Funtion comapres string 
 * 
 * @param lhs   string 1 to be compared
 * @param rhs   string 2 to be compared against
 * @returns     Print result whether both strings are equal. or which string is shorter
 */
void compare_string(const char *lhs, const char*rhs){
    int compare = STRCMP(lhs, rhs);
    if (compare > 0)
        printf("Right string goes first.\n");
    else if (compare < 0)
        printf("Left string goes first.\n");
    else
        printf("Both strings are equal.\n");

}

/**
 * @brief       Function to get the length of a text
 * 
 * @param text  Text to be evaluated
 * @returns     Nothing, Prints out the length of the text given;
 */
void describe_string(const char*text){
    printf("The length of the path \"%s\" is %zu.\n", text, STRLEN(text));
}


/**
 * @brief           Function find_string check is substring is found in string
 * 
 * @param string    Pointer to start of string to be checked against
 * @param substring Pointer to start of substring to be found from given string
 */
void find_string(const char* string, const char*substring){
    char *result;
    //find if string contains substring
    result = STRSTR(string, substring);

    printf("Searching for a string:\n");
    printf("\tText:     %s\n", string);
    printf("\tSub-text: %*s\n",1, substring);

    if(result != NULL)
      printf("\tResult:   found %zu characters at a position %zu.\n", STRLEN(substring), result-string);
    else
        printf("\tResult:   not found\n");
}