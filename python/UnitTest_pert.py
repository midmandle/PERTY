import unittest
from task import Task
from tasklist import TaskList

class pertEquationTests(unittest.TestCase):
    def test_expectedDurationCalculation(self):
        estimate = 3.0
        optimistic = 1.0
        pessimistic = 12.0

        taskA = Task(optimistic, estimate, pessimistic, 3)

        self.assertEqual(4.17, taskA.expected)

    def test_standardDeviationCalculation(self):
        estimate = 3.0
        optimistic = 1.0
        pessimistic = 12.0

        taskA = Task(optimistic, estimate, pessimistic, 3)

        self.assertEqual(1.83, taskA.stdDev)

    def test_bestCaseEstimate(self):
        estimate = 3.0
        optimistic = 1.0
        pessimistic = 12.0

        taskA = Task(optimistic, estimate, pessimistic, 3)

        bestCaseEstimate_value = taskA.expected - (taskA.multiplier * taskA.stdDev)

        self.assertEqual(bestCaseEstimate_value, taskA.bestCase)

    def test_worstCaseEstimate(self):
        estimate = 3.0
        optimistic = 1.0
        pessimistic = 12.0

        taskA = Task(optimistic, estimate, pessimistic, 3)

        worstCaseEstimate_value = taskA.expected + (taskA.multiplier * taskA.stdDev)

        self.assertEqual(worstCaseEstimate_value, taskA.worstCase)

    def test_priorityCalculation(self):
        estimate = 3.0
        optimistic = 1.0
        pessimistic = 12.0

        taskA = Task(optimistic, estimate, pessimistic, 3)

        bestCasePriority = taskA.weight/taskA.bestCase
        self.assertEqual(bestCasePriority, taskA.priorityBest)

        expectedDurationPriority = taskA.weight/taskA.expected
        self.assertEqual(expectedDurationPriority, taskA.priorityExpected)

        worstCasePriority = taskA.weight/taskA.worstCase
        self.assertEqual(worstCasePriority, taskA.priorityWorst)

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



if __name__ == '__main__':
    unittest.main()
