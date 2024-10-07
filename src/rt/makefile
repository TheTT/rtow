CXX = g++
CXXFLAGS = -Wall -O2 -std=c++20
TARGET = main.exe
SRCS = main.cpp vec3.hpp vec3io.hpp color.hpp ray.hpp camera.hpp tracer.hpp hittable.hpp sphere.hpp scene.hpp base.hpp interval.hpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) main.cpp -o main

.PHONY: all clean
clean:
	rm -f $(TARGET)
