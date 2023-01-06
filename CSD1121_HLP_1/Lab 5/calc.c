
#include "operation.h"
#include <stdio.h>
#include <math.h>


void calculate(float x, float y, operation op){
    printf("\t");
    switch (op)
    {
    case UNKNOWN:
        printf("\tUnknown operation selected!\n");
        break;
    case ADDITION:
        printf("%f", x + y);
        break;
    case SUBTRACTION:
        printf("%f", x - y);
        break;
    case MULTIPLICATION:
        printf("%f", x * y);
        break;
    case DIVISION:
        if(y == 0){
            printf("Division by 0!\n");
        }
        printf("%f", x / y);
        break;
    case DIVISION_INTEGERS:
        if(y == 0){
            printf("Division by 0!\n");
        }
        printf("\t%f\n", (float) ((int)x/(int)y));
        break;
    case MODULUS:
        if (y == 0){
            printf("Division by 0!\n");
        }
        printf("\t%f\n", (float) ((int)x/(int)y));
        break;
    default:
        break;
    }
}