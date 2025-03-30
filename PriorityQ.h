#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include <memory>
#include <cstddef>
#include <utility>
namespace myNamespace {
class EmptyQueueException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Priority queue is empty";
    }
};

class PriorityQueue {
public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& other);
    ~PriorityQueue();
    
    bool empty() const;
    size_t size() const;
    void push(int value, int weight);
    PriorityQueue& operator+=(const std::pair<int, int>& p);
    PriorityQueue& operator-=(int);
    PriorityQueue& operator<<(const std::pair<int, int>& p);
    void operator!();
    int top() const;
    int topWeight() const;
    void pop();
    void clear();
    int operator[](int value) const;
private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

}

#endif
