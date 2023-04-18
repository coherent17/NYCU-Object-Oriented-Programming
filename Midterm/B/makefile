CC = g++
CXXFLAGS = -g -Wall
BIN = B-1 B-2

all: $(BIN)

%: %.cpp
	$(CC) $(CXXFLAGS) Pair.cpp Container.cpp $< -o $@

clean:
	rm $(BIN)