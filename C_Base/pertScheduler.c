#include "pertScheduler.h"

struct Scheduler *newScheduler()
{
  struct Scheduler *scheduler = (Scheduler *) malloc(sizeof(struct Scheduler));
  scheduler->taskList = newTaskList();;

  return scheduler;
}

void destroyScheduler(struct Scheduler *scheduler)
{
  if(scheduler->taskList != NULL)
    freeTaskList(scheduler->taskList);
  free(scheduler);
}

void sortScheduledTasksByPriorityHighest(struct Scheduler *scheduler)
{

}
