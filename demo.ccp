#include "PriorityQ.h"
#include <iostream>

using namespace myNamespace;
using namespace std;

int main() {
    cout << "PriorityQueue Demo" << endl;
    cout << "==================" << endl << endl;

    PriorityQueue pq;
    cout << "Created a new priority queue: " << pq.ToString() << endl;

    cout << "\n1. Adding elements with different priorities:" << endl;
    pq.push(100, 3);  // Value 100 with priority 3
    pq.push(200, 5);  // Value 200 with priority 5
    pq.push(300, 1);  // Value 300 with priority 1
    cout << "Queue after adding elements: " << pq.ToString() << endl;
    cout << "Top element: " << pq.top() << " with weight: " << pq.topWeight() << endl;

    cout << "\n2. Using operator overloads:" << endl;
    pq += make_pair(400, 7);  // Using += to add element
    cout << "After adding 400 with weight 7: " << pq.ToString() << endl;
    
    cout << "Position of value 200: " << pq[200] << endl;
    cout << "Position of value 999 (not in queue): " << pq[999] << endl;
    
    pq << make_pair(250, 5);  // Change value with weight 5 from 200 to 250
    cout << "After updating value with weight 5: " << pq.ToString() << endl;

    cout << "\n3. Creating a copy using copy constructor:" << endl;
    PriorityQueue pq2(pq);
    cout << "Original: " << pq.ToString() << endl;
    cout << "Copy: " << pq2.ToString() << endl;

    cout << "\n4. Using assignment operator:" << endl;
    PriorityQueue pq3;
    pq3.push(500, 2);
    pq3.push(600, 4);
    cout << "Queue 3 before assignment: " << pq3.ToString() << endl;
    
    pq3 = pq;
    cout << "Queue 3 after assignment: " << pq3.ToString() << endl;

    cout << "\n5. Comparing queues:" << endl;
    cout << "pq1 == pq2: " << (pq == pq2 ? "true" : "false") << endl;
    cout << "pq1 == pq3: " << (pq == pq3 ? "true" : "false") << endl;
    
    pq2.pop();
    cout << "After popping from pq2: " << pq2.ToString() << endl;
    cout << "pq1 == pq2: " << (pq == pq2 ? "true" : "false") << endl;
    cout << "pq1 > pq2: " << (pq > pq2 ? "true" : "false") << endl;

    cout << "\n6. Popping elements from the queue:" << endl;
    cout << "Original queue: " << pq.ToString() << endl;
    
    cout << "Popping: " << pq.top() << endl;
    pq.pop();
    cout << "Queue: " << pq.ToString() << endl;
    
    cout << "Popping: " << pq.top() << endl;
    pq.pop();
    cout << "Queue: " << pq.ToString() << endl;
    
    cout << "Popping: " << pq.top() << endl;
    pq.pop();
    cout << "Queue: " << pq.ToString() << endl;
    
    cout << "Popping: " << pq.top() << endl;
    pq.pop();
    cout << "Queue: " << pq.ToString() << endl;

    cout << "\n7. Using ! operator to clear the queue:" << endl;
    cout << "Queue 2 before clearing: " << pq2.ToString() << endl;
    !pq2;
    cout << "Queue 2 after clearing: " << pq2.ToString() << endl;

    cout << "\n8. Working with an array of queues:" << endl;
    PriorityQueue queues[3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            queues[i].push(i * 10 + j, 3 - j);
        }
        cout << "Queue " << i << ": " << queues[i].ToString() << endl;
    }

    return 0;
}