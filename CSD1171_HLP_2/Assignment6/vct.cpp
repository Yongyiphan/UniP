#include "vct.hpp"
#include <cstdlib>

namespace hlp2{

    template <typename T>
    vector<T>::vector():sz(0), space(0), allocs(0):data(nullptr){}
    template <typename T>
    vector<T>::vector(size_type n):sz(n), space(0), allocs(1){
        data = (T*)malloc(sizeof(T) * n);
    }
    template <typename T>
    vector<T>::vector(std::initializer_list<int> rhs):sz(0), space(0){
        reserve(rhs.size());
        sz = space = rhs.size();
        for(const int &i: rhs){
            push_back(i);
        }
    }
    template <typename T>
    vector<T>::vector(std::initializer_list<T> rhs):sz(0), space(0){
        reserve(rhs.size());
        sz = space = rhs.size();
        for(const T &i: rhs){
            push_back(i);
        }
    }
    template <typename T>
    vector<T>::vector(vector<T> const&rhs){
        reserve(rhs.sz);
        for(const T&i: rhs){
            push_back(i);
        }
    }
    template <typename T>
    vector<T>::~vector(){free(data);}
    
    template <typename T>
    vector<T>& vector<T>::operator=(vector const& rhs){
        swap(rhs);
    }
    template <typename T>
    vector<T>& vector<T>::operator=(std::initializer_list<int> rhs){
        vector<int> Temp(rhs);
        swap(Temp);
    }
    template <typename T>
    vector<T>& vector<T>::operator=(std::initializer_list<T> rhs){
        vector<T> Temp(rhs);
        swap(Temp);
    }

    
    template <typename T>
    void vector<T>::push_back(value_type value){
        if(space == 0){
            reserve(1);
        }
        else if(sz==space){
            reserve(space * 2);
        }
        data[sz] = value;
        sz++;
    }
    template <typename T>
    void vector<T>::pop_back(){sz--;}
    template <typename T>
    void vector<T>::reserve(size_type n){
        if(n <= space)
            return;
        pointer na = (pointer)malloc(sizeof(T) * n);
        allocs++;
        if(data){
            for(size_type i{}; i < sz; na[i] = data[i], i++);
            free(data);
        }
        data = na;
        space = n;
    }
    template <typename T>
    void vector<T>::resize(size_type n){
        if(n>space){
            reserve(n);
            sz = n;
        }
        else if(n>sz && n <= space){
            sz = n;
        }
        else if (n == sz){
            return;
        }
        

    }
    template <typename T>
    void vector<T>::swap(const vector<T>&){}
    
    
    template <typename T>
    vector<T>::reference vector<T>::operator[](size_type i )            {return *(data + i);}
    template <typename T>
    vector<T>::const_reference vector<T>::operator[](size_type i) const {return *(data + i);}
    
    
    template <typename T>
    bool vector<T>::empty()                         const{return space ? false : true;}
    template <typename T>
    vector<T>::size_type vector<T>::size()          const{return sz;}
    template <typename T>
    vector<T>::size_type vector<T>::capacity()      const{return space;}
    template <typename T>
    vector<T>::size_type vector<T>::allocations()   const{return allocs;}
    
    template <typename T>
    vector<T>::pointer vector<T>::begin()                {return data;}
    template <typename T>
    vector<T>::const_pointer vector<T>::begin()     const{return data;}
    template <typename T>
    vector<T>::const_pointer vector<T>::cbegin()    const{return data;}

    template <typename T>
    vector<T>::pointer vector<T>::end()                  {return data + sz;}
    template <typename T>
    vector<T>::const_pointer vector<T>::end()       const{return data + sz;}
    template <typename T>
    vector<T>::const_pointer vector<T>::cend()      const{return data + sz;}
    

}