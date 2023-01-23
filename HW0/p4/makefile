CC = g++
CXXFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = p4

all: $(BIN)

p4: p4.cpp
	$(CC) $(CXXFLAGS) $< -o $@

do1:
	./p4 testcase/1.in testcase/1.out

do2:
	./p4 testcase/2.in testcase/2.out

check:
	$(CHECKCC) $(CHECKFLAGS) ./p4 testcase/1.in testcase/1.out


clean:
	rm p4 testcase/*.out