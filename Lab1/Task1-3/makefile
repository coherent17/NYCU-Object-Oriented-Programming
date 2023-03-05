CC = g++
CXXFLAGS = -g -Wall
BIN = lab1-3-1 lab1-3-2 lab1-3-3

all: $(BIN)

%:%.cpp
	$(CC) $(CXXFLAGS)  $< -o $@

clean:
	rm -rf $(BIN)