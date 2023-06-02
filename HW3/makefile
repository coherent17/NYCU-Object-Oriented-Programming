CC = g++
CXXFLAGS = -g -Wall
BIN = hw3-1 hw3-2
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 


all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $< -o $@

hw3-1: hw3-1.cpp Window.o View.o Button.o Label.o TextInput.o
	$(CC) $(CXXFLAGS) $^ -o $@

hw3-2: hw3-2.cpp Window.o View.o Button.o Label.o TextInput.o Calculator.o
	$(CC) $(CXXFLAGS) $^ -o $@

check1:
	$(CHECKCC) $(CHECKFLAGS) ./hw3-1

check2:
	$(CHECKCC) $(CHECKFLAGS) ./hw3-2

clean:
	rm $(BIN) *.o
