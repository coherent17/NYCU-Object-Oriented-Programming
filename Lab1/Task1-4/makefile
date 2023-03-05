CC = g++
CXXFLAGS = -g -Wall
BIN = lab1-4-1 lab1-4-2

all: $(BIN)

%:%.cpp
	$(CC) $(CXXFLAGS)  $< -o $@

clean:
	rm -rf $(BIN)