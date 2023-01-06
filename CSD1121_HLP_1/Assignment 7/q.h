// TODO1: provide file header documentation
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 7 Encryption and Decryption with Pointer 
@date 22/10/2022
@brief This file contains the declaration of the functions
    : encrypt, that takes in a target char via pointer and a char that represents the key for encryption
    : decrypt, that takes in a target char via pointer and a char that represents the key for decryption
*//*______________________________________________________________________*/

#ifndef Q_H
#define Q_H

// Don't remove!!!
// We're limiting ASCII set to the basic character set
// with encoding from 0 to 127
#define ASCII_COUNT 128

// TODO2: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function encrypt

// TODO3: declaration for function encrypt
//Function takes in a target char via pointer and a char that represents the key for encryption
void encrypt(char *letter, char text);

// TODO4: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function decrypt

// TODO5: declaration for function decrypt
//Function takes in a target char via pointer and a char that represents the key for decryption
void decrypt(char *letter, char text);


#endif // Q_H
