CC = g++
CFLAGS = -g -Wall
BINS = B

all: $(BINS)

$(BINS): B.cpp
	$(CC) $(CFLAGS) $^ Complex.h Queue.h -o $@


clean:
	rm $(BINS) $(OBJS)
