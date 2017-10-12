#include "sort.h"

void bubbleSort(void *data, size_t sizeOfElement, size_t sizeOfGroup, size_t offsetToComparable, size_t sizeOfComparable)
{
  int numberOfElements = sizeOfGroup/sizeOfElement;
  int switchOccured = 0;
  //printf("%d\t%d\t%d\n", numberOfElements, sizeOfGroup, sizeOfElement); DEBUGGING OUTPUT

  int j = 0;
  do
  {
    switchOccured = 0;
    for(int i = 0; i < numberOfElements-1; i++)
    {
      char tempItemA[sizeOfElement];
      char tempItemB[sizeOfElement];
      memcpy(tempItemA, (char *)data+(i*sizeOfElement), sizeOfElement);
      memcpy(tempItemB, (char *)data+((i+1)*sizeOfElement), sizeOfElement);

      if(*(tempItemA+offsetToComparable) > *(tempItemB+offsetToComparable))
      {
        switchOccured = 1;
        memcpy((char *)data+((i+1)*sizeOfElement), tempItemA, sizeOfElement);
        memcpy((char *)data+(i*sizeOfElement), tempItemB, sizeOfElement);
      }

      //DEBUGGING OUTPUT
      /*printf("A = %x\n", *tempItemA);
      printf("B = %x\n", *tempItemB);*/

    }
    j++;
  }while(switchOccured);

  //DEBUGGING OUTPUT
  /*for(int i = 0; i < numberOfElements; i++)
  {
    char tempItemA[sizeOfElement];
    memcpy(tempItemA, (char *)data+(i*sizeOfElement), sizeOfElement);
    printf("%x\n", *tempItemA);

  }*/

}

void insertionSort(void *data)
{

}

void quickSort(void *data)
{

}

struct ListItem *simpleSort(struct ListItem *listItem)
{

  if(listItem->item->priorityExpected <= listItem->nextItem->item->priorityExpected)
  {
    //Do a switch and reiterate.
    //TODO THIS NEEDS WORKING OUT!!
    listItem->nextItem = listItem->nextItem->nextItem;
    listItem = simpleSort(listItem);
    return listItem;
  }

  listItem->nextItem = simpleSort(listItem->nextItem);
  return listItem;

}

int compareIntArrays(int arrayA[], int arrayB[], int size)
{
  for(int i = 0; i < size; i++)
  {
    if(arrayA[i] == arrayB[i])
      continue;
    else
      return 0;
  }

  return 1;
}
