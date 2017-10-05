#include "pertScheduler.h"

struct Scheduler *newScheduler()
{
  struct Scheduler *scheduler = (Scheduler *) malloc(sizeof(struct Scheduler));
  scheduler->taskList = NULL;

  return scheduler;
}

void destroyScheduler(struct Scheduler *scheduler)
{
  free(scheduler);
}

void sortScheduledTasksByPriorityHighest(struct Scheduler *scheduler)
{

}
