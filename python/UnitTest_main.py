##THIS IS THE UNIT TEST DRIVER PROGRAM. ADD ALL YOUR TEST CLASSES HERE TO BE TESTED

import unittest
from UnitTest_pert import pertEquationTests
from UnitTest_tasklist import taskListOperationTests
from UnitTest_faasFunctions import faasFunctionsTests

suiteList = []
suiteList.append(unittest.TestLoader().loadTestsFromTestCase(pertEquationTests))
suiteList.append(unittest.TestLoader().loadTestsFromTestCase(taskListOperationTests))
suiteList.append(unittest.TestLoader().loadTestsFromTestCase(faasFunctionsTests))

combinedSuite = unittest.TestSuite(suiteList)
unittest.TextTestRunner(verbosity=0).run(combinedSuite)
