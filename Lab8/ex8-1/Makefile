CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 
OBJS = Personnel.o Teacher.o Student.o TA.o Course.o E3.o 
BINS = 8-1

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): ex8-1.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BINS) inputs/personals.csv inputs/courses.csv

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BINS) inputs/personals.csv inputs/courses.csv

clean:
	rm $(BINS) $(OBJS)
