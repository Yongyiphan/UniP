// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 6 Problem Solving with Arrays 
@date 17/10/2022
@brief Contains definition for functions that
    : uses a loop to read in values for an array
    : index of which the max value of the array is located at
    : index of which the min value of the arrau is located at
    : average of value in an array
    : variance of values in an array
    : standard deviation of values in an array
*//*______________________________________________________________________*/
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of neccessary functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily meant for your clients.
// The documentation header here is primarily for use by you [and other on your team] solely t
// aid maintenance and debugging tasks ...

// @todo: If necessary, include q.h here ...
#include "q.h"
#include <stdio.h>
#include <math.h>

// @todo: Add necessary C standard library headers here ...

// @todo: Provide necessary definitions of functions
// that match corresponding declarations in q.h ...

//Takes in an array of n size and its size as parameters
int read_data(double array[], int max_count){
    int i = 0;
    double num;
    //using while loop, fill in array with values retrieved with scanf
    while ((scanf("%lf", &num) != EOF ) && i < max_count){
        array[i++] = num;
    }
    return i; 
}

//Returns the index of which the max value of the array is located at
int max_index(double const arr[], int size){
    double cMax = 0, index;
    //loop through array to find the index of which the max value is located at.
    for(int i = 0; i < size; i++){
        if(arr[i] > cMax){
            //if value at current index is larger than the previously recorded maximum
            //update recorded maximum
            //update its relative index
            cMax = arr[i];
            index = i;
        }
    }    
    return index;
}

//Returns the index of which the min value of the array is located at
int min_index(double const arr[], int size){
    double cMin = arr[0], index;
    //loop through array to find the index of which the min value is located at.
    for(int i = 0; i < size; i++){
        if(arr[i] < cMin){
            //if value at current index is smaller than the previously recorded minimum 
            //update recorded minimum
            //update its relative index
            cMin = arr[i];
            index = i;
        }
    }    
    return index;
}

//returns average value of an array of double values
double mean(double const arr[], int size){

    double sum = 0;
    //sum up all value within array
    for(int i= 0; i <size; i++){
        sum += arr[i];
    }
    //return average of array by dividing total sum with size of array
    return sum/size;
}

//returns the variance from the average of an array
double variance(double const arr[], int size){
    //returns 0 if array size is < 2
    //due to possible division by zero error
    if (size <2){
        return 0.0;
    }

    //get average with previously defined functino: mean()
    double avg = mean(arr, size), sum = 0.0;
    for(int i=0; i<size; i++){
        //sum up the squared value of the difference between value at index with the average of the array
        sum += pow(arr[i] - avg, 2);
    }

    //return variance
    return sum/(size-1);
}

//returns standard deviation of an array
double std_dev(double const arr[], int size){
    //std_dev is the squared root of variance of an array
    return sqrt(variance(arr, size));
}