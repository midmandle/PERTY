##THIS IS THE UNIT TEST DRIVER PROGRAM. ADD ALL YOUR TEST CLASSES HERE TO BE TESTED

import unittest
from UnitTest_pert import pertEquationTests
from UnitTest_tasklist import taskListOperationTests
from UnitTest_faasFunctions import faasFunctionsTests
from UnitTest_workflow import workflowOperationTests
from UnitTest_mongoDB import mongoDBOperationTests

suiteList = []
suiteList.append(unittest.TestLoader().loadTestsFromTestCase(pertEquationTests))
suiteList.append(unittest.TestLoader().loadTestsFromTestCase(taskListOperationTests))
suiteList.append(unittest.TestLoader().loadTestsFromTestCase(faasFunctionsTests))
suiteList.append(unittest.TestLoader().loadTestsFromTestCase(workflowOperationTests))
suiteList.append(unittest.TestLoader().loadTestsFromTestCase(mongoDBOperationTests))

combinedSuite = unittest.TestSuite(suiteList)
unittest.TextTestRunner(verbosity=0).run(combinedSuite)
