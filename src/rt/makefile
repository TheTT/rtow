CXX = g++
CXXFLAGS = -Wall -Ofast -std=c++20 -flto -funroll-loops
TARGET = main.exe
SRCS = main.cpp vec3.hpp vec3io.hpp color.hpp ray.hpp camera.hpp tracer.hpp hittable.hpp sphere.hpp scene.hpp base.hpp interval.hpp common.hpp

all: $(TARGET)

$(TARGET): $(SRCS) makefile
	$(CXX) $(CXXFLAGS) main.cpp -o main

.PHONY: all clean
clean:
	rm -f $(TARGET)
