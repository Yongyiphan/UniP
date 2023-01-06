#include <stdio.h>
#include "q.h"


int main(void){

    //printf("Enter a number: ");
    int input, i = 40;
    while (i > 0){
        scanf("%d", &input);
        if (input > 0 && input <= 5000){
            decimal_to_roman(input);
        }
        i--;
    }
    return 0;
}