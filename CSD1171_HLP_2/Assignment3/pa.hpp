// See the specs for more information on how to author pa.hpp ...
/*!*****************************************
 \file      pa.h
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 3
 \date      26-01-2023
 \brief     File-header Documentation for pa.h
 \brief     This file contains function to
            1) Fill in a vector of struct from a multi line text file
            2) Find the max names' length within the struct vector
            3) function to sort a vector using specific conditions
            compare conditions:
                4) when left's name is lexicographically less than right's name
                5) when left's name is lexicographically more than right's name
                6) when left's population is greater than right's population
                7) when left's population is lesser than right's population
            8) function to write struct vector to output text file in specific formatting
*/
#ifndef PA_HPP
#define PA_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

namespace hlp2 {
    // structure to encapsulate a country's name and its population ...
    struct CountryInfo {
        std::string name; // country's name - *exactly* as in input file
        long int pop; // country's population
    };
    using Ptr_Cmp_Func = bool (*)(CountryInfo const&, CountryInfo const&);
    using UI32 = unsigned int;

    /*
    \brief      Reads from a text file and fill in a vector struct
    \param[in]  is file stream
    \return     A vector of struct <CountryInfo> that is filled with values retrieved from the text file
    */
    std::vector<CountryInfo> fill_vector_from_istream(std::istream& is);

    /*
    \brief      Find the max name's length within a vector of struct
    \param[in]  result -> reference to vector of struct
    \return     value of the longest name's length
    */
    size_t max_name_length(std::vector<CountryInfo> const&);

    /*
    \brief      Sort out vector using specified comparisons methods
    \param[in]  rv  -> reference to struct vector
    \parma[in   cmp -> function pointer
    */
    void sort(std::vector<CountryInfo>& rv, Ptr_Cmp_Func cmp);

    /*
    \brief      write out struct vector to output text file
    \param[in]  v   -> reference to struct vector
    \param[in]  os  -> output stream
    \param[in]  fw  -> format padding
    */
    void write_to_ostream(std::vector<CountryInfo> const& v,std::ostream& os, size_t fw);

    /*
    \brief      compare left and right 's name lexicographically
    \param[in]  left    -> reference to struct to be compared against
    \param[in]  right   -> reference to struct to be compared with 
    \return     boolean result if left's name is lexicographically less than right's name
    */
    bool cmp_name_less(CountryInfo const& left, CountryInfo const& right);

    /*
    \brief      compare left and right 's name lexicographically
    \param[in]  left    -> reference to struct to be compared against
    \param[in]  right   -> reference to struct to be compared with 
    \return     boolean result if left's name is lexicographically more than right's name
    */
    bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right);

    /*
    \brief      compare left and right 's population
    \param[in]  left    -> reference to struct to be compared against
    \param[in]  right   -> reference to struct to be compared with 
    \return     boolean result if left's population is lesser than right's population 
    */
    bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right);


    /*
    \brief      compare left and right 's population
    \param[in]  left    -> reference to struct to be compared against
    \param[in]  right   -> reference to struct to be compared with 
    \return     boolean result if left's population is greater than right's population 
    */
    bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right);
// other declarations ...
} // end namespace hlp2
#endif