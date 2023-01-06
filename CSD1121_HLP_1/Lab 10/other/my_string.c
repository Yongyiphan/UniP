/*!
@file :my_string.c
@author :Darryl Dan Wah Ping (d.dan@digipen.edu)
@course :HLP1
@section :Section A
@tutorial : Lab 10
@date : 11/11/2022
@brief :This program contains function definition for my_strlen, my_strcpy,
        my_strcat, my_strcmp and my_strstr.
*/
/*______________________________________________________________________*/


// @todo: Add necessary C standard library headers here ...

#include "my_string.h"

/*
    Function: my_strlen
    Parameters: str
    Returns: length
    Description: This function returns the length of a string.
    // https://en.cppreference.com/w/c/string/byte/strlen
*/
size_t my_strlen(const char* str){
    size_t length = 0 ;
    while(*str++){
        length++;
    }
    return length;
}
/*
    Function: my_strcpy
    Parameters: dest, src
    Returns: pointer to a string
    Description: This function copies string from src to dest.
    // https://en.cppreference.com/w/c/string/byte/strcpy
*/
char* my_strcpy(char* dest, const char* src) {
    char* copy = dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return copy;
}

/*
    Function: my_strcat
    Parameters: dest, src 
    Returns: pointer to a string.
    Description: This function concatenates a string from src and adds it to dest.
    // https://en.cppreference.com/w/c/string/byte/strcat
*/
char* my_strcat(char* dest, const char* src){
    my_strcpy(dest + my_strlen(dest), src);
    return dest;
}

/*
    Function: my_strcmp
    Parameters: lhs, rhs
    Returns: int value.
    Description: This function compare two strings
// https://en.cppreference.com/w/c/string/byte/strcmp
*/
int my_strcmp(const char* lhs, const char* rhs){
    while(*lhs==*rhs){
        if(*lhs =='\0'){
            return (int)(lhs - rhs);
        }
        lhs++;
        rhs++;
    }
    return (int)(lhs-rhs);
}

/*
    Function: my_strstr
    Parameters: str, substr
    Returns: pointer to a string
    Description: This function finds the first occurrence of a substring.
// https://en.cppreference.com/w/c/string/byte/strstr
*/
char* my_strstr(const char* str, const char* substr){
    const char *a, *b;
    b = substr;
    if(*b == 0){
        return (char *)str;
    }

    for(; *str !=0; str++){
        if(*str != *b){
            continue;
        }
        a = str;

        while(1){
            if(*b == 0){
                return (char *)str;
            }
            if(*a++ != *b++){
                break;
            }
        }
        b = substr;
    }
    return NULL;
}