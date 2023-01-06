/******************************************************************************
* @filename stats_driver.c
* @author   Prasanna Ghali
* @DP email pghali@digipen.edu 
* @course   High-Level Programming 1
* @section  All sections 
* @date     07/26/2017
* @brief    Implementation of driver to test the interface declared
*           in stats.h and implemented in stats.o
******************************************************************************/
#include "stats.h"  // stats package
#include <stdlib.h> // rand(), srand()

// create data set with range of values [0, 999]
int *create_data_set(int);

int main(void) {
  int const data_sz = 200;
  int *data_set = create_data_set(data_sz);
  print_statistics(data_set, data_sz);
  free(data_set);

  return 0;
}

int *create_data_set(int size) {
  int *pi = (int*) malloc(sizeof(int) * size);
  
  srand(1023);
  int i = 0;
  while (i < size) {
    pi[i++] = rand() % 1000;    
  }
  return pi;
}