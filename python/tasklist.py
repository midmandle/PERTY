class TaskList:
    def __init__(self):
        self.taskCount = 0
        self.listOfTasks = list()
        self.bestCase

    def addTask(self, taskToAdd):
        self.listOfTasks.append(taskToAdd)
        self.taskCount += 1

    def removeTask(self, taskToRemove):
        self.listOfTasks.remove(taskToRemove)
        self.taskCount -= 1

    def sortTaskList(self, taskListToSort, propertyToSort, ascendOrDescend):
        #self.listOfTasks = taskListToSort
