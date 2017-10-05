/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_PertyTestSuite_init = false;
#include "PertyTestSuite.h"

static PertyTestSuite suite_PertyTestSuite;

static CxxTest::List Tests_PertyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_PertyTestSuite( "PertyTestSuite.h", 5, "PertyTestSuite", suite_PertyTestSuite, Tests_PertyTestSuite );

static class TestDescription_suite_PertyTestSuite_test_PERTExpectedDurationFunction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_PERTExpectedDurationFunction() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 50, "test_PERTExpectedDurationFunction" ) {}
 void runTest() { suite_PertyTestSuite.test_PERTExpectedDurationFunction(); }
} testDescription_suite_PertyTestSuite_test_PERTExpectedDurationFunction;

static class TestDescription_suite_PertyTestSuite_test_PERTStdDeviationFunction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_PERTStdDeviationFunction() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 56, "test_PERTStdDeviationFunction" ) {}
 void runTest() { suite_PertyTestSuite.test_PERTStdDeviationFunction(); }
} testDescription_suite_PertyTestSuite_test_PERTStdDeviationFunction;

static class TestDescription_suite_PertyTestSuite_test_bestCaseEstimateFunction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_bestCaseEstimateFunction() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 62, "test_bestCaseEstimateFunction" ) {}
 void runTest() { suite_PertyTestSuite.test_bestCaseEstimateFunction(); }
} testDescription_suite_PertyTestSuite_test_bestCaseEstimateFunction;

static class TestDescription_suite_PertyTestSuite_test_worstCaseEstimateFunction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_worstCaseEstimateFunction() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 69, "test_worstCaseEstimateFunction" ) {}
 void runTest() { suite_PertyTestSuite.test_worstCaseEstimateFunction(); }
} testDescription_suite_PertyTestSuite_test_worstCaseEstimateFunction;

static class TestDescription_suite_PertyTestSuite_test_processTaskListFunction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_processTaskListFunction() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 76, "test_processTaskListFunction" ) {}
 void runTest() { suite_PertyTestSuite.test_processTaskListFunction(); }
} testDescription_suite_PertyTestSuite_test_processTaskListFunction;

static class TestDescription_suite_PertyTestSuite_test_addNewTaskToList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_addNewTaskToList() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 100, "test_addNewTaskToList" ) {}
 void runTest() { suite_PertyTestSuite.test_addNewTaskToList(); }
} testDescription_suite_PertyTestSuite_test_addNewTaskToList;

static class TestDescription_suite_PertyTestSuite_test_addMultipleTasksToList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_addMultipleTasksToList() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 123, "test_addMultipleTasksToList" ) {}
 void runTest() { suite_PertyTestSuite.test_addMultipleTasksToList(); }
} testDescription_suite_PertyTestSuite_test_addMultipleTasksToList;

static class TestDescription_suite_PertyTestSuite_test_freeTaskList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_freeTaskList() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 132, "test_freeTaskList" ) {}
 void runTest() { suite_PertyTestSuite.test_freeTaskList(); }
} testDescription_suite_PertyTestSuite_test_freeTaskList;

static class TestDescription_suite_PertyTestSuite_test_calculateExpectedForFullTaskList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_calculateExpectedForFullTaskList() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 143, "test_calculateExpectedForFullTaskList" ) {}
 void runTest() { suite_PertyTestSuite.test_calculateExpectedForFullTaskList(); }
} testDescription_suite_PertyTestSuite_test_calculateExpectedForFullTaskList;

static class TestDescription_suite_PertyTestSuite_test_calculateStdDevForFullTaskList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertyTestSuite_test_calculateStdDevForFullTaskList() : CxxTest::RealTestDescription( Tests_PertyTestSuite, suiteDescription_PertyTestSuite, 156, "test_calculateStdDevForFullTaskList" ) {}
 void runTest() { suite_PertyTestSuite.test_calculateStdDevForFullTaskList(); }
} testDescription_suite_PertyTestSuite_test_calculateStdDevForFullTaskList;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
