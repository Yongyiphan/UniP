////////////////////////////////////////////////////////////////////////////////
#ifndef VCT_HPP
#define VCT_HPP
////////////////////////////////////////////////////////////////////////////////
#include "initializer_list"
#include <cstdlib>

// provide definition of class template vector:
// 1) Start with the correct implementation of assignment 6.
// 3) Add member function: void swap(vector&);
// 4) Rewrite [if necessary] copy assignment operator overloads to follow
//    the copy-and-swap idiom.
namespace hlp2 {

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
  using size_type       = size_t;
  using value_type      = T;
  // reference, const_reference, pointer, const_pointer
  using reference       = value_type&;
  using const_reference = const value_type&;
  using pointer         = value_type*;
  using const_pointer   = const value_type*;

public:
  vector();
  vector(vector<T> const &rhs);
  vector(std::initializer_list<T> const& rhs);
  ~vector();
  
  vector&         operator=(vector const& rhs);
  vector&         operator=(std::initializer_list<T> const& rhs);
  reference       operator[](size_type i )     ; 
  const_reference operator[](size_type i) const; 
  
  void push_back(T);
  void pop_back();
  void reserve(size_type n);
  void resize(size_type n);
  void swap(vector&rhs);
  
  bool      empty()       const;
  size_type size()        const;
  size_type capacity()    const;
  size_type allocations() const;
  
  pointer       begin()        ;
  const_pointer begin()   const;
  const_pointer cbegin()  const;
  pointer       end()          ;
  const_pointer end()     const;
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
vector<T>::~vector(){if(data)std::free(data);}


template <class T>
vector<T>&          vector<T>::operator=(vector const& rhs){
  vector temp{rhs};
  swap(temp);
  return *this;
}
template <class T>
vector<T>&          vector<T>::operator=(std::initializer_list<T>const& rhs){
  vector temp{rhs};
  swap(temp);
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
    pointer na = (pointer)std::malloc(sizeof(T) * n);
    allocs++;
    if(data){
        for(size_type i{}; i < sz; na[i] = data[i], i++);
        std::free(data);
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
typename vector<T>::const_reference   vector<T>::operator[](size_type i) const {return *(data + i);}
template <class T>
bool      vector<T>::empty()                           const{return sz?false:true;}
template <class T>
typename vector<T>::size_type vector<T>::size()        const{return sz;}
template <class T>
typename vector<T>::size_type vector<T>::capacity()    const{return space;}
template <class T>
typename vector<T>::size_type vector<T>::allocations() const{return allocs;}
template <class T>
typename vector<T>::pointer       vector<T>::begin()        {return data;}
template <class T>
typename vector<T>::const_pointer vector<T>::begin()   const{return data;}
template <class T>
typename vector<T>::const_pointer vector<T>::cbegin()  const{return data;}
template <class T>
typename vector<T>::pointer       vector<T>::end()          {return data + sz;}
template <class T>
typename vector<T>::const_pointer vector<T>::end()     const{return data + sz;}
template <class T>
typename vector<T>::const_pointer vector<T>::cend()    const{return data + sz;}

}
#endif // VCT_HPP

