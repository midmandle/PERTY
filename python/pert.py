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
