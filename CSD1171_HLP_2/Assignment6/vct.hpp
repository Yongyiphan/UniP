////////////////////////////////////////////////////////////////////////////////
#ifndef VCT_HPP
#define VCT_HPP
////////////////////////////////////////////////////////////////////////////////
#include "initializer_list"

namespace hlp2 {

// provide definition of class template vector:
// 1) Start with the correct implementation of assignment 6.
// 3) Add member function: void swap(vector&);
// 4) Rewrite [if necessary] copy assignment operator overloads to follow
//    the copy-and-swap idiom.
// 5) Add member function: void pop_back();
//    What does pop_back() do? It removes the last element in the vector, effectively reducing the container size by one.
// 6) Use your own tests to make sure your class does the right thing for
//    a basic type such as int, standard library type std::string, and user-defined type hlp2::Str
// 7) Just as in class lecture, use these concrete class definitions to define the class template.
// 8) Your implementation must define member functions OUTSIDE the class definition.
//    You will need this practice to correctly answer final test questions!!!
// 9) Make sure your implementation/submission doesn't include <vector>.
//    It is a good idea to delete the previous line once you've read it!!!
// 10) The file must contain a file header documentation block and a file documentation
//    block for each function you're defining (including the ones that have been previously implemented).

template <typename T>
class vector {
public:
  // types to declare: size_type, value_type,
  using size_type = size_t;
  using value_type = T;
  // reference, const_reference, pointer, const_pointer
  using reference = value_type&;
  using const_reference = const reference;
  using pointer = value_type*;
  using const_pointer = const value_type*;

public:
  vector();
  explicit vector(size_type n);
  vector(std::initializer_list<int> rhs);
  vector(std::initializer_list<T> rhs);
  vector(vector<T> const&rhs);
  ~vector();
  
  vector& operator=(vector const& rhs);
  vector& operator=(std::initializer_list<int> rhs);
  vector& operator=(std::initializer_list<T> rhs);
  reference operator[](size_type i );
  const_reference operator[](size_type i) const;
  
  void push_back(value_type value);
  void pop_back();
  void reserve(size_type newsize);
  void resize(size_type newsize);
  void swap(const vector<T>&);
  
  bool empty() const;
  size_type size() const;
  size_type capacity() const;
  size_type allocations() const;
  
  pointer begin();
  pointer end();
  const_pointer begin() const;
  const_pointer end() const;
  const_pointer cbegin() const;
  const_pointer cend() const;
  

private:
  size_type sz;     // the number of elements in the array
  size_type space;  // the allocated size (in terms of elements) of the array
  size_type allocs; // number of times space has been updated
  pointer   data;   // the dynamically allocated array (int*)
};

} // namespace hlp2
#endif // VCT_HPP

