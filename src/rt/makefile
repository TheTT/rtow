CXX = g++
CXXFLAGS = -Wall -O2 -std=c++20
TARGET = main.exe
SRCS = main.cpp vec3.hpp point.hpp vec3io.hpp color.hpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o main

.PHONY: all clean
clean:
	rm -f $(TARGET)
