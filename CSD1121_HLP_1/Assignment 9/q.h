#ifndef Q_H
#define Q_H

// TODO: File documentation block required
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.h
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 9, Problem solving with structures and files
@date 7/11/2022
@brief

*//*______________________________________________________________________*/

/*The data members encapsulated in struct 
Tsunami must include the tsunami's
date of occurrence [including month, day, and year], 
its maximum wave height, 
number of human fatalities caused by the tsunami, and 
geographical location. 
The month, day, year, and number of fatalities are represented as int s, 
the maximum wave height is represented as a doubleprecision floating-point number, and the 
location is represented by a null-terminated character string with a maximum of 80 characters 
*/
#include <stdio.h>
typedef struct Tsunami{
    int day;
    int month;
    int year;
    double WaveHeight;
    int Fatalities;
    char Location[80];
}Tsunami;
// TODO: Include only those C standard library headers that declare/define names used in functions declared below

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
int read_data(char const *file_name, struct Tsunami *arr, int max_cnt);

/**
 * @brief      Function print_info prints to output stream out_stm a nicely formatted list of the
            information recorded in each tsunami event 
 * @param     *arr => arr of tsunami structs
            size => size of tsunami arr
            out_stm => file to output to
 * @returns    none
*/
void print_info(struct Tsunami const *arr, int size, FILE *out_stm);

/**
 * @brief   Function get_max_height returns the maximum wave height in array specified by base
            address arr with size number of tsunami events
 * @param   arr => arr of tsunami which contains data obtained from read_data
 * @param   size => size of array 
 * @return  maximum height of wave found in arr
 */
double get_max_height(struct Tsunami const *arr, int size);

/**
 *  @brief  Function get_average_height returns the average wave height in array specified by base
            address arr with size number of tsunami events
    @param  arr => array of tsunami struct
    @param  size => size of array
    @return average height of wave data store in tsunami struct array
* 
*/double get_average_height(struct Tsunami const *arr, int size);

/**
 * @brief   Function print_height prints to output stream out_stm the maximum wave heights and
            locations of those tsunamis with higher maximum wave heights than the wave height
            specified by parameter height . 
 * @param arr => arr of tsunami struct
 * @param size => size of array
 * @param height => height to compare against print out height that is heigher than this value
 * @param out_stm => file stream to print out
 */
void print_height(struct Tsunami const *arr, int size, double height, FILE *out_stm);

#endif
