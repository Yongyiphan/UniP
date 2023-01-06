/******************************************************************************
* @filename stats.h
* @author   Prasanna Ghali
* @DP email pghali@digipen.edu 
* @course   High-Level Programming 1
* @section  All sections
* @date     07/26/2017
* @brief Contains the interface for computing the statistics of a set of
*        32-bit integral values stored in an array.
******************************************************************************/ 
#ifndef __STATS_H__
#define __STATS_H__

/******************************************************************************
* @brief print_statistics() prints the maximum, minimum, median, and mean
* values in a read-only array of 32-bit integer values.
*
* This function will call helper functions find_maximum(), find_minimum(),
* find_median() and find_mean() to compute the appropriate statistics. It
* uses printf() - declared in <stdio.h> - to print the values to standard
* output.
*
* @param src represents first element in a read-only sequence of values
*        where each value is of type int.
*        Note: The function does not test if the parameter is a null pointer.
* @param elem_cnt Specifies the number of elements in sequence.
*
* @return None.
******************************************************************************/ 
void print_statistics(int const *src, int elem_cnt);

/******************************************************************************
* @brief print_array() prints the values in a read-only array of 32-bit
*        integer values to standard output.
*
* This function prints the values in a read-only array where each
* element of the array is of type int.
* This function uses printf() - declared in <stdio.h> -  to print 
* the values to standard output.
*
* @param src represents a pointer to the 1st element in a sequence of elem_cnt
*        number of elements where each element is of type int.
*        Note: The function does not test if the parameter is a null pointer.
* @param elem_cnt Specifies the number of elements in sequence.
* @param prefix_str Specifies a string that is printed before displaying
*        the array elements.
* @param postfix Specifies a string that is printed after displaying the
*        array elements.
*
* @return None.
******************************************************************************/ 
void print_array(int const   *src,
                 int         elem_cnt,
                 char const *prefix_str,
                 char const *postfix_str);

/******************************************************************************
* @brief find_median() returns the value of element lying at the midpoint
*        of values in a read-only array of 32-bit integers.
*
* To determine the median, the function must sort the elements in the array.
* However, since the function receives a read-only sequence of values, it must
* first make a copy of the input sequence on the heap. The function returns
* the dynamically allocated memory to the heap after the median is computed.
* After sorting the array, the median is computed in one of two ways. If the
* array contains an odd number of elements, the data value at the middle of
* the array is returned as the median. For even number of elements, the
* median is returned as the mean of the data values of the middle two
* elements of the array.
*
* @param src represents first element in sequence of elem_cnt elements
*        where each element is of type int.
*        Note: The function does not test if the parameter is a null pointer.
* @param elem_cnt Specifies the number of elements in sequence.
*
* @return median value in array of type int.
******************************************************************************/ 
int find_median(int const *src, int elem_cnt);

/******************************************************************************
* @brief find_mean() returns the average value in a read-only array of
*        32-bit integers in range [0, 255].
*
* The function accumulates the sum of elements in the array in a variable
* of type int. The function computes the mean of the elements of the
* array of type double. The function doesn't return a floating-point value. 
* Instead, the truncated value of type int is returned.
*
* @param src represents first element in sequence of elem_cnt elements
*        where each element is of type int.
*        Note: The function does not test if the parameter is a null pointer.
* @param elem_cnt Specifies the number of elements in sequence.
*
* @return average value in array of type int.
******************************************************************************/ 
int find_mean(int const *src, int elem_cnt);

/******************************************************************************
* @brief find_maximum() returns the largest value in a read-only array of
*        32-bit integer values.
*
* This function does not assume that the array is sorted and therefore must
* visit every element of the array.
*
* @param src represents a pointer to the 1st element in a sequence of elem_cnt
*        number of elements where each element is of type int.
*        Note: The function does not test if the parameter is a null pointer.
* @param elem_cnt Specifies the number of elements in sequence.
*
* @return largest value in array of type int.
******************************************************************************/ 
int find_maximum(int const *src, int elem_cnt);

/******************************************************************************
* @brief find_minimum() returns the smallest value in a read-only array of
*        32-bit integer values.
*
* This function does not assume that the array is sorted and therefore must
* to visit every element of the array.
*
* @param src represents a pointer to the 1st element in a sequence of elem_cnt
*        number of elements where each element is of type int.
*        Note: The function does not test if the parameter is a null pointer.
* @param elem_cnt Specifies the number of elements in sequence.
*
* @return smallest value in array of type int.
******************************************************************************/ 
int find_minimum(int const *src, int elem_cnt);

/******************************************************************************
* @brief sort_array() sorts the elements of the array in descending
         order.
*
* This function will call helper function q_sort() declared in
* <stdlib.h> to implement the sort algortihm.
*
* @param src represents first element in a read-only sequence of values
*        where each values is of type int.
*        Note: The function does not test if the parameter is a null pointer.
* @param elem_cnt Specifies the number of elements in sequence.
*
* @return None.
******************************************************************************/ 
void sort_array(int *src, int elem_cnt);

#endif /* __STATS_H__ */