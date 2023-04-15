CC = g++
CXXFLAGS = -g -Wall
BIN = C01 C02 C03

all: $(BIN)

C01:
	$(CC) $(CXXFLAGS) Seq.cpp main_C01.cpp -o $@

C02:
	$(CC) $(CXXFLAGS) Seq.cpp main_C02.cpp -o $@

C03:
	$(CC) $(CXXFLAGS) Seq.cpp main_C03.cpp -o $@

clean:
	rm $(BIN)
