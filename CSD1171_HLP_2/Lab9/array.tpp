// This file must contain definitions of ALL member and non-member functions
// of class template Array<T,N>
// Do not include <array> - otherwise, your submission will not compile!!!
// Make sure to remove above line before submitting to grader!!!
#include "array.hpp"
namespace hlp2{

    template <typename T, size_t N> 
    Array<T, N>::Array(Array<T,N> const&rhs){
        for(size_type i{}; i < N; i++){
            _data[i] = rhs[i];
        }
    }  
    template <typename T, size_t N> 
    Array<T, N>::Array(std::initializer_list<T> const &rhs){
        size_type j{};
        for(const T* i = rhs.begin(); i < rhs.end(); i++, j++){
            *(_data + j) = *i;
        }
    }


    template <typename T, size_t N> 
    Array<T,N>&                                     Array<T,N>::operator=(Array<T,N> const &rhs)      {
        Array<T,N> temp{rhs};
        this->swap(temp);
        return *this;
    }

    template <typename T, size_t N> 
    typename Array<T,N>::reference                  Array<T,N>::operator[](size_type i)      {return *(_data + i);}
    template <typename T, size_t N> 
    typename Array<T,N>::const_reference            Array<T,N>::operator[](size_type i) const{return *(_data + i);}
    
    template <typename T, size_t N> 
    bool                                            Array<T,N>::empty() const{return N == 0;}
    template <typename T, size_t N> 
    typename Array<T,N>::size_type                  Array<T,N>::size() const{return N;}
    template <typename T, size_t N> 
    void                                            Array<T,N>::swap(Array<T,N>&rhs){
        
        T tmp[N];
        //Copy rhs's Nments to tmp
        for(size_type i{}; i < N; tmp[i] = _data[i], i++);
        for(size_type i{}; i < N; _data[i] = rhs[i], i++);
        for(size_type i{}; i < N; rhs[i] = tmp[i], i++);

    }
    template <typename T, size_t N> 
    void                                            Array<T,N>::fill(T value){
        for(size_type i{}; i < N; i++){
            _data[i] = value;
        }

    }

    template <typename T, size_t N> 
    typename Array<T,N>::pointer                    Array<T,N>::data()         {return _data;}
    template <typename T, size_t N> 
    typename Array<T,N>::const_pointer              Array<T,N>::data()    const{return _data;}
    
    template <typename T, size_t N> 
    typename Array<T,N>::reference                  Array<T,N>::front()        {return *_data;}
    template <typename T, size_t N> 
    typename Array<T,N>::const_reference            Array<T,N>::front()   const{return *_data;}
    template <typename T, size_t N> 
    typename Array<T,N>::reference                  Array<T,N>::back()         {return *(_data + N);}
    template <typename T, size_t N> 
    typename Array<T,N>::const_reference            Array<T,N>::back()    const{return *(_data + N);}

    template <typename T, size_t N> 
    typename Array<T,N>::pointer                    Array<T,N>::begin()        {return _data;}
    template <typename T, size_t N> 
    typename Array<T,N>::const_pointer              Array<T,N>::begin()   const{return _data;}
    template <typename T, size_t N> 
    typename Array<T,N>::const_pointer              Array<T,N>::cbegin()  const{return _data;}
    template <typename T, size_t N> 
    typename Array<T,N>::reverse_iterator           Array<T,N>::end()          {return _data + N;}
    template <typename T, size_t N> 
    typename Array<T,N>::const_reverse_iterator     Array<T,N>::end()     const{return _data + N;}
    template <typename T, size_t N> 
    typename Array<T,N>::const_reverse_iterator     Array<T,N>::cend()    const{return _data + N;}


    template <typename T>
    void swap(T&lhs, T&rhs){
        T
    }

    template <typename T, size_t N>
    bool operator==(Array<T,N>&lhs, Array<T,N>&rhs){}
    template <typename T, size_t N>
    bool operator!=(Array<T,N>&lhs, Array<T,N>&rhs){}
    template <typename T, size_t N>
    bool operator< (Array<T,N>&lhs, Array<T,N>&rhs){}
    template <typename T, size_t N>
    bool operator> (Array<T,N>&lhs, Array<T,N>&rhs){}


}
