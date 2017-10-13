import pert
class Task:
    def __init__(self, optimistic, estimate, pessimistic, weight):
        self.optimistic = optimistic
        self.estimate = estimate
        self.pessimistic = pessimistic
        self.multiplier = 1

        self.expected = pert.expectedDuration(self.estimate, self.pessimistic, self.optimistic)
        self.stdDev = pert.standardDeviation(self.estimate, self.pessimistic, self.optimistic)
        self.bestCase = pert.bestCaseEstimate(self.expected, self.stdDev, self.multiplier)
        self.worstCase = pert.worstCaseEstimate(self.expected, self.stdDev, self.multiplier)

        self.weight = weight
        self.priorityBest = pert.priorityCalculation(self.weight, self.bestCase)
        self.priorityExpected = pert.priorityCalculation(self.weight, self.expected)
        self.priorityWorst = pert.priorityCalculation(self.weight, self.worstCase)
