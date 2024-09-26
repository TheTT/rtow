CXX = g++
CXXFLAGS = -Wall -O2 -std=c++20
TARGET = main.exe
OBJS = output-to-ppm.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

output-to-ppm.o: output-to-ppm.cpp
	$(CXX) $(CXXFLAGS) -c output-to-ppm.cpp

.PHONY: all clean
clean:
	rm -f $(OBJS) $(TARGET)
