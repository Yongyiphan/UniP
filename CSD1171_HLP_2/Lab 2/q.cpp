/*!*****************************************
 \file      q.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 2
 \date      13-01-2023
 \brief     File-header Documentation for q.cpp
 \brief     Contains definition of  function 
            read_tsunami_data -> that reuturns an array of tsunmai struct fill with data read from file
            print_tsunami_data-> that prints out tsunami struct in a format
*/
// This file can only have these 5 files included and therefore you should not
// remove the following include directives nor provide additional include directives!!!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "q.hpp" // compiler needs definition of type Tsunami

// anonymous namespace for any helper functions that you wish to implement
namespace {
  // ...
}

namespace hlp2 {
  // provide definitions of functions declared in q.hpp here ...
  /*!
  \brief Function that read from a file by line, store data into a struct of Tsunami
  \param[in] file_name string that represents the input file to read from;
  \param[in] max_cnt   the number pointer that needs to be updated with the number of struct entry found
  \returns  
    A arrays of struct Tsunmai that contains data filled from text file
    max_cnt update with the number of structs found
  */
  Tsunami * read_tsunami_data(std::string const&file_name, int &max_cnt){
    std::ifstream ifs{file_name};
    max_cnt = 0;
    if(!ifs){
      std::cout << "Unable to open file: " << file_name << std::endl;
      return nullptr;
    }
    std::string line;
    while(std::getline(ifs, line)){
      max_cnt++;
    }
    ifs.clear();
    ifs.seekg(0);
    Tsunami *record = new Tsunami[max_cnt];
    for(int i=0; i < max_cnt; i++){
      ifs >> record[i].month >> record[i].day >> record[i].year >> record[i].fatal >> record[i].wh;
      std::getline(ifs, line);
      int start = line.find_first_not_of(' ');
      int end   = line.find_last_not_of(' ');
      int range = end - start + 1;
      record[i].location = line.substr(start, range);
    }
    ifs.close();
    return record;

  }
  /*!
  \brief Print out data stored in a array of tsunmai struct in a format, analysis of wave height done and printed out 
  \param[in]  arr array of tsunami struct
  \param[in]  size  number of struct
  \param[in]  file_name string that represents output file name.
  \return     None
  */
  void print_tsunami_data(Tsunami const *arr , int size, std::string const &file_name){
    std::ofstream out(file_name);
    if(!out){
      return;
    }
    out << "List of tsunamis:" << std::endl;
    out << "-----------------" << std::endl;

    int c = 0;
    double max_height = 0.0, sum_height = 0.0, average_height;
    while(c < size){
      Tsunami curr = arr[c];
      out << std::right;
      out << std::setfill('0') << std::setw(2) << curr.month << " ";
      out << std::setfill('0') << std::setw(2) << curr.day   << " ";
      out << std::setfill(' ') << std::setw(4) << curr.year  << " ";
      out << std::right << std::setw(6) << curr.fatal;
      out << std::fixed << std::setprecision(2) << std::setw(11) << curr.wh;
      out << "     ";
      out << std::left  << curr.location << std::endl;
      if(curr.wh > max_height)
        max_height = curr.wh;
      sum_height+= curr.wh;
      c++;
    }
    out << std::endl;
    average_height = sum_height/size;
    out << "Summary information for tsunamis" << std::endl;
    out << "--------------------------------\n" << std::endl;
    out << "Maximum wave height (in meters): " << max_height << "\n" << std::endl;
    out << "Average wave height (in meters): " << std::right << std::setw(5) << average_height << "\n" << std::endl;
    out << "Tsunamis with greater than average height " << average_height << ":" << std::endl;
    out << std::left;
    for(int i =0; i < size; i++){
      if(arr[i].wh > average_height){
        out << std::setw(10) << arr[i].wh << arr[i].location << std::endl;
      } 
    }

  }
}
