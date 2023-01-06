// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
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


// @todo: Add necessary C standard library headers here ...

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
#include "q.h"
#include <stdio.h>
// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in q.h ...
/*
@brief      Given a string, converts all lowercase letters to uppercase, this function works in-place
@params     string -> pointer to start of char array (string)
@return     a pointer to the first character of the string. 
*//*______________________________________________________________________*/
char* str_to_upper(char* string){
    //change ascii value to upper equivalent
    //== +32 a =65 A = 79
    while(*string)
   {
        //if int value of char at current pointer is within a and z (lower caps)
        //subtract 32 to make it uppercase
       if ( *string >= 'a' && *string <= 'z' )
       {
            int ch = (int) *string;
            *string = (char) (ch - 32);
       }
       //increment pointer to the next char
       string++;
   }
   //return converted string
   return string;
}

/*
@brief      Given the file name of a dictionary text file, counts the number of words that start with a given letter
@params     const char* dictionary -> string that represents the dictionary file's name
            char letter -> target letter to search for
@returns    FILE_ERR_OPEN if file cannot be opended
            else: the number of words that start with target char
*//*______________________________________________________________________*/
WordCount words_starting_with(const char* dictionary, char letter){

    FILE *dict = fopen(dictionary, "r");
    //file open error handling
    if(dict == NULL){
        return FILE_ERR_OPEN; 
    }
    int cget, starting = 0, count = 0, iletter = (int) letter;    
    //since comparison is case-insensitive, convert all comparison chars to upper case for consistency
    //change letter to uppercase if is in lower for upper case to uppcase comparison later on
    if( 'a' <= letter && letter <= 'z'){
        iletter-=32;
    }
    //read thru file by chars
    while((cget = fgetc(dict)) != EOF){
        //if reach end of line, update to start comparing the next char (the first char of a new line)
        if(cget == '\n' || cget ==' '){
            starting = 0;
        }else{
            //else start comparing the first char of a line
            if(starting == 0){
                if( 'a' <= cget && cget <= 'z'){
                    //convert to uppercase
                    cget-=32;
                }
                //if match increment counter
                if(cget == iletter){
                    count += 1;
                    }
                //update algo to stop comparing until a new line if found - to start the next comparison of 
                //first chars
                starting = 1;
            }
        }
    }

    //close file stream
    fclose(dict);
    //return found count
    return count;
}

/*
@brief      Given the file name of a dictionary text file and a word, looks up the word in the dictionary.
@params     const char* dictionary -> string that represents the dictionary file's name
            const char* word -> string to find
@returns    FILE_ERR_OPEN if file cannot be opened
            WORD_BAD if word not found
            else WORD_OK
*//*______________________________________________________________________*/
ErrorCode spell_check(const char* dictionary, const char* word){
    FILE *dict = fopen(dictionary, "r");

    //file open error handling
    if(dict == NULL){
        return FILE_ERR_OPEN; 
    }
    
    char temp[LONGEST_WORD];
    int wordSize = 0;
    //function matches characters in a case insensitive way, therefore convert all chars involved to uppercase form
    //for comparison

    //iterate thru const word, store its values into another array of type char, convert to uppercase if neccessary
    while(*word != '\0'){
        int ch = (int) *word;
        if('a'<= *word && *word <= 'z'){
            ch -= 32;
        }
        temp[wordSize] = (char) ch;
        word++;
        //record down the word length of *word
        wordSize++;
    }
    
    
    char string[LONGEST_WORD];
    while(fgets(string,LONGEST_WORD, dict)){
        //converts string read from file to uppercase
        str_to_upper(string);
        int string_len = 0;
        //iterate through both strings (char array)s to find match
        while(string[string_len] == temp[string_len]){
            string_len += 1;
        }
        //if both string have the same chars in the same order and in the same length
        //close file and return that word is found
        if(string_len == wordSize){
            fclose(dict);
            return WORD_OK;
        } 
    }
    //else close file and return that word is NOT found
    fclose(dict);
    return WORD_BAD;
}
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
ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count){
    //open file
    FILE *dict = fopen(dictionary, "r");
    char tempS[LONGEST_WORD];
    //file open error handling
    if(NULL == dict){
        return FILE_ERR_OPEN;
    }

    //iterate through each line of file
    //storing each line as a string (char array)
    while(fgets(tempS, LONGEST_WORD, dict)){
        int WordCount = 0;
        //the '\n' char is included in fgets but it should be excluded from the word count
        //loop through the line, stop counting when '\n' is found
        //result will be the actual wordlength of the string
        while(tempS[WordCount] != '\n'){
            WordCount++;
        }
        //if the found word lenght is part of target length to check
        //store it in its respective location in lengths[]
        if(WordCount <= count){
            lengths[WordCount] += 1;
        }
    }
    //close file strea,
    fclose(dict);
    //reurn file is ok
    return FILE_OK;
}

/*
@brief      Given the file name of a dictionary text file, returns its description (the length of the shortest
            and the longest words, and the count of all words) using the DictionaryInfo structure. The
            function returns:
@params     const char*dictionary -> string that represent the dictionary file's name
            DictionaryInfo *info -> pointer to structure that is supposed to contain information of the dictionary
@returns    FILE_ERR_OPEN if file cannot be opened
            else FILE_OK
*//*______________________________________________________________________*/
ErrorCode info(const char* dictionary, DictionaryInfo* info){
    FILE *dict = fopen(dictionary , "r");

    //file open error handling
    if(NULL == dict)
        return FILE_ERR_OPEN;
    
    
    WordLength cMax = 1, cShort = LONGEST_WORD;
    WordCount wC = 0;
    
    char tempS[LONGEST_WORD];
    //iterate through file, recording each line as string (char array)
    while(fgets(tempS, LONGEST_WORD, dict)){
        WordLength wordcount = 0;
        //fgets records '\n' as part of the string, but it should be excluded from the word length
        //iterate through the string from fgets, and count the number of chars until '\n' is found
        //final value will be the actual length of the word
        while(tempS[wordcount] != '\n')
            wordcount++;
        //compare the word count with current longest and shortest word length, replace accordingly
        cMax = wordcount > cMax ? wordcount : cMax;
        cShort = wordcount < cShort ? wordcount : cShort;
        //increment the total word count
        wC++;
    }
    //fill in DictionaryInfo *info structure with new found values 
    info->count = wC;
    info->longest = cMax;
    info->shortest = cShort;
    //close file stream and return that file is ok
    fclose(dict);
    return FILE_OK;
}

