// TODO1: add file header documentation!!!
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 7 Encryption and Decryption with Pointer 
@date 22/10/2022
@brief This file contains the definition of the functions
    : encrypt, that takes in a target char via pointer and a char that represents the key for encryption
    : decrypt, that takes in a target char via pointer and a char that represents the key for decryption
*//*______________________________________________________________________*/
#include "q.h" // included because q.c requires access to ASCII_COUNT

// TODO2: include other C standard library headers. for reasons 
// explained in previous assignments/labs, think carefully about 
// the need to add an include file before you do so ...

// TODO3: define functions encrypt and decrpyt ...
//Function takes in a pointer char letter and a char key of which will be used to modify the value of letter
//for encryption
void encrypt(char *letter, char key){
    int x = 0;
    x = (int)*letter + (int)key;
    //Wrap the value of letter around the max ascii code limit of 127
    if (x > 127){
        x -= ASCII_COUNT;
    }
    //update the value of given letter via pointers
    *letter = (char)x;
}

//Function takes in a pointer char letter and a char key of which will be used to modify the value of letter
//for decryption
void decrypt(char *letter, char key){
    int x = 0;
    x = (int)*letter - (int)key;
    //Wrap the value of letter around the max ascii code limit of 127
    if (x < 0){
        x +=ASCII_COUNT;
    }
    //update the value of given letter via pointers
    *letter = (char)x;
}