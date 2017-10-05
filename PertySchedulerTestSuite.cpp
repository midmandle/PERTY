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

bool suite_PertySchedulerTestSuite_init = false;
#include "PertySchedulerTestSuite.h"

static PertySchedulerTestSuite suite_PertySchedulerTestSuite;

static CxxTest::List Tests_PertySchedulerTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_PertySchedulerTestSuite( "PertySchedulerTestSuite.h", 5, "PertySchedulerTestSuite", suite_PertySchedulerTestSuite, Tests_PertySchedulerTestSuite );

static class TestDescription_suite_PertySchedulerTestSuite_test_newScheduler : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertySchedulerTestSuite_test_newScheduler() : CxxTest::RealTestDescription( Tests_PertySchedulerTestSuite, suiteDescription_PertySchedulerTestSuite, 9, "test_newScheduler" ) {}
 void runTest() { suite_PertySchedulerTestSuite.test_newScheduler(); }
} testDescription_suite_PertySchedulerTestSuite_test_newScheduler;

static class TestDescription_suite_PertySchedulerTestSuite_test_destroyScheduler : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertySchedulerTestSuite_test_destroyScheduler() : CxxTest::RealTestDescription( Tests_PertySchedulerTestSuite, suiteDescription_PertySchedulerTestSuite, 19, "test_destroyScheduler" ) {}
 void runTest() { suite_PertySchedulerTestSuite.test_destroyScheduler(); }
} testDescription_suite_PertySchedulerTestSuite_test_destroyScheduler;

static class TestDescription_suite_PertySchedulerTestSuite_test_sortScheduledTasksByPriorityHighest : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PertySchedulerTestSuite_test_sortScheduledTasksByPriorityHighest() : CxxTest::RealTestDescription( Tests_PertySchedulerTestSuite, suiteDescription_PertySchedulerTestSuite, 28, "test_sortScheduledTasksByPriorityHighest" ) {}
 void runTest() { suite_PertySchedulerTestSuite.test_sortScheduledTasksByPriorityHighest(); }
} testDescription_suite_PertySchedulerTestSuite_test_sortScheduledTasksByPriorityHighest;

