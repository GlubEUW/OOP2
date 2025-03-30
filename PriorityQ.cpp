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
    Impl(const Impl& other) : head(nullptr), count(0) {
        if (other.head == nullptr) {
            return;
        }
        Node* otherCurrent = other.head;
        while (otherCurrent != nullptr) {
            push(otherCurrent->value, otherCurrent->weight);
            otherCurrent = otherCurrent->next;
        }
    }
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
            throw EmptyQueueException();
        }
        return head->value;
    }

    int topWeight() const {
        if (empty()) {
            throw EmptyQueueException();
        }
        return head->weight;
    }

    void pop() {
        if (empty()) {
            throw EmptyQueueException();
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }
    int findValue(int weight) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->weight == weight) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    void clear() {
        while (!empty()) {
            pop();
        }
    }
};

PriorityQueue::PriorityQueue() : pImpl(std::make_unique<Impl>()) {}
PriorityQueue::~PriorityQueue() = default;

PriorityQueue::PriorityQueue(const PriorityQueue& other) : pImpl(std::make_unique<Impl>(*other.pImpl)) {}
bool PriorityQueue::empty() const{ 
    return pImpl->empty();
 }
size_t PriorityQueue::size() const{
    return pImpl->size(); 
}
void PriorityQueue::push(int value, int weight){ 
    pImpl->push(value, weight);
}
int PriorityQueue::top() const{
    return pImpl->top(); 
}
int PriorityQueue::topWeight() const{ 
    return pImpl->topWeight(); 
}
void PriorityQueue::pop(){ 
    pImpl->pop(); 
}
void PriorityQueue::clear(){ 
    pImpl->clear(); 
}
PriorityQueue& PriorityQueue::operator+=(const std::pair<int, int>& pair) {
    push(pair.first, pair.second);
    return *this;
}
PriorityQueue& PriorityQueue::operator-=(int) {
    pop();
    return *this;
}
void PriorityQueue::operator!(){
    clear();
}
int PriorityQueue::operator[](int value) const {
    return pImpl->findValue(value);
}
PriorityQueue& PriorityQueue::operator<<(const std::pair<int, int>& p){
    //FIXME
}
}