CC = g++
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 
OBJS = Spotify.o User.o Playlist.o Song.o
BINS = hw2_1

all: $(BINS)

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): main.cpp $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

do:
	./$(BINS) music.txt

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BINS) music.txt

clean:
	rm $(BINS) $(OBJS)