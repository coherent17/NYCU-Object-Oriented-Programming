CC = g++
CFLAGS = -g -Wall
OBJS = Circle.o Shape.o Rect.o Square.o Triangle.o
BINS = ex2

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): main.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm $(BINS) $(OBJS)
