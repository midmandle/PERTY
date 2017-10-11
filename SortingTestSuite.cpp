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

bool suite_SortingTestSuite_init = false;
#include "SortingTestSuite.h"

static SortingTestSuite suite_SortingTestSuite;

static CxxTest::List Tests_SortingTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SortingTestSuite( "SortingTestSuite.h", 5, "SortingTestSuite", suite_SortingTestSuite, Tests_SortingTestSuite );

static class TestDescription_suite_SortingTestSuite_test_compareIntArrays : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SortingTestSuite_test_compareIntArrays() : CxxTest::RealTestDescription( Tests_SortingTestSuite, suiteDescription_SortingTestSuite, 9, "test_compareIntArrays" ) {}
 void runTest() { suite_SortingTestSuite.test_compareIntArrays(); }
} testDescription_suite_SortingTestSuite_test_compareIntArrays;

static class TestDescription_suite_SortingTestSuite_test_bubbleSort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SortingTestSuite_test_bubbleSort() : CxxTest::RealTestDescription( Tests_SortingTestSuite, suiteDescription_SortingTestSuite, 20, "test_bubbleSort" ) {}
 void runTest() { suite_SortingTestSuite.test_bubbleSort(); }
} testDescription_suite_SortingTestSuite_test_bubbleSort;

static class TestDescription_suite_SortingTestSuite_test_insertionSort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SortingTestSuite_test_insertionSort() : CxxTest::RealTestDescription( Tests_SortingTestSuite, suiteDescription_SortingTestSuite, 30, "test_insertionSort" ) {}
 void runTest() { suite_SortingTestSuite.test_insertionSort(); }
} testDescription_suite_SortingTestSuite_test_insertionSort;

static class TestDescription_suite_SortingTestSuite_test_quickSort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SortingTestSuite_test_quickSort() : CxxTest::RealTestDescription( Tests_SortingTestSuite, suiteDescription_SortingTestSuite, 37, "test_quickSort" ) {}
 void runTest() { suite_SortingTestSuite.test_quickSort(); }
} testDescription_suite_SortingTestSuite_test_quickSort;

