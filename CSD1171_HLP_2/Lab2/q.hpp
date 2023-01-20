
/*!*****************************************
 \file      q.hpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 2
 \date      13-01-2023
 \brief     File-header Documentation for q.hpp
 \brief     Contains definition of  function 
            read_tsunami_data -> that reuturns an array of tsunmai struct fill with data read from file
            print_tsunami_data-> that prints out tsunami struct in a format
*/

#ifndef Q_HPP
#define Q_HPP

// This file can have only one include directive ...

// required since type Tsunami has data member of type std::string
#include <string> // don't remove

namespace hlp2 {
  
  struct Tsunami {
    // declare data members ...
    int month, day, year, fatal;
    double wh;
    std::string location;


  };
  
  // declaration of interface functions ...
  /*!
  \brief Function that read from a file by line, store data into a struct of Tsunami
  \param[in] file_name string that represents the input file to read from;
  \param[in] max_cnt   the number pointer that needs to be updated with the number of struct entry found
  \returns  
    A arrays of struct Tsunmai that contains data filled from text file
    max_cnt update with the number of structs found
  */
  Tsunami * read_tsunami_data(std::string const&file_name, int &max_cnt);

  /*!
  \brief Print out data stored in a array of tsunmai struct in a format, analysis of wave height done and printed out 
  \param[in]  arr array of tsunami struct
  \param[in]  size  number of struct
  \param[in]  file_name string that represents output file name.
  \return     None
  */
  void print_tsunami_data(Tsunami const *arr , int size, std::string const &file_name);

  
  
} // end namespace hlp2
#endif
