/*
@filename       q.c
@author         dylan.h
@course         CSD1121
@assignment     Ass 10
@date           11 November 2022
@brief          This file contains the source code for functions used to 
                analyze an unknown number of course grades from a data file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "q.h" // we're including q.h here because we want to apply the DRY principle [see specs for additional info]


/*!
@brief -            Opens text file, determines num of double floating point vals in file,
                    writes count to location of ptr_cnt. 
                    Allocates EXACT heap mem to copy vals from file to.
                    return NULL on any error
@param              *file_name  - file where grades data is recorded in
                    *ptr_cnt    - number of grades
@return             double*
*//*______________________________________________________________*/
double* read_data(char const *file_name, int *ptr_cnt) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) return NULL;

    double val;
    while (fscanf(file, "%lf", &val) == 1)
        ++*ptr_cnt;
    double *vals_heap = malloc(*ptr_cnt * sizeof(val));
    if (!vals_heap) return NULL;

    rewind(file);
    for (int i = 0; fscanf(file, "%lf", &val) == 1; ++i)
        *(vals_heap + i) = val;

    fclose(file);
    return vals_heap;
}

/*!
@brief -            Get highest grade in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double max(double const *begin, double const *end) {
    double largest = 0.0;
    do {
        if (*begin > largest) largest = *begin;
    } while (++begin < end);

    return largest;
}

/*!
@brief -            Get lowest grade in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double min(double const *begin, double const *end) {
    double minimum = 100.0;
    do {
        if (*begin < minimum) minimum = *begin;
    } while (++begin < end);

    return minimum;
}

/*!
@brief -            Get average grade in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double average(double const *begin, double const *end) {
    double sum = 0.0;
    int size = 0;
    do {
        sum += *begin;
        ++size;
    } while (++begin < end);

    return sum / (double)size;
}

/*!
@brief -            Get variance of grades in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double variance(double const *begin, double const *end) {
    double avg = average(begin, end);
    double total = 0.0;
    int size = 0;
    do {
        total += pow(*begin - avg, 2.0);
        ++size;
    } while (++begin < end);

    return total / (double)(size-1);
}

/*!
@brief -            Get std dev of grades in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double std_dev(double const *begin, double const *end) {
    return sqrt(variance(begin, end));
}

/*!
@brief -            Get median of grades in half open range
@param              *base  - pointer to start of range
                    size   - size of range
@return             double
*//*______________________________________________________________*/
double median(double *base, int size) {
    selection_sort (base, size);

    return (size % 2 == 0) ? // (even size) : (odd size)
    ((*(base + (size / 2 - 1)) + *(base + (size / 2))) / 2.0) : 
    (*(base + (int)floor(size / 2)));
}

/*!
@brief -            Selection sort algorithm
@param              *base  - pointer to start of range
                    size   - size of range
@return             void
*//*______________________________________________________________*/
void selection_sort(double *base, int size) {
    for (int i = 0; i < size - 1; ++i) {
        double *i_base = base + i;
        int min = i; // index of smallest element (j)
        for (int j = i + 1; j < size; ++j) {
            double *j_base = base + j;
            if (*j_base < *i_base && *j_base < *(base + min)) { // if the search is less than i AND less than current min
                min = j;
            }
        }
        double temp = *i_base;
        *i_base = *(base + min);
        *(base + min) = temp;
    }
}

/*!
@brief -            Counts number of each letter grade. 
                    Updates percentage of letter grade in *ltr_grade using enum _GRADES 
                    v = value;
                    v >= 90         A   A_GRADE
                    80 <= v < 90    B   B_GRADE
                    70 <= v < 80    C   C_GRADE
                    60 <= v < 70    D   D_GRADE
                    v < 60          F   F_GRADE
@param              *base  - pointer to start of range
                    size   - size of range
@return             void
*//*______________________________________________________________*/
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades) {
    int count = 0;
    int ltrs[TOT_GRADE] = {0};
    do {
        double grade = *begin;
        int lettergrade = A_GRADE;
        if (grade >= 90.0)
            lettergrade = A_GRADE;
        else if (80.0 <= grade && grade < 90.0)
            lettergrade = B_GRADE;
        else if (70.0 <= grade && grade < 80.0)
            lettergrade = C_GRADE;
        else if (60.0 <= grade && grade < 70.0)
            lettergrade = D_GRADE;
        else if (grade < 60.0)
            lettergrade = F_GRADE;

        ++count;
        ++ltrs[lettergrade];
    } while (++begin < end);

    for (int i = 0; i < TOT_GRADE; ++i)
        *(ltr_grades + i) = (double)ltrs[i] / (double)count * 100.0;
}
