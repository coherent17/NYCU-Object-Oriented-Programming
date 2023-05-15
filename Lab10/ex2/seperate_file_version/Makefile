CC = g++
CFLAGS = -g -Wall
OBJS = Point2D.o Vector.o
BINS = ex10-2

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): ex10-2.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm $(BINS) $(OBJS)
