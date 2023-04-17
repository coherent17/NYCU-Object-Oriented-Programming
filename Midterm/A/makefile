CC = g++
CXXFLAGS = -g -Wall
BIN = A-1 A-1-2 A-2 A-2-2 A-3 A-3-2

all: $(BIN)

%: %.cpp
	$(CC) $(CXXFLAGS) Matrix.cpp $< -o $@

clean:
	rm $(BIN)