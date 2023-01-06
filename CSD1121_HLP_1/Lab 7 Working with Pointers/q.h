// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 7 Working with Pointers
@date 21/10/2022
@brief Function declaration for 
    : reading numbers from user
    : read 3 numbers of input and returns respective values via pointers
    : swap 2 values using pointers
    : sort 3 numbers in descending order with pointers as input parameters
    : sort 4 numbers in descending order. keeping only the largest 3 values
        with pointers to 3 sorted numbers and resorting with an additonal number

*//*______________________________________________________________________*/

// @todo: Provide function-level documentation header for each function 
// as explained in Assignment 2 specs ...
// It is important that you provide a function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users ...

// @todo: Now, provide the declaration or prototype of the functions 
// read_total_count, read_3_numbers, swap, sort_3_numbers, and 
// maintain_3_largest

/*
Reads in one integer from the user and tests if the value is less than 3. In such case it prints
an error message and causes the entire program to exit by calling the function exit() - read
the online reference for more information.
*/
size_t read_total_count(void);

/*
Performs a simple task of reading in 3 integer values from the user and initializing the
objects pointed to by the function parameters. These parameters are meant to allow for
side-effect output; programmers sometimes refer to such parameters as output parameters
*/
void read_3_numbers(int* first, int *second, int*third);

/*
Exchanges the values of the left-hand side object indicated by lhs and the right-hand side
object indicated by rhs .
*/
void swap(int*lhs, int*rhs);


/*
Sorts the values of integer objects indicated by pointer parameters, so that when the
function returns the largest value is in the object indicated by first , the second largest in
the object indicated by second , and the third largest in the object indicated by third .
*/
void sort_3_numbers(int*first, int*second, int*third);


/*
Assumes that objects indicated by first , second , and third have been already sorted
and inserts a new value number into these objects as necessary, so that when the function
returns the largest value is in the object indicated by first , the second largest in the object
indicated by second , and the third largest in the object indicated by third ; the fourth
unnecessary value can be discarded.
*/
void maintain_3_largest(int number, int*first, int*second, int*third);

