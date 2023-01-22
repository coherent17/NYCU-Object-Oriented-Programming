CC = g++
CXXFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = p4

all: $(BIN)

p4: p4.cpp
	$(CC) $(CXXFLAGS) $< -o $@

do1:
	./p4 testcase/1.in

do2:
	./p4 testcase/2.in

check:
	$(CHECKCC) $(CHECKFLAGS) ./p4 testcase/1.in


clean:
	rm p4