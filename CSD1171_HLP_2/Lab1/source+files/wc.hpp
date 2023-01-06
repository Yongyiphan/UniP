// Don't forget to include file-header and function-level Doxygen documentation blocks!!!
/*!*****************************************
 \file      wc.hpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 1
 \date      06-01-2023
 \brief     File-header Documentation for wc.hpp
    
*/

// A handout on documenting code using Doxygen is available on the course web page.
// Our convention is use suffix hpp for header files that will be consumed by C++ source files!!!

// We must always provide header guards in every header file to avoid types being defined
// multiple times [which will be flagged by the compiler]. This happens when this file
// will be included multiple times in a source file.
#ifndef WC_HPP
#define WC_HPP

// No header files must be included here!!!
// The presence of preprocesser directive include in this file will prevent compilation of your code.

// To avoid name clashes, everything we do this must be declared and defined in namespace hlp2:

namespace hlp2 {
// Add function-level Doxygen documentation block for function wc!!!
/*!****************************************
 \brief     Function Level Documentation
 \param[in] argc
    Number of files
 \param[in] argv
    Filename
 \return
   None
 \exception
   None

*/
    void wc(int argc,char **argv);
} // end namespace hlp2

#endif // end header guard
