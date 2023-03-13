CC = g++
CFLAGS = -g -Wall -O3
OBJS = Class.o
BINS = ex3-2

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): ex3-2.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BINS) < stdin.in

clean:
	rm $(BINS) $(OBJS)