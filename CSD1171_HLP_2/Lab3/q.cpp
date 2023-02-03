// See the specs for more information on how to author q.cpp ...
// don't forget - all names introduced by you must be in namespace hlp2 ...
/*!*****************************************
 \file      q.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 3
 \date      20-01-2023
 \brief     File-header Documentation for q.cpp
 \brief     Contains definition of  function 
            Given a string, convert said word into pig latin;
*/
#include "q.hpp"

namespace hlp2{

    /*!
    \brief      Converts a word to piglatin equivalent
    \param[in]  word    Given word for conversion
    \return     reformatted word
    */
    std::string to_piglatin(std::string word){
        std::string vowel{"aeiouAEIOU"}, store, temp, v;
        bool capital = isupper(word[0]) ? true : false, firsty = toupper(word[0]) == 'Y' ? true : false, found = false; 
        if(capital) word[0] = tolower(word[0]);
        if(vowel.find_first_of(word[0]) != std::string::npos) store = word + "-yay";
        else{
            for(std::string::iterator it = word.begin(); it != word.end();it++){
                if(!found && (vowel.find_first_of(*it) != std::string::npos || (!firsty && toupper(*it) == 'Y') )){
                    v = *it;found = true;continue;
                }
                if(found) store += *it; else temp += *it;
            }            
            if(found) store = v + store + temp + "-ay";else store = v + store + temp + "-way";
        }
        if(capital)store[0] = toupper(store[0]);
        return store;
    }
}