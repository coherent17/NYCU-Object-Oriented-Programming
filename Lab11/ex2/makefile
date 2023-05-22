CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRCS = ex11_2.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = ex11_2

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

do1-1:
	./$(TARGET) D1.in catcatscatdooog

do1-2:
	./$(TARGET) D1.in catcatscatdogsdog

do2-1:
	./$(TARGET) D2.in IloveloveOOPandIlikeOPwenverymuch

do2-2:
	./$(TARGET) D2.in IloveloveOOPandIlikelikeOPwenverymuch

clean:
	rm -f $(OBJS) $(TARGET)
