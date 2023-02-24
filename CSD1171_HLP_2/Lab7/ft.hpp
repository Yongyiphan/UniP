// make sure to add file-level documentation here!!!

//-------------------------------------------------------------------------
#ifndef FT_H
#define FT_H
//-------------------------------------------------------------------------
#include <iostream>
// Do not add any other header files. Otherwise, your submission
// will not compile!!!

namespace hlp2 {
// DECLARE (not define!!!) and DOCUMENT in ALPHABETIC ORDER the function
// templates you'll be defining. There are *13* function templates to be
// declared and defined.
  
// I'm providing the declaration and documentation for swap here:
/***************************************************************************/
/*!
\brief
 Swaps two objects. There is no return value but the two objects are
 swapped in place.

\param lhs
  Reference to the first object to swap.

\param rhs
 Reference to the second object to swap.
*/
/**************************************************************************/
  
// Provide DEFINITIONS for each function template declared above ...

template <typename I, typename T> T     copy(const I &start,const I &end, T dst);
template <typename I, typename T> int   count(const I &start,const I &end, T value);
template <typename T>             void  display(const T &lhs,const T &rhs);
template <typename T>             bool  equal();
template <typename I, typename T> void  fill(const I &start,const I &end, T index);
template <typename I, typename T> I     find(const I& start, const I&end, T value);
template <typename T>             T     max_element(const T&start, const T&end);
template <typename T>             T     min_element(const T&start, const T&end);
template <typename I, typename T> I     remove(const I &start,const I &end, T index);
template <typename I, typename T> void  replace(const I &start,const I &end, T oitem, T nitem);
template <typename I, typename T> T     sum(const I&start, const I&end);
template <typename T>             void  swap(T &lhs, T &rhs);
template <typename T>             void  swap_ranges(const T&start1, const T&end1, const T&start2);

template <typename I, typename T> T     copy(const I &start,const I &end, T dst){
  
  for (; start != end; (void)++start, (void)++dst)
        *dst = *start;
 
  return dst;

}


template <typename I, typename T> int   count(const I &start,const I &end, T value){
  int c{};
  while(start != end){
    if(*start++ == value){
      c++;
    }
  }
  return c;
}

template <typename T>             void  display(const T &start,const T &end){
  while(start != end){

  }
}

}

#endif
//-------------------------------------------------------------------------
