import unittest
from task import Task
from tasklist import TaskList

class workflowOperationTests(unittest.TestCase):
    def setUp(self):
        self.taskA = Task(1.0, 2.0, 3.0, 1)
        self.taskB = Task(2.0, 3.0, 4.0, 2)
        self.taskC = Task(3.0, 4.0, 5.0, 3)
        self.taskD = Task(4.0, 5.0, 6.0, 4)
        self.taskE = Task(5.0, 6.0, 7.0, 5)

        self.taskList = TaskList()
        self.taskList.addTask(self.taskC)
        self.taskList.addTask(self.taskD)
        self.taskList.addTask(self.taskE)

        self.workflow = Workflow()


    def tearDown(self):
        self.taskA = None
        self.taskB = None
        self.taskC = None
        self.taskD = None
        self.taskE = None

        self.taskList.removeTask(self.taskC)
        self.taskList.removeTask(self.taskD)
        self.taskList.removeTask(self.taskE)
        self.taskList = None

        self.workflow = None

    def test_addTaskToWorkflow(self):
        self.assertNotIn(taskA, self.workflow.flowList)
        self.workflow.addTaskToWorkflow(self.taskA)
        self.assertIn(taskA, self.workflow.flowList)


    def test_addTaskListToWorkflow(self):
        pass
