CC = g++
CFLAGS = -g -Wall
OBJS = Electronics.o TV.o Phone.o
BINS = ex9-1

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): ex9-1.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm $(BINS) $(OBJS)
