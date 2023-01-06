// TODO: File documentation block required
/*!
@file q.h
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 8: Pointer Arithmetic and Half-Open Ranges
@date   29/10/2022
@brief  thie file provides the declaration for functions that
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

// NOTE 1: This file should not contain any standard library includes.
// The auto-grader will not accept your submission if this file
// contains include directives.

// NOTE 2: A function documentation block provides information that is crucial
// for clients to correctly use the function. Provide a documention block
// for each declared function that contains the following information:
// What does the function do?
// What are the (types) of the parameters?
// What is the (type) of value returned by function?
// Is there any particular input that will break the function?

// NOTE 3: When uploading this file for grading, make sure to remove
// all references to the subscript operator or the [ or ] symbols. 
// It is important that even your comments should not include these symbols.

// TODO: Now, declare the necessary functions.


/*
@brief      returns a pointer to the first occurrence of val in a half-open range of values. If
            no such element is found, the function returns NULL .

@param      :begin -> pointer to start of array to search
            :end   -> pointer to end of arrya to search
            :val   -> target char for searching

@return     returns pointer to the first occurence of val
            else: return NULL
*//*______________________________________________________________*/
char const* find(char const *begin, char const *end, char val);

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

char const* find_any(char const *begin, char const *end,char const *vals, int len);

/*!
@brief      returns the number of elements in a half-open range of values equivalent to val

@params     :begin -> pointer to start of char array
            :end   -> pointer to end of char array
            :val   -> value to count
@return     int value of char counted 
*//*______________________________________________________________*/
int count(char const *begin, char const *end, char val);

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
int count_any(char const *begin, char const *end, char const *vals, int len);

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
int compare(char const *begin1, char const *begin2, int len);

/*!
@brief      swaps the values in the two arrays whose first elements are pointed to by
            begin1 and begin2 with both arrays containing count number of elements.

@params     begin1 -> pointer to start of char array 1
            begin2 -> pointer to start of char array 2
            len    -> len of char array, for both arrays
@return     Nothing
*//*______________________________________________________________*/
void exchange(char *begin1, char *begin2, int len);

/*!
@brief      copies len number of values starting from the element pointed to by src into
            corresponding elements pointed to by dst . 
            Might have overlapping ranges
@param      :dst = pointer to the end of dst
            :src = pointer to the end of src
            :len of values pointed by src
@return     Nothing
*//*______________________________________________________________*/
void copy(char *dst, char *src, int len);