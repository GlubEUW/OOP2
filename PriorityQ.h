// Mindaugas Kalvinskas 2 gr. 1 pgr. 2 IND prioritetine eile
// Funkcionuoja kaip panasiai kaip stekas, metodai push(+=) pop(-=) skirti prideti/naikinti Node's 
// toString spausdina pirmus 5, clear (!) isvalo, yra visi palyginimo operatoriai, priskyrimo operatorius atleika deep copy
// find by value([]) metodas randa kaip giliai yra Node su tokia verte, jei neranda grazina 1
//
//
#ifndef PRIORITYQ_H
#define PRIORITYQ_H
#include <memory>
#include <cstddef>
#include <utility>
#include <string>
#include <sstream>

namespace myNamespace {
class EmptyQueueException : public std::exception {
    public:
        const char* what() const noexcept override;
    };

class PriorityQueue {
    private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
    public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& other);
    PriorityQueue& operator=(const PriorityQueue& other);
    ~PriorityQueue();
    
    bool empty() const;
    size_t size() const;
    void push(int value, int weight);
    PriorityQueue& operator+=(const std::pair<int, int>& p);
    PriorityQueue& operator-=(int);
    void pop();
    PriorityQueue& operator<<(const std::pair<int, int>& p);
    PriorityQueue& operator!();
    int top() const;
    int topWeight() const;
    
    void clear();
    int operator[](int value) const;
    bool operator<(const PriorityQueue& other) const;
    bool operator==(const PriorityQueue& other) const;
    bool operator!=(const PriorityQueue& other) const;
    bool operator<=(const PriorityQueue& other) const;
    bool operator>(const PriorityQueue& other) const;
    bool operator>=(const PriorityQueue& other) const;
    std::string toString() const;


};

}

#endif
