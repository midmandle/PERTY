CC = g++ -ggdb

CXXTESTGEN = cxxtestgen

all: main clean

main: root
	$(CC) -o runner -I$CXXTEST runner.cpp PertyTestSuite.cpp PertySchedulerTestSuite.cpp SortingTestSuite.cpp pert.c pertScheduler.c sort.c

root: parts
	$(CXXTESTGEN) --root --error-printer -o runner.cpp

parts:
	$(CXXTESTGEN) --part --error-printer -o PertyTestSuite.cpp PertyTestSuite.h pert.h
	$(CXXTESTGEN) --part --error-printer -o PertySchedulerTestSuite.cpp PertySchedulerTestSuite.h pertScheduler.h
	$(CXXTESTGEN) --part --error-printer -o SortingTestSuite.cpp SortingTestSuite.h sort.h

clean:
	rm -f *.o
