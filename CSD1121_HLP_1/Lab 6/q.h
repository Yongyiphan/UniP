// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 6 Problem Solving in Arrays
@date 17/10/2022
@brief Contains declaration for functions that
    : return max value in an array
    : return min value in an array
    : return average of a set of value in an array

*//*______________________________________________________________________*/

// @todo: Provide function-level documentation header as explained in the specs ...
// It is important that you provide function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users to solve problems related to computing summary statistics.
// In a commercial environment, the source file q.c containing definitions of
// functions that compute summary statistics is your intellectual property and should
// therefore be kept private. Instead, you'll provide your clients object file q.o
// [obtained by only compiling q.c].
// Therefore, your clients will know how to use the functions related to computing
// summary statistics only by reading this function-level documentation header ...

// @todo: Now, provide the declarations or prototypes of necessary functions ...

//Function: to read user input to fill in an array of N values
//returns the size of array
int read_data(double array[], int max_count);

//returns index of array of which the max value of the array is located at
int max_index(double const arr[], int size);

//returns index of array of which the min value of the array is located at
int min_index(double const arr[], int size);

//returns the average of an array
double mean(double const arr[], int size);

//returns the variance of values of an array from the average of an array 
double variance(double const arr[], int size);

//returns the standard-deviations of a array of double values
double std_dev(double const arr[], int size);

