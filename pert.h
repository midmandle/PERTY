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

  float priority;
  float weight;
};

struct ListItem {
  struct Task *item;
  struct ListItem *nextItem;
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

void processTaskList(struct TaskList *taskList);
void calculateExpectedForTaskList(struct TaskList *taskList);
void calculateStdDevForTaskList(struct TaskList *taskList);

struct TaskList *newTaskList();

struct ListItem *newListItem();
struct Task *newTask();
struct Task *newTask(float optimistic, float estimated, float pesimistic, float weight); //OVERLOAD

int freeTaskList(struct TaskList *taskListToFree);
void addTaskToTaskList(struct TaskList *taskList, struct Task *task);
void addMultipleTasksToList(struct TaskList *taskList, int count, ...);
