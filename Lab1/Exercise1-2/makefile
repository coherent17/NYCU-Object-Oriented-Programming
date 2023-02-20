CC = g++
CXXFLAGS = -g -Wall
OBJ = Array.o
BIN = ex1-2

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BIN): ex1-2.cpp $(OBJ)
	$(CC) $(CXXFLAGS)  $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)