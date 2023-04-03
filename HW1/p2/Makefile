CC = g++
CFLAGS = -g -Wall
OBJS = stock.o
BINS = hw1-2

CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): hw1-2.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BINS)

clean:
	rm $(BINS) $(OBJS)
