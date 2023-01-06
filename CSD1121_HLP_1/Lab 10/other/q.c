/*!
@file :q.c
@author :Darryl Dan Wah Ping (d.dan@digipen.edu)
@course :HLP1
@section :Section A
@tutorial : Lab 10
@date : 11/11/2022
@brief :This program contains function definition for build_path, compare_string
        describe_string and find_str.
*/
/*______________________________________________________________________*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q.h"

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
const char *build_path(const char *parent, const char *separator, const char *const folders[], size_t count)
{
    char *path;
    size_t size = 0;

    // get size for folders + separator
    for (size_t i = 0; i < count; i++)
    {
        size += STRLEN(folders[i]);
        size += STRLEN(separator);
    }

    path = (char *)debug_malloc(STRLEN(parent) + size + 1);

    STRCPY(path, parent);

    for (size_t i = 0; i < count; i++)
    {
        STRCAT(path, folders[i]);
        STRCAT(path, separator);
    }
    return path;
}

/*
    Function: compare_string
    Parameters: lhs,rhs
    Returns: -
    Description: This function prints out a statement about a 3-way comparison of two strings.

                 demonstrate calls to STRCMP.
*/
void compare_string(const char *lhs, const char *rhs)
{
    int compare = strcmp(lhs, rhs);
    if (compare < 0)
    {
        printf("Left string goes first.\n");
    }
    else if (compare > 0)
    {
        printf("Right string goes first.\n");
    }
    else
    {
        printf("Both strings are equal.\n");
    }
}

/*
    Function: describe_string
    Parameters: text
    Returns: -
    Description: This function prints out the lenght of a provided string of text.

                 demonstrate calls to STRLEN
*/
void describe_string(const char *text)
{
    printf("The length of the path \"%s\" is %zu.\n", text, STRLEN(text));
}

/*
    Function: find_string
    Parameters: string, substring
    Returns: -
    Description: This function prints out a statement describing a result of searchi0ng for a
                 string of text(substring) within another string of text(string).

                 demonstrate calls to STRSTR

                 Searching for a string:
    Text:     /home/user/files/documents/images/20201031/
    Sub-text: 20201031
    Result:   found 8 characters at a position 34.
*/
void find_string(const char *string, const char *substring)
{
    char *ret;
    ret = strstr(string, substring);

    printf("Searching for a string:\n");
    printf("\tText:     %s\n", string);
    printf("\tSub-text: %*s\n",1, substring);

    if(ret != NULL){
      printf("\tResult:   found %zu characters at a position %zu.\n", STRLEN(substring), ret-string);
    }
    else{
        printf("\tResult:   not found\n");
    }
    
}