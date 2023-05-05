CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 
OBJS = Role.o Mage.o Warrior.o Vampire.o
BINS = hw2_2

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): main.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BINS)

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BINS)

clean:
	rm $(BINS) $(OBJS)