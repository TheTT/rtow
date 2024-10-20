CXX = g++
CXXFLAGS = -Wall -Ofast -std=c++20 -flto -funroll-loops
TARGET = main.exe

SRCS = camera.cpp color.cpp common.cpp hittable.cpp interval.cpp main.cpp material.cpp ray.cpp scene.cpp sphere.cpp tracer.cpp vec3.cpp vec3io.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) makefile

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp makefile
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: all clean
clean:
	rm -f $(TARGET) *.o
