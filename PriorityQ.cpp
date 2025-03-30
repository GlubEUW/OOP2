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
    int findByWeight(int weight) const {
        Node* current = head;
        int i = 0;
        while (current != nullptr) {
            if (current->weight == weight) {
                return i;
            }
            ++i;
            current = current->next;
        }
        return -1;
    }
    bool updateValueByWeight(int weight, int newValue) {
        Node* current = head;
        while (current != nullptr) {
            if (current->weight == weight) {
                current->value = newValue;
                return true;
            }
            current = current->next;
        }
        return false;  // Weight not found
    }
    
    void clear() {
        while (!empty()) {
            pop();
        }
    }

    
bool operator<(const Impl& other) const {
    if (empty() && !other.empty()) {
        return true;
    }
    if (!empty() && other.empty()) {
        return false;
    }
    if (empty() && other.empty()) {
        return false;  // Equal, not less than
    }
    
    if (size() < other.size()) {
        return true;
    }
    if (size() > other.size()) {
        return false;
    }
    
    Node* thisCurrent = head;
    Node* otherCurrent = other.head;
    
    while (thisCurrent != nullptr && otherCurrent != nullptr) {
        if (thisCurrent->weight < otherCurrent->weight) {
            return true;
        }
        if (thisCurrent->weight > otherCurrent->weight) {
            return false;
        }
        
        if (thisCurrent->value < otherCurrent->value) {
            return true;
        }
        if (thisCurrent->value > otherCurrent->value) {
            return false;
        }
        
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }
    return false;
}


bool operator==(const Impl& other) const {
    if (size() != other.size()) {
        return false;
    }
    
    if (empty() && other.empty()) {
        return true;
    }
    
    Node* thisCurrent = head;
    Node* otherCurrent = other.head;
    
    while (thisCurrent != nullptr && otherCurrent != nullptr) {
        if (thisCurrent->weight != otherCurrent->weight || 
            thisCurrent->value != otherCurrent->value) {
            return false;
        }
        
        thisCurrent = thisCurrent->next;
        otherCurrent = otherCurrent->next;
    }
    
    return true;
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
int PriorityQueue::operator[](int weight) const {
    return pImpl->findByWeight(weight);
}
PriorityQueue& PriorityQueue::operator<<(const std::pair<int, int>& pair) {
    pImpl->updateValueByWeight(pair.second, pair.first);
    return *this;
}
bool PriorityQueue::operator<(const PriorityQueue& other) const {
    return *pImpl < *other.pImpl;
}

bool PriorityQueue::operator==(const PriorityQueue& other) const {
    return *pImpl == *other.pImpl;
}


}