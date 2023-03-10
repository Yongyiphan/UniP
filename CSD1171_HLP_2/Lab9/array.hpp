//-------------------------------------------------------------------------
#ifndef ARRAY_HPP_
#define ARRAY_HPP_
//-------------------------------------------------------------------------

#include "initializer_list"
#include <cstdlib>
#include <cstddef> // for size_t
// Don't include <array> [remove this line!!!]
// Otherwise, your submission will not compile!!!

namespace hlp2 {

// Define class template Array<T,N> and document each member function

// Declare and document non-member functions


template <class T, size_t N>
class Array{
public:
  using value_type              = T;
  using size_type               = size_t;
  using reference               = value_type&;
  using const_reference         = const value_type&;
  using pointer                 = value_type*;
  using const_pointer           = const value_type*;
  using iterator                = pointer;
  using const_iterator          = const_pointer;
  using reverse_iterator        = pointer;
  using const_reverse_iterator  = const_pointer;

public:
  Array() = default;
  Array(Array const &rhs);  
  Array(std::initializer_list<T> const &rhs);
  ~Array() = default;

  Array&                  operator=(Array const &rhs);
  reference               operator[](size_type i)      ;
  const_reference         operator[](size_type i) const;
  
  bool empty() const;
  size_type size() const;
  void swap(Array<T,N>&rhs);
  void fill(T value);

  pointer                 data()         ;
  const_pointer           data()    const;
  
  reference               front()        ;
  const_reference         front()   const;
  reference               back()         ;
  const_reference         back()    const;
  pointer                 begin()        ;
  const_pointer           begin()   const;
  const_pointer           cbegin()  const;
  reverse_iterator        end()          ;
  const_reverse_iterator  end()     const;
  const_reverse_iterator  cend()    const;

private:
  //size_type ele{N};
  T _data[N];


};

template <typename T>
void swap(T&lhs, T&rhs);

template <typename T, size_t N>
bool operator==(Array<T,N>&lhs, Array<T,N>&rhs);
template <typename T, size_t N>
bool operator!=(Array<T,N>&lhs, Array<T,N>&rhs);
template <typename T, size_t N>
bool operator< (Array<T,N>&lhs, Array<T,N>&rhs);
template <typename T, size_t N>
bool operator> (Array<T,N>&lhs, Array<T,N>&rhs);


} // end namespace hlp2

// EVERY member and non-member function must be defined 
// in separate file array.tpp
#include "array.tpp"

#endif // end ARRAY_HPP_
