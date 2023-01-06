/*
@filename       q.h
@author         dylan.h
@course         CSD1121
@assignment     Lab 11
@date           18 November 2022
@brief          This file contains the declaration for print_data function.
*/

#include <stdio.h>
#include "q.h"


/*!
@brief -            Prints out data in a fixed format, based off array provided, data size, and span of each data
@param              *ptr - Address of first byte in array
                    size - Total count of bytes
                    span - Count of bytes printed per line
@return             void
*//*______________________________________________________________*/
void print_data(const void* ptr, size_t size, size_t span) {
    const char* ptrChar = (const char*)ptr;
    for (size_t currentSize = 0; currentSize < size; currentSize += span) {
        for (size_t currentSpan = 0; currentSpan < span; currentSpan += 4) {
            fprintf(stdout, "%x ", *(ptrChar + currentSize + currentSpan));
            fprintf(stdout, "%x ", *(ptrChar + currentSize + currentSpan + 1));
            fprintf(stdout, "%x ", *(ptrChar + currentSize + currentSpan + 2));
            fprintf(stdout, "%x ", *(ptrChar + currentSize + currentSpan + 3));
            fprintf(stdout, "  ");
        }
        fprintf(stdout, "|   ");
        for (size_t currentSpan = 0; currentSpan < span; currentSpan += 4) {
            fprintf(stdout, "%c ", *(ptrChar + currentSize + currentSpan));
            fprintf(stdout, "%c ", *(ptrChar + currentSize + currentSpan + 1));
            fprintf(stdout, "%c ", *(ptrChar + currentSize + currentSpan + 2));
            fprintf(stdout, "%c ", *(ptrChar + currentSize + currentSpan + 3));
            fprintf(stdout, "  ");
        }
        fprintf(stdout, "\n");
    }
}
