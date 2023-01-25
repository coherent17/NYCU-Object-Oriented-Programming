CC = g++
CXXFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = p1

all: $(BIN)

p1: p1.cpp
	$(CC) $(CXXFLAGS) $< -o $@

do1:
	./p1 testcase/1.in testcase/1.out

do2:
	./p1 testcase/2.in testcase/2.out

do3:
	./p1 testcase/3.in testcase/3.out

do4:
	./p1 testcase/4.in testcase/4.out

check:
	$(CHECKCC) $(CHECKFLAGS) ./p1 1.in 1.out


clean:
	rm p1  *.out