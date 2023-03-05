CC = g++
CXXFLAGS = -g -Wall
BIN = lab1-5-1 lab1-5-2

all: $(BIN)

%:%.cpp
	$(CC) $(CXXFLAGS)  $< -o $@

clean:
	rm -rf $(BIN)