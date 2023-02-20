CC = g++
CXXFLAGS = -g -Wall
OBJ = Double.o
BIN = ex1-1

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BIN): ex1-1.cpp $(OBJ)
	$(CC) $(CXXFLAGS)  $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)