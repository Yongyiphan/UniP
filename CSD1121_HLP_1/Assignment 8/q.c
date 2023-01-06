// TODO: File documentation block required
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 8: Pointer Arithmetic and Half-Open Ranges
@date   29/10/2022
@brief  thie file provides the definitions for functions that
        :find()     ->  returns a pointer to the first occurrence of val in a half-open range of values. If
                        no such element is found, the function returns NULL .

        :find_any() ->  returns a pointer to the first occurrence of any member of the array whose
                        first element is pointed to by pointer vals and has len number of elements in a half-open
                        range of values. 

        :count()    ->  returns the number of elements in a half-open range of values equivalent to
                        val .
        :count_any()->  returns the number of elements in a half-open range of values equivalent to
                        any member of the array whose first element is pointed to by parameter vals and has len
                        number of elements.

        :compare()  ->  compares corresponding elements in the arrays whose first elements are
                        pointed to by begin1 and begin2 (both of which have len number of values) to determine if
                        they contain the same values in the same order
        
        :exchange() ->  swaps the values in the two arrays whose first elements are pointed to by
                        begin1 and begin2 with both arrays containing count number of elements.

        :copy()     ->  copies len number of values starting from the element pointed to by src into
                        corresponding elements pointed to by dst .

*//*______________________________________________________________________*/

// NOTE 2: Even if you don't need the NULL, don't remove this macro ...
#define NULL ((void*)0) 

// NOTE 3: When uploading this file for grading, make sure to remove all
// standard library includes from this file.
// The auto-grader will not accept your submission if the file contains
// include directives.

// NOTE 4: When uploading this file for grading, make sure to remove
// all references to the subscript operator or the [ or ] symbols from your code. 
// It is important that even your comments should not include these symbols.

// TODO: Definitions of functions declared in q.h go here ...


/*
@brief      returns a pointer to the first occurrence of val in a half-open range of values. If
            no such element is found, the function returns NULL .

@param      :begin -> pointer to start of array to search
            :end   -> pointer to end of arrya to search
            :val   -> target char for searching

@return     returns pointer to the first occurence of val
            else: return NULL
*//*______________________________________________________________*/
char const* find(char const *begin, char const *end, char val){
    /*
    Step thru pointers' position (each cycle = 1 increment to pointer)
        :if val == value at *begin == found, exit program
        :else continue stepping through.
    */
    while(begin != end){
        if(val == *begin){
            //of val is found in any of the pointers begin is pointing to
            //return begin's pointer
            return begin;
        }
        begin++;
    }
    return NULL;
}
/*!
@brief      returns a pointer to the first occurrence of any member of the array whose
            first element is pointed to by pointer vals and has len number of elements in a half-open
            range of values. If none of the members of array vals are found, the function returns NULL . 

@params     :begin -> pointer to start of array of char
            :end   -> pointer to end of array of char
            :vals  -> pointer to arr of chars to check 

@return     returns a pointer to the first occurence of any member of the array whoe first element is pointed to by pointer val
            else: return NULL
*//*______________________________________________________________*/
char const* find_any(char const *begin, char const *end,char const *vals, int len){
    
    //Step through len of char array at vals
    for(int i=0; i< len; i++){
        //at each pointer step, use find() previously defined to find if char found
        char const *temp = find(begin, end, *vals++);
        //post increment of vals
        if(temp){
            //return result if found
            return temp;
        }
    } 
    return NULL;
}

/*!
@brief      returns the number of elements in a half-open range of values equivalent to val

@params     :begin -> pointer to start of char array
            :end   -> pointer to end of char array
            :val   -> value to count
@return     int value of char counted 
*//*______________________________________________________________*/
int count(char const *begin, char const *end, char val){
    int counter = 0;
    while(begin < end){
        //check if current char pointed by begin is the same as target val
        //post increment the pointer's position after if condition
        if(*begin++ == val){
            //if match, increment the count by 1
            counter++;
        } 
    }
    //after iterating through target array from begin to end
    //return found count
    return counter;
}
/*!
@brief      returns the number of elements in a half-open range of values equivalent to
            any member of the array whose first element is pointed to by parameter vals and has len
            number of elements.
@params     :begin -> pointer to start of char array
            :end   -> pointer to end of char array
            :val   -> value to count
            :len   -> length of pointer to char arr i.e array size
@return     int total number of values counted
*//*______________________________________________________________*/
int count_any(char const *begin, char const *end, char const *vals, int len){
    int counter = 0;
    for(int i =0; i<len; i++){
        //for each char vals is pointer to
        //count number of frequencies it appears
        //add the sum to a total number count
        counter += count(begin, end, *vals);

        //increment pointer to pointer to next char in array
        vals++;
    }
    return counter;
}
/*!
@brief      swaps the values in the two arrays whose first elements are pointed to by
            begin1 and begin2 with both arrays containing count number of elements.

@params     :begin1 -> pointer to start of first char array
            :begin2 -> pointer to start of second char array
            :len    -> length size of both array
@return     if value of 
            begin1 is smaller than begin2, return -1 (any negative value)
            begin1 is larger than begin2, return 1 (any positive value)
            else
                return 0
*//*______________________________________________________________*/
int compare(char const *begin1, char const *begin2, int len){
    for(int i = 0; i<len; i++, begin1++, begin2++){
        //count the value of values at 
        if(*begin1 < *begin2){
            //returns any negative numbers
            return -1;
        } 
        else if(*begin1 > *begin2){
            //return any positive number
            return 1;
        }
    }

    return 0;
}
/*!
@brief      swaps the values in the two arrays whose first elements are pointed to by
            begin1 and begin2 with both arrays containing count number of elements.

@params     begin1 -> pointer to start of char 
            begin2 -> pointer to start of char array 2
            len    -> len of char array, for both arrays
@return     Nothing
*//*______________________________________________________________*/
void exchange(char *begin1, char *begin2, int len){
    //init temp holder for char pointer's value
    char temp;
    for(int i=0;i<len;i++, begin1++, begin2++){
        //store begin1's value
        temp = *begin1;
        //reassigned begin1's value to that of begin2
        *begin1 = *begin2;
        //reassigned begin2 with value stored previously with temp
        *begin2 = temp;
        //Pointers increment to next location -) in for loop update expression
    }
}


/*!
@brief      copies len number of values starting from the element pointed to by src into
            corresponding elements pointed to by dst . 
            Might have overlapping ranges
@param      :dst = pointer to the end of dst
            :src = pointer to the end of src
            :len of values pointed by src
@return     Nothing
*//*______________________________________________________________*/
void copy(char *dst, char *src, int len){
    //Create two pointers to point to end of target copying position
    //for both array at dst and src
    char *endOfSrc = src + len;
    char *endOfDst = dst + len;
    for(int i=0; i<len;i++){
        //decrement then reassignment
        //until number of target copying is done.
        *--endOfDst = *--endOfSrc;
    }

}
