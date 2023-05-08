CC = g++
CFLAGS = -g -Wall
OBJS = Commodity.o Food.o Healthy.o
BINS = ex9-2

CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): main.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	$(CHECKCC) $(CHECKFLAGS) ./$(BINS) 1.txt

clean:
	rm $(BINS) $(OBJS)
