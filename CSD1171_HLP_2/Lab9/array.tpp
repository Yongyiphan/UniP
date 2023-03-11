// This file must contain definitions of ALL member and non-member functions
// File header documentation is required!!!
/*!*****************************************
 \file      array.tpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 9
 \date      11-03-2023
 \brief     File-header Documentation for array.tpp
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
#include "array.hpp"
namespace hlp2{

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
        
        Array tmp{rhs};
        rhs = *this;
        *this = tmp;

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
    typename Array<T,N>::reference                  Array<T,N>::back()         {return *(_data + N - 1);}
    template <typename T, size_t N> 
    typename Array<T,N>::const_reference            Array<T,N>::back()    const{return *(_data + N - 1);}

    template <typename T, size_t N> 
    typename Array<T,N>::pointer                    Array<T,N>::begin()        {return _data;}
    template <typename T, size_t N> 
    typename Array<T,N>::const_pointer              Array<T,N>::begin()   const{return _data;}
    template <typename T, size_t N> 
    typename Array<T,N>::const_pointer              Array<T,N>::cbegin()  const{return _data;}
    template <typename T, size_t N> 
    typename Array<T,N>::reverse_iterator           Array<T,N>::end()          {return (_data + N);}
    template <typename T, size_t N> 
    typename Array<T,N>::const_reverse_iterator     Array<T,N>::end()     const{return (_data + N);}
    template <typename T, size_t N> 
    typename Array<T,N>::const_reverse_iterator     Array<T,N>::cend()    const{return (_data + N);}


    template <typename T>
    void swap(T&lhs, T&rhs){
        lhs.swap(rhs);
    }

    template <typename T, size_t N>
    bool operator==(Array<T,N>&lhs, Array<T,N>&rhs){
        if(lhs.size() == rhs.size()){
            for(size_t i{}; i < N;i++){
                if(lhs[i] != rhs[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    template <typename T, size_t N>
    bool operator!=(Array<T,N>&lhs, Array<T,N>&rhs){
        return lhs == rhs ? false : true;
    }
    template <typename T, size_t N>
    bool operator< (Array<T,N>&lhs, Array<T,N>&rhs){
        if(lhs.size() == rhs.size()){
            for (size_t i = 0; i < N; i++)
                if (lhs[i] < rhs[i]) 
                    return true;
                else if (lhs[i] > rhs[i]) 
                    return false;
        }
        return false;
    }
    template <typename T, size_t N>
    bool operator> (Array<T,N>&lhs, Array<T,N>&rhs){
        if(lhs.size() == rhs.size()){
            for (size_t i = 0; i < N; i++)
                if (lhs[i] > rhs[i]) 
                    return true;
                else if (lhs[i] < rhs[i]) 
                    return false;
        }
        return false;
    }


}
