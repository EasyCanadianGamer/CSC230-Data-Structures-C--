#include <iostream>
#include <stack>
using namespace std;

template <class T>
class MyQueue {
    // these two stck are instance variables
    // by default, the access is private
    stack<T> first;
    stack<T> second;
    
    public:

    // return the value of the oldest member
   T front() {
    if (first.empty()) {
        throw underflow_error("Queue is empty");
    }
    // Move all elements from first to second stack
    while (!first.empty()) {
        second.push(first.top());
        first.pop();
    }
    // Get the front element from second stack
    T oldest = second.top();
    // Move elements back to first stack
    while (!second.empty()) {
        first.push(second.top());
        second.pop();
    }
    return oldest;
}


    // add value val to MyQueue
void push(T val) {
    first.push(val);
}



    // remove the oldest member from MyQueue
void pop() {
    if (first.empty()) {
        throw underflow_error("Queue is empty");
    }
    // Move all elements from first to second stack except the last one
    while (first.size() > 1) {
        second.push(first.top());
        first.pop();
    }
    // Remove the last element from first stack
    first.pop();
    // Swap the stacks
    swap(first, second);
}

};
