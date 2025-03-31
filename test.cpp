#include "PriorityQ.h"
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace myNamespace;

void printTestResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

void testBasicOperations() {
    PriorityQueue pq;
    
    assert(pq.empty());
    assert(pq.size() == 0);
    printTestResult("Empty queue tests", true);
    
    pq.push(10, 5);
    assert(!pq.empty());
    assert(pq.size() == 1);
    assert(pq.top() == 10);
    assert(pq.topWeight() == 5);
    printTestResult("Push and top tests", true);
    
    pq.push(20, 8);
    assert(pq.size() == 2);
    assert(pq.top() == 20);
    assert(pq.topWeight() == 8);
    
    pq.push(30, 3);
    assert(pq.size() == 3);
    assert(pq.top() == 20);
    printTestResult("Priority ordering tests", true);
    
    pq.pop();
    assert(pq.size() == 2);
    assert(pq.top() == 10);
    pq.pop();
    assert(pq.size() == 1);
    assert(pq.top() == 30);
    pq.pop();
    assert(pq.empty());
    printTestResult("Pop tests", true);
    
    bool exceptionThrown = false;
    try {
        pq.top();
    } catch (const EmptyQueueException&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    
    exceptionThrown = false;
    try {
        pq.pop();
    } catch (const EmptyQueueException&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    printTestResult("Exception tests", true);
}

void testCopyConstructor() {
    PriorityQueue pq1;
    pq1.push(10, 5);
    pq1.push(20, 8);
    pq1.push(30, 3);
    
    PriorityQueue pq2(pq1);
    assert(pq2.size() == 3);
    assert(pq2.top() == 20);
    
    pq2.pop();
    assert(pq2.size() == 2);
    assert(pq2.top() == 10);
    assert(pq1.size() == 3);
    assert(pq1.top() == 20);
    
    printTestResult("Copy constructor tests", true);
}

void testClear() {
    PriorityQueue pq;
    pq.push(10, 5);
    pq.push(20, 8);
    
    pq.clear();
    assert(pq.empty());
    assert(pq.size() == 0);
    
    printTestResult("Clear tests", true);
}

void testOperators() {
    PriorityQueue pq;
    
    pq += std::make_pair(10, 5);
    assert(pq.size() == 1);
    assert(pq.top() == 10);
    
    pq -= 0;
    assert(pq.empty());
    
    pq.push(10, 5);
    pq.push(20, 8);
    
    !pq;
    assert(pq.empty());
    
    pq.push(10, 5);
    pq.push(20, 8);
    pq.push(30, 3);
    
    assert(pq[20] == 0);
    assert(pq[10] == 1);
    assert(pq[30] == 2);
    assert(pq[40] == -1);
    
    pq << std::make_pair(99, 8);
    assert(pq.top() == 99);
    
    printTestResult("Operator overload tests", true);
}


void testComparisonOperators() {
    PriorityQueue pq1;
    PriorityQueue pq2;
    
    assert(pq1 == pq2);
    assert(!(pq1 < pq2));
    assert(pq1 <= pq2);
    assert(pq1 >= pq2);
    
    pq1.push(10, 5);
    assert(!(pq1 == pq2));
    assert(!(pq1 < pq2));
    assert(!(pq1 <= pq2));
    assert(pq1 > pq2);
    assert(pq1 >= pq2);
    
    pq2.push(10, 5);
    assert(pq1 == pq2);
    
    pq1.push(20, 8);
    assert(!(pq1 < pq2));
    assert(!(pq1 <= pq2));
    assert(pq1 > pq2);
    assert(pq1 >= pq2);
    
    pq2.push(30, 8);
    assert(pq1 < pq2);
    assert(pq1 <= pq2);
    assert(!(pq1 > pq2));
    assert(!(pq1 >= pq2));
    
    printTestResult("Comparison operator tests", true);
}

void testMultipleObjects() {
    const int numQueues = 5;
    PriorityQueue queues[numQueues];
    
    for (int i = 0; i < numQueues; i++) {
        for (int j = 0; j < 3; j++) {
            queues[i].push(i * 10 + j, 5 - j);
        }
    }
    
    for (int i = 0; i < numQueues; i++) {
        assert(queues[i].size() == 3);
        assert(queues[i].top() == i * 10); // Highest priority value should be i*10
    }
    
    for (int i = 0; i < numQueues - 1; i++) {
        for (int j = 0; j < numQueues - i - 1; j++) {
            if (queues[j] > queues[j + 1]) {
                PriorityQueue temp = queues[j];
                queues[j] = queues[j + 1];
                queues[j + 1] = temp;
            }
        }
    }
    
    for (int i = 1; i < numQueues; i++) {
        assert(queues[i-1] <= queues[i]);
    }
    
    printTestResult("Multiple objects tests", true);
}

void testToString() {
    PriorityQueue pq;
    
    std::string emptyStr = pq.ToString();
    assert(emptyStr == "Empty Queue");
    
    pq.push(10, 5);
    pq.push(20, 8);
    pq.push(30, 3);
    
    std::string str = pq.ToString();
    assert(str.find("PriorityQueue:") != std::string::npos);
    assert(str.find("[20:8]") != std::string::npos);
    assert(str.find("[10:5]") != std::string::npos);
    assert(str.find("[30:3]") != std::string::npos);
    
    printTestResult("ToString tests", true);
}

void testEdgeCases() {
    PriorityQueue pq;
    
    pq.push(10, 5);
    pq.push(20, 5);
    pq.push(30, 5);
    
    assert(pq.top() == 10);
    pq.pop();
    assert(pq.top() == 20);
    pq.pop();
    assert(pq.top() == 30);
    
    bool updated = (pq << std::make_pair(99, 10)).size() > 0;
    assert(pq.top() == 30);
    
    pq.clear();
    const int numElements = 1000;
    for (int i = 0; i < numElements; i++) {
        pq.push(i, numElements - i);
    }
    
    assert(pq.size() == numElements);
    assert(pq.top() == 0);
    

    for (int i = 0; i < numElements; i++) {
        assert(pq.top() == i);
        pq.pop();
    }
    
    assert(pq.empty());
    
    printTestResult("Edge case tests", true);
}

int main() {
    std::cout << "Running PriorityQueue tests..." << std::endl;
    
    testBasicOperations();
    testCopyConstructor();
    testClear();
    testOperators();
    testComparisonOperators();
    testMultipleObjects();
    testToString();
    testEdgeCases();
    
    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}