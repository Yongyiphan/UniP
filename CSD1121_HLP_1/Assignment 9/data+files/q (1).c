/*
@filename       q.c
@author         dylan.h
@course         CSD1121
@assignment     Ass 9
@date           04 November 2022
@brief          This file contains the source code for functions and structures
                used to print a report giving the maximum wave height for the 
                tsunamis recorded in a data file.
*/

#include "q.h"


/*!
@brief -            Copies maxcnt of tsu. events recorded in file by filename
@param              *file_name  - file where tsunami events are recorded in
                    *arr        - array Tsunami data
                    max_cnt     - number of events to be read from file
@return             int
*//*______________________________________________________________*/
int read_data(char const *file_name, struct Tsunami *arr, int max_cnt) {
    int count = 0;
    struct Tsunami newTsu;

    FILE *file = fopen(file_name, "r");
    if (file == NULL) return 0;
    while (fscanf(file, "%d %d %d %d %lf %[^\n]s", &newTsu.month, &newTsu.day, &newTsu.year, &newTsu.fatalities, &newTsu.maxHeight, newTsu.location) == 6) {
        if (count < max_cnt)
            *(arr + count++) = newTsu;
    }

    fclose(file);
    return count;
}


/*!
@brief -            prints to output stream out_stm a nicely formatted list of the
                    information recorded in each tsunami event
@param              *arr        - array Tsunami data
                    size        - size of arr
                    *out_stm    - output stream
@return             void
*//*______________________________________________________________*/
void print_info(struct Tsunami const *arr, int size, FILE *out_stm) {
    int count = 0;
    do {
        struct Tsunami const tsu = *(arr + count);
        fprintf(out_stm, (tsu.month > 9) ? ("%d ") : ("0%d "), tsu.month);
        fprintf(out_stm, (tsu.day > 9) ? ("%d ") : ("0%d "), tsu.day);
        fprintf(out_stm, "%d ", tsu.year);
        fprintf(out_stm, "%6d ", tsu.fatalities);
        fprintf(out_stm, "%5.2lf ", tsu.maxHeight);
        fprintf(out_stm, "%s\n", tsu.location);
    } while (++count < size);
}

/*!
@brief -            Compares heights of each tsunami, returns max height
@param              *arr        - array Tsunami data
                    size        - size of arr
@return             double
*//*______________________________________________________________*/
double get_max_height(struct Tsunami const *arr, int size) {
    int count = 0;
    double max = 0.0;
    do { 
        if ((arr + count)->maxHeight > max) max = (arr + count)->maxHeight;
    } while (++count < size);
    return max;
}

/*!
@brief -            Returns average heights of tsunamis
@param              *arr        - array Tsunami data
                    size        - size of arr
@return             double
*//*______________________________________________________________*/
double get_average_height(struct Tsunami const *arr, int size) {
    int count = 0;
    double sum = 0.0;
    do { 
        sum += (arr + count)->maxHeight;
    } while (++count < size);
    return (sum / (double)size);
}

/*!
@brief -            Copies maxcnt of tsu. events recorded in file by filename
@param              *arr        - array Tsunami data
                    size        - size of arr
                    height      - height to be compared against
                    *out_stm    - output stream
@return             int
*//*______________________________________________________________*/
void print_height(struct Tsunami const *arr, int size, double height, FILE *out_stm) {
    int count = 0;
    do { 
        struct Tsunami tsu = *(arr + count);
        if (tsu.maxHeight > height) {
            fprintf(out_stm, "%5.2lf ", tsu.maxHeight);
            fprintf(out_stm, "%s\n", tsu.location);
        }
    } while (++count < size);
}
