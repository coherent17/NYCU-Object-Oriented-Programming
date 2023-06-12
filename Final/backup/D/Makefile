CC = g++
CFLAGS = -Wall
RM = rm -rf

SRC_D-1 = D-1.cpp AbstractContainer.hpp List.hpp Node.h
SRC_D-2 = D-2.cpp AbstractContainer.hpp Vector.hpp
SRC_D-3 = D-3.cpp AbstractContainer.hpp List.hpp Node.h Vector.hpp MySTL.hpp

EXE = D-1 D-2 D-3

all: $(EXE)

D-1: $(SRC_D-1)
	$(CC) $(CFLAGS) $< -o $@

D-2: $(SRC_D-2)
	$(CC) $(CFLAGS) $< -o $@

D-3: $(SRC_D-3)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	$(RM) $(EXE)