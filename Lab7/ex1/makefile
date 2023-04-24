CC = g++
CFLAGS = -g -Wall
OBJS = Stocks.o Fruits.o
BINS = ex1

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): main.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm $(BINS) $(OBJS)
