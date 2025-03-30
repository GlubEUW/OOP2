#include "PriorityQ.h"
#include <stdexcept>

namespace myNamespace {

class PriorityQueue::Impl {
private:
    struct Node {
        int value;
        int weight;
        Node* next;
        Node(int val, int w) : value(val), weight(w), next(nullptr) {}
    };

    Node* head;
    size_t count;

public:
    Impl() : head(nullptr), count(0) {}
    ~Impl() { clear(); }

    bool empty() const { return head == nullptr; }
    size_t size() const { return count; }

    void push(int value, int weight) {
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

    int top() const {
        if (empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        return head->value;
    }

    int topWeight() const {
        if (empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        return head->weight;
    }

    void pop() {
        if (empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    void clear() {
        while (!empty()) {
            pop();
        }
    }
};

PriorityQueue::PriorityQueue() : pImpl(std::make_unique<Impl>()) {}
PriorityQueue::~PriorityQueue() = default;

bool PriorityQueue::empty() const { return pImpl->empty(); }
size_t PriorityQueue::size() const { return pImpl->size(); }
void PriorityQueue::push(int value, int weight) { pImpl->push(value, weight); }
int PriorityQueue::top() const { return pImpl->top(); }
int PriorityQueue::topWeight() const { return pImpl->topWeight(); }
void PriorityQueue::pop() { pImpl->pop(); }
void PriorityQueue::clear() { pImpl->clear(); }

}