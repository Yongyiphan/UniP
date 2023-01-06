// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 4: Formatted Console I/O
@date 23/09/22
@brief This file contains functions to calculate the coin breakdown of money
    inputted by user. And a go() function that runs the entire program indefinitely
    until a break condition occurs. 
*//*______________________________________________________________________*/

//Including Header files
#include <stdio.h>

//Function prints a single line of the output
//table; it takes in index (to be displayed in the first column), the value cents remaining
//for breakdown (the breakdown is shown in the third column), and value
//corresponding to the denomination used in the current line; it returns no output.
void print_line(int index, int rest, int denomination){

    //Col 1 -> 2 digit space, align left
    //Col 2 -> 9 digit space, align right
    //  must contain a single char of a decimal separator (.)
    //  and 2 decimal position representing cents.
    //  cents must show the leading 0
    //Col 3 -> 5 digit space, align right
    if (denomination >= 100){
        printf("| %-2d | %9d.00 | %5d |\n", index, denomination/100, rest);
    }
    else if(denomination >= 10){
        printf("| %-2d | %9d.%d | %5d |\n", index,0 ,denomination, rest);
    }
    else if(denomination >= 1){
        printf("| %-2d | %9d.0%d | %5d |\n", index,0 ,denomination, rest);
    }

}

//This function takes in cents which is the value in cents to be
//broken down into the various denominations. It prints the header of the output table, a
//row for each denomination by calling print_line , and the borders of the table.
//break_down returns void.
void break_down(int cents){
    //TODO: provide implementation later
    //in cents
    //print output header
    printf("\n");
    printf("+----+--------------+-------+\n");
    printf("| #  | Denomination | Count |\n");
    printf("+----+--------------+-------+\n");
    //using a for loop
    //loops through a int array which contains all denominations in cents format
    
    int quotient, denom;
    int denomination[11] = {10000, 5000, 1000, 500, 200, 100, 50, 20, 10, 5, 1};
    for(int i = 0; i<11; i++){
        //for each int denominations in the int array,
        //divide the remaining cents with the denomination to find 
        //how many of the denomination does the remaining cents contain
        denom = denomination[i];
        quotient = cents /denom;
        //subtract the result from cents, to get new remainder value
        cents -= quotient * denom;
        //print out result
        print_line(i+1, quotient, denom);
    }

    //Implemented using a while loop
    //while loop loops with each iterations
    //subtracting the closest denomination and having its make up 
    //recorded which is then printed out in a certain format;
    //int hundred = 10000, fifty = 5000, ten = 1000, five = 500, two = 200, one = 100, fiftycents = 50, twentycents = 20, tencents = 10, fivecents = 5, onecents = 1;
    //int hundredq = 0, fiftyq =0, tenq=0, fiveq=0, twoq=0, oneq=0, fiftycentsq=0, twentycentsq=0, tencentsq=0, fivecentsq=0, onecentsq=0;
    //while (cents >  0){
    //    if(cents >= hundred){
    //        hundredq = cents/hundred;
    //        cents -= hundredq * hundred;
    //    }
    //    else if(cents >= fifty){
    //        fiftyq = cents/fifty;
    //        cents -= fiftyq * fifty;
    //    }
    //    else if(cents >= ten){
    //        tenq = cents/ten;
    //        cents -= tenq * ten;
    //    }
    //    else if(cents>= five){
    //        fiveq = cents / five;
    //        cents -= fiveq * five;
    //    }
    //    else if(cents>=two){
    //        twoq = cents/two;
    //        cents -=  twoq * two;
    //    }
    //    else if(cents>=one){
    //        oneq = cents/one;
    //        cents -= oneq * one;
    //    }
    //    else if(cents>=fiftycents){
    //        fiftycentsq = cents/fiftycents;
    //        cents -= fiftycentsq * fiftycents;
    //    }
    //    else if(cents >= twentycents){
    //        twentycentsq = cents/twentycents;
    //        cents -= twentycentsq * twentycents;
    //    }
    //    else if(cents >= tencents){
    //        tencentsq = cents/ tencents;
    //        cents -= tencentsq * tencents;
    //    }
    //    else if(cents >=fivecents){
    //        fivecentsq = cents/fivecents;
    //        cents -= fivecentsq * fivecents;
    //    }
    //    else if(cents >= onecents){
    //        onecentsq = cents/onecents;
    //        cents -= onecentsq * onecents;
    //    }
    //}
    //print_line(1, hundredq, hundred);
    //print_line(2, fiftyq, fifty);
    //print_line(3, tenq, ten);
    //print_line(4, fiveq, five);
    //print_line(5, twoq, two);
    //print_line(6, oneq, one);
    //print_line(7, fiftycentsq, fiftycents);
    //print_line(8, twentycentsq, twentycents);
    //print_line(9, tencentsq, tencents);
    //print_line(10, fivecentsq, fivecents);
    //print_line(11, onecentsq, onecents);
    

    printf("+----+--------------+-------+\n");

}

//This is the entry point of the program that does not take in any
//parameters. It handles all user input for the amount of money to break-down into
//denominations. main performs input validation and calls break_down to execute the
//break-down and print out the results. This function always returns 0 .

void go(void){

while(1){
    //TODO: provide implementation later
    int dollars, cents; 
    //print question for user input
    printf("Please enter total value: ");
    //accept user input, with number of input being assigned to the variable input
    int input = scanf("%d.%d", &dollars, &cents);
    //break conditions of
    //if there missing input of either dollar/cents,
    //if there is no dollar input
    //if cents input is not in range of 0~99 (0 and 99 inclusive)
    if (input != 2 || dollars < 0 || cents <0 || cents > 100)
    {
        //if invalid input is received, breaks while loop, exiting the program. 
        printf("Program ended\n");
        break;
    }
    //if valid input is given;
    //proceed with converting dollar.cents to cents format
    cents += dollars * 100;
    //call function to get the break down of the user's input
    break_down(cents);
}   
}