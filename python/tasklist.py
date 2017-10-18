class TaskList:
    def __init__(self):
        self.taskCount = 0
        self.listOfTasks = list()

    def addTask(self, taskToAdd):
        self.listOfTasks.append(taskToAdd)
        self.taskCount += 1

    def removeTask(self, taskToRemove):
        self.listOfTasks.remove(taskToRemove)
        self.taskCount -= 1
