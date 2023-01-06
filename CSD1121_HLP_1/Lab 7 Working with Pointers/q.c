// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 7 Working with Pointers
@date 21/10/2022
@brief Function Definition for 
    : reading numbers from user
    : read 3 numbers of input and returns respective values via pointers
    : swap 2 values using pointers
    : sort 3 numbers in descending order with pointers as input parameters
    : sort 4 numbers in descending order. keeping only the largest 3 values
        with pointers to 3 sorted numbers and resorting with an additonal number

*//*______________________________________________________________________*/
// @todo: Add necessary C standard library headers here ...
#include <stdio.h>
#include <stdlib.h>
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in q.h ...

// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in q.h ...
/*
Reads in one integer from the user and tests if the value is less than 3. In such case it prints
an error message and causes the entire program to exit by calling the function exit() - read
the online reference for more information.
*/
size_t read_total_count(void){
    size_t uI = 0;
    printf("Please enter the number of integers: ");
    scanf("%zu", &uI);
    //if int input value < 3
    //output error
    if(uI < 3){
        printf("There is no third largest number.\n");
        exit(0);
    }
    return uI;
}

/*
Performs a simple task of reading in 3 integer values from the user and initializing the
objects pointed to by the function parameters. These parameters are meant to allow for
side-effect output; programmers sometimes refer to such parameters as output parameters
*/
void read_3_numbers(int* first, int *second, int*third){
    int one, two, three;
    //read three inputs from user
    //and store them in local values
    scanf("%d %d %d", &one, &two, &three);
    //update pointers with values received
    *first = one;
    *second = two;
    *third = three;
}

/*
Exchanges the values of the left-hand side object indicated by lhs and the right-hand side
object indicated by rhs .
*/
void swap(int*lhs, int*rhs){
    //temp to store temp number before overriding
    int temp = *lhs;
    //swap two numbers' values
    *lhs = *rhs;
    //update with stored temp value
    *rhs = temp;
}

/*
Sorts the values of integer objects indicated by pointer parameters, so that when the
function returns the largest value is in the object indicated by first , the second largest in
the object indicated by second , and the third largest in the object indicated by third .
*/
void sort_3_numbers(int*first, int*second, int*third){
    if(*first < *third){
        swap(first, third);
    }
    if(*first < *second){
        swap(first, second);
    }
    if(*second < *third){
        swap(second, third);
    }

}

/*
Assumes that objects indicated by first , second , and third have been already sorted
and inserts a new value number into these objects as necessary, so that when the function
returns the largest value is in the object indicated by first , the second largest in the object
indicated by second , and the third largest in the object indicated by third ; the fourth
unnecessary value can be discarded.
*/
void maintain_3_largest(int number, int*first, int*second, int*third){
    //algo to sort 4 numbers in ascending order
    if (number > *first) {swap(&number, first);}
    if (*second > *third) {swap(second, third);}
    if (number > *second) {swap(&number,second);}
    if (*first > *third) {swap(first, third);}
    if (*first > *second) {swap(first, second);}
    //first second and third are the largest values
    //in ascending order.
    //resort them into descending order
    sort_3_numbers(first, second, third);
}

