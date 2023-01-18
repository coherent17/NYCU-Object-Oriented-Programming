CC = g++
CXXFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s
BIN = p5

all: $(BIN)

p5: p5.cpp
	$(CC) $(CXXFLAGS) $< -o $@

do:
	./p5 testcase/1.txt

check:
	$(CHECKCC) $(CHECKFLAGS) ./p5 testcase/1.txt


clean:
	rm p5