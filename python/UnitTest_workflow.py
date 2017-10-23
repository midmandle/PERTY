import unittest
from task import Task
from tasklist import TaskList

class workflowOperationTests(unittest.TestCase):
    def setUp(self):
        self.workflow = Workflow()

        self.taskA = Task()
        self.taskB = Task()
        self.taskC = Task()
        self.taskD = Task()
        self.taskE = Task()

    def tearDown(self):
        self.taskA = None
        self.taskB = None
        self.taskC = None
        self.taskD = None
        self.taskE = None

        self.workflow = None

    def test_addTaskToWorkflow(self):

    def test_addTaskListToWorkflow(self):

    def test_addItemToWorkflow(self):
