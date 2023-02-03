// See the specs for more information on how to author q.hpp ...
// don't forget - all names introduced by you must be in namespace hlp2 ...
/*!*****************************************
 \file      q.h
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 3
 \date      20-01-2023
 \brief     File-header Documentation for q.cpp
 \brief     Contains definition of  function 
            Given a string, convert said word into pig latin;
*/

#include <iostream>
#include <string>

namespace hlp2{
    /*!
    \brief      Converts a word to piglatin equivalent
    \param[in]  word    Given word for conversion
    \return     reformatted word
    */
    std::string to_piglatin(std::string);
}