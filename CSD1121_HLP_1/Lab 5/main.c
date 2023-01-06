#include <stdio.h>
#include "calc.h"
#include "operation.h"

int main(void){
    float x, y;
    char operand;
    printf("This program evaluates mathematical expressions.\n");
    printf("The format of an expression is:\n");
    printf("\tOPERAND1 SYMBOL OPERAND2\n");
    printf("Available operation symbols:\n");
    printf("\t+ addition\n");
    printf("\t- subtraction\n");
    printf("\t* multiplication\n");
	printf("\t/ division\n");
	printf("\t\\ integer division\n");
	printf("\t%% modulus\n\n");

    while(1){
        printf("\nEnter an expression:\n\t");
        int noInput = scanf("\t%f%c%f", &x, &operand, &y);
        if(noInput != 3){
            printf("Invalid number of arguments!\n");
            int c;
            while( (c=getchar()) != '\n' && c!= EOF);
            break;
        }
        switch (operand)
        {
        case '+':            /* code */
            calculate(x, y, ADDITION);
            break;
        case '-':            /* code */
            calculate(x, y, SUBTRACTION);
            break;
        case '*':            /* code */
            calculate(x, y, MULTIPLICATION);
            break;
        case '/':            /* code */
            calculate(x, y, DIVISION);
            break;
        case '\\':            /* code */
            calculate(x, y, DIVISION_INTEGERS);
            break;
        case '%':            /* code */
            calculate(x, y, MODULUS);
            break;
        default:
            calculate(x, y, UNKNOWN);
            break;
        }
    }
    printf("Closing the program..\n");
    return 0;
}