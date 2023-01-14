/*!*****************************************
 \file      q.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 1
 \date      11-01-2023
 \brief     File-header Documentation for q.cpp
 \brief     Contains declaration of  function q
            which read from a file, analyse and write values to a provided output file in table format
*/
#ifndef Q_HPP_
#define Q_HPP_


namespace hlp2 {
  // declare function q here ...
  /*!
  \brief  Function that reads from an input file and 
          count the number of digits, white space, characters and its frequency percentage, 
          number of number, sum and average of numbers
          in a formatted table. 
  \param[in] input_filename input filename
  \param[in] analysis_file  output filename
  \return    None
  */
  void q(char const *input_filename, char const *analysis_file);

}

#endif
