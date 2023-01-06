// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 4: Formatted Console I/O
@date 23/09/22
@brief

*//*______________________________________________________________________*/
#include <stdio.h>

int main(void){
    int x, y, z;
    int r = scanf("%d-%d-%d", &x, &y, &z);
    printf("%d\n", r);
    return 0;
}

