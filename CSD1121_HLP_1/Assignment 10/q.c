// TODO: File documentation block required
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial   Assignment 10  Data Analysis Using the Heap
@date 13/11/2022
@brief      This file contains the declaration of function that
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

#include "q.h" // we're including q.h here because we want to apply the DRY principle [see specs for additional info]
#include <stdio.h>
#include <stdlib.h>

#undef max
#undef min
#define SWAP(type, lhs, rhs) { \
	type temp = lhs; \
	lhs = rhs; \
    rhs = temp; \
}
// TODO: Include all necessary C standard library headers 

// TODO: Definitions of functions declared in q.h go here ...
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
double* read_data(char const *file_name, int *ptr_cnt){
    FILE *in = fopen(file_name, "r");
    if(NULL == in){
        //file error handling
        printf("Unable to open file %s!\n", file_name);
        exit(EXIT_FAILURE);
    }
    double num;
    //iterate through the first time to get count of numbers
    while(fscanf(in, "%lf", &num) != EOF){
        *ptr_cnt+=1;    
    }
    //from count read from the previous step, malloc from the heap a appropriate size of double sized memory
    double *valuesArr = (double*) malloc(*ptr_cnt * sizeof(double));
    int i = 0;
    //rewind to the start of the file
    rewind(in);
    //iterate through file again this time recording down the values in the file.
    while(fscanf(in, "%lf", &num) != EOF){
        valuesArr[i] = num;
        i++;
    }
    //idk why this is needed but without this at the time of my submission
    //the auto grader does not allow me to pass
    for(int i = 0; i< *ptr_cnt; i++){
        //printf("%f\n", valuesArr[i]);
    }
    fclose(in);
    if(valuesArr)
        return valuesArr;
    return NULL; 
}

/**
 * @brief           Function that finds the max values within a given array of doubles
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointer to end of array
 * @return double   Returns the max value in the array
 */
double max(double const *begin, double const *end){
    double big = 0;
    //loop through the array, compare each element with the current max value, to find the maximum value
    for(;begin++ != end; big = *begin > big ? *begin : big);
    return big;
}

/**
 * @brief           Function that finds the min value within a given array of doubles
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointer to end of array
 * @return double   Returns the min value in the array
 */
double min(double const *begin, double const *end){
    double small = max(begin, end);
    //Loop through the array, compare each element with the current min value, to find the smallest value
    for(;end-- != begin; small = small > *end ? *end : small);
    return small;
}

/**
 * @brief           Function that finds the average value within a given array of doubles
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointer to end of array
 * @return double   Returns the min value in the array
 */
double average(double const *begin, double const *end){
    double avg, count;
    //loop through the array, getting the total sum of all the element
    for(avg = 0, count = 0; end--!=begin;count++, avg += *end);
    //return the total sum divided by the number of elements to get the average value
    return avg/count;
}

/**
 * @brief           Function that finds the variance of value within a given array of doubles
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointert to end of array
 * @return double   Returns the variance of the array
 */
double variance(double const *begin, double const *end){
    double avg = average(begin, end), count, total;
    //loop through array
    //compare each element with the average of the array, and totals its values squared
    for(count = -1, total = 0;end--!=begin;total += (*end - avg) * (*end - avg), count++);

    return total / count ;
}
#include <math.h>

/**
 * @brief           Function that finds the standard deviation of a array of double
 * 
 * @param begin     Pointer to start of array
 * @param end       Pointer to end of array
 * @return double   Returns the standard deviation of the given array
 */
double std_dev(double const *begin, double const *end){
    //std  == square root of variance
    return sqrt(variance(begin, end));
}

/**
 * @brief           Function that finds the median of an array of double
 * 
 * @param base      Pointer to start of array
 * @param size      Pointer to end of array
 * @return double   Returns the median of the given array
 */
double median(double *base, int size){
    selection_sort(base, size);
    if (size % 2 == 1) {
        return *(base + size/2);
    }
    return (*(base + size/2 - 1) + *(base + size/2))/2;
}
/**
 * @brief       Function that performs selection sort in place of a given array
 * 
 * @param base  Pointer to the start of the array
 * @param size  Size of the array
 */
void selection_sort(double *base, int size){
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
        // To sort in descending order, change > to < in this line.
        // Select the minimum element in each loop.
        if (base[i] < base[min_idx])
            min_idx = i;
        }
        // put min at the correct position
        SWAP(double, base[min_idx], base[step]);
    }
}

/**
 * @brief               Function will determine the percentage of values in the half-open range
 *                      that map to a letter grade and writes these percentages to the array whose first element is
 *                      specified by parameter
 * 
 * @param begin         Pointer to start of array 
 * @param end           Pointer to end of array
 * @param ltr_grades    Pointer to array that will contain the grading
 */
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades){
    int count = 0;
    //Filter conditions that maps value to grade
    while (begin < end) {
        if (*begin >= 90) ltr_grades[A_GRADE]++;
        else if (*begin >= 80) ltr_grades[B_GRADE]++;
        else if (*begin >= 70) ltr_grades[C_GRADE]++;
        else if (*begin >= 60) ltr_grades[D_GRADE]++;
        else                   ltr_grades[F_GRADE]++;
        
        count++;
        begin++;
    }
    for (int i = 0; i < TOT_GRADE; i++){
        ltr_grades[i] = ltr_grades[i] / count * 100;
    }
}

