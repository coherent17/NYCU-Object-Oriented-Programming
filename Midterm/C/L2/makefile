CC = g++
CXXFLAGS = -g -Wall
BIN = C-2

all: $(BIN)

%: %.cpp
	$(CC) $(CXXFLAGS) HashTable-2.cpp $< -o $@

clean:
	rm $(BIN)