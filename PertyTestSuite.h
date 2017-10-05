#include <cxxtest/TestSuite.h>

#include "pert.h"

class PertyTestSuite : public CxxTest::TestSuite
{
  struct Task *task1;
  struct Task *task2;
  struct TaskList *testList;

  public:
    void setUp()
    {
      task1 = newTask();
      task2 = newTask();
      testList = newTaskList();
      task1->optimistic = 1.0f;
      task1->estimated = 3.0f;
      task1->pesimistic = 12.0f;

      task2->optimistic = 1.0f;
      task2->estimated = 1.5f;
      task2->pesimistic = 14.0f;

      task1->expected = expectedDuration(task1);
      task1->standardDeviation = standardDeviation(task1);
      task2->expected = expectedDuration(task2);
      task2->standardDeviation = standardDeviation(task2);
    }

    void tearDown()
    {
      //This has been confirmed working but should be done manually.
      //freeTaskList(testList);
    }

    void helper_showListPointers(struct TaskList *testList)
    {
      int i = 0;
      testList->current = testList->head;
      printf("\n");
      while(testList->current != NULL)
      {
        i++;
        printf("[%d] CURRENT: %p\tNEXT: %p\n", i, testList->current, testList->current->nextItem);
        testList->current = testList->current->nextItem;
      }
    }

    void test_PERTExpectedDurationFunction(void)
    {
      TS_ASSERT_EQUALS(4.17f , expectedDuration(task1));
      TS_ASSERT_EQUALS(3.5f , expectedDuration(task2));
    }

    void test_PERTStdDeviationFunction(void)
    {
      TS_ASSERT_EQUALS(1.83f , standardDeviation(task1));
      TS_ASSERT_EQUALS(2.17f , standardDeviation(task2));
    }

    void test_bestCaseEstimateFunction(void)
    {
      TS_ASSERT_EQUALS(4.17f-1.83f , bestCaseEstimate(1, task1));
      TS_ASSERT_EQUALS(3.5f-2.17f , bestCaseEstimate(1, task2));
      TS_ASSERT_EQUALS(4.17f-(1.83f*2) , bestCaseEstimate(2, task1));
    }

    void test_worstCaseEstimateFunction(void)
    {
      TS_ASSERT_EQUALS(4.17f+1.83f , worstCaseEstimate(1, task1));
      TS_ASSERT_EQUALS(3.5f+2.17f , worstCaseEstimate(1, task2));
      TS_ASSERT_EQUALS(4.17f+(1.83f*2) , worstCaseEstimate(2, task1));
    }

    void test_processTaskListFunction(void)
    {
      processTaskList(testList);

      float calculatedExpectedValue = 0;
      float calculatedStdDevValue = 0;
      float calculatedBestCaseValue = 0;
      float calculatedWorstCaseValue = 0;

      testList->current = testList->head;
      while(testList->current != NULL)
      {
        calculatedExpectedValue = expectedDuration(testList->current->item);
        calculatedStdDevValue = standardDeviation(testList->current->item);
        calculatedBestCaseValue = bestCaseEstimate(1,testList->current->item);
        calculatedWorstCaseValue = worstCaseEstimate(1,testList->current->item);
        TS_ASSERT_EQUALS(calculatedExpectedValue, testList->current->item->expected);
        TS_ASSERT_EQUALS(calculatedStdDevValue, testList->current->item->expected);
        TS_ASSERT_EQUALS(calculatedBestCaseValue, testList->current->item->expected);
        TS_ASSERT_EQUALS(calculatedWorstCaseValue, testList->current->item->expected);
        testList->current = testList->current->nextItem;
      }
    }

    void test_addNewTaskToList(void)
    {
      TS_ASSERT(testList->head == NULL);
      TS_ASSERT(testList->current == NULL);

      addTaskToTaskList(testList, task1);

      TS_ASSERT(testList->head != NULL);
      TS_ASSERT(testList->current != NULL);

      struct ListItem *tempHead = testList->head;
      struct ListItem *tempCurrent = testList->current;

      addTaskToTaskList(testList, task2);
      //printf("Task1 %x, Task2 %x\n", task1, task2);
      //Should still point to the HEAD of the list even with multiple items.
      TS_ASSERT_EQUALS(testList->head, tempHead);
      TS_ASSERT(testList->current != tempCurrent);
      TS_ASSERT_EQUALS(testList->current->item, task2);

      //helper_showListPointers(testList);
    }

    void test_addMultipleTasksToList(void)
    {
      addMultipleTasksToList(testList, 2, task1, task2);
      helper_showListPointers(testList);

      TS_ASSERT_EQUALS(testList->head->item, task1);
      TS_ASSERT_EQUALS(testList->head->nextItem->item, task2);
    }

    void test_freeTaskList(void)
    {
      addTaskToTaskList(testList, task1);
      addTaskToTaskList(testList, task2);
      //printf("Task1 %x, Task2 %x\n", testList->head->item, testList->current->item);
      freeTaskList(testList);
      //printf("Task1 %x, Task2 %x\n", testList->head->item, testList->current->item);
      TS_ASSERT(testList->head->item == 0);
      TS_ASSERT(testList->current->item == 0);
    }

    void test_calculateExpectedForFullTaskList(void)
    {
      addTaskToTaskList(testList, task1);
      addTaskToTaskList(testList, task2);

      processTaskList(testList);

      float testExpectedValue = 7.67f;
      float actualExpectedValue = calculateExpectedForTaskList(testList);

      TS_ASSERT_EQUALS(testExpectedValue, actualExpectedValue);
    }

    void test_calculateStdDevForFullTaskList(void)
    {
      addTaskToTaskList(testList,task1);
      addTaskToTaskList(testList,task2);

      processTaskList(testList);

      //Sqrt of the sum of squares of StdDevs
      float testStdDevValue = 2.84f;
      float actualStdDevValue = calculateStdDevForTaskList(testList);

      TS_ASSERT_EQUALS(testStdDevValue, actualStdDevValue);
    }

};
