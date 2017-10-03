CC = g++ -ggdb

CXXTESTGEN = cxxtestgen

all: cxxtest cfiles main clean

cxxtest:
	$(CXXTESTGEN) --error-printer -o runner.cpp *.h

cfiles:
	$(CC) -c runner.cpp *.c

main:
	$(CC) -o runner *.o

clean:
	rm -f *.o
