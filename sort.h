#ifndef __SORT_H__
#define __SORT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pert.h"

void bubbleSort(void *data, size_t sizeOfElement, size_t sizeOfGroup, size_t offsetToComparable, size_t sizeOfComparable);
void insertionSort();
void quickSort();

struct ListItem *simpleSort(struct ListItem *listItem);

int compareIntArrays(int arrayA[], int arrayB[], int size);
#endif
