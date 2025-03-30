CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
RM = del /Q
EXE = test.exe

all: $(EXE)

$(EXE): test.o PriorityQ.o
	$(CXX) $(CXXFLAGS) -o $(EXE) test.o PriorityQ.o

test.o: test.cpp PriorityQ.h
	$(CXX) $(CXXFLAGS) -c test.cpp

PriorityQ.o: PriorityQ.cpp PriorityQ.h
	$(CXX) $(CXXFLAGS) -c PriorityQ.cpp

clean:
	$(RM) *.o $(EXE)

.PHONY: all clean
