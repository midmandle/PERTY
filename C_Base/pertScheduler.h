#ifndef __PERTSCHED_H__
#define __PERTSCEHD_H__

#include <stdio.h>
#include <stdlib.h>
#include "pert.h"

struct Scheduler {
  struct TaskList *taskList;

};

struct Scheduler *newScheduler();
void destroyScheduler(struct Scheduler *scheduler);
void sortScheduledTasksByPriorityHighest(struct Scheduler *scheduler);
#endif
