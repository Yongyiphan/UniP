/*!*****************************************
 \file      vector.hpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 5
 \date      19-02-2023
 \brief     File-header Documentation for vector.hpp
 \brief     This file contains the implementation of a vector class
            with member functions that allows
              constructors using:
                1. a vector with starting size of type size_type
                2. a vector using another vector object
                3. a vector using a initializer_list object
              destructor
              operator assignment overload that allows assignment using
                1. reference to another vector
                2. initializer_list object
              operator subsript overload with non-const and const version
              Setter functions:
                reserve() -> allocate memory of the vector
                resize()  -> resize the vector
                push_back() -> adds a value to vector
              Getter functions:
                empty()   -> checks if vector is empty
                size()    -> returns the no. of elements in the vector
                capacity()-> returns the total memory space allocated to the vector
                allocations() -> returns the number of times memory has been allocated to the vector
                begin()   -> Pointer to the start of vector (with const variant)
                end()     -> Pointer to the end of vector (with const variant)

*/

////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR_HPP
#define VECTOR_HPP
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>          // need this for size_t
#include <initializer_list> // need this for std::initializer_list<int>
// read the specs to know which standard library headers cannot be included!!!
namespace hlp2 {
	
class vector {
public:
  // types to declare: size_type, value_type,
  using size_type = size_t;
  using value_type = int;
  // reference, const_reference, pointer, const_pointer
  using reference = value_type&;
  using const_reference = const reference;
  using pointer = value_type*;
  using const_pointer = const value_type*;

public:
  /*
  \brief    Default constructor
  */
  vector();
  
  /*
  \brief      Constructor with initial vector size
  \param[in]  n -> size of initial vector
  */
  explicit vector(size_type n);

  /*
  \brief      Constructor using initializer_list to fill vector
  \param[in]  rhs -> list to construct vector from
  */
  vector(std::initializer_list<int> rhs);
  
  /*
  \brief      Constructor using another vector object
  \param[in]  rhs -> reference to target object to construct from
  */
  vector(vector const&rhs);
  
  /*
  \brief      Default destructor
  */
  ~vector();
  
  /*
  \brief      Copy assignment using another vector object
  \param[in]  rhs -> reference to vector to copy contents from
  \return     reference to current vector object
  */
  vector& operator=(vector const& rhs);
  

  /*
  \brief      Copy assignment using initializer_list object
  \param[in]  rhs -> reference to initializer_list to copy contents from
  \return     reference to current vector object
  */
  vector& operator=(std::initializer_list<int> rhs);
  
  /*
  \brief      Subscript operator overload
  \param[in]  i -> index of array to modify
  \return     reference to value at index
  */
  reference operator[](size_type i );
  
  /*
  \brief      Subscript operator overload
  \param[in]  i -> index of array to modify
  \return     const reference to value at index
  */
  const_reference operator[](size_type i) const;
  
  /*
  \brief      Add value to end of vector
  \param[in]  value -> value to be added at the end of the array
  */
  void push_back(value_type value);
  
  /*
  \brief      Function to change size/ increase size of vector
  \param[in]  newsize -> new size of vector
  */
  void reserve(size_type newsize);
  
  /*
  \brief      Function to resize vector to contain n elements
  \param[in]  newsize -> new size of vector
  */
  void resize(size_type newsize);
  
  
  /*
  \brief      Checks if vector is empty
  \return     boolean value of whether vector is empty
  */
  bool empty() const;
  
  /*
  \brief      Get Size of vector, no. of elements in vector
  \returns    no. of elements in vector
  */
  size_type size() const;
  
  /*
  \brief      Get total space allocated to the vector
  \return     total space allocated to vector
  */
  size_type capacity() const;
  
  /*
  \brief      Get number of times reallocation vector went through
  \returns    no. of allocation done to vector object
  */
  size_type allocations() const;
  
	/*
  \brief      Pointer to start of vector
  \return     Pointer to start of vector
  */
  pointer begin();
  
  /*
  \brief      Pointer to end of vector
  \return     Pointer to end of vector
  */
  pointer end();
  
	/*
  \brief      Pointer to start of vector
  \return     const Pointer to start of vector
  */
  const_pointer begin() const;
  
  /*
  \brief      Pointer to end of vector
  \return     const Pointer to end of vector
  */
  const_pointer end() const;
  
	/*
  \brief      Pointer to start of vector
  \return     const Pointer to start of vector
  */
  const_pointer cbegin() const;
  
  /*
  \brief      Pointer to end of vector
  \return     const Pointer to end of vector
  */
  const_pointer cend() const;
  

private:
  size_type sz;     // the number of elements in the array
  size_type space;  // the allocated size (in terms of elements) of the array
  size_type allocs; // number of times space has been updated
  pointer   data;   // the dynamically allocated array (int*)
};

} // namespace hlp2

#endif // VECTOR_HPP
