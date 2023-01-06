// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 4: Formatted Console I/O
@date 23/09/22
@brief Lab 4: Formatted Console I/O
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
    //int quotient, denom;
    //int denomination[11] = {10000, 5000, 1000, 500, 200, 100, 50, 20, 10, 5, 1};
    //for(int i = 0; i<11; i++){
    //    denom = denomination[i];
    //    quotient = cents /denom;
    //    cents -= quotient * denom;
    //    print_line(i+1, quotient, denom);
    //}

    int hundred = 10000, fifty = 5000, ten = 1000, five = 500, two = 200, one = 100, fiftycents = 50, twentycents = 20, tencents = 10, fivecents = 5, onecents = 1;
    int hundredq = 0, fiftyq =0, tenq=0, fiveq=0, twoq=0, oneq=0, fiftycentsq=0, twentycentsq=0, tencentsq=0, fivecentsq=0, onecentsq=0;
    while (cents >  0){
        if(cents >= hundred){
            hundredq = cents/hundred;
            cents -= hundredq * hundred;
        }
        else if(cents >= fifty){
            fiftyq = cents/fifty;
            cents -= fiftyq * fifty;
        }
        else if(cents >= ten){
            tenq = cents/ten;
            cents -= tenq * ten;
        }
        else if(cents>= five){
            fiveq = cents / five;
            cents -= fiveq * five;
        }
        else if(cents>=two){
            twoq = cents/two;
            cents -=  twoq * two;
        }
        else if(cents>=one){
            oneq = cents/one;
            cents -= oneq * one;
        }
        else if(cents>=fiftycents){
            fiftycentsq = cents/fiftycents;
            cents -= fiftycentsq * fiftycents;
        }
        else if(cents >= twentycents){
            twentycentsq = cents/twentycents;
            cents -= twentycentsq * twentycents;
        }
        else if(cents >= tencents){
            tencentsq = cents/ tencents;
            cents -= tencentsq * tencents;
        }
        else if(cents >=fivecents){
            fivecentsq = cents/fivecents;
            cents -= fivecentsq * fivecents;
        }
        else if(cents >= onecents){
            onecentsq = cents/onecents;
            cents -= onecentsq * onecents;
        }
    }
    print_line(1, hundredq, hundred);
    print_line(2, fiftyq, fifty);
    print_line(3, tenq, ten);
    print_line(4, fiveq, five);
    print_line(5, twoq, two);
    print_line(6, oneq, one);
    print_line(7, fiftycentsq, fiftycents);
    print_line(8, twentycentsq, twentycents);
    print_line(9, tencentsq, tencents);
    print_line(10, fivecentsq, fivecents);
    print_line(11, onecentsq, onecents);
    

    printf("+----+--------------+-------+\n");

}

//This is the entry point of the program that does not take in any
//parameters. It handles all user input for the amount of money to break-down into
//denominations. main performs input validation and calls break_down to execute the
//break-down and print out the results. This function always returns 0 .

int main(void){

    //TODO: provide implementation later
    int dollars, cents; 
    printf("Please enter total value: ");
    int input = scanf("%d.%d", &dollars, &cents);
    if (input != 2)
    {
        printf("You did not type in the correct format in terms of dollars and  cents.\n");
    }
    else if (dollars < 0)
    {
        printf("The dollars part specified must be non-negative.\n");
    }
    else if (cents < 0 || cents > 100)
    {
        printf("The cents part specified must be between 0...99 (inclusive)\n");
    }
    else 
    {
        cents += dollars * 100;
        break_down(cents);
    } 
   
}