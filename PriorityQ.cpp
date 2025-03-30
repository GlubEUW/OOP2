#include "PriorityQ.h"

using namespace std;
namespace myNamespace {
PriorityQueue::PriorityQueue() : head(nullptr), count(0) {}

PriorityQueue::~PriorityQueue() {
    clear();
}

bool PriorityQueue::empty() const {
    return head == nullptr;
}

size_t PriorityQueue::size() const {
    return count;
}


void PriorityQueue::push(int value, int weight) {
    Node* newNode = new Node(value, weight);

    if (empty() || weight > head->weight) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->weight >= weight) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    count++;
}

int PriorityQueue::top() const {
    if (empty()) {
        throw runtime_error("Priority queue is empty");
    }
    return head->value;
}

int PriorityQueue::topWeight() const {
    if (empty()) {
        throw runtime_error("Priority queue is empty");
    }
    return head->weight;
}

void PriorityQueue::pop() {
    if (empty()) {
        throw runtime_error("Cannot pop from an empty priority queue");
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    count--;
}

void PriorityQueue::clear() {
    while (!empty()) {
        pop();
    }
}

}
