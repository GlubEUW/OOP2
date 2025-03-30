#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include <iostream>
#include <stdexcept>
namespace myNamespace {
class PriorityQueue {
private:
    struct Node {
        int value;
        int weight;
        Node* next;
        // Constructor
        Node(int val, int w) : value(val), weight(w), next(nullptr) {}
    };

    Node* head;
    size_t count;

public:
    PriorityQueue();

    ~PriorityQueue();

    bool empty() const;

    size_t size() const;

    void push(int value, int weight);

    int top() const;

    int topWeight() const;

    void pop();

    void clear();
};
}
#endif // PRIORITY_QUEUE_H
