CXX = g++
CXXFLAGS = -Wall

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = ex6-1

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
