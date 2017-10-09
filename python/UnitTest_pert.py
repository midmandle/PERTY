import unittest
import pert

class pertEquationTests(unittest.TestCase):
    def test_expectedDurationCalculation(self):
        estimate = 3.0
        optimistic = 1.0
        pessimistic = 12.0

        self.assertEqual(4.17, pert.expectedDuration(estimate, pessimistic, optimistic))

    def test_standardDeviationCalculation(self):
        estimate = 3.0
        optimistic = 1.0
        pessimistic = 12.0

        self.assertEqual(1.83, pert.standardDeviation(estimate, pessimistic, optimistic))

if __name__ == '__main__':
    unittest.main()
