CXX = g++
CXXFLAGS = -Wall -Ofast -std=c++20 -flto -funroll-loops
TARGET = main.exe
SRCS = *.cpp

all: $(TARGET)

$(TARGET): $(SRCS) makefile
	$(CXX) $(CXXFLAGS) $(SRCS) -o main

.PHONY: all clean
clean:
	rm -f $(TARGET)
