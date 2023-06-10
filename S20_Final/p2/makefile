CC = g++
CXXFLAGS = -g -Wall
BIN = pg01 pg02

all: $(BIN)

pg01:
	$(CC) $(CXXFLAGS) Point2D.cpp Hash_table.cpp pb02Part1.cpp -o $@

pg02:
	$(CC) $(CXXFLAGS) Point2D.cpp Hash_table.cpp pb02Part2.cpp -o $@

do1:
	./pg01 pg02int.txt pg02string.txt pg02Point2D.txt

do2:
	./pg02 pg02int.txt pg02string.txt pg02Point2D.txt

clean:
	rm $(BIN)
