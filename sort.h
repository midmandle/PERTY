#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *bubbleSort(void *data, size_t sizeOfElement, size_t sizeOfGroup, size_t offsetToComparable);
void *insertionSort();
void *quickSort();

int compareIntArrays(int arrayA[], int arrayB[], int size);
