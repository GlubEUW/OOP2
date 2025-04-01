#include "PriorityQ.h"
#include <iostream>

using namespace myNamespace;
using namespace std;

int main() {
    try{
        cout << "PriorityQueue Demo" << endl;
        cout << "==================" << endl << endl;

        PriorityQueue pq;
        cout << "Created a new priority queue: " << pq.toString() << endl;

        cout << "\n1. Adding elements with different priorities:" << endl;
        pq.push(100, 3);
        pq.push(200, 5);
        pq.push(300, 1);
        cout << "Queue after adding elements: " << pq.toString() << endl;
        cout << "Top element: " << pq.top() << " with weight: " << pq.topWeight() << endl;

        cout << "\n2. Using operator overloads:" << endl;
        pq += make_pair(400, 7);
        cout << "After adding 400 with weight 7: " << pq.toString() << endl;
    
        cout << "Position of value 200: " << pq[200] << endl;
        cout << "Position of value 999 (not in queue): " << pq[999] << endl;
    
        pq << make_pair(250, 5);
        cout << "After updating value with weight 5: " << pq.toString() << endl;

        cout << "\n3. Creating a copy using copy constructor:" << endl;
        PriorityQueue pq2(pq);
        cout << "Original: " << pq.toString() << endl;
        cout << "Copy: " << pq2.toString() << endl;

        cout << "\n4. Using assignment operator:" << endl;
        PriorityQueue pq3;
        pq3.push(500, 2);
        pq3.push(600, 4);
        cout << "Queue 3 before assignment: " << pq3.toString() << endl;
    
        pq3 = pq;
        cout << "Queue 3 after assignment: " << pq3.toString() << endl;

        cout << "\n5. Comparing queues:" << endl;
        cout << "pq1 == pq2: " << (pq == pq2 ? "true" : "false") << endl;
        cout << "pq1 == pq3: " << (pq == pq3 ? "true" : "false") << endl;
    
        pq2.pop();
        cout << "After popping from pq2: " << pq2.toString() << endl;
        cout << "pq1 == pq2: " << (pq == pq2 ? "true" : "false") << endl;
        cout << "pq1 > pq2: " << (pq > pq2 ? "true" : "false") << endl;

        cout << "\n6. Popping elements from the queue:" << endl;
        cout << "Original queue: " << pq.toString() << endl;
    
        cout << "Popping: " << pq.top() << endl;
        pq.pop();
        cout << "Queue: " << pq.toString() << endl;
    
        cout << "Popping: " << pq.top() << endl;
        pq.pop();
        cout << "Queue: " << pq.toString() << endl;
    
        cout << "Popping: " << pq.top() << endl;
        pq.pop();
        cout << "Queue: " << pq.toString() << endl;
    
        cout << "Popping: " << pq.top() << endl;
        pq.pop();
        cout << "Queue: " << pq.toString() << endl;

        cout << "\n7. Using ! operator to clear the queue:" << endl;
        cout << "Queue 2 before clearing: " << pq2.toString() << endl;
        !pq2;
        cout << "Queue 2 after clearing: " << pq2.toString() << endl;

        cout << "\n8. Working with an array of queues:" << endl;
        PriorityQueue queues[3];
    
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                queues[i].push(i * 10 + j, 3 - j);
            }
            cout << "Queue " << i << ": " << queues[i].toString() << endl;
        }

    }
    catch(...){
        std::cout << "Some exception occured" << std::endl;    
    }
return 0;
}