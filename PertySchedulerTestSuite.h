#include <cxxtest/TestSuite.h>

#include "pertScheduler.h"
#include "sort.h"

class PertySchedulerTestSuite : public CxxTest::TestSuite
{
  public:

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

    void test_newScheduler()
    {
      struct Scheduler *scheduler1 = newScheduler();

      TS_ASSERT(scheduler1 != NULL);
      TS_ASSERT(scheduler1->taskList != NULL);

      destroyScheduler(scheduler1);
    }

    void test_destroyScheduler()
    {
      struct Scheduler *scheduler1 = newScheduler();

      TS_ASSERT(scheduler1 != NULL);

      destroyScheduler(scheduler1);
    }

    void test_sortScheduledTasksByPriorityHighest()
    {
      struct Scheduler *scheduler1 = newScheduler();

      struct Task *taskC = newTask(9,10,11,12);
      struct Task *taskA = newTask(1,2,3,4);
      struct Task *taskD = newTask(13,14,15,16);
      struct Task *taskB = newTask(5,6,7,8);

      addMultipleTasksToList(scheduler1->taskList, 3, taskC, taskA, taskD, taskB);

      processTaskList(scheduler1->taskList);

      //TODO simpleSort(scheduler1->taskList->head);
      sortScheduledTasksByPriorityHighest(scheduler1);

      scheduler1->taskList->current = scheduler1->taskList->head;
      while(scheduler1->taskList->current != NULL)
      {
        puts("DING");
        printf("%f\t%f\t%f\n", scheduler1->taskList->current->item->expected, scheduler1->taskList->current->item->weight, scheduler1->taskList->current->item->priorityExpected);

        if(scheduler1->taskList->current->nextItem != NULL)
          TS_ASSERT(scheduler1->taskList->current->item->priorityExpected >= scheduler1->taskList->current->nextItem->item->priorityExpected);

        scheduler1->taskList->current = scheduler1->taskList->current->nextItem;
      }

      helper_showListPointers(scheduler1->taskList);

      destroyScheduler(scheduler1);
    }
};
