// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 6 Linear Algebra and Arrays 
@date 17/10/2022
@brief  This file contains the definition of functions that
    : reverse an array of values
    : sum up values of two arrays
    : scale elements of array by given scale factor
    : dot product of 2 arrays
    : cross product of 2 arrays of size of at least 3
    : length of array = square root of sum of squared values of elements of array

*//*______________________________________________________________________*/
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of neccessary functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily meant for your clients.
// The documentation header here is primarily for use by you [and other on your team] solely t
// aid maintenance and debugging tasks ...

// @todo: If necessary, include q.h here ...
#include <math.h>

// @todo: Add necessary C standard library headers here ...

// @todo: Provide necessary definitions of functions
// that match corresponding declarations in q.h ...

// Given an array, reverse the order of the elements in the array.
// Do not create another array in the function
void reverse_array(int a[], int size){
    //reverse values of array by switching the values at
    //the start and end. moving towards the center of the array
    int start = 0, end = size - 1, temp;
    while(start<end){
        //store the value at the left of array
        temp = a[start];
        //replace left of array with right of array
        a[start] = a[end];
        //replace right of array with left of array stored within variable "temp"
        a[end] = temp;

        //move index towards middle of array
        start++;
        end--;
    }
}

// Add elements of first two arrays and put the sum in the third array.
void add_arrays(int const a[], int const b[], int c[], int size){
    /* 
    loop through two array with same size with increasing index of 'i'
    add value from both array at index 'i'
    store sum'ed values in c[] at index 'i'
    */
    for(int j = 0; j < size; j++){
        c[j] = a[j] + b[j];
    }
}

// Given an array and multiplier, multiply each element by multiplier.
void scalar_multiply(int a[ ], int size, int scale_factor){
    /*
    loop through array a[]'s elements using its size
    multiply each said elements with scale factor
    */
    for (int i = 0; i<size; i++){
        a[i] *= scale_factor;
    }
}

// Given two arrays, return the dot product. Dot product means sum of
// products, i.e., multiply each corresponding element of 2 arrays and
// sum the products.
int dot_product(int const a[ ], int const b[ ], int size){
    int sum = 0;
    /*
    loop through 2 arrays of same size with increasing index of 'i'
    sum up all mutiplied values of value at a[i] and b[i]
    */
    for(int i = 0; i < size; i++){
        sum += a[i] * b[i];
    }
    //return dot product
    return sum;
}

// Given three arrays, determine the cross product of the first two.
// The cross product is another array and will be placed into third array.
// The size of all three arrays will always be at least three.
void cross_product(int const a[ ], int const b[ ], int c[ ]){
    /* Formula for cross product
        -> Vectors of only size 3 [x, y, z]
    Cross Product (CP) of 
    [x1, y1, z1] and 
    [x2, y2, z2] = 
    [i, -(j), k]
    where 
        :  i =  (y1 * z2) - (y2 * z1)
        : -j = ((x1 * z2) - (x2 * z1)) * -1
        :  k =  (x1 * y2) - (x2 * y1) 
    */
    c[0] =  (a[1] * b[2]) - (a[2] * b[1]);
    c[1] = ((a[0] * b[2]) - (a[2] * b[0])) * -1;
    c[2] =  (a[0] * b[1]) - (a[1] * b[0]);
}

// Return length or magnitude of array with size element.
double length(int const a[ ], int size){

    /*Formula for length of vector (array)
    square root of (sum of (squared of each element in array))
    */
    double s = 0;
    //Calculates the sum of squared value of each element in array
    for(int i = 0; i < size; i++){
        s += a[i] * a[i];
    }
    return sqrt(s);
}

