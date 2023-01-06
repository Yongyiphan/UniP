// TODO: File documentation block required
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.h
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial   Assignment 10  Data Analysis Using the Heap
@date 13/11/2022
@brief      This file contains the definition of function that
            read_data() -> takes in a filename, reads the files contains and store its value into an array
            max() -> find the maximum of an array
            min() -> find the minimum of an array
            average() -> find the average of an array
            variance() -> find the variance of an array
            std_dev() -> finds the standard deviation of an array
            median() -> returns the median of an array
            selection_sort() -> implements selection sort on a given array
            ltr_grade_pctg() -> determine the percentage of values in the half-open range
            *                   that map to a letter grade and writes these percentages to the array whose first element is
            *                   specified by parameter 

*//*______________________________________________________________________*/


#ifndef Q_H
#define Q_H

// TODO: declare anonymous enumeration type as described in the specs


// TODO: A function documentation block provides information that is crucial
// for clients to correctly use the function. Provide a documention block
// for each declared function that contains the following information:
// What does the function do?
// What are the (types) of the parameters?
// What is the (type) of value returned by function?
// Is there any particular input that will break the function?

// TODO: Now, declare the necessary function.

// TODO: Repeat function documentation block plus function declaration for remaining functions
/**
 * @brief           Function read_data opens the text file specified by parameter file_name , 
 *                  determines the number of double-precision floating-point values in the file and 
 *                  writes this count to the location pointed to by parameter ptr_cnt .  
 * 
 * @param file_name Pointer to start of string of filename
 * @param ptr_cnt   Value to be updated with the count of values recorded
 * @return double*  array double typed that contains values from textfile
 *                  If unable to allocate memory return null;
 */
double* read_data(char const *file_name, int *ptr_cnt);

/**
 * @brief           Function that finds the max values within a given array of doubles
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointer to end of array
 * @return double   Returns the max value in the array
 */
double max(double const *begin, double const *end);

/**
 * @brief           Function that finds the max values within a given array of doubles
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointer to end of array
 * @return double   Returns the max value in the array
 */
double min(double const *begin, double const *end);

/**
 * @brief           Function that finds the average value within a given array of doubles
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointer to end of array
 * @return double   Returns the min value in the array
 */
double average(double const *begin, double const *end);

/**
 * @brief           Function that finds the variance of value within a given array of doubles
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointert to end of array
 * @return double   Returns the variance of the array
 */
double variance(double const *begin, double const *end);

/**
 * @brief           Function that finds the standard deviation of a array of double
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointer to end of array
 * @return double   Returns the standard deviation of the given array
 */
double std_dev(double const *begin, double const *end);

/**
 * @brief           Function that finds the median of an array of double
 * 
 * @param base      Pointer to start of array
 * @param size      Pointer to end of array
 * @return double   Returns the median of the given array
 */
double median(double *base, int size);

/**
 * @brief       Function that performs selection sort in place of a given array
 * 
 * @param base  Pointer to the start of the array
 * @param size  Size of the array
 */
void selection_sort(double *base, int size);

enum {
    A_GRADE = 0,
    B_GRADE = 1,
    C_GRADE = 2,
    D_GRADE = 3,
    F_GRADE = 4,
    TOT_GRADE = 5
};

/**
 * @brief               Function will determine the percentage of values in the half-open range
 *                      that map to a letter grade and writes these percentages to the array whose first element is
 *                      specified by parameter
 * 
 * @param begin         Pointer to start of array 
 * @param end           Pointer to end of array
 * @param ltr_grades    Pointer to array that will contain the grading
 */
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades);
#endif // #ifndef Q_H
