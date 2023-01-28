CC = g++
CXXFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = p3

all: $(BIN)

p3: p3.cpp
	$(CC) $(CXXFLAGS) $< -o $@

do:
	./p3 testcase/1.in

check:
	$(CHECKCC) $(CHECKFLAGS) ./p3 testcase/1.in testcase/1.out


clean:
	rm p3  testcase/*.out