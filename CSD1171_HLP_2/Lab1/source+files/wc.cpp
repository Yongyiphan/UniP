
// Don't forget to include file-header and function-level Doxygen documentation blocks!!!
// A handout on documenting code using Doxygen is available on the course web page.

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
  std::tuple<std::size_t, std::size_t> word_count(char* line){
      size_t wc = 0, bc = 0;
      char prev = ' ';
      while(*line != '\0'){
        if (*line == ' ' && prev != ' '){
          wc++;
        }
        prev = *line;
        bc++;
        line++;
      }
      if(prev != ' '){
        wc++;
      }
      return std::make_pair(wc, bc);
  }

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
  \details  PseudoCode
    Init line_c, word, byte counter
    for each fiel in argv
      init line, word byte, counter*/
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
      char line[MAX_LINE_LEN];
      if (!reader){
        return;
      }
      while(reader.getline(line, MAX_LINE_LEN - 1)){
        iline_c++;
        std::tuple<std::size_t, std::size_t> result = word_count(line);
        iword_c += int(std::get<0>(result));
        ibyte_c += int(std::get<1>(result));
      }
      std::cout << line;
      ibyte_c += iline_c;
      printsingle(iline_c, iword_c, ibyte_c);
      std::cout << argv[i] << "\n";
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
