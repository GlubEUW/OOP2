#include "PriorityQ.h"
#include <iostream>

using namespace std;

int main() {
    PriorityQueue pq;

    cout << "Testing Priority Queue Implementation\n";
    cout << "-------------------------------------\n";

    // Test empty queue
    cout << "Empty queue test: " << (pq.empty() ? "PASS" : "FAIL") << endl;
    cout << "Size test (expected 0): " << pq.size() << endl;

    // Push elements
    cout << "\nPushing elements...\n";
    pq.push(10, 2);
    pq.push(30, 3);
    pq.push(20, 1);
    pq.push(40, 5);
    pq.push(50, 2);

    cout << "Empty queue test after pushing (expected false): " << (pq.empty() ? "true" : "false") << endl;
    cout << "Size test (expected 5): " << pq.size() << endl;

    // Test top element
    cout << "\nTop element test (expected 40): " << pq.top() << endl;
    cout << "Top weight test (expected 5): " << pq.topWeight() << endl;

    // Pop all elements and display
    cout << "\nPopping all elements in priority order:\n";
    cout << "Value\tWeight\n";
    cout << "-----\t------\n";

    while (!pq.empty()) {
        cout << pq.top() << "\t" << pq.topWeight() << endl;
        pq.pop();
    }

    // Test clear
    cout << "\nPushing more elements...\n";
    pq.push(60, 1);
    pq.push(70, 4);
    pq.push(80, 3);
    cout << "Size before clear: " << pq.size() << endl;

    pq.clear();
    cout << "Size after clear (expected 0): " << pq.size() << endl;
    cout << "Empty after clear (expected true): " << (pq.empty() ? "true" : "false") << endl;

    cout << "\nAll tests completed.\n";

    return 0;
}
