// TODO: File documentation block required
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 9, Problem solving with structures and files
@date 7/11/2022
@brief

*//*______________________________________________________________________*/

// TODO: Include all necessary C standard library headers 
#include <stdio.h>
#include <stdlib.h>
#include "q.h"

// TODO: Definitions of functions declared in q.h go here ...
/**
 * @brief       Function read_data copies a maximum of max_cnt number of tsunami events recorded in
                text file specified by parameter file_name into an array whose base address is specified by
                parameter arr . 
* @param        char const *filename, represents the string of file to be read from
                struct Tsunami *arr, an array which will contain the data gathered from file given
                int max_cnt, the total lines of data to be read
* @returns      The function should return the number of tsunami events stored in the array. Each line of
                the text file contains information for each tsunami event in the following order: integer
                values representing month, day, year, fatalities, a double-precision floating-point value
                representing maximum wave height and a sequence of characters (that may contain
                whitespace characters) representing the tsunami's location. S
*/
int read_data(char const *file_name, struct Tsunami *arr, int max_cnt){
    FILE *txtFile = fopen(file_name, "r");
    //File open error handling
    if(NULL == txtFile){
        exit(EXIT_FAILURE);
    }
    /*int values representing month, day, year, fatalities, a double-precision floating-point value
    representing maximum wave height and a sequence of characters (that may contain
    whitespace characters) representing the tsunami's location.*/
    int i = 0;
    //Read from file using fscanf
    //directly modifying the arr via pointers, subscript access. 
    while(max_cnt >= i &&
    (fscanf(txtFile, "%d %d %d %d %lf %[^\n]", 
    &arr[i].month, &arr[i].day, &arr[i].year, 
    &arr[i].Fatalities, 
    &arr[i].WaveHeight, 
    arr[i].Location)!=EOF)){ 
        i++;
    }
    //close file
    fclose(txtFile);
    return i;

}
/**
 * @brief      Function print_info prints to output stream out_stm a nicely formatted list of the
            information recorded in each tsunami event 
 * @param     *arr => arr of tsunami structs
            size => size of tsunami arr
            out_stm => file to output to
 * @returns    none
*/
void print_info(struct Tsunami const *arr, int size, FILE *out_stm){
    /*
    -> month [formatted with digits or more, left padded with zeroes],
    -> day [formatted with digits or more, left padded with zeroes],
    -> year [formatted with width of at least digits],
    -> number of fatalities [formatted with width of at least digits],
    -> maximum wave height [formatted with width of at least digits and precision of digits], and
        the location of the tsunami [printed as a character string].
    */
    for(int i =0;i<size;i++, arr++){
        Tsunami t = *arr;
        fprintf(out_stm, "%02d %02d %4d %6d %5.2lf %s\n", t.month,t.day, t.year,t.Fatalities,t.WaveHeight,t.Location);
    }
}


/**
 * @brief   Function get_max_height returns the maximum wave height in array specified by base
            address arr with size number of tsunami events
 * @param   arr => arr of tsunami which contains data obtained from read_data
 * @param   size => size of array 
 * @return  maximum height of wave found in arr
 */
double get_max_height(struct Tsunami const *arr, int size){
    double max = 0;
    for (int i = 0; i < size; i++, arr++)
    {
        //compare with current max height
        //replace if current arr index's waveheight is higher
        max = arr->WaveHeight > max ? arr->WaveHeight : max;   
    }
    return max;
}

/**
 *  @brief  Function get_average_height returns the average wave height in array specified by base
            address arr with size number of tsunami events
    @param  arr => array of tsunami struct
    @param  size => size of array
    @return average height of wave data store in tsunami struct array
* 
*/
double get_average_height(struct Tsunami const *arr, int size){
    double avg = 0;
    //loop through arr and sum up the total wave height recorded in the array
    for (int i = 0; i <= size;avg += arr->WaveHeight,i++, arr++);
    //return the average height; 
    return avg / size;

}

/**
 * @brief   Function print_height prints to output stream out_stm the maximum wave heights and
            locations of those tsunamis with higher maximum wave heights than the wave height
            specified by parameter height . 
 * @param arr => arr of tsunami struct
 * @param size => size of array
 * @param height => height to compare against print out height that is heigher than this value
 * @param out_stm => file stream to print out
 */
void print_height(struct Tsunami const *arr, int size, double height, FILE *out_stm){
    for(int i = 0; i<size;i++, arr++){
        double h = arr->WaveHeight;
        //if current waveheight is heigher then height input, print to out_stm
        if(h > height)
            fprintf(out_stm, "%5.2lf %s\n", h, arr->Location);
    }
}

