#include <stdio.h>
#include "greeting.h"

//gcc -std=c11 -pedantic-errors -Wall -Wextra -Werror -c calc.c -o calc.o
//gcc -std=c11 -pedantic-errors -Wall -Wextra -Werror -c calc-driver.c -o calc-driver.o
//gcc calc-driver.o calc.o -o calc.out
//./calc.out > good.txt


int main(void){
    greeting();
    return 0;

}

