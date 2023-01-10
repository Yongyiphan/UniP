
// Don't forget to include file-header and function-level Doxygen documentation blocks!!!
// A handout on documenting code using Doxygen is available on the course web page.

/*!*****************************************
 \file      wc.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 1
 \date      06-01-2023
 \brief     File-header Documentation for wc.cpp
*/
// Your definition of function wc can only rely on the following C++ Standard Library headers:

#include <iostream>
#include <iomanip>
#include <fstream>


// The use of functions declared in C Standard Library will be a violation of the Academic Integrity Policy ...
// If you are unsure about whether a function is declared in the Standard C library, use this reference: https://en.cppreference.com/w/c/header

// A text file consists of zero or more linesm, each line terminated by a line feed '\n' character.
// Watch out - don't use Windows OS programs [such as notepad.exe] to open and edit your text files.
// This is because Windows text files terminate each line by a carriage return '\r' character followed by a line feed '\n'.

// We don't want to deal with dynamic memory allocation/deallocation. Instead, we'll assume the longest length
// of a line [in any of the files that we'll process] is 2048 characters [including the null terminating character].

// This is an anonymous namespace - i.e., a namespace with no name.
// Anonymous namespaces are used by C++ programmers to make names declared at global scope private to this source file:
namespace {
  const size_t MAX_LINE_LEN {2048};

}

// In C++ [unlike in C], variable MAX_LINE_LEN is considered a constant expression [i.e. like a literal].
// Therefore, you can define a static char array with dimension MAX_LINE_LEN that can be used to store the
// characters of each line of text that you'll read in each of the source files that you'll process ...

// Helper functions must also be private to this source file and must therefore be declared/defined in
// an anonymous namespace ...
namespace {
  // Declare/define your helper functions here ...
  /*!
  \brief      Find number of words within a string (sentence)
  \param[in]  line Pointer to start of char[]
  \return     Word Count
  */
  int getwc(char *line){
    int iword_c = 0;
    char *s, prev;
    for(s = line, prev = ' '; *s != '\0'; prev = *s, s++){
      if(*s == ' ' && prev != ' '){
        iword_c++;
      }
    }
    //Check if sentence ends with a word
    if(prev != ' '){
      ++iword_c;
    }
    return iword_c;
}
  /*!
  \brief      Function to print out values in desired table format
  \param[in]  lc Line Count
  \param[in]  wc Word Count
  \param[in]  bc Byte Count
  \return     None
  */
  void printsingle(int lc, int wc, int bc){
    int spacing = 7;
    std::cout << std::setw(spacing) << lc << " ";
    std::cout << std::setw(spacing) << wc << " ";
    std::cout << std::setw(spacing) << bc << " ";
  }
}

// Now, define function wc in namespace hlp2 ...
namespace hlp2 {
  // define function wc here ...
  /*!
  \brief      Find the word count in a file
  \param[in]  argc Number of files passed as argument
  \param[in]  argv String of filenames passed as argument
  \return     None
  \exception  File Close, function exits if unable to open file
  */
  void wc(int argc, char **argv){
    //Initialise Counters
    int line_c = 0, word_c = 0, byte_c = 0;
    int iline_c, iword_c, ibyte_c;
    //Connect to file provided in argv
    for (int i = 1; i < argc; i++){
      iline_c = 0, iword_c = 0, ibyte_c = 0;
      //Open File
      std::ifstream reader(argv[i]);
      if (!reader){
        return;
      }
      int ct = 0;
      char c, line[MAX_LINE_LEN];
      while((c = reader.get()) != EOF){
        ibyte_c++;
        if(c == '\n'){
          iline_c++;
          line[ct] = '\0';
          iword_c += getwc(line);
          ct = 0;
          continue;
        }
        line[ct++] = c;
      }
      line[ct] = '\0';
      iword_c += getwc(line);

      printsingle(iline_c,iword_c, ibyte_c);
      std::cout << argv[i] << std::endl;
      line_c += iline_c;
      word_c += iword_c;
      byte_c += ibyte_c;
      reader.close();
    }
    if (argc > 2){
      printsingle(line_c, word_c, byte_c);
      std::cout << "total" << "\n";
    }
    
  }
} // end namespace hlp2
