/*!*****************************************
 \file      vector.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 5
 \date      19-02-2023
 \brief     File-header Documentation for vector.cpp
 \brief     This file contains the implementation of a vector class
            with member functions that allows
              constructors using:
                1. a vector with starting size of type size_type
                2. a vector using reference to another vector object
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
#include "vector.hpp"

namespace hlp2{
  /*
  \brief    Default constructor
  */
  vector::vector(): sz(0), space(0), allocs(0), data(nullptr){}

  /*
  \brief      Constructor with initial vector size
  \param[in]  n -> size of initial vector
  */
  vector::vector(size_type n) : sz(n), space(n), allocs(1), data(nullptr){
    data = new value_type[n];
  }

  /*
  \brief      Constructor using initializer_list to fill vector
  \param[in]  rhs -> list to construct vector from
  */
  vector::vector(std::initializer_list<int> rhs) : sz(0), space(0), allocs(0), data(nullptr){
    //data = new value_type[rhs.size()];
    reserve(rhs.size());
    for(int c : rhs){
        push_back(c);
    }
  }
  
  /*
  \brief      Constructor using another vector object
  \param[in]  rhs -> reference to target object to construct from
  */
  vector::vector(vector const &rhs) : sz(0), space(0), allocs(0), data(nullptr){
    //data = new value_type[rhs.size()];
    reserve(rhs.size());
    for(int c : rhs){
        push_back(c);
    }
  }

  /*
  \brief      Default destructor
  */
  vector::~vector(){
    if(data){
        delete[] data;
    }
  }
  
  /*
  \brief      Copy assignment using another vector object
  \param[in]  rhs -> reference to vector to copy contents from
  \return     reference to current vector object
  */
  vector& vector::operator=(vector const& rhs){
    pointer na = new value_type[rhs.size()];
    allocs++;
    size_type i{};
    for(int c: rhs){
        na[i++] = c;
    }
    if(data){
        delete[] data;
    }
    data = na;
    space = rhs.size();
    sz = i;

    return *this;
  }
  
  /*
  \brief      Copy assignment using initializer_list object
  \param[in]  rhs -> reference to initializer_list to copy contents from
  \return     reference to current vector object
  */
  vector& vector::operator=(std::initializer_list<int> rhs){
    pointer na = new value_type[rhs.size()];
    allocs++;
    size_type i{};
    for(int c: rhs){
        na[i++] = c;
    }
    if(data){
        delete[] data;
    }
    data = na;
    sz = space = rhs.size();
    return *this;
  }
  
 
  /*
  \brief      Add value to end of vector
  \param[in]  value -> value to be added at the end of the array
  */
  void vector::push_back(value_type value){
    if(space == 0){
        reserve(1);
    }
    else if( sz == space){
        reserve(space * 2);
    }
    data[sz] = value;
    sz++;
  }
  
  /*
  \brief      Function to change size/ increase size of vector
  \param[in]  newsize -> new size of vector
  */
  void vector::reserve(size_type n){
    if(n <= space)
        return;
    //Init new array
    pointer na = new value_type[n];
    allocs++;
    if(data){
        for(size_type i{}; i < sz; na[i] = data[i], i++);
        delete[] data;
    }
    data = na;
    space = n;
  }
  
  /*
  \brief      Function to resize vector to contain n elements
  \param[in]  newsize -> new size of vector
  */
  void vector::resize(size_type n){
    if(n > space){
        reserve(n);
        sz = n;
    }
    else if(n > sz && n <= space){
        sz = n;
    }
    else if(n < sz){
        sz = n;
    }
    else if(n == sz){
        return;
    }

  }
  
  
  /*
  \brief      Subscript operator overload
  \param[in]  i -> index of array to modify
  \return     reference to value at index
  */
  vector::reference vector::operator[](size_type i)            {return *(data + i);}
  
  /*
  \brief      Subscript operator overload
  \param[in]  i -> index of array to modify
  \return     const reference to value at index
  */
  vector::const_reference vector::operator[](size_type i) const{return *(data + i);}
  
  /*
  \brief      Checks if vector is empty
  \return     boolean value of whether vector is empty
  */
  bool vector::empty()                      const{return space ? true : false;}
  
  /*
  \brief      Get Size of vector, no. of elements in vector
  \returns    no. of elements in vector
  */
  vector::size_type vector::size()          const{return sz;}
  
  /*
  \brief      Get total space allocated to the vector
  \return     total space allocated to vector
  */
  vector::size_type vector::capacity()      const{return space;}
  
  /*
  \brief      Get number of times reallocation vector went through
  \returns    no. of allocation done to vector object
  */
  vector::size_type vector::allocations()   const{return allocs;}
  
  /*
  \brief      Pointer to start of vector
  \return     Pointer to start of vector
  */
  vector::pointer vector::begin()                {return data;}
  
  /*
  \brief      Pointer to end of vector
  \return     Pointer to end of vector
  */
  vector::pointer vector::end()                  {return data + sz;}
  
	/*
  \brief      Pointer to start of vector
  \return     const Pointer to start of vector
  */
  vector::const_pointer vector::begin()           const{return data;}
  
  /*
  \brief      Pointer to end of vector
  \return     const Pointer to end of vector
  */
  vector::const_pointer vector::end()             const{return data + sz;}
  
	/*
  \brief      Pointer to start of vector
  \return     const Pointer to start of vector
  */
  vector::const_pointer vector::cbegin()          const{return data;}
  
  /*
  \brief      Pointer to end of vector
  \return     const Pointer to end of vector
  */
  vector::const_pointer vector::cend()            const{return data + sz;}
  
}