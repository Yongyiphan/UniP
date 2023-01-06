/*
@filename       q.h
@author         dylan.h
@course         CSD1121
@assignment     Ass 10
@date           11 November 2022
@brief          This file contains the definitions for functions used to 
                analyze an unknown number of course grades from a data file.
*/

#ifndef Q_H
#define Q_H

enum {
    A_GRADE = 0,
    B_GRADE,
    C_GRADE,
    D_GRADE,
    F_GRADE,
    TOT_GRADE
};

/*!
@brief -            Opens text file, determines num of double floating point vals in file,
                    writes count to location of ptr_cnt. 
                    Allocates EXACT heap mem to copy vals from file to.
                    return NULL on any error
@param              *file_name  - file where grades data is recorded in
                    *ptr_cnt    - number of grades
@return             double*
*//*______________________________________________________________*/
double* read_data(char const *file_name, int *ptr_cnt);

/*!
@brief -            Get highest grade in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double max(double const *begin, double const *end);

/*!
@brief -            Get lowest grade in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double min(double const *begin, double const *end);

/*!
@brief -            Get average grade in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double average(double const *begin, double const *end);

/*!
@brief -            Get variance of grades in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double variance(double const *begin, double const *end);

/*!
@brief -            Get std dev of grades in half open range
@param              *begin  - pointer to start of range
                    *end    - pointer to end of range
@return             double
*//*______________________________________________________________*/
double std_dev(double const *begin, double const *end);

/*!
@brief -            Get median of grades in half open range
@param              *base  - pointer to start of range
                    size   - size of range
@return             double
*//*______________________________________________________________*/
double median(double *base, int size);

/*!
@brief -            Selection sort algorithm
@param              *base  - pointer to start of range
                    size   - size of range
@return             void
*//*______________________________________________________________*/
void selection_sort(double *base, int size);

/*!
@brief -            Counts number of each letter grade. 
                    Makes use of enum of _GRADES to increase count in ltr_grades[]
                    ltr_grades[TOT_GRADE] will contain the total number of letter grades
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
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades);


#endif // #ifndef Q_H
