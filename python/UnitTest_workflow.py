import unittest
from task import Task
from tasklist import TaskList
from workflow import Workflow

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

        self.taskList.removeTask(self.taskC)
        self.taskList.removeTask(self.taskD)
        self.taskList.removeTask(self.taskE)

        self.taskList = None

        self.taskC = None
        self.taskD = None
        self.taskE = None

        self.workflow = None

    def test_addTaskToWorkflow(self):
        self.assertNotIn(self.taskA, self.workflow.flowList)
        self.workflow.addTaskToWorkflow(self.taskA)
        self.assertIn(self.taskA, self.workflow.flowList)

    def test_removeTaskFromWorkflow(self):
        self.workflow.addItemToWorkflow(self.taskA)
        self.assertIn(self.taskA, self.workflow.flowList)
        self.workflow.removeTaskFromWorkflow(self.taskA)
        self.assertNotIn(self.taskA, self.workflow.flowList)

    def test_addTaskListToWorkflow(self):
        self.assertNotIn(self.taskList, self.workflow.flowList)
        self.workflow.addTaskListToWorkflow(self.taskList)
        self.assertIn(self.taskList, self.workflow.flowList)

    def test_removeTaskListFromWorkflow(self):
        self.workflow.addTaskListToWorkflow(self.taskList)
        self.assertIn(self.taskList, self.workflow.flowList)
        self.workflow.removeTaskListFromWorkflow(self.taskList)
        self.assertNotIn(self.taskList, self.workflow.flowList)

    def test_addItemToWorkflow(self):
        self.assertNotIn(self.taskA, self.workflow.flowList)
        self.workflow.addItemToWorkflow(self.taskA)
        self.assertIn(self.taskA, self.workflow.flowList)
        self.assertEqual(self.workflow.itemCount, 1)
        self.assertEqual(self.workflow.taskCount, 1)
        self.assertEqual(self.workflow.listCount, 0)

        self.assertNotIn(self.taskList, self.workflow.flowList)
        self.workflow.addItemToWorkflow(self.taskList)
        self.assertIn(self.taskList, self.workflow.flowList)
        self.assertEqual(self.workflow.itemCount, 4)
        self.assertEqual(self.workflow.taskCount, 1)
        self.assertEqual(self.workflow.listCount, 1)

    def test_removeItemFromWorkflow(self):
        self.workflow.addItemToWorkflow(self.taskA)
        self.assertIn(self.taskA, self.workflow.flowList)
        self.workflow.addItemToWorkflow(self.taskList)
        self.assertIn(self.taskList, self.workflow.flowList)
        self.assertEqual(self.workflow.itemCount, 4)
        self.assertEqual(self.workflow.taskCount, 1)
        self.assertEqual(self.workflow.listCount, 1)

        self.workflow.removeItemFromWorkflow(self.taskA)
        self.assertNotIn(self.taskA, self.workflow.flowList)
        self.assertEqual(self.workflow.itemCount, 3)
        self.assertEqual(self.workflow.taskCount, 0)
        self.assertEqual(self.workflow.listCount, 1)

        self.workflow.removeItemFromWorkflow(self.taskList)
        self.assertNotIn(self.taskList, self.workflow.flowList)
        self.assertEqual(self.workflow.itemCount, 0)
        self.assertEqual(self.workflow.taskCount, 0)
        self.assertEqual(self.workflow.listCount, 0)
