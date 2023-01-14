/*!*****************************************
 \file      q.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 1
 \date      11-01-2023
 \brief     File-header Documentation for q.cpp
 \brief     Contains definition of  function q
            which read from a file, analyse and write values to a provided output file in table format
*/
#include <iostream>
#include <iomanip>
#include <fstream>


namespace hlp2 {
  /*!
  \brief Print out values in a format
  \param[in] ofs output file strea
  \param[in] spacing spacing for the texts
  \param[in] Header string to print at the start of the row
  \param[in] count value to output
  \param[in] perc  value's frequency in percentage
  */
  void prow(std::ofstream &ofs, int spacing, char const* Header, int count, float perc){
    ofs <<  std::left  << std::setw(spacing) << Header <<
            std::right << std::setw(spacing) << count  << 
            std::fixed << std::setw(spacing + 2) << std::setprecision(2) << perc << " %" << std::endl;
  }
  // provide definition of q here ...
  /*!
  \brief  Function that reads from an input file and 
          count the number of digits, white space, characters and its frequency percentage, 
          number of number, sum and average of numbers
          in a formatted table. 
  \param[in] input_filename input filename
  \param[in] analysis_file  output filename
  \return    None
  */
  void q(char const *input_filename, char const *analysis_file){

    std::ifstream ifs(input_filename);
    std::ofstream  ofs;
    ofs.open(analysis_file); 
    if(!ifs){
      std::cout << "File " << input_filename << " not found." << std::endl;
      return;
    }
    if(!ofs.is_open()){
      std::cout << "Unable to create output file " << analysis_file << "." <<std::endl;
      return;
    }


    //Handle Output
    char c;
    bool numf = false; //if number is found
    int ac[26] = {}; //array of respective alphabet count
    int dc, inttracker , intcounter , intsum , ltrc  , lc  ,  wsc ,  oc  ,  tc; 
    dc = inttracker = intcounter = intsum = ltrc  = lc  =  wsc =  oc  =  tc  = 0; 

    while((c = ifs.get()) != EOF){
      tc++;
      int ci(c);
      if(isdigit(ci)){
        if(!numf){
          intcounter++;
          numf = true;
        }
        if(numf){
          c -= '0';
          if(inttracker == 0){
            inttracker += c;
          }
          else{
            inttracker = inttracker*10 + c;
          }
        }
        dc++;
      }
      else{
        numf = false;
        intsum += inttracker;
        inttracker = 0;
        if(c == ' ' || c == '\n'){
          wsc++;
        }
        if(isalpha(ci)){
          if(islower(ci)){
            lc++;
            c -= 32;
          }
          ltrc++;
          ac[c - 65]++;
        }
      }
    }
    oc = tc - dc - wsc - ltrc;
    int s1 = 18;
    std::string lineborder{"---------------------------------------------------------------------" };
    ofs << "Statistics for file: " << input_filename << std::endl;
    ofs << lineborder << '\n' << std::endl;
    ofs << "Total # of characters in file: " << tc  << "\n"<< std::endl;
    ofs <<  std::left  << std::setw(s1)  << "Category" << 
            std::right << std::setw(s1)  << "How many in file" << 
                          std::setw(s1 + 4) << " % of file" << std::endl;
    ofs << lineborder << std::endl;

    prow(ofs, s1, "Letters",           ltrc,  ltrc * 100.0f/tc);
    prow(ofs, s1, "White space",       wsc, wsc* 100.0f/tc);
    prow(ofs, s1, "Digits",            dc,  dc * 100.0f/tc);
    prow(ofs, s1, "Other characters",  oc,  oc * 100.0f/tc);
    
    ofs << "\n\nLETTER STATISTICS\n" << std::endl;
    ofs <<  std::left  << std::setw(s1)  << "Category" << 
            std::right << std::setw(s1)  << "How many in file" << 
                          std::setw(s1 + 4) << " % of all letters" << std::endl;
    ofs << lineborder << std::endl;
    prow(ofs, s1, "Uppercase",         ltrc - lc,  100.0f - lc * 100.0f/ltrc);
    prow(ofs, s1, "Lowercase",         lc,         lc * 100.0f/ltrc);
    
    for(int i = 0; i < 26; i++){
      std::string cc{(char)('a' + i)};
      prow(ofs, s1, cc.c_str(), ac[i], ac[i] * 100.0f / ltrc);
    }

    ofs << "\n\nNUMBER ANALYSIS\n" << std::endl;
    float avg = intcounter != 0 ? float(intsum) / intcounter : 0.0f;
    ofs << std::left << std::setw(37) << "Number of integers in file:"  << std::setprecision(2) << intcounter << std::endl;
    ofs << std::left << std::setw(37) << "Sum of integers:"             << std::setprecision(2) << intsum << std::endl;
    ofs << std::left << std::setw(37) << "Average of integers:"         << std::setprecision(2) << avg << std::endl;
    ofs << "_____________________________________________________________________" << std::endl;
    ifs.close();
  }
}
