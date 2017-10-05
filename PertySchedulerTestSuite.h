#include <cxxtest/TestSuite.h>

#include "pertScheduler.h"

class PertySchedulerTestSuite : public CxxTest::TestSuite
{
  public:

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
      scheduler1->taskList = newTaskList();

      struct Task *taskI = newTask(1,2,3,4);
      struct Task *taskJ = newTask(5,6,7,8);

      addMultipleTasksToList(scheduler1->taskList, 2, taskI, taskJ);

      processTaskList(scheduler1->taskList);

      destroyScheduler(scheduler1);
    }
};
