// make sure to add file-level documentation here!!!
/*!*****************************************
 \file      ft.hpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 7
 \date      26-02-2023
 \brief     File-header Documentation for point.hpp
 \brief     Contains delcaration and definition of function templates that:
              copy()        -> copy contents from a container to another container
              count()       -> count occurance of a target value within container
              display()     -> display contents of container
              equal()       -> check if two containers' elements are equal
              fill()        -> fill a container with target value
              find()        -> find position of target value within container if exist
              max_element() -> find max valued element in container
              min_element() -> find min valued element in container
              remove()      -> remove a target value from container
              replace()     -> replace a target value from container
              sum()         -> sum up value within container
              swap()        -> swap two object's value in-place
              swap_ranges() -> swap elements between two element

*/
////////////////////////////////////////////////////////////////////////////////

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
  
/*
\brief      copy contents from a container to another container
\param[in]  *start  -> pointer to start of source container
\param[in]  *end    -> pointer to end of source container
\param[in]  *dst    -> pointer to start of target container
\return     pointer to end of target container
*/
template <typename I>             I*      copy(const I* start, const I* end, I* dst);

/*
\brief      count the number of occurance of a target value
\param[in]  *start  -> pointer to start of container
\param[in]  *end    -> pointer to end of container
\param[in]  value   -> value to count occurance of
\return     number of occurance
*/
template <typename I, typename T> int     count( I*  start, I*  end, T value);

/*
\brief      print out elements of a container, separated by comma 
\param[in]  *start  -> pointer to start of container
\param[in]  *end    -> pointer to end of container
*/
template <typename I>             void    display(const I* start, const I* end);

/*
\brief      check if two containers are equal
\param[in]  *start1  -> pointer to start of first container
\param[in]  *end1    -> pointer to end of first container
\param[in]  *start2 -> pointer to start of second container
\return     true if both containers are same, false if not
*/
template <typename I, typename T> bool    equal(  I* start1,  I* end1,  T* start2);

/*
\brief      fill a container with a given value
\param[in]  *start  -> pointer to start of container
\param[in]  *end    -> pointer to end of container
\param[in]  value   -> value to fill container with
*/
template <typename I, typename T> void    fill( I*  start, I* end, T value);

/*
\brief      find position of a value within a container
\param[in]  *start  -> pointer to start of container
\param[in]  *end    -> pointer to end of container
\param[in]  value   -> value to find
*/
template <typename I, typename T> I*      find( I*  start, I* end, T value);

/*
\brief      find the max valued element in container
\param[in]  *start  -> pointer to start of container
\param[in]  *end    -> pointer to end of container
\return     position of the max valued element
*/
template <typename I>             I*      max_element( I* start,  I* end);

/*
\brief      find the min valued element in container
\param[in]  *start  -> pointer to start of container
\param[in]  *end    -> pointer to end of container
\return     position of the min valued element
*/
template <typename I>             I*      min_element( I* start,  I* end);

/*
\brief      remove a given value if exist from the container
\param[in]  *start  -> pointer to start of container
\param[in]  *end    -> pointer to end of container
\param[in]  value   -> value to be removed
\return     return pointer to end of container with given value removed from container
*/
template <typename I, typename T> I*      remove( I* start, I* end, T value);

/*
\brief      replace a given value with a new value provided
\param[in]  *start  -> pointer to start of container
\param[in]  *end    -> pointer to end of container
\param[in]  oitem   -> old item within container to be replaced
\param[in]  nitem   -> new item to replace old item with
*/
template <typename I, typename T> void    replace( I*  start, I*  end, T oitem, T nitem);

/*
\brief      sum value of elements within container
\param[in]  *start  -> pointer to start of container
\param[in]  *end    -> pointer to end of container
\param[in]  return sum calculated
*/
template <typename T> T     sum( T* start,  T* end);

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
template <typename T>             void  swap(T &lhs, T &rhs);

/*
\brief      swap element between two container
\param[in]  *start1 -> pointer to start of first container
\param[in]  *end1   -> pointer to end of first container
\param[in]  *start2 -> pointer to start of second container
*/
template <typename I>             void  swap_ranges( I* start1,  I* end1,  I* start2);



//FUNCTION TEMPLATE DEFINITIONS
template <typename I>             I*    copy(const I* start, const I* end, I* dst){
  for(; start < end; *dst = *start, ++dst, ++start);
  return dst;
}

template <typename I, typename T> int   count( I*  start, I*  end, T value){
  int c{};
  for(; start < end; ++start)
    if(*start == value)
      c++;
  
  return c;
}

template <typename I>             void  display(const I* start, const I* end){
  while(start < end){
    std::cout << *start;
    if(++start != end)
      std::cout << ", ";
  }
  std::cout << std::endl;
}

template <typename I, typename T> bool  equal(  I* start1,  I* end1,  T* start2){
  for(;start1 < end1; ++start1, ++start2){
    if(*start1 != *start2)
      return false;
  }
  return true;
}

template <typename I, typename T> void  fill( I*  start, I* end, T value){
  for(;start < end; ++start)
    *start = value;
}

template <typename I, typename T> I*     find( I*  start, I* end, T value){
  for(;start < end; ++start)
    if(*start == value)
      return start;
  return start;
}

template <typename I>             I*     max_element( I* start,  I* end){
  I* m = start;
  for(; start < end; ++start){
    if(*start < *m){
      continue;
    }
    m = start;
  }
  return m;
}

template <typename I>             I*     min_element( I* start,  I* end){
  I* m = start;
  for(; start < end; ++start){
    if(*start < *m)
      m = start;
  }
  return m;
}

template <typename I, typename T> I*     remove( I* start, I* end, T value){
  I* newEnd = start;
  for(; start < end; ++start){
    if(*start == value) continue;
    *newEnd = *start;
    ++newEnd;
  }
  return newEnd;
}

template <typename I, typename T> void  replace( I*  start, I*  end, T oitem, T nitem){
  for(; start < end; ++start)
    if(*start == oitem)
      *start = nitem;
}

template <typename T>             T     sum( T* start,  T* end){
  T total{};
  for(;start < end; total += *start, ++start);
  return total;
}

template <typename T>             void  swap(T &lhs, T &rhs){
  T temp = lhs;
  lhs = rhs;
  rhs = temp;
}

template <typename I>             void  swap_ranges( I* start1,  I* end1,  I* start2){
  for(;start1 < end1; ++start1, ++start2){
    swap(*start1, *start2);
  }
}



}

#endif
//-------------------------------------------------------------------------
