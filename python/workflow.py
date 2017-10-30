from task import Task
from tasklist import TaskList

class Workflow:
    def __init__(self):
        self.flowList = list()
        self.itemCount = 0
        self.taskCount = 0
        self.listCount = 0

    def addTaskToWorkflow(self, taskToAdd):
        self.flowList.append(taskToAdd)
        self.taskCount += 1
        self.itemCount += 1

    def removeTaskFromWorkflow(self, taskToRemove):
        self.flowList.remove(taskToRemove)
        self.taskCount -= 1
        self.itemCount -= 1

    def addTaskListToWorkflow(self, taskListToAdd):
        self.flowList.append(taskListToAdd)
        self.itemCount += len(taskListToAdd.listOfTasks)
        self.listCount += 1

    def removeTaskListFromWorkflow(self, taskListToRemove):
        self.flowList.remove(taskListToRemove)
        self.itemCount -= len(taskListToRemove.listOfTasks)
        self.listCount -= 1

    def addItemToWorkflow(self, itemToAdd):
        try:
            if(isinstance(itemToAdd, Task)):
                self.addTaskToWorkflow(itemToAdd)
            elif(isinstance(itemToAdd, TaskList)):
                self.addTaskListToWorkflow(itemToAdd)
            else:
                raise ValueError

        except ValueError:
            print "ERR: The item to add is not of type Task or TaskList"

    def removeItemFromWorkflow(self, itemToRemove):
        try:
            if(isinstance(itemToRemove, Task)):
                self.removeTaskFromWorkflow(itemToRemove)
            elif(isinstance(itemToRemove, TaskList)):
                self.removeTaskListFromWorkflow(itemToRemove)
            else:
                raise ValueError

        except:
            print "ERR: The item to remove is not of type Task or TaskList"
