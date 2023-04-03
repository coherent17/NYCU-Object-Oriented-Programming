CC = g++
CFLAGS = -g -Wall
OBJS = BST.o
BINS = hw1-1

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): hw1-1.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm $(BINS) $(OBJS)
