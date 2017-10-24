import unittest
from task import Task
from tasklist import TaskList

class taskListOperationTests(unittest.TestCase):

    def setUp(self):
        self.estimate = 3.0
        self.optimistic = 1.0
        self.pessimistic = 12.0

        self.taskA = Task(self.optimistic, self.estimate, self.pessimistic, 3)
        self.taskB = Task(1.0, 1.5, 14.0, 4)

        self.taskList = TaskList();

    def tearDown(self):
        self.estimate = 0
        self.optimistic = 0
        self.pessimistic = 0

        self.taskA = None
        self.taskB = None
        self.taskList = None

    def test_addTaskToTaskList(self):
        self.assertEqual(self.taskList.taskCount, 0) #Originally no items.
        self.taskList.addTask(self.taskA)
        self.taskList.addTask(self.taskB)
        self.assertEqual(self.taskList.taskCount, 2) #Now two should exist.

    def test_removeTaskFromTaskList(self):
        self.assertEqual(self.taskList.taskCount, 0) #Originally no items.
        self.taskList.addTask(self.taskA)
        self.taskList.addTask(self.taskB)
        self.assertEqual(self.taskList.taskCount, 2) #Now two should exist.

        self.taskList.removeTask(self.taskA)
        self.assertEqual(self.taskList.taskCount, 1)
        self.taskList.removeTask(self.taskB)
        self.assertEqual(self.taskList.taskCount, 0)

    def test_sortTaskList(self):
        #self.assertEqual(self.taskList.taskCount, 0)
        self.taskList.addTask(self.taskA)
        self.taskList.addTask(self.taskB)
        self.taskList.addTask(Task(1.0, 2.0, 15.0, 5))
        self.assertEqual(self.taskList.taskCount, 3)

        self.taskList.sortTaskList(self.taskList, optimistic, ascend)
        self.taskList.assertGreater(self.taskList.listOfTasks[1].optimistic, self.taskList.listOfTasks[0].optimistic)

        self.taskList.sortTaskList(self.taskList, pessimistic, descend)
        self.taskList.assertLess(self.taskList.listOfTasks[1].pessimistic, self.taskList.listOfTasks[0].pessimistic)


    '''

    def test_calculateTaskListExpected(self):
        print("TODO")

    def test_calculateTaskListWorstCase(self):
        print("TODO")

    def test_calculateTaskListBestCase(self):
        print("TODO")

    def test_calculateTaskListStandardDeviation(self):
        print("TODO")
    '''
