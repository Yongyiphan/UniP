/*!*****************************************
 \file      vct.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 6
 \date      09-03-2023
 \brief     File-header Documentation for vct.cpp
 \brief     This file contains the implementation of a vector template class
            with member functions that allows
              constructors using:
                1. default constructor with no parameters
                2. a vector using reference to another vector object
                3. a vector using a initializer_list object
              destructor
              operator copy assignment overload that allows assignment using
                1. reference to another vector
                2. initializer_list object
              operator subsript overload with non-const and const version
              Setter functions:
                push_back() -> adds a value to vector
                pop_back()  -> remove the last element of vector
                reserve()   -> allocate memory of the vector
                resize()    -> resize the vector
                swap()      -> swap contents between two vector
              Getter functions:
                empty()   -> checks if vector is empty
                size()    -> returns the no. of elements in the vector
                capacity()-> returns the total memory space allocated to the vector
                allocations() -> returns the number of times memory has been allocated to the vector
                begin()   -> Pointer to the start of vector (with const variant)
                end()     -> Pointer to the end of vector (with const variant)

*/
////////////////////////////////////////////////////////////////////////////////
#ifndef VCT_HPP
#define VCT_HPP
////////////////////////////////////////////////////////////////////////////////
#include "initializer_list"
#include <cstdlib>

namespace hlp2 {


template <typename T>
class vector {
public:
  // types to declare: size_type, value_type,
  using size_type       = size_t;
  using value_type      = T;
  // reference, const_reference, pointer, const_pointer
  using reference       = value_type&;
  using const_reference = const value_type&;
  using pointer         = value_type*;
  using const_pointer   = const value_type*;

public:
  /*
  \brief      Default constructor
  */
  vector();

  /*
  \brief      Constructor taking in another vector object
  \param[in]  rhs -> reference to target vector object
  */
  vector(vector<T> const &rhs);

  /*
  \brief      Constructor taking in a initializer_list of type T object to fill in vector
  \param[in]  rhs -> reference to target initiazliser list object
  */
  vector(std::initializer_list<T> const& rhs);

  /*
  \brief      Default deconstructor
  */
  ~vector();
  

  /*
  \brief      Operator overload for assignment
  \param[in]  rhs -> reference object to be assigned with
  \return     reference to current object
  */
  vector&         operator=(vector const& rhs);

  /*
  \brief      Operator overload for assignment
  \param[in]  rhs -> reference to object to be assigned with
  \return     reference to current object
  */
  vector&         operator=(std::initializer_list<T> const& rhs);

  /*
  \brief      Operator overload for subscript
  \param[in]  i   -> index to access vector at
  \return     value at target index of vector
  */
  reference       operator[](size_type i )     ; 

  /*
  \brief      Operator overload for subscript
  \param[in]  i   -> index to access vector at
  \return     value at target index of vector
  */
  const_reference operator[](size_type i) const; 
  
  /*
  \brief      Push a given value to the end of the vector
  \param[in]  value -> value to be added to the vector
  */
  void push_back(T value);

  /*
  \brief      Remove last element of the vector
  */
  void pop_back();

  /*
  \brief      Allocate memory for vector
  \param[in]  n -> number of elements to be allocated memory for, in vector
  */
  void reserve(size_type n);

  /*
  \brief      Resize the vector
  \param[in]  n -> target size to resize vector to
  */
  void resize(size_type n);

  /*
  \brief      swap the content of two vector
  \param[in]  rhs -> reference to target vector to swap contents with
  */
  void swap(vector&rhs);

  /*
  \brief      Checks if vector is empty
  \return     true if vector is empty
  */ 
  bool      empty()       const;

  /*
  brief       Get the number of elements in vector
  \return     number of elements in vector
  */
  size_type size()        const;

  /*
  \brief      Get the memory/space allocated to vector
  \return     number of space allocated to vector
  */
  size_type capacity()    const;

  /*
  \brief      Get the number of allocations vector went through
  \return     Number of time allocations is done with vector
  */
  size_type allocations() const;
  
  /*
  \brief      Pointer to start of vector
  \return     Pointer to start of vector
  */
  pointer       begin()        ;
  
  /*
  \brief      Pointer to start of vector
  \return     Pointer to start of vector
  */
  const_pointer begin()   const;
  
  /*
  \brief      Pointer to start of vector
  \return     Pointer to start of vector
  */
  const_pointer cbegin()  const;
  
  /*
  \brief      Pointer to end of vector
  \return     Pointer to end of vector
  */
  pointer       end()          ;
  
  /*
  \brief      Pointer to end of vector
  \return     Pointer to end of vector
  */
  const_pointer end()     const;
  
  /*
  \brief      Pointer to end of vector
  \return     Pointer to end of vector
  */
  const_pointer cend()    const;
  

private:
  size_type sz{0};     // the number of elements in the array
  size_type space{0};  // the allocated size (in terms of elements) of the array
  size_type allocs{0}; // number of times space has been updated
  pointer   data{nullptr};   // the dynamically allocated array (int*)
};

template <class T>
vector<T>::vector(){}
//template <class T>
template <class T>
vector<T>::vector(vector<T> const &rhs){
  reserve(static_cast<size_type>(rhs.size()));
  for(const T&i:rhs){push_back(i);}
}
template <class T>
vector<T>::vector(std::initializer_list<T> const& rhs){
  reserve(static_cast<size_type>(rhs.size()));
  for(const T&i:rhs){push_back(i);}
}

template <class T>
vector<T>::~vector(){if(data)delete[] data;}


template <class T>
vector<T>&          vector<T>::operator=(vector const& rhs){
  vector temp{rhs};
  swap(temp);
  allocs = temp.allocations() + 1;
  return *this;
}
template <class T>
vector<T>&          vector<T>::operator=(std::initializer_list<T>const& rhs){
  vector temp{rhs};
  swap(temp);
  allocs = temp.allocations() + 1;
  return *this;
}

template <class T>
void vector<T>::pop_back(){sz--;}

template <class T>
void vector<T>::push_back(T value){
    if(space == 0){
        reserve(static_cast<size_type>(1));
    }
    else if(sz==space){
        reserve(static_cast<size_type>(space * 2));
    }
    *(data + sz) = value;
    sz++;
}


template <class T>
void vector<T>::reserve(size_type n){
    if(n <= space)
        return;
    pointer na = new T[n];
    allocs++;
    if(data){
        for(size_type i{}; i < sz; na[i] = data[i], i++);
        delete[] data;
    }
    data = na;
    space = n;
}

template <class T>
void vector<T>::resize(size_type n){
    if(n>space){
      reserve(n);
      sz = n;
    }
    else if(n>sz && n <= space){
      sz = n;
    }
    else if (n < sz){
      sz = n;
    }
    else if (n == sz){
        return;
    }
    

}

template <class T>
void vector<T>::swap(vector& rhs){
  pointer   tdata   = rhs.data;
  size_type tsz     = rhs.size();
  size_type tspace  = rhs.capacity();
  size_type tallocs = rhs.allocations();

  rhs.data    = data;
  rhs.sz      = sz;
  rhs.space   = space;
  rhs.allocs  = allocs;


  data    = tdata;
  sz      = tsz;
  space   = tspace;
  allocs  = tallocs;

   

}


template <class T>
typename vector<T>::reference         vector<T>::operator[](size_type i )      {return *(data + i);}
template <class T>
typename vector<T>::const_reference   vector<T>::operator[](size_type i)  const{return *(data + i);}
template <class T>
bool                                  vector<T>::empty()                  const{return sz?false:true;}
template <class T>
typename vector<T>::size_type         vector<T>::size()                   const{return sz;}
template <class T>
typename vector<T>::size_type         vector<T>::capacity()               const{return space;}
template <class T>
typename vector<T>::size_type         vector<T>::allocations()            const{return allocs;}
template <class T>
typename vector<T>::pointer           vector<T>::begin()                       {return data;}
template <class T>
typename vector<T>::const_pointer     vector<T>::begin()                  const{return data;}
template <class T>
typename vector<T>::const_pointer     vector<T>::cbegin()                 const{return data;}
template <class T>
typename vector<T>::pointer           vector<T>::end()                         {return data + sz;}
template <class T>
typename vector<T>::const_pointer     vector<T>::end()                    const{return data + sz;}
template <class T>
typename vector<T>::const_pointer     vector<T>::cend()                   const{return data + sz;}

}
#endif // VCT_HPP

