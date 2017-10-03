#include <math.h>

struct Task {
  float optimistic;
  float estimated;
  float pesimistic;
  float expected;
  float standardDeviation;
  float bestCaseEstimate;
  float worstCaseEstimate;
};

struct ListItem {
  struct Task *item;
  struct ListItem *nextItem;
};

struct TaskList {
  struct ListItem *head = NULL;
  struct ListItem *current = NULL;
};

float expectedDuration(struct Task *task);
float standardDeviation(struct Task *task);

float bestCaseEstimate(float multiplier, struct Task *task);
float worstCaseEstimate(float multiplier, struct Task *task);

void processTaskList(struct TaskList *taskList);

struct TaskList *newTaskList();
struct ListItem *newListItem();
struct Task *newTask();

int freeTaskList(struct TaskList *taskListToFree);
void addTaskToTaskList(struct TaskList *taskList, struct Task *task);
