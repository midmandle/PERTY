import unittest
from task import Task
from tasklist import TaskList

class taskListOperationTests(unittest.TestCase):
    def test_addTaskToTaskList(self):
        estimate = 3.0
        optimistic = 1.0
        pessimistic = 12.0

        taskA = Task(optimistic, estimate, pessimistic, 3)
        taskB = Task(1.0, 1.5, 14.0, 4)

        taskList = TaskList();
        self.assertEqual(taskList.taskCount, 0) #Originally no items.
        taskList.addTask(taskA)
        taskList.addTask(taskB)
        self.assertEqual(taskList.taskCount, 2) #Now two should exist.

    def test_removeTaskFromTaskList(self):
        estimate = 3.0
        optimistic = 1.0
        pessimistic = 12.0

        taskA = Task(optimistic, estimate, pessimistic, 3)
        taskB = Task(1.0, 1.5, 14.0, 4)

        taskList = TaskList();
        self.assertEqual(taskList.taskCount, 0) #Originally no items.
        taskList.addTask(taskA)
        taskList.addTask(taskB)
        self.assertEqual(taskList.taskCount, 2) #Now two should exist.

        taskList.removeTask(taskA)
        self.assertEqual(taskList.taskCount, 1)
        taskList.removeTask(taskB)
        self.assertEqual(taskList.taskCount, 0)
    '''
    def test_sortTaskList(self):
        print("TODO")

    def test_calculateTaskListExpected(self):
        print("TODO")

    def test_calculateTaskListWorstCase(self):
        print("TODO")

    def test_calculateTaskListBestCase(self):
        print("TODO")

    def test_calculateStandardDeviation(self):
        print("TODO")
    '''
