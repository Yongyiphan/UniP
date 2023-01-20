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
        std::string vowel{"aeiouAEIOU"}, store, temp;
        bool capital = false;
        if (isupper(word[0])){
            capital  =true;
            word[0] = tolower(word[0]);
        }
        if(vowel.find_first_of(word[0]) != std::string::npos){
            store = word + "-yay";
        }
        else{
            std::string v = "";
            bool  firsty = toupper(word[0]) == 'Y' ? true : false; 
            bool found = false;
            for(std::string::iterator it = word.begin(); it != word.end();it++){
                if(!found && (vowel.find_first_of(*it) != std::string::npos || (!firsty && toupper(*it) == 'Y') )){
                    v = *it;
                    found = true;
                    continue;
                }
                if(found){
                    store += *it;
                }
                else{
                    temp += *it;
                }
            }            
            if(found){
                store = v + store + temp + "-ay";
            }
            else{
                store = v + store + temp + "-way";
            }
        }
        if(capital){
            store[0] = toupper(store[0]);
        }
        return store;
    }
}