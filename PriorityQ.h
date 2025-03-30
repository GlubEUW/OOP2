#ifndef PRIORITYQ_H
#define PRIORITYQ_H

#include <memory>
#include <cstddef>

namespace myNamespace {

class PriorityQueue {
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

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};

}

#endif // PRIORITYQ_H
