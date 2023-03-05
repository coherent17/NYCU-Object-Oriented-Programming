CC = g++
CXXFLAGS = -g -Wall
BIN = main1 main2

all: $(BIN)

lab1-1.o: lab1-1.cpp lab1-1.h
	$(CC) $(CXXFLAGS) -c $< -o $@

main1:lab1-1.o
	$(CC) $(CXXFLAGS)  lab1-1-main1.cpp lab1-1.o -o $@

main2:lab1-1.o
	$(CC) $(CXXFLAGS)  lab1-1-main2.cpp lab1-1.o -o $@

clean:
	rm -rf lab1-1.o main1 main2