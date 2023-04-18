CC = g++
CFLAGS = -g -Wall
OBJS = Factory.o Item.o Store.o
BINS = E

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): E.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm $(BINS) $(OBJS)
