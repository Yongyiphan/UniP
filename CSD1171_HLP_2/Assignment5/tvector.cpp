#include "vector.hpp"

namespace hlp2{
    vector::vector(){
        sz = space = allocs = 0;
        data = nullptr;

    }
    vector::vector(size_type n): sz(n), space(n), allocs(1){
        data = new value_type[n];
        for(size_type i{}; i < n; i++){
            data[i] = 0;
        }
        //returns nothing

    }
    vector::vector(std::initializer_list<int> rhs){
        data = new value_type[rhs.size()];
        size_type i{};
        for(int c : rhs){
            data[i++] = c;
        }
        sz = space = rhs.size();
        allocs = 1;
        //returns nothing

    }
    vector::vector(vector const&rhs){
        data = new value_type[rhs.size()];
        for(size_type i{}; i < sz;i++){
            data[i] = rhs.data[i];
        }
        sz = space = rhs.sz;
        allocs = 1;
    }
    vector::~vector(){
        delete[] data;
    }
    vector& vector::operator=(vector const& rhs){
        //reserve(rhs.size());
        resize(rhs.size());
        for(size_type i{}; i < rhs.sz; data[i] = rhs.data[i], i++);
        sz = space = rhs.size();
        return *this;
    }
    vector& vector::operator=(std::initializer_list<int> rhs){
        //reserve(rhs.size());
        resize(rhs.size());
        sz = space = rhs.size();
        size_type i{};
        for(int c : rhs){
            data[i++] = c;
        }

        return *this;
    }
    vector::reference vector::operator[](size_type index)             {return *(data + index);}
    vector::const_reference vector::operator[](size_type index) const {return *(data + index);}
    
    void vector::push_back(value_type value){
        if(sz >= space){
            //Need to resize
            size_type newsize = space ? space * 2 : 1;
            reserve(newsize);
        }
        data[sz] = value;
        sz++;
    }
    void vector::reserve(size_type newsize){
        if(newsize <= space)
            return;

        pointer newArr = new value_type[newsize];
        //pointer start = newArr;
        //Transfer data from old arr to new arr
        for(size_type i{}; i < sz; i++){
            newArr[i] = data[i]; 
        }

        delete[] data;
        data = newArr;
        space = newsize;
        allocs++;
    }
    void vector::resize(size_type newsize){
        //Make this->data same size as no. of elements
        //Case1: newsize > space;
        if(newsize > space){
            reserve(newsize);
            sz = space = newsize;
        }
        //Case2: newsize > sz && space <= space;
        else if (newsize > sz && newsize <= space)
        {
            allocs++;
            sz = newsize;
        }
        //Case3: newsize < sz;
        else if (newsize < sz){
            sz = newsize;
        }
        //Case4: space = newsize; 
        else if (newsize == sz){
            return;
        }
    }
    
    bool vector::empty() const{ return sz ? false : true;}
    vector::size_type vector::size()        const{ return sz;}
    vector::size_type vector::capacity()    const{ return space;}
    vector::size_type vector::allocations() const{ return allocs;}
        
    vector::pointer vector::begin()         { return data;}
    vector::pointer vector::end()           { return (data + sz);}
    vector::pointer vector::begin() const   { return data;}
    vector::pointer vector::end() const     { return data + sz;}
    vector::pointer vector::cbegin() const  { return data;}
    vector::pointer vector::cend() const    { return data + sz;}
}