

#include "pert.h"

struct ListItem *_freeTaskListRecurse(struct ListItem *headPointer);
int _freeListItem(struct ListItem *ListItemToFree);
int _freeTask(struct Task *taskToFree);

//################# PERT calculations #############################

float expectedDuration(struct Task *task)
{
  float expected = 0.0f;
  float optimistic = task->optimistic;
  float estimated = task->estimated;
  float pesimistic = task->pesimistic;

  expected = (optimistic + (4 * estimated) + pesimistic) / 6.0f;

  return roundf(expected*100)/100;
}

float standardDeviation(struct Task *task)
{
  float stdDeviation = 0.0f;
  float optimistic = task->optimistic;
  float estimated = task->estimated;
  float pesimistic = task->pesimistic;

  stdDeviation = (pesimistic - optimistic) / 6.0f;

  return roundf(stdDeviation*100)/100;
}

float bestCaseEstimate(float multiplier, struct Task *task)
{
  return task->expected - (multiplier * task->standardDeviation);
}

float worstCaseEstimate(float multiplier, struct Task *task)
{
  return task->expected + (multiplier * task->standardDeviation);
}

//Calculate PERT values for each Task in an array.
void  processTaskList(struct TaskList *taskList)
{
  taskList->current = taskList->head;
  while(taskList->current != NULL)
  {
    Task *taskToBeProcessed = taskList->current->item;
    taskList->current->item->expected = expectedDuration(taskToBeProcessed);
    taskList->current->item->standardDeviation = standardDeviation(taskToBeProcessed);
    taskList->current->item->bestCaseEstimate = bestCaseEstimate(1,taskToBeProcessed);
    taskList->current->item->worstCaseEstimate = worstCaseEstimate(1,taskToBeProcessed);
    taskList->current = taskList->current->nextItem;
  }
}

//Calculate combined expectedDuration for entire TaskList
float calculateExpectedForTaskList(struct TaskList *taskList)
{
  float combinedExpected = 0.0f;
  taskList->current = taskList->head;

  while(taskList->current != NULL)
  {
    combinedExpected += taskList->current->item->expected;
    taskList->current = taskList->current->nextItem;
  }

  return combinedExpected;
}

//Calculate combined standardDeviation for entire TaskList
float calculateStdDevForTaskList(struct TaskList *taskList)
{
  float combinedStdDev = 0.0f;
  taskList->current = taskList->head;

  while(taskList->current != NULL)
  {
    combinedStdDev += powf((taskList->current->item->standardDeviation),2);
    taskList->current = taskList->current->nextItem;
  }

  return roundf(sqrt(combinedStdDev) *100)/100;
}

//################# END OF PERT calculations #############################

//################# LINKED LIST IMPLEMENTATION ###########################

//Allocate new TaskList struct to heap and return pointer to space.
struct TaskList *newTaskList()
{
  struct TaskList *ptrToNewTaskList = (TaskList *) malloc(sizeof(struct TaskList));

  ptrToNewTaskList->head = NULL;
  ptrToNewTaskList->current = NULL;

  return ptrToNewTaskList;
}

//Allocate new ListItem struct to heap and return pointer to space.
struct ListItem *newListItem()
{
  struct ListItem *ptrToNewListItem = (ListItem *) malloc(sizeof(struct ListItem));

  ptrToNewListItem->item = NULL;
  ptrToNewListItem->nextItem = NULL;

  return ptrToNewListItem;
}

//Allocate new Task struct to heap and return pointer to space.
struct Task *newTask()
{
  struct Task *ptrToNewTask = (Task *) malloc(sizeof(struct Task));
  ptrToNewTask->optimistic = 0;
  ptrToNewTask->estimated = 0;
  ptrToNewTask->pesimistic = 0;
  ptrToNewTask->expected = 0;
  ptrToNewTask->standardDeviation = 0;
  ptrToNewTask->bestCaseEstimate = 0;
  ptrToNewTask->worstCaseEstimate = 0;

  return ptrToNewTask;
}

//OVERLOAD
struct Task *newTask(float optimistic, float estimated, float pesimistic)
{
  struct Task *ptrToNewTask = (Task *) malloc(sizeof(struct Task));
  ptrToNewTask->optimistic = optimistic;
  ptrToNewTask->estimated = estimated;
  ptrToNewTask->pesimistic = pesimistic;
  ptrToNewTask->expected = 0;
  ptrToNewTask->standardDeviation = 0;
  ptrToNewTask->bestCaseEstimate = 0;
  ptrToNewTask->worstCaseEstimate = 0;

  return ptrToNewTask;
}

int freeTaskList(struct TaskList *taskListToFree)
{
  _freeTaskListRecurse(taskListToFree->head);
  free(taskListToFree);
  return 0;
}

struct ListItem *_freeTaskListRecurse(struct ListItem *headPointer)
{
  if(headPointer->nextItem != NULL)
  {
    headPointer->nextItem = _freeTaskListRecurse(headPointer->nextItem);
  }

  _freeListItem(headPointer);
  return NULL;
}

int _freeListItem(struct ListItem *listItemToFree)
{
  _freeTask(listItemToFree->item);
  free(listItemToFree);
  return 0;

}

int _freeTask(struct Task *taskToFree)
{
  free(taskToFree);
  return 0;
}

void addTaskToTaskList(struct TaskList *taskList, struct Task *task)
{
  //Need to use malloc here to allocate to heap-space instead of current stack frame.
  struct ListItem *item = newListItem(); //newListItem used to implement heap allocation of struct.
  item->item = task;
  item->nextItem = NULL;

  //printf("ITEM: %x\n", item);//DEBUG

  // If list is empty and uninitialised set it up.
  if(taskList->head == NULL)
  {
    taskList->current = item;
    taskList->head = item;
  }
  else
  {
    taskList->current->nextItem = item;
    taskList->current = item;
  }
  //printf("\n\t%x %x %x %x\n", item, taskList->head, taskList->current, taskList->current->nextItem); //DEBUG
  return;
}

//Use <stdarg.h> to allow variable numbers of function arguments (variadic functions).
void addMultipleTasksToList(struct TaskList *taskList, int count, ...)
{
  va_list listOfTasks;
  int i = 0;

  va_start(listOfTasks, count);

  for(int i = 0; i < count; i++)
  {
    addTaskToTaskList(taskList, va_arg(listOfTasks, struct Task *));
  }

  va_end(listOfTasks);
}

//################# END OF LINKED LIST IMPLEMENTATION ###########################
