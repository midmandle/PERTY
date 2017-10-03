#include <cxxtest/TestSuite.h>

#include "pert.h"

class PertyTestSuite : public CxxTest::TestSuite
{
  struct Task *task1 = newTask();
  struct Task *task2 = newTask();
  struct TaskList *testList = newTaskList();

  public:
    void setUp()
    {
      task1->optimistic = 1;
      task1->estimated = 3;
      task1->pesimistic = 12;

      task2->optimistic = 1;
      task2->estimated = 1.5;
      task2->pesimistic = 14;

      task1->expected = expectedDuration(task1);
      task1->standardDeviation = standardDeviation(task1);
      task2->expected = expectedDuration(task2);
      task2->standardDeviation = standardDeviation(task2);
    }

    void helper_showListPointers(TaskList testList)
    {
      int i = 0;
      while(testList.current != NULL)
      {
        printf("[%d]: %x\n", i, testList.current);
        i++;
        printf("CURRENT: %x %x NEXT: %x %x\n",&testList.current->item, testList.current->item, &testList.current->nextItem, testList.current->nextItem);
        testList.current = testList.current->nextItem;
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
};
