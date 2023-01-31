CC = g++
CXXFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = p2

all: $(BIN)

p2: p2.cpp
	$(CC) $(CXXFLAGS) $< -o $@

do1:
	./p2 example_testcase/1.set example_testcase/1.data example_testcase/1.rand1 example_testcase/1.rand2

do2:
	./p2 testcase/1.set testcase/1.data testcase/1.rand1 testcase/1.rand2

check:
	$(CHECKCC) $(CHECKFLAGS) ./p2 testcase/1.set testcase/1.data testcase/1.rand1 testcase/1.rand2


clean:
	rm p2