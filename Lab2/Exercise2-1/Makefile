CC = g++
CFLAGS = -g -Wall
OBJS = VM.o
BINS = Lab2

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): main.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./#(BINS)

clean:
	rm $(BINS) $(OBJS)