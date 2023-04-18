CC = g++
CXXFLAGS = -g -Wall
BIN = C-1

all: $(BIN)

%: %.cpp
	$(CC) $(CXXFLAGS) HashTable-1.cpp $< -o $@

clean:
	rm $(BIN)