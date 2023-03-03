#include "vct.hpp"
#include "malloc.h"
namespace hlp2{
    template <typename T>
    vector<T>::vector():sz(0), space(0), allocs(0), data(nulltpr){};

    template <typename T>
    vector<T>::vector(size_type n): sz(0), space(0), allocs(1){
        data = static_cast<pointer>(std::malloc(sizeof(T) * n));
    }

    template <typename T>
    vector<T>::vector(std::initializer_list<int> rhs){

    }

    template <typename T>
    vector<T>::vector(std::initializer_list<T> rhs){
        
    }

    template <typename T>
    vector<T>::vector(vector<T> const&rhs){
        
    }


    
    template <typename T>
    vector<T>::reference vector<T>::operator[](size_type i ) {return *(data + i);};
    template <typename T>
    vector<T>::const_reference vector<T>::operator[](size_type i) const {return *(data + i);};


    template <typename T>
    void vector<T>::reserve(size_type newsize){
        
        if(n <= space)
            return;
        //Init new array
        pointer na = static_cast<pointer>(std::malloc(sizeof(T) * newsize));
        allocs++;
        if(data){
            for(size_type i{}; i < sz; na[i] = data[i], i++);
            std::free(data);
        }
        data = na;
        space = n;

    };

    template <typename T>
    void vector<T>::resize(size_type newsize){};
    template <typename T>

    void vector<T>::push_back(value_type value){};

    template <typename T>
    void vector<T>::pop_back(){};

    template <typename T>
    void vector<T>::swap(vector<T>&rhs){};

}