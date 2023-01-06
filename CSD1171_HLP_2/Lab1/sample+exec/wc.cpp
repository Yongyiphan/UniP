
/*!************************************************************************
\file    wc.cpp
\author  Darryl.Dan
\par     DP email: d.dan\@digipen.edu
\par     Course: CSD 1171
\par     Lab 1
\date    06-01-2023
\brief
  This source file implements functions for File I/O.

\details
  The functions include:
  - wc
    Calculates & displays number of lines, words, and bytes in a file.
**************************************************************************/

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
  
}

// Now, define function wc in namespace hlp2 ...
namespace hlp2 {
  // define function wc here ...
  void wc(int argc, char **argv){
    int total_line=0, total_word=0, total_byte=0;

    for(int i=1;i<argc; i++){

  // Read the file character by character
      int c;
      int line_count=0, word_count=0, byte_count=0;
      // char line[MAX_LINE_LEN];
      std::ifstream fs(argv[i]);
      char last = ' ';

      /*while((c = fs.get())!=EOF){
      byte_count++;
      if( c == ' ' && last != ' '){word_count++; std::cout <<" " << word_count;}
      if( c =='\n'){line_count++;}
      last=c;
      std::cout << char(c);
      }
      if(last != '\n' && last != ' '){
        word_count++;
      }*/
  while ((c = fs.get()) != EOF) {
    // Increment the byte count
    ++byte_count;

    // Increment the word count if this is a space and the previous character was not a space
    if (c == ' ' && last != ' ') {
      ++word_count;
    }

    // Increment the line count if this is a newline
    if (c == '\n') {
      if (last != ' '){
        word_count++;
      }
      ++line_count;
    }

    last = c;
  }

  // Increment the word count if the file ended in a word
  if (last != ' ' && last != '\n') {
    ++word_count;
  }

      // while(fs.getline(line, MAX_LINE_LEN-1)){

      //   line_count++;

      //   int length=0;
      //   while (true){
      //     if(line[length]=='\0')break;
      //     length += 1;
      //   }
      //   byte_count += length;

      //   int words = 0;
      //   char last = ' ';
      //   for(int i =0; i< length; i++){
      //     if(last == ' ' && line[i] != ' '){
      //       words++;
      //     }
      //     last = line[i];
      //   }
      //   word_count += words;
      // }
      fs.close();
      std::cout << std::setw(7) << line_count << std::setw(8) << word_count << std::setw(8) << byte_count << " " << argv[i] << "\n";
      total_line += line_count;
      total_word += word_count;
      total_byte += byte_count;
    }
    if(argc > 2)std::cout << std::setw(7) << total_line << std::setw(8) << total_word << std::setw(8) << total_byte << std::setw(8) << "total\n";
  }
} // end namespace hlp2
