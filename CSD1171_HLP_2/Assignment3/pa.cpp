// See the specs for more information on how to author pa.cpp ...
/*!*****************************************
 \file      pa.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 2
 \date      26-01-2023
 \brief     File-header Documentation for pa.cpp
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
#include "pa.hpp"

namespace hlp2 {
    /*
    \brief      Reads from a text file and fill in a vector struct
    \param[in]  is file stream
    \return     A vector of struct <CountryInfo> that is filled with values retrieved from the text file
    */

    std::vector<CountryInfo> fill_vector_from_istream(std::istream& is){
        std::vector<CountryInfo> result;
        //ifstream provided
        std::string line,population, alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ()"};
        while(getline(is, line)){
            CountryInfo ci;
            size_t start = line.find_first_of(alphabet);
            size_t end   = line.find_last_of(alphabet);
            ci.name = line.substr(start, end - start + 1);
            population = line.substr(end + 1);
            size_t f = 0;
            while((f = population.find(',')) != std::string::npos){
                population.erase(f, 1);
            }
            ci.pop = std::stol(population);
            result.push_back(ci);
        }
        return result;
    }

    /*
    \brief      Find the max name's length within a vector of struct
    \param[in]  result -> reference to vector of struct
    \return     value of the longest name's length
    */
    size_t max_name_length(std::vector<CountryInfo> const& result){
        size_t maxl{0}, i{0};
        for(; i < result.size(); i++){
            if(maxl < result[i].name.size()){
                maxl = result[i].name.size();
            }
        }
        return maxl;
    }

    /*
    \brief      Sort out vector using specified comparisons methods
    \param[in]  rv  -> reference to struct vector
    \parma[in   cmp -> function pointer
    */
    void sort(std::vector<CountryInfo>& rv, Ptr_Cmp_Func cmp){
      int size = rv.size();
      for(int i = 0; i < size-1; i++){
        int min_index = i;
        for(int j = i+1; j < size; j++){
          if(cmp(rv[j], rv[min_index])){
            min_index = j;
          }
        }
        std::swap(rv[min_index], rv[i]);
      }

    }

    /*
    \brief      write out struct vector to output text file
    \param[in]  v   -> reference to struct vector
    \param[in]  os  -> output stream
    \param[in]  fw  -> format padding
    */
    void write_to_ostream(std::vector<CountryInfo> const& v,std::ostream& os, size_t fw){
      for(size_t i = 0; i < v.size() ; i++){
        os << std::setw(fw) << std::left << v[i].name << v[i].pop << std::endl;
      }
    }

    /*
    \brief      compare left and right 's name lexicographically
    \param[in]  left    -> reference to struct to be compared against
    \param[in]  right   -> reference to struct to be compared with 
    \return     boolean result if left's name is lexicographically less than right's name
    */
    bool cmp_name_less(CountryInfo const& left, CountryInfo const& right){
        return left.name < right.name ? true : false;
    }

    /*
    \brief      compare left and right 's name lexicographically
    \param[in]  left    -> reference to struct to be compared against
    \param[in]  right   -> reference to struct to be compared with 
    \return     boolean result if left's name is lexicographically more than right's name
    */
    bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right){
        return left.name > right.name ? true : false;

    }

    /*
    \brief      compare left and right 's population
    \param[in]  left    -> reference to struct to be compared against
    \param[in]  right   -> reference to struct to be compared with 
    \return     boolean result if left's population is lesser than right's population 
    */
    bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right){
        return left.pop < right.pop;
    }

    /*
    \brief      compare left and right 's population
    \param[in]  left    -> reference to struct to be compared against
    \param[in]  right   -> reference to struct to be compared with 
    \return     boolean result if left's population is greater than right's population 
    */
    bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right){
        return left.pop > right.pop;
    }
}