#ifndef __PERT_H__
#define __PERT_H__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>

struct Task {
  float optimistic;
  float estimated;
  float pesimistic;
  float expected;
  float standardDeviation;
  float bestCaseEstimate;
  float worstCaseEstimate;

  float priorityBest;
  float priorityExpected;
  float priorityWorst;
  float weight;
};

struct ListItem {
  struct Task *item = NULL;
  struct ListItem *nextItem = NULL;
};

struct TaskList {
  struct ListItem *head = NULL;
  struct ListItem *current = NULL;

  float expectedForTaskList = 0.0f;
  float stdDevForTaskList = 0.0f;
};

float expectedDuration(struct Task *task);
float standardDeviation(struct Task *task);

float bestCaseEstimate(float multiplier, struct Task *task);
float worstCaseEstimate(float multiplier, struct Task *task);

void processTask(struct Task *task);
void processTaskList(struct TaskList *taskList);
void calculateExpectedForTaskList(struct TaskList *taskList);
void calculateStdDevForTaskList(struct TaskList *taskList);
float calculatePriority(float weight, float time);
void calculateTaskPriority(struct Task *task);

struct TaskList *newTaskList();

struct ListItem *newListItem();
struct Task *newTask();
struct Task *newTask(float optimistic, float estimated, float pesimistic, float weight); //OVERLOAD

int freeTaskList(struct TaskList *taskListToFree);
void addTaskToTaskList(struct TaskList *taskList, struct Task *task);
void addMultipleTasksToList(struct TaskList *taskList, int count, ...);

#endif
