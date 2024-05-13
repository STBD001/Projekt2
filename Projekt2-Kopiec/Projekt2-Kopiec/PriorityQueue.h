#pragma once
#include <iostream>
#include <stdexcept>
class PriorityQueue {

    // w sprawku umieszcic rowniez 
    // 1: elementy do porownania w priority queue musza byc! porownalne
public:
    virtual ~PriorityQueue() {}

    virtual void insert(int element, int priority) = 0;
    virtual int extractMax() = 0;
    virtual int findMax() const = 0;
    virtual void modifyKey(int element, int newPriority) = 0;
    virtual int returnSize() const = 0;

    // fix do modifykey random
    //virtual int priorityOnList(int random) const;
    virtual void queueState()const = 0; // basically print function
    virtual int returnLos(int priority)const = 0;
};

