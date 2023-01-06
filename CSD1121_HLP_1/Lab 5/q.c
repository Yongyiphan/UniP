// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 5 Flow Control 
@date 30/09/2022
@brief 
    cost() takes in user's age and number of accidents
    and calculates the total cost for when a person gets into an accident
    it outputs the base charges, in addition to additioanl surcharges depending on the number of accidents

    rev() takes in an int user input and prints said int input in reverse

*//*______________________________________________________________________*/
// @todo: Add necessary C standard library headers here ...

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
#include <stdio.h>
// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in q.h ...
//calculates the total costs of insurance coverage
void cost(void){

    int age, accidents, baseCharge = 500;
        //takes in user input values for users' age and number of accidents
        int inputs = scanf("%d, %d", &age, &accidents);
        //breaks if theres an invalid input by users
        if(inputs != 2){
            return;
        }
        
        printf("age = %d, number of accidents = %d, ", age, accidents);
        //evaluate user's age to determine is theres any need to calculate surcharges;
        if(age <16){
            printf("no insurance coverage!\n");
            //since there is not need for further calculation, end the program here.
            return;
        }
        if(age <25){
            baseCharge += 50;
        }
        if (accidents == 5){
            printf("no insurance coverage!\n");
            return;
        }
        printf("insurance cost = ");
        //determine what are the additional surcharges based on number of accidents
        if(accidents == 0){
            printf("%d\n", baseCharge + 0);
        }
        else if(accidents == 1 || accidents == 2){
            printf("%d\n", baseCharge + 100 );
        }
        else if(accidents == 3 || accidents == 4){
            printf("%d\n", baseCharge + 225);
        }
}


//outputs int input in reverse
void rev(void){
    //get users' input value, and record the number of inputs. 
    int inputValue , input = scanf("\n%d", &inputValue);
    if (input != 1){
        //if invalid input, returns/breaks from the program.
        return;
    }
    if (inputValue < 0){
        //print negative sign if value is negative
        printf("-");
        //update value to be positive
        inputValue *= -1;
    } 
    //assuming number of 2345   
    /*    
    n	    n != 0	remainder	reverse
    2345	true	5	        0 * 10 + 5 = 5
    234	    true	4	        5 * 10 + 4 = 54
    23	    true	3	        54 * 10 + 3 = 543
    2	    true	2	        543 * 10 + 2 = 5432
    0	    false	-	        Loop terminates..*/
    do{
        //get the digit in 1's position and print the remainder
        printf("%d", inputValue % 10);
        //divide value by 10 to get quotient, removing the previous value at 1's position.
        inputValue /=10;
    }
    //Keeps looping until theres not more remainder i.e value == 0
    while(inputValue > 0);
    //print a breakline
    printf("\n");
    //exits the program
    return;
}