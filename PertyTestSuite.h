#include <cxxtest/TestSuite.h>

#include "pert.h"

class PertyTestSuite : public CxxTest::TestSuite
{
  struct Task *task1;
  struct Task *task2;
  struct Task *task3;
  struct TaskList *testList;

  public:

    void setUp()
    {
      task1 = newTask();
      task2 = newTask();
      task3 = newTask(1.0f,3.0f,12.0f,3);

      task1->optimistic = 1.0f;
      task1->estimated = 3.0f;
      task1->pesimistic = 12.0f;

      task2->optimistic = 1.0f;
      task2->estimated = 1.5f;
      task2->pesimistic = 14.0f;
    }

    void tearDown()
    {

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

      free(task1);
      free(task2);
      free(task3);
    }

    void test_PERTStdDeviationFunction(void)
    {
      TS_ASSERT_EQUALS(1.83f , standardDeviation(task1));
      TS_ASSERT_EQUALS(2.17f , standardDeviation(task2));

      free(task1);
      free(task2);
      free(task3);
    }

    void test_bestCaseEstimateFunction(void)
    {
      processTask(task1);
      processTask(task2);
      TS_ASSERT_EQUALS(4.17f-1.83f , bestCaseEstimate(1, task1));
      TS_ASSERT_EQUALS(3.5f-2.17f , bestCaseEstimate(1, task2));
      TS_ASSERT_EQUALS(4.17f-(1.83f*2) , bestCaseEstimate(2, task1));

      free(task1);
      free(task2);
      free(task3);
    }

    void test_worstCaseEstimateFunction(void)
    {
      processTask(task1);
      processTask(task2);
      TS_ASSERT_EQUALS(4.17f+1.83f , worstCaseEstimate(1, task1));
      TS_ASSERT_EQUALS(3.5f+2.17f , worstCaseEstimate(1, task2));
      TS_ASSERT_EQUALS(4.17f+(1.83f*2) , worstCaseEstimate(2, task1));

      free(task1);
      free(task2);
      free(task3);
    }

    void test_processTaskFunction(void)
    {
      TS_ASSERT(task1->expected == 0);
      TS_ASSERT(task1->standardDeviation == 0);
      TS_ASSERT(task1->bestCaseEstimate == 0);
      TS_ASSERT(task1->worstCaseEstimate == 0);
      processTask(task1);
      TS_ASSERT(task1->expected != 0);
      TS_ASSERT(task1->standardDeviation != 0);
      TS_ASSERT(task1->bestCaseEstimate != 0);
      TS_ASSERT(task1->worstCaseEstimate != 0);

      free(task1);
      free(task2);
      free(task3);
    }

    void test_processTaskListFunction(void)
    {
      testList = newTaskList();
      addMultipleTasksToList(testList, 3, task1, task2, task3);
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
        TS_ASSERT_EQUALS(calculatedStdDevValue, testList->current->item->standardDeviation);
        TS_ASSERT_EQUALS(calculatedBestCaseValue, testList->current->item->bestCaseEstimate);
        TS_ASSERT_EQUALS(calculatedWorstCaseValue, testList->current->item->worstCaseEstimate);
        testList->current = testList->current->nextItem;
      }
      freeTaskList(testList);
    }

    void test_newTask()
    {
      struct Task *taskA = newTask();
      struct Task *taskB = newTask(1.0f, 2.0f, 3.0f, 4);

      TS_ASSERT(taskA != NULL);
      TS_ASSERT(taskA->estimated == 0);
      TS_ASSERT(taskA->expected == 0);

      TS_ASSERT(taskB != NULL);
      TS_ASSERT(taskB->estimated == 2.0f);
      TS_ASSERT(taskB->expected == 0); //Not yet been calculated so should be 0.
      TS_ASSERT(taskB->weight == 4);

      free(taskA);
      free(taskB);

      free(task1);
      free(task2);
      free(task3);
    }

    void test_newListItem()
    {
      //TODO
      struct ListItem *currentListItem = newListItem();

      TS_ASSERT(currentListItem != NULL);

      free(currentListItem);
      free(task1);
      free(task2);
      free(task3);
    }

    void test_newTaskList()
    {
      //TODO
      testList = newTaskList();

      TS_ASSERT(testList != NULL);

      freeTaskList(testList);
      /*free(task1);
      free(task2);
      free(task3);*/
    }

    void test_addNewTaskToList(void)
    {
      testList = newTaskList();

      TS_ASSERT(testList->head == NULL);
      addTaskToTaskList(testList, task1);
      TS_ASSERT(testList->head != NULL);

      freeTaskList(testList);
      /*free(task1);
      free(task2);
      free(task3);*/
    }

    void test_addMultipleTasksToList(void)
    {
      testList = newTaskList();


      addMultipleTasksToList(testList, 2, task1, task2);

      TS_ASSERT_EQUALS(testList->head->item, task1);
      TS_ASSERT_EQUALS(testList->head->nextItem->item, task2);

      freeTaskList(testList);
      /*free(task1);
      free(task2);
      free(task3);*/
    }

    void test_calculateExpectedForFullTaskList(void)
    {
      testList = newTaskList();
      addMultipleTasksToList(testList, 3, task1, task2, task3);
      processTaskList(testList);

      float testExpectedValue = (task1->expected + task2->expected + task3->expected);

      TS_ASSERT_EQUALS(testExpectedValue, testList->expectedForTaskList);

      freeTaskList(testList);
    }

    void test_calculateStdDevForFullTaskList(void)
    {
      testList = newTaskList();
      addMultipleTasksToList(testList, 3, task1, task2, task3);
      processTaskList(testList);
      //printf("\nstd1 = %f\tstd2 = %f\tstd3 = %f\n", task1->standardDeviation, task2->standardDeviation, task3->standardDeviation);
      //Sqrt of the sum of squares of StdDevs
      float testStdDevValue = roundf(3.3773*100)/100;

      TS_ASSERT_EQUALS(testStdDevValue, testList->stdDevForTaskList);
      freeTaskList(testList);
    }

};
