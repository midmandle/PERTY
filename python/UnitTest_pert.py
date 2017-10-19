import unittest
from task import Task

class pertEquationTests(unittest.TestCase):

    def setUp(self):
        self.estimate = 3.0
        self.optimistic = 1.0
        self.pessimistic = 12.0

        self.taskA = Task(self.optimistic, self.estimate, self.pessimistic, 3)

    def tearDown(self):
        self.estimate = 0
        self.optimistic = 0
        self.pessimistic = 0
        self.taskA = None

    def test_expectedDurationCalculation(self):
        self.assertEqual(4.17, self.taskA.expected)

    def test_standardDeviationCalculation(self):
        self.assertEqual(1.83, self.taskA.stdDev)

    def test_bestCaseEstimate(self):
        bestCaseEstimate_value = self.taskA.expected - (self.taskA.multiplier * self.taskA.stdDev)
        self.assertEqual(bestCaseEstimate_value, self.taskA.bestCase)

    def test_worstCaseEstimate(self):
        worstCaseEstimate_value = self.taskA.expected + (self.taskA.multiplier * self.taskA.stdDev)
        self.assertEqual(worstCaseEstimate_value, self.taskA.worstCase)

    def test_priorityCalculation(self):
        bestCasePriority = self.taskA.weight/self.taskA.bestCase
        self.assertEqual(bestCasePriority, self.taskA.priorityBest)

        expectedDurationPriority = self.taskA.weight/self.taskA.expected
        self.assertEqual(expectedDurationPriority, self.taskA.priorityExpected)

        worstCasePriority = self.taskA.weight/self.taskA.worstCase
        self.assertEqual(worstCasePriority, self.taskA.priorityWorst)
