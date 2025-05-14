CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = matrix
OBJS = main.o matrix.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp

clean:
	rm -f *.o $(TARGET)
