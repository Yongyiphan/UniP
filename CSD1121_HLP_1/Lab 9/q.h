// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
/*!
@file q.h
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 9 Strings, arrays, pointers, structures and file I/O
@date 5/11/2022
@brief This file contains the definition of functions that
    : str_to_upper() -> converts a string to its uppercased equivalent
    : words_starting_with() -> find words throught a given text file, that begins with target character
    : spell_check() -> given a file name of a dictionary text file, looks up for a word
    : word_lengths() -> given a file name of a dictionary text file, counts the number of words of each length and returns the accumulated results
    : info() -> given a file name of a dictionary, returns its description of lengths of shortest, longest word and word count

*//*______________________________________________________________________*/

// @todo: Copy type aliases and macros from the current specs
typedef int WordCount;
typedef unsigned char WordLength;
typedef int ErrorCode;
struct DictionaryInfo
{
// Length of the shortest word
WordLength shortest;
// Length of the longest word
WordLength longest;
// Number of words in the dictionary
WordCount count;
};
typedef struct DictionaryInfo DictionaryInfo;
enum ErrorCode
{
FILE_OK = -1, // The file was opened successfully.
FILE_ERR_OPEN = -2, // The file was not opened.
WORD_OK = -3, // The word was found in the dictionary.
WORD_BAD = -4 // The word was not found in the dictionary.
};
enum
{
LONGEST_WORD = 50
};

/*
@brief      Given a string, converts all lowercase letters to uppercase, this function works in-place
@params     string -> pointer to start of char array (string)
@return     a pointer to the first character of the string. 
*//*______________________________________________________________________*/
char* str_to_upper(char* string);

/*
@brief      Given the file name of a dictionary text file, counts the number of words that start with a given letter
@params     const char* dictionary -> string that represents the dictionary file's name
            char letter -> target letter to search for
@returns    FILE_ERR_OPEN if file cannot be opended
            else: the number of words that start with target char
*//*______________________________________________________________________*/
WordCount words_starting_with(const char* dictionary, char letter);

/*
@brief      Given the file name of a dictionary text file and a word, looks up the word in the dictionary.
@params     const char* dictionary -> string that represents the dictionary file's name
            const char* word -> string to find
@returns    FILE_ERR_OPEN if file cannot be opened
            WORD_BAD if word not found
            else WORD_OK
*//*______________________________________________________________________*/
ErrorCode spell_check(const char* dictionary, const char* word);

/*
@brief      Given the file name of a dictionary text file, counts the number of words of each length
            between 1 and count (inclusive) and stores this result in an array lengths at the position
            corresponding to the length.
@params     const char *dictionary -> string that represent the dictionary file's name
            WordCount length[] -> array that contains the the count of words that meet specific length
            WordLength Count -> Max length of words to check
@returns    FILE_ERR_OPEN if file cannot be opened
            else FILE_OK
*//*______________________________________________________________________*/
ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count);

/*
@brief      Given the file name of a dictionary text file, returns its description (the length of the shortest
            and the longest words, and the count of all words) using the DictionaryInfo structure. The
            function returns:
@params     const char*dictionary -> string that represent the dictionary file's name
            DictionaryInfo *info -> pointer to structure that is supposed to contain information of the dictionary
@returns    FILE_ERR_OPEN if file cannot be opened
            else FILE_OK
*//*______________________________________________________________________*/
ErrorCode info(const char* dictionary, DictionaryInfo* info);

// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the functions 
// str_to_upper, words_starting_with, spell_check, word_lengths, and info




