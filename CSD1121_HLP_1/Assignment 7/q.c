/*!
@file :q.h
@author :Darryl Dan Wah Ping (d.dan@digipen.edu)
@course :HLP1
@section :Section A
@tutorial : Assignment 7
@date : 21/10/2022
@brief :This program contains function definition for encrpyt and decrypt.
*/
/*______________________________________________________________________*/


#include "q.h" // included because q.c requires access to ASCII_COUNT

/*
    Function: encrpyt
    Parameters: letter, keytext
    Returns: -
    Description: This function reads a letter and encrypts it using Vigenere cipher
                 with a given keyword.
*/
void encrypt(char* letter, char keyword){
    int code = 0;
    code = (int)*letter + (int)keyword;
    if(code > 127){
        code -= ASCII_COUNT;
    } 
    *letter = (char)code;
}

/*
    Function: encrpyt
    Parameters: letter, keytext
    Returns: -
    Description: This function reads a letter and decrypts it using Vigenere cipher
                 with a given keyword.
*/
void decrypt(char* letter, char keyword){
    int code = 0;
    code = (int)*letter - (int)keyword;
    if(code < 0 ){
        code += ASCII_COUNT;
    } 
    *letter = (char)code;
}