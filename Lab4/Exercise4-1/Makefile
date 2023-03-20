CC = g++
CFLAGS = -g -Wall
OBJS = Grid.o MineSweeper.o
BINS = ex4-1


CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 


all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): ex4-1.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

debug:
	$(CHECKCC) $(CHECKFLAGS) ./ex4-1


clean:
	rm $(BINS) $(OBJS)