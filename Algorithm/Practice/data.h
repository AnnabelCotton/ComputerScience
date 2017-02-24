
#ifndef _DATA_HEADER_
#define _DATA_HEADER_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int Data;

int profiling;
int compareCount, swapCount;

void resetProfiling() {
    compareCount = 0;
    swapCount = 0;
    profiling = 1;
}

void closeProfiling() {
    profiling = 0;
}

void showProfiling() {
    printf("Compare Count = %d, Swap Count = %d.\n", compareCount, swapCount);
}

int compare(Data *a, Data *b) {
    if (profiling)
        compareCount++;

    return (*a > *b) ? 1 : (*a == *b ? 0 : -1);
}

void swap(Data *a, Data *b) {
    if (profiling)
        swapCount++;

    Data tmp = *a;
    *a = *b;
    *b = tmp;
}

int isSorted(Data seq[], int len) {
    int i;

    closeProfiling();

    for (i = 0; i < len - 1; i++)
        if (compare(seq + i, seq + i + 1) > 0)
            return 0;

    return 1;
}

void showSeq(Data seq[], int len) {
    int i;

    printf("seq = [ ");

    for (i = 0; i < len; i++)
        printf("%d ", seq[i]);

    printf("]\n");
}

#endif
