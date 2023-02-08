CC = g++
CXXFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = p3

all: $(BIN)

p3: p3.cpp
	$(CC) $(CXXFLAGS) $< -o $@

do1:
	./p3 testcase/1.in

do2:
	./p3 testcase/2.in
	
do3:
	./p3 testcase/3.in

do4:
	./p3 testcase/4.in

check:
	$(CHECKCC) $(CHECKFLAGS) ./p3 testcase/1.in testcase/1.out


clean:
	rm p3  testcase/*.out