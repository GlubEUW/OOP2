CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra

SRCS = PriorityQ.cpp PriorityQTest.cpp PriorityQDemo.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

TEST_BIN = PriorityQTest.exe
DEMO_BIN = PriorityQDemo.exe

TEST_LOG = test.txt
DEMO_LOG = demo.txt

all: $(TEST_BIN) $(DEMO_BIN)

%.o: %.cpp PriorityQ.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_BIN): PriorityQ.o PriorityQTest.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(DEMO_BIN): PriorityQ.o PriorityQDemo.o
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(TEST_BIN)
	./$(TEST_BIN) > $(TEST_LOG)

demo: $(DEMO_BIN)
	./$(DEMO_BIN) > $(DEMO_LOG)

run: test demo

clean:
	del /F /Q *.o $(TEST_BIN) $(DEMO_BIN) $(TEST_LOG) $(DEMO_LOG) 2>nul || rm -f *.o $(TEST_BIN) $(DEMO_BIN) $(TEST_LOG) $(DEMO_LOG)

.PHONY: all test demo run clean
