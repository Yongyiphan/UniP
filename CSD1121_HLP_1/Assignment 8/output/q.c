/*
@filename       q.c
@author         dylan.h
@course         CSD1121
@assignment     Ass 8
@date           28 October 2022
@brief          This file contains the source code for Pointers and Half-Open
                Ranges.
*/

// NOTE 2: Even if you don't need the NULL, don't remove this macro ...
#define NULL ((void*)0) 


/*!
@brief -            Returns a pointer to the first occurrence of val in a half-open range of values. If
                    no such element is found, the function returns NULL
@param              *begin  - start of occurrence
                    *end    - end of occurrence
                    val     - value to be found
@return             char const* 
*//*______________________________________________________________*/
char const* find(char const *begin, char const *end, char val) {
    while (begin < end) {
        if(*begin == val) return begin;
        ++begin;
    }
    return NULL;
}

/*!
@brief -            Returns a pointer to the first occurrence of any member of the array whose
                    first element is pointed to by pointer vals and has len number of elements in a half-open
                    range of values. If none of the members of array vals are found, the function returns NULL .
@param              *begin  - start of occurrence
                    *end    - end of occurrence
                    *vals   - any values to be found
                    len     - length of vals
@return             char const* 
*//*______________________________________________________________*/
char const* find_any(char const *begin, char const *end, char const *vals, int len) {
    char const *valsBegin = vals;
    char const *valsEnd = (vals + (len * sizeof(*vals)));
    while (begin < end) {
        while (valsBegin < valsEnd) {
            if (*valsBegin++ == *begin) return begin;
        }
        valsBegin = vals;
        ++begin;
    }
    return NULL;
}

/*!
@brief -            Returns the number of elements in a half-open range of values equivalent to val
@param              *begin  - start of occurrence
                    *end    - end of occurrence
                    val     - value to be found
@return             int 
*//*______________________________________________________________*/
int count(char const *begin, char const *end, char val) {
    int i = 0;
    while (begin < end) {
        if (*begin++ == val) ++i;
    }
    return i;
}

/*!
@brief -            Returns the number of elements in a half-open range of values equivalent to
                    any member of the array whose first element is pointed to by parameter vals and has len
                    number of elements
@param              *begin  - start of occurrence
                    *end    - end of occurrence
                    *vals   - any values to be found
                    len     - length of vals
@return             int
*//*______________________________________________________________*/
int count_any(char const *begin, char const *end, char const *vals, int len) {
    int i = 0;
    char const *valsBegin = vals;
    char const *valsEnd = (vals + (len * sizeof(*vals)));
    while (begin < end) {
        while (valsBegin < valsEnd) {
            if (*valsBegin++ == *begin) ++i;
        }
        valsBegin = vals;
        ++begin;
    }
    return i;
}

/*!
@brief -            Compares corresponding elements in the arrays whose first elements are
                    pointed to by begin1 and begin2
@param              *begin1 - start of first occurrence
                    *begin2 - start of second occurrence
                    len     - length of both b1 and b2
@return             int     - 0 for similar, negative val for if b1 < b2, positive value for if b1 > b2
*//*______________________________________________________________*/
int compare(char const *begin1, char const *begin2, int len) {
    char const *end = (begin1 + (len * sizeof(*begin1)));
    while (begin1 < end) {
        if (*begin1 < *begin2) return -1;
        if (*begin1 > *begin2) return 1;

        ++begin1;
        ++begin2;
    }
    return 0;
}

/*!
@brief -            Swaps the values in the two arrays whose first elements are pointed to by
                    begin1 and begin2 with both arrays containing count number of elements
                    Special circumstance: possible that the two ranges overlap
@param              *begin1 - start of first occurrence
                    *begin2 - start of second occurrence
                    len     - length of both b1 and b2
@return             void
*//*______________________________________________________________*/
void exchange(char *begin1, char *begin2, int len) {
    char *end = (begin1 + (len * sizeof(*begin1)));
    char backup;
    while (begin1 < end) {
        backup = *begin1;
        *begin1 = *begin2;
        *begin2 = backup;

        ++begin1;
        ++begin2;
    }
}

/*!
@brief -            copies len number of values starting from the element pointed to by src into
                    corresponding elements pointed to by dst 
                    Special circumstance: possible that the two ranges overlap
@param              *dst    - destination 
                    *src    - source
                    len     - length of both dst/src
@return             void
*//*______________________________________________________________*/
void copy(char *dst, char *src, int len) {
    char *srclen = (src + ((len - 1) * sizeof(*src)));
    char *dstlen = (dst + ((len - 1) * sizeof(*dst)));
    while (dstlen > (dst - sizeof(*dst))) {
        *dstlen-- = *srclen--;
    }
}