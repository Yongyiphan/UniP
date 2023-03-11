// File header documentation is required!!!
/*!*****************************************
 \file      array.hpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 9
 \date      11-03-2023
 \brief     File-header Documentation for array.hpp
 \brief     Contains delcaration of template class array
 \brief     Member Functions for array template class for
            Constructor, Descructor, Copy assignment are declared/defined implicitly
            []  -> subscript operator overload (with const variant)
            empty() -> check if array is empty
            size()  -> get the size of the array
            swap()  -> swap contents between two array
            fill()  -> fill in the array with a given value

            Accessors
              begin(), begin() const, cbegin()  -> getting iterator to the start of array
              end(), end() const, cend()        -> getting iterator to the end of array
              front() -> reference to front element of array (with const variant)
              back()  -> reference to last element of the array (with const variant)
              data()  -> pointer to array container
            Non member functions
              Operator overloads for ==, !=, <, >
              Swap()  -> swap between two given targets


*/
//-------------------------------------------------------------------------
#ifndef ARRAY_HPP_
#define ARRAY_HPP_
//-------------------------------------------------------------------------

#include "initializer_list"
#include <cstdlib>
#include <cstddef> // for size_t

namespace hlp2 {



template <class T, size_t N>
class Array{
public:
  /*
  \brief    Type aliases
  */
  using value_type              = T;
  using size_type               = size_t;
  using reference               = value_type&;
  using pointer                 = value_type*;
  using iterator                = pointer;
  using const_reference         = const value_type&;
  using const_pointer           = const value_type*;
  using const_iterator          = const_pointer;

  using reverse_iterator        = pointer;
  using const_reverse_iterator  = const_pointer;

public:
  /*
  \brief      Operator subscript overload
  \param[in]  i -> index to access the array
  \return     reference to value at index
  */
  reference               operator[](size_type i)      ;
  
  /*
  \brief      Operator subscript overload
  \param[in]  i -> index to access the array
  \return     const reference to value at index
  */
  const_reference         operator[](size_type i) const;

  /*
  \brief      Check if array is empty
  \return     true if array is empty
  */ 
  bool empty() const;

  /*
  \brief      Gets the size of the array
  \return     number of elements in the array
  */
  size_type size() const;


  /*
  \brief      Swap contents between two array
  \param[in]  rhs -> reference to array to swap with
  */  
  void swap(Array<T,N>&rhs);

  /*
  \brief      fill array with given value
  \param[in]  value -> value to fill in the array with
  */
  void fill(T value);


  /*
  \brief      Accessor for array container
  \return     Pointer to array container
  */
  pointer                 data()         ;

  /*
  \brief      Accessor for array container
  \return     Const Pointer to array container
  */
  const_pointer           data()    const;

  /*
  \brief      Get first element of array
  \return     reference to first element of array
  */ 
  reference               front()        ;

  /*
  \brief      Get first element of array
  \return     const reference to first element of array
  */ 
  const_reference         front()   const;

  /*
  \brief      Get last element of array
  \return     reference to last element of array
  */ 
  reference               back()         ;

  /*
  \brief      Get last element of array
  \return     const reference to last element of array
  */ 
  const_reference         back()    const;

  /*
  \brief      Get pointer to start of array
  \return     Pointer to start of array
  */
  iterator                begin()        ;

  /*
  \brief      Get pointer to start of array
  \return     Const Pointer to start of array
  */
  const_iterator          begin()   const;

  /*
  \brief      Get pointer to start of array
  \return     Const Pointer to start of array
  */
  const_iterator          cbegin()  const;


  /*
  \brief      Get pointer to end of array
  \return     Pointer to end of array
  */
  reverse_iterator        end()          ;

  /*
  \brief      Get pointer to end of array
  \return     const Pointer to end of array
  */
  const_reverse_iterator  end()     const;

  /*
  \brief      Get pointer to end of array
  \return     const Pointer to end of array
  */
  const_reverse_iterator  cend()    const;

public:
  /*
  \brief      Array container
  */
  T _data[N];


};


/*
\brief        swap content between 2 given object
*/
template <typename T>
void swap(T&lhs, T&rhs);


/*
\brief        Operator == overload to check if two arrays are equal
\param[in]    lhs -> reference to array on the left-hand side of the expression;
\param[in]    rhs -> reference to array on the right-hand side of the expression;
\return       true if both arrays are equal
*/
template <typename T, size_t N>
bool operator==(Array<T,N>&lhs, Array<T,N>&rhs);

/*
\brief        Operator != overload to check if two arrays are not equal
\param[in]    lhs -> reference to array on the left-hand side of the expression;
\param[in]    rhs -> reference to array on the right-hand side of the expression;
\return       true if both arrays are not equal
*/
template <typename T, size_t N>
bool operator!=(Array<T,N>&lhs, Array<T,N>&rhs);

/*
\brief        Operator < overload to check if an array is smaller lexicographically than another array
\param[in]    lhs -> reference to array on the left-hand side of the expression;
\param[in]    rhs -> reference to array on the right-hand side of the expression;
\return       true if lhs array is smaller than rhs
*/
template <typename T, size_t N>
bool operator< (Array<T,N>&lhs, Array<T,N>&rhs);

/*
\brief        Operator > overload to check if an array is bigger lexicographically than another array
\param[in]    lhs -> reference to array on the left-hand side of the expression;
\param[in]    rhs -> reference to array on the right-hand side of the expression;
\return       true if lhs array is bigger than rhs
*/
template <typename T, size_t N>
bool operator> (Array<T,N>&lhs, Array<T,N>&rhs);


} // end namespace hlp2

// EVERY member and non-member function must be defined 
// in separate file array.tpp
#include "array.tpp"

#endif // end ARRAY_HPP_
