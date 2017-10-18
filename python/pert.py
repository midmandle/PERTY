def expectedDuration(estimate, pessimistic, optimistic):
    expected = 0.0
    expected = (optimistic + (4 * estimate) + pessimistic) / 6.0
    expected = round(expected, 2)
    return expected

def standardDeviation(estimate, pessimistic, optimistic):
    stdDeviation = 0.0
    stdDeviation = (pessimistic - optimistic) / 6.0
    stdDeviation = round(stdDeviation, 2)
    return stdDeviation

def bestCaseEstimate(expectedDuration, standardDeviation, multiplier):
    return expectedDuration - (multiplier * standardDeviation)

def worstCaseEstimate(expectedDuration, standardDeviation, multiplier):
    return expectedDuration + (multiplier * standardDeviation)

def priorityCalculation(weight, time):
    return weight/time

def taskPriorityCalculation(weight, bestCase, expected, worstCase)
    priorityBest = priorityCalculation(weight, bestCase)
    priorityExpected = priorityCalculation(weight, expected)
    priorityWorst = priorityCalculation(weight, worstCase)
