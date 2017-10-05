#include <cxxtest/TestSuite.h>

#include "pert.h"

class PertyTestSuite : public CxxTest::TestSuite
{
  struct Task *task1;
  struct Task *task2;
  struct Task *task3;
  struct TaskList *testList;

  public:

    PertyTestSuite()
    {
      //This is in the wrong place. Needs removal.
      testList = newTaskList();

      task1 = newTask();
      task2 = newTask();
      task3 = newTask(1.0f,3.0f,12.0f,3);

      task1->optimistic = 1.0f;
      task1->estimated = 3.0f;
      task1->pesimistic = 12.0f;

      task2->optimistic = 1.0f;
      task2->estimated = 1.5f;
      task2->pesimistic = 14.0f;

      addTaskToTaskList(testList, task1);
      addTaskToTaskList(testList, task2);
      addTaskToTaskList(testList, task3);

      processTaskList(testList);
    }

    static PertyTestSuite* createSuite()
    {
      return new PertyTestSuite();
    }

    static void destroySuite(PertyTestSuite* suite)
    {
      freeTaskList(suite->testList);
      delete suite;
    }

    void setUp()
    {

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
    }

    void test_newListItem()
    {
      //TODO
      struct ListItem *currentListItem = newListItem();

      TS_ASSERT(currentListItem != NULL);

      free(currentListItem);
    }

    void test_newTaskList()
    {
      //TODO
      struct TaskList *currentTestList = newTaskList();

      TS_ASSERT(currentTestList != NULL);

      free(currentTestList);
    }

    void test_addNewTaskToList(void)
    {
      struct TaskList *currentTestList = newTaskList();
      struct Task *taskToAdd = newTask(1,2,3,4);

      TS_ASSERT(currentTestList->head == NULL);
      addTaskToTaskList(currentTestList, taskToAdd);
      TS_ASSERT(currentTestList->head != NULL);

      freeTaskList(currentTestList);
    }

    void test_addMultipleTasksToList(void)
    {
      struct TaskList *currentTestList = newTaskList();
      struct Task *taskToAddA = newTask(1,2,3,4);
      struct Task *taskToAddB = newTask(5,6,7,8);

      addMultipleTasksToList(currentTestList, 2, taskToAddA, taskToAddB);

      TS_ASSERT_EQUALS(testList->head->item, taskToAddA);
      TS_ASSERT_EQUALS(testList->head->nextItem->item, taskToAddB);

      freeTaskList(currentTestList);
    }

    void test_calculateExpectedForFullTaskList(void)
    {

      float testExpectedValue = 7.67f;

      TS_ASSERT_EQUALS(testExpectedValue, testList->expectedForTaskList);
    }

    void test_calculateStdDevForFullTaskList(void)
    {
      //Sqrt of the sum of squares of StdDevs
      float testStdDevValue = 2.84f;
      calculateStdDevForTaskList(testList);

      TS_ASSERT_EQUALS(testStdDevValue, testList->stdDevForTaskList);
    }

};
