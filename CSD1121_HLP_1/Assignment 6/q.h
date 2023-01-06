// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
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

// @todo: Provide function-level documentation header as explained in the specs ...
// It is important that you provide function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users to solve certain problems related to linear algebra.
// In a commercial environment, the source file q.c containing definitions of
// functions that solve linear algebra problems is your intellectual property and should
// therefore be kept private. Instead, you'll provide your clients object file q.o
// [obtained by only compiling q.c].
// Therefore, your clients will know how to use the functions related to solving
// linear algebra problems only by reading this function-level documentation header ...

// @todo: Now, provide the declarations or prototypes of necessary functions ...

// Given an array, reverse the order of the elements in the array.
// Do not create another array in the function
void reverse_array(int a[], int size);

// Add elements of first two arrays and put the sum in the third array.
void add_arrays(int const a[], int const b[], int c[], int size);

// Given an array and multiplier, multiply each element by multiplier.
void scalar_multiply(int a[ ], int size, int scale_factor);

// Given two arrays, return the dot product. Dot product means sum of
// products, i.e., multiply each corresponding element of 2 arrays and
// sum the products.
int dot_product(int const a[ ], int const b[ ], int size);

// Given three arrays, determine the cross product of the first two.
// The cross product is another array and will be placed into third array.
// The size of all three arrays will always be at least three.
void cross_product(int const a[ ], int const b[ ], int c[ ]);

// Return length or magnitude of array with size element.
double length(int const a[ ], int size);

