CC = g++
CXXFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = p1

all: $(BIN)

p1: p1.cpp
	$(CC) $(CXXFLAGS) $< -o $@

do:
	./p1 testcase/1.in testcase/1.out

check:
	$(CHECKCC) $(CHECKFLAGS) ./p1 1.in 1.out


clean:
	rm p1  *.out