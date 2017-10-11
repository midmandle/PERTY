#include <cxxtest/TestSuite.h>

#include "sort.h"

class SortingTestSuite : public CxxTest::TestSuite
{
  public:

    void test_compareIntArrays(void)
    {
      int arrayA[10] = {10,5,4,8,9,6,7,3,2,1};
      int arrayB[10] = {1,2,3,4,5,6,7,8,9,10};
      int arrayC[10] = {1,2,3,4,5,6,7,8,9,10};

      TS_ASSERT_EQUALS(0, compareIntArrays(arrayA, arrayB, 10));

      TS_ASSERT_EQUALS(1, compareIntArrays(arrayC, arrayB, 10));
    }

    void test_bubbleSort(void)
    {
      int arrayA[10] = {10,5,4,8,9,6,7,3,2,1};
      int arrayB[10] = {1,2,3,4,5,6,7,8,9,10};

      TS_ASSERT_EQUALS(0, compareIntArrays(arrayA, arrayB, 10));
      bubbleSort(arrayA, sizeof(int), sizeof(arrayA), 0);
      TS_ASSERT_EQUALS(1, compareIntArrays(arrayA, arrayB, 10));
    }

    void test_insertionSort(void)
    {
      int array[10] = {10,5,4,8,9,6,7,3,2,1};

      TS_ASSERT(0==0);
    }

    void test_quickSort(void)
    {
      int array[10] = {10,5,4,8,9,6,7,3,2,1};

      TS_ASSERT(0==0);
    }
};
